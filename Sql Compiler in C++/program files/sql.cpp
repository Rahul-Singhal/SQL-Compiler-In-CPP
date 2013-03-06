#include<iostream>
#include<string>
#include<cstring>
#include<ctype.h>
#include"general.h"
#include"check.cpp"
#include"groupby.cpp"
#include"having.cpp"
#include"orderby.cpp"
#include"tempfun.cpp"
#include"comfun.cpp"
#include"safe.cpp"
#include"display.cpp"
using namespace std;




string aggrfunc; string aggrcol;string gby;
//converts the string s to uppercase using inbuilt function (toupper(char))
string upr(string s)
{
int i,count=1;
for(i=0;i<s.length();i++){
if(s[i]=='\'')
count++;
if(count%2==1)
s[i]=toupper(s[i]);
}
return s;
}

//returns 1 if string s is a valid number
int checkNum(string s)
{
int i=0;int point=0;
while(i<s.length()){
if(s[i]=='.')point++;
else if(!(s[i]<='9'&&s[i]>='0'))return 1;
if(point>1)return 1;
i++;
}
return 0;
}
 
//checks the syntax of ORDER BY  ( ORDER BY column name [ASC ] [DESC]
int orderBy()
{
char*p=strtok(NULL," ");
string st=p;
if(!(st=="BY"))
return 0;
st=p=strtok(NULL," ");
if(st.find_first_of("<>/,*\()+=\{}\'")!=string::npos)//checks if its a valid column name 
return 0;
st=p=strtok(NULL," ");
if(st==";")
return 1;
if((st=="DESC"||st=="ASC"))
{
st=p=strtok(NULL," ");
if(st==";")
return 1;
}
return 0;
}

//checks the syntax of HAVING (HAVING AGGREGATE FUNCTION LOGICAL OPERATOR VALUE)

int having(){
string s;int i=0;
char*p;
s=p=strtok(NULL," ");

if(s==aggrfunc)
{
      s=p=strtok(NULL," ");
      if (s!="\(")return 0;                  
      s=p=strtok(NULL," ");
      
      if(s!=aggrcol){return 0;}
      s=p=strtok(NULL," ");
      if(s!=")")return 0;
      s=p=strtok(NULL," ");

      if(!(s==">"||s=="<"||s=="="))return 0;
      s=p=strtok(NULL," ");

      if(checkNum(s))return 0;
      s=p=strtok(NULL," ");

      if(s!=";")return 0;
      return 1;
}
return 0;
}
     
//checks the syntax of the condition after where using recursion
int checkAndOrNot()
{

    int obrac=0, cbrac=0;//stores the number of opening and closing brackets 
    char *p;int cond=0;string st;int i=0;
    while(!(cond!=0&&obrac==cbrac)){
        st=p=strtok(NULL," ");
       
        if(st=="\("){obrac++;continue;}
        if(st==")"){cbrac++;continue;}
        
        if(st=="AND"||st=="OR")
        {
        if(cond!=0){checkAndOrNot();}
        else {return 0;}
        }
        else if(st=="NOT")
        {
        cond++;
        checkAndOrNot();
        }
        else if(st.find_first_of("<>/,*\()+=\{}\';")!=string::npos){return 0;}
        else
        {    
             i=0;
             st=p=strtok(NULL," ");
             if(st=="+"||st=="-"||st=="/"||st=="*")
             {
             st=p=strtok(NULL," ");
             if(checkNum(st))return 0; 
             i=0;
             st=p=strtok(NULL," ");
             }
             
             
             if(!(st==">"||st=="<"||st=="="||st=="LIKE"||st=="BETWEEN")){return 0;}
               
             if(st=="LIKE")
             {
                return 0;
                st=p=strtok(NULL," ");
                
                if(st[0]!='\''){return 0;}
             }
             else if(st=="BETWEEN")
             {
                return 0;
             	st=p=strtok(NULL," ");
             	if(checkNum(st))return 0;
             	st=p=strtok(NULL," ");
             	if(!(st=="AND"))return 0;
             	st=p=strtok(NULL," ");
             	i=0;
             	if(checkNum(st))return 0;
             	
			 }
			 else
             {
                st=p=strtok(NULL," ");
                if(st[0]!='\'')
                {if(checkNum(st))return 0;}
             }
             cond++;
       }
    }


return 1;
}

                                
         
//function to check the validity of command given by user.
int checkSelect(string st,int n){
    
  char*p;           
  int i=0;
            
       
  

  //checking the first word of input command i.e select.
  // syntax of SELECT ( SELECT [DISTINCT COLUMN NAME or ALL COLUMN NAME or *] COLUMN NAMES )
  if(st!="SELECT"){return 0;}
  st=p=strtok(NULL," "); 
  if(st=="*"){st=p=strtok(NULL," ");agcount=1;}
  else if(st=="DISTINCT" || st=="ALL")
   { 
          st=p=strtok(NULL," "); 
          if(st.find_first_of("<>/,*\()+=\{}\'")!=string::npos){return 0;}
          st=p=strtok(NULL," ");
          agcount=1;
   } 
  else
  {  if(st=="FROM"||st==","||st==";"){return 0;}
     do
     {  if(st==",")
        {
          st=p=strtok(NULL," "); 
        }
        if(st=="DISTINCT"||st=="ALL"){return 0;}
        if(st=="FROM"){return 0;}
        else if(st=="AVG"||st=="MIN"||st=="MAX"||st=="SUM"||st=="COUNT")
        {    if(agcount==-1){}
             else if(agcount<0)return 0;
             else
             agcount++;
             aggrfunc=st;
             st=p=strtok(NULL," "); 
             if(st!="(")return 0;
             st=p=strtok(NULL," "); 
             if(st.find_first_of("<>/,*\()+=\{}\'")!=string::npos){return 0;}
             aggrcol=st;
             st=p=strtok(NULL," ");
             if(st!=")")return 0;
             st=p=strtok(NULL," ");
             if(agcount==-1){agcount=0;break;}
        }
        else
        {   if(agcount==1){}
            else if(agcount>0)return 0;
            else
            agcount--;
            if(st.find_first_of("<>/,*\()+=\{}\'")!=string::npos){return 0;}
            if(agcount==1){gby=st;st=p=strtok(NULL," ");agcount=0;break;}
            if(agcount==-1){gby=st;} 
            st=p=strtok(NULL," ");
            if(st=="+"||st=="-"||st=="/"||st=="*")
            {
              st=p=strtok(NULL," ");
              i=0;
           	  if(checkNum(st))return 0;
              st=p=strtok(NULL," "); 
            }
           
        } 

     }  
     while(st==",");
  }
  

  
  if(st!="FROM")return 0;//checks if From comes after SELECT Column names 

  st=p=strtok(NULL," ");
  if(st.find_first_of("<>/,*\()+=\{}\'")!=string::npos){return 0;}
  file_name=p;//stores the name of the file (only handling single files pe8r query
  st=p=strtok(NULL," ");
  int brac=0;
  //if aggregate function present syntax should have GROUP BY
  if(st!="WHERE"&&agcount==0)
  {  
     if(st!="GROUP")return 0;
     st=p=strtok(NULL," ");
     if(st!="BY")return 0;
     st=p=strtok(NULL," ");
     if(st!=gby)return 0;
     if(st.find_first_of("<>/,*\()+=\{}\'")!=string::npos){return 0;}
     st=p=strtok(NULL," ");
     if(st==";")return 1;
     
     
     
     //HAVING can only exist after GROUP BY
     
     else if(st=="HAVING")return having();
     else return 0;
  }

    if(st==";")return 1;
  if(st=="UNION"||st=="INTERSECT"||st=="EXCEPT"){st=p=strtok(NULL," ");return 0;}
  else if(st=="ORDER"&&n==0)
  return orderBy(); 
  
  
  
  else if(st=="WHERE")
  {  

       do
       {
       if(!checkAndOrNot())return 0;
       st=p=strtok(NULL," ");
       }
       while(st=="AND"||st=="OR");
       
       
    }
       else return 0;
       
       if(brac==1&&st!=")")
       return 0;
       if(brac==1)
       st=p=strtok(NULL," ");
       
     if(agcount==0)
      {
     if(st!="GROUP")return 0;
     st=p=strtok(NULL," ");
     if(st!="BY")return 0;
     st=p=strtok(NULL," ");
     if(st!=gby)return 0;
     if(st.find_first_of("<>/,*\()+=\{}\'")!=string::npos){return 0;}
     st=p=strtok(NULL," ");
     if(st==";")return 1;
     else if(st=="HAVING")return having();
     else return 0;
     }
     if(st==";")return 1;
       if(st=="UNION"||st=="INTERSECT"||st=="EXCEPT"){st=p=strtok(NULL," ");return checkSelect(st,1);}
       else if(st=="ORDER"&&n==0)
       return orderBy();
       else
       {return 0;}

       
       
return 0;
}


//accepts the sql query in multiline format

void inputer(){
string s="";
while(input[input.length()-2]!=';')
{
getline(cin,s);
input+=s+" ";
}

input=upr(input);
s=input;
input="";int count=1;
string delim="<>/,*\()+=\{}\';";
size_t pos=s.find_first_of(delim);
while(pos!=string::npos)
{
if(s[pos]=='\'')
{
	input=input+s.substr(0,pos)+" "+s.substr(pos,1);
	s=s.substr(pos+1);
	pos=s.find_first_of("\'");
	input=input+s.substr(0,pos+1);
	s=s.substr(pos+1);
}
else
{
input=input+s.substr(0,pos)+" "+s.substr(pos,1);
s=s.substr(pos+1);
}


input=input+" ";
pos=s.find_first_of(delim);
}

input=input+s;


}
    

 
int main()
{
char key='\0';string s; size_t length;
char buffer[1000];int n;

cout<<"###############################################################################\n";
cout<<"       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
cout<<"        %% WELCOME TO THE NEW WORLD OF SQL CODING IN C++ ENVIRONMENT %%\n";
cout<<"            __JUST USE THE COMMANDS OF SQL AND ENJOY THE MAGIC__\n";
cout<<"       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
cout<<"###############################################################################\n\n";

while(1)
{
        
input="";
row=0;col=0;
agcount=0;
if(key!='\0')
{
             cout<<endl<<endl;
cout<<"Press C to CONTINUE or press any other key to EXIT"<<endl<<endl;
cin>>key;
if(!(key=='C'||key=='c'))break;
}

cout<<endl<<endl;
cout<<"Enter the SQL Query"<<endl;
key='c';
cout<<endl;
inputer();
length=input.copy(buffer,input.length(),0);
buffer[length]='\0';
char*p=strtok(buffer," ");
s=p;
cout<<endl<<endl;
if(checkSelect(s,0))
{


if(!parseData(file_name,input))continue;

length=input.copy(buffer,input.length(),0);
buffer[length]='\0';
char*p=strtok(buffer," ");
s=p;

while(s!="FROM")s=p=strtok(NULL," ");
s=p=strtok(NULL," ");s=p=strtok(NULL," ");
if(s=="WHERE")
{
if(!conditionEval()){cout<<"ERROR IN WHERE CONDITION"<<endl;continue;}

int srow=-1;
for(int i=0;i<row;i++)
{
if(Selected[i]==1)
{srow++;
for(int j=0;j<col;j++)
strcpy(column[srow][j],column[i][j]);
}
}
row=srow+1;
srow=-1;
for(int i=0;i<main_row;i++)
{
if(Selected[i]==1)
{srow++;
for(int j=0;j<main_col;j++)
strcpy(main_array[srow][j],main_array[i][j]);
}
}
main_row=srow+1;
s=ap;

}

if(s=="ORDER")
{
s=p=strtok(NULL," ");
s=p=strtok(NULL," ");
string ocol=s;
s=p=strtok(NULL," ");
 if(s=="ASC"){orderby(ocol,1);s=p=strtok(NULL," ");}
 else if(s=="DESC"){orderby(ocol,2);s=p=strtok(NULL," ");}
else
orderby(ocol,1);

}

if(s=="GROUP")
{
if(aggrfunc=="SUM")n=4;
if(aggrfunc=="MIN")n=1;
if(aggrfunc=="MAX")n=2;
if(aggrfunc=="COUNT")n=3;
if(aggrfunc=="AVG")n=5;

if(!groupby(gby,aggrcol,n)){cout<<"ERROR IN GROUP BY CONDITION"<<endl;input="";continue;}
//cout<<retgroupby_column[0][0]<<endl;
while(s!=";"&&s!="HAVING")s=p=strtok(NULL," ");

if(s=="HAVING")
{
//cout<<s;
for(int i=0;i<4;i++)
s=p=strtok(NULL," ");
s=p=strtok(NULL," ");
if(s==">")n=1;
if(s=="=")n=2;
if(s=="<")n=3;
s=p=strtok(NULL," ");
if(!having(aggrfunc,n,s))cout<<"ERROR IN HAVING CONDITION"<<endl;
s=p=strtok(NULL," ");
}
display(retgroupby_column);continue;
}



if(s==";")display(column);




cout<<endl;


}
else
cout<<"SYNTAX ERROR"<<endl;

}
return 0;
}
   
    
    
   /* int main(){
        string s;
        int a;
        getline(cin,s);
            
  size_t length;
  char str[1000];            
  length=s.copy(str,s.length(),0);
  str[length]='\0';
  char*p; 
  s=p=strtok(str," ");
        if(checkSelect(s,0))
        cout<<"DF";
        cin>>a;
        return 0;
        }
*/
            
            
            
            
