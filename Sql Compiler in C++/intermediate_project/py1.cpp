#include<iostream>
#include<string>
#include<cstring>
#include<ctype.h>
#include<istream>
#include<fstream>
#include<stdio.h>

#define LENMAX  100

using namespace std;

 //function to count number ofcolumn//

  char nfile[50];  
int NoOfCol(char *line){
    
    int charIndex=0;
    int noOfCol=0;
    
    
    
    
    while( line[charIndex] != '\n'){
           if( line[charIndex++]=='\t' ){
    		   noOfCol++;
           }
    }
    return noOfCol +1;
}
//function to count number of rows by counting number of new line char//
int NoOfRows(){
    ifstream fin(nfile);
    char line[LENMAX];
    int no=0;
    do{
    no++;
    fin.getline(line,LENMAX);
    
    }while(!fin.eof());
    
    return (no-1);
    }
//function to find the I index of string//
int searchI(string pword , char parray[10][10][10] ){
int m;
for (int i=0;i<10;i++){for(int j=0;j<10;j++){if (pword==parray[i][j]){
m=i;}
}
}
return (m);
} 
//function to find the J index of string//
int searchJ(string pword , char parray[10][10][10] ){
int n;
for (int i=0;i<10;i++){for(int j=0;j<10;j++){if (pword==parray[i][j]){
n=j;}
}
}
return (n);
} 





string pdata[30];int pn=0;int flagstar=0;int flagorder=0; int flaggroup=0;int flaggreater=0;int flagsmaller=0;int flagor=0;int flagand=0;string qorder;int qordertype=0;
string pdata2[30]; int pn2=0;


string input="";


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


int orderBy()
{
flagorder=1;
char*p=strtok(NULL," ");
string st=p;
if(!(st=="BY"))
return 0;
st=p=strtok(NULL," ");
qorder=st;
if(st.find_first_of("<>/,*\()+=\{}\'")!=string::npos)
return 0;
st=p=strtok(NULL," ");
if(st==";")
return 1;
if((st=="DESC"||st=="ASC"))
{
if(st=="DESC")qordertype=1;
st=p=strtok(NULL," ");
if(st==";")
return 1;
}
return 0;
}


int having(){
string s;int i=0;
char*p;
s=p=strtok(NULL," ");
if(s=="MIN" || s=="MAX" || s=="AVG"||s=="SUM"||s=="COUNT")
{
      s=p=strtok(NULL," ");
      if (s!="\(")return 0;                  
      s=p=strtok(NULL," ");
      if(s.find_first_of("<>/,*\()+=\{}\'")!=string::npos){return 0;}
      s=p=strtok(NULL," ");
      if(s==")")return 0;
      s=p=strtok(NULL," ");
      if(!(s==">"||s=="<"||s=="="))return 0;
      s=p=strtok(NULL," ");
      while(i<s.length()){if(!(s[i]<='9'&&s[i]>='0'))return 0;i++;}
      s=p=strtok(NULL," ");
      if(s!=";")return 0;
      return 1;
}
return 0;
}
     

int checkAndOrNot()
{

    int obrac=0, cbrac=0;char *p;int cond=0;string st;int i=0;
    while(!(cond!=0&&obrac==cbrac)){
        st=p=strtok(NULL," ");
       
        if(st=="\("){obrac++;continue;}
        if(st==")"){cbrac++;continue;}
        if(st=="OR")
        {flagor=1;
        if(cond!=0){checkAndOrNot();}
        else {return 0;}
        }
        if(st=="AND")
        {flagand=1;
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
             pdata2[pn2]=st;pn2++;
             st=p=strtok(NULL," ");
         
             if(!(st==">"||st=="<"||st=="="||st=="LIKE"||st=="BETWEEN")){return 0;}
               
             if(st=="LIKE")
             {
                st=p=strtok(NULL," ");
                
                if(st[0]!='\''){return 0;}
                pdata2[pn2]=st;pn2++;
             }
             else if(st=="BETWEEN")
             {
             	st=p=strtok(NULL," ");
             	while(i<st.length()){if(!(st[i]<='9'&&st[i]>='0'))return 0;i++;}
                pdata2[pn2]=st;pn2++;
             	st=p=strtok(NULL," ");
             	if(!(st=="AND"))return 0;
             	st=p=strtok(NULL," ");
             	i=0;
             	while(i<st.length()){if(!(st[i]<='9'&&st[i]>='0'))return 0;i++;}
             	pdata2[pn2]=st;pn2++;
			 }
			 else
             {
                st=p=strtok(NULL," ");
                if(st[0]!='\'')
                {while(i<st.length()){if(!(st[i]<='9'&&st[i]>='0'))return 0;i++;}}
                 pdata2[pn2]=st;pn2++;
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

  //temporary string to store the individual words extracted byfuction strtok(). 
  //function to extract individual words from a string consecutively.                 
       
  
  //checking the first word of input command i.e select.
  if(st!="SELECT"){return 0;}
  st=p=strtok(NULL," "); 
  if(st=="*"){st=p=strtok(NULL," ");flagstar=1;}
  else
  {  if(st=="FROM"||st==","){return 0;}
     do
     {  if(st==",")
        {
          st=p=strtok(NULL," "); 
        }
        if(st=="FROM"){return 0;}
        if(st=="DISTINCT" || st=="ALL")
        { 
          st=p=strtok(NULL," "); 
          if(st.find_first_of("<>/.,*\()+=\{}\'")!=string::npos){return 0;}
          st=p=strtok(NULL," ");
        } 
        else if(st=="AVG"||st=="MIN"||st=="MAX"||st=="SUM"||st=="COUNT")
        {
             st=p=strtok(NULL," "); 
             if(st!="(")return 0;
             st=p=strtok(NULL," "); 
             if(st.find_first_of("<>/.,*\()+=\{}\'")!=string::npos){return 0;}
             st=p=strtok(NULL," ");
             if(st!=")")return 0;
             st=p=strtok(NULL," ");
        }
        else
        {
             
            if(st.find_first_of("<>/.,*\()+=\{}\'")!=string::npos){return 0;}
            pdata[pn]=st;pn++; 
            st=p=strtok(NULL," ");
            if(st=="+"||st=="-"||st=="/"||st=="*")
            {
              st=p=strtok(NULL," ");
              i=0;
           	  while(i<st.length()){if(!(st[i]<='9'&&st[i]>='0'))return 0;i++;}
              st=p=strtok(NULL," "); 
            }
        } 

     }  
     while(st==",");
  }
  
  
  
  if(st!="FROM")return 0;
 
  st=p=strtok(NULL," ");int t1=0;
  for(t1=0;t1<st.length();t1++)
  nfile[t1]=st[t1];
  nfile[t1]='\0';
  if(st==",")return 0;
  do
  {  if(st==",")
     {
     st=p=strtok(NULL," "); 
     }
     if(st.find_first_of("<>/.,*\()+=\{}\'")!=string::npos){return 0;}
     st=p=strtok(NULL," ");
     if(st=="NATURAL")
     {  
        while(st=="NATURAL")
        {              
        st=p=strtok(NULL," "); 
        if(st!="JOIN")return 0;
        st=p=strtok(NULL," "); 
        if(st.find_first_of("<>/.,*\()+=\{}\'")!=string::npos){return 0;}
        st=p=strtok(NULL," ");
        }
     }
     
     
  }
  while(st==",");
  
  if(st==";")return 1;
  if(st=="UNION"||st=="INTERSECT"||st=="EXCEPT"){st=p=strtok(NULL," ");return checkSelect(st,1);}
  else if(st=="ORDER"&&n==0)
  return orderBy();
  else if(st=="GROUP"&&n==0)
  {
     st=p=strtok(NULL," ");
     if(st!="BY")return 0;
     st=p=strtok(NULL," ");
     if(st.find_first_of("<>/,*\()+=\{}\'")!=string::npos){return 0;}
     st=p=strtok(NULL," ");
     if(st==";")return 1;
     else if(st=="HAVING")return having();
     else return 0;
  }  
  else if(st=="WHERE")
  {
     st=p=strtok(NULL," ");
     if(st=="NOT")
     {
       do
       {
       if(!checkAndOrNot())return 0;
       st=p=strtok(NULL," ");
       }
       while(st=="AND"||st=="OR");
      
     }    
     else if(st.find_first_of("<>/,*\()+=\{}\';")==string::npos)
     {
             i=0;
pdata2[pn2]=st;pn2++;
             st=p=strtok(NULL," ");
             
         
             if(!(st==">"||st=="<"||st=="="||st=="LIKE"||st=="BETWEEN")){return 0;}
               
             if(st=="LIKE")
             {
                st=p=strtok(NULL," ");
                if(st[0]!='\''){return 0;}
                pdata2[pn2]=st;pn2++;
             }
             else if(st=="BETWEEN")
             {
             	st=p=strtok(NULL," ");
             	while(i<st.length()){if(!(st[i]<='9'&&st[i]>='0'))return 0;i++;}
                  pdata2[pn2]=st;pn2++;
             	st=p=strtok(NULL," ");
             	if(!(st=="AND"))return 0;
             	st=p=strtok(NULL," ");
             	i=0;
             	while(i<st.length()){if(!(st[i]<='9'&&st[i]>='0'))return 0;i++;}
             	pdata2[pn2]=st;pn2++;
			 }
            else
             {  if(st==">")flaggreater=1;if(st=="<")flagsmaller=1;
                st=p=strtok(NULL," ");
                if(st[0]!='\'')
                {while(i<st.length()){if(!(st[i]<='9'&&st[i]>='0'))return 0;i++;}}
                pdata2[pn2]=st;pn2++;
             }
             st=p=strtok(NULL," ");
             while(st=="AND"||st=="OR")
             {
              if(st=="AND")flagand=1;else flagor=1;
             if(!checkAndOrNot())return 0;
             st=p=strtok(NULL," ");
             }
       }
       else 
       {return 0;}
       
       if(st==";")return 1;
       if(st=="UNION"||st=="INTERSECT"||st=="EXCEPT"){st=p=strtok(NULL," ");return checkSelect(st,1);}
       else if(st=="ORDER"&&n==0){
       return orderBy();flagorder=1;}
       else if(st=="GROUP"&&n==0)
       { flaggroup=1;
         st=p=strtok(NULL," ");
         if(st!="BY")return 0;
         st=p=strtok(NULL," ");
         if(st.find_first_of("<>/,*\()+=\{}\'")!=string::npos){return 0;}
         st=p=strtok(NULL," ");
         if(st==";")return 1;
         else if(st=="HAVING")return having();
         else return 0;
       }
       else
       {return 0;}
}
else
{return 0;}  
       
       
return 0;
}


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
if(input[input.length()-1]=='\'')
input=input+s.substr(0,pos+1);
else
input=input+s.substr(0,pos)+" "+s.substr(pos,1);
s=s.substr(pos+1);
if(input[input.length()-1]=='\''&&count%2==1)
{
pos=s.find_first_of("\'");
count++;continue;
}
input=input+" ";
pos=s.find_first_of(delim);
}

input=input+s;


}
    
    
 
int main()
{
char key='C';string s; size_t length;
char buffer[1000];ifstream rFile;
while(key=='C'||key=='c')
{
cout<<"===========welcome to a prototype of SQL========"<<endl;
cout<<"Please Enter your SQL Query"<<endl;
inputer();
length=input.copy(buffer,input.length(),0);
buffer[length]='\0';
char*p=strtok(buffer," ");
s=p;
if(checkSelect(s,0))
cout<<"valid"<<endl;
else
cout<<"invalid"<<endl;

for(int i=0;i<pn2;i++)
{
if(pdata2[i][0]=='\'')
{pdata2[i]=pdata2[i].substr(1,pdata2[i].length()-2);}

}





//cout<<"and "<<flagand<<"flagor"<<flagor<<"flaggreater"<<flaggreater<<endl<<"flagsmaller"<<flagsmaller<<"flagorder"<<flagorder<<"qorder"<<qorder<<qordertype<<endl;

    rFile.open(nfile);
    //if(rFile==NULL)continue;
     char line[LENMAX];
    int i,j,k;
    int firstLine=1,noOfCols,noOfRows;
    int index=0,lengthOfColName = 0;
             char colName[10][10][10]; // max 10 cols and length of colName is 10  
    int firstPt = 0;
           int SecondPt = 0;
           char am;
    if (rFile.is_open()) {
                                                              
            firstLine=1;
            for(int p=0;p<NoOfRows();p++ ){
           
           firstPt = 0;
           SecondPt = 0;
              
               rFile.getline(line,LENMAX);
              
               noOfCols = NoOfCol(line);//number of column//
               
               index=0,lengthOfColName = 0;
               k=1;
               
               do{
                     if(line[SecondPt]!='\t'){
                         SecondPt++;
                     }
                     else{
   		                  lengthOfColName = SecondPt - firstPt; // -1 is for copying char till before tab.//
    		              for(i = 0; i< lengthOfColName; i++){
    			               colName[p][index][i]=line[firstPt+i];
                          }
                          colName[p][index][i] = '\0';
                          cout<<colName[p][index];
                         
                          index++;
   		                  SecondPt++;
   		                  firstPt=SecondPt;
    	                  cout<<'\t';
                          k++;
                    }
                    
               }while (k <noOfCols);
               
               cout<<endl;
               }
               }
         
          			//finding index of columns in the query



int countpkn;
int pkn[30];
for(int t1=0;t1<30;t1++){pkn[t1]=-1;}
int g =0,h1=0;
	if (flagstar==0){
			while(g<pn)
					{for(int j=0;j<pn;j++){
								pkn[g]=searchJ(pdata[j],colName);
								
								g++;
								}
					}
			countpkn=g;
			}
if(flagstar!=0){ for(int j1=0;j1<noOfCols-1;j1++)
                    {
                    pkn[j1]=h1;h1++;
                    }

                }
							//to find index of conditional terms//

//counting the number of conditional terms



int y=0,countpdata2=0;
	while (pdata2[y++]!=""){countpdata2++;}

//cout<<"no of pdata2 is "<<countpdata2<<endl;

//initialising pkn2


int pkn2[NoOfRows()];
		for(int i=0;i<NoOfRows();i++){pkn2[i]=-1;}





//finding indexes for 'AND' condition//
//Flag condition is needed//

cout<<endl;

int z =0,r=0,w=1,t=0,count=0;
int pkn4[30],m;k=0;
if(flagand==1){
		pkn2[0]=0;k=1;
		for (int j =0 ;j<countpdata2;j=j+2)
			{
				for(i=0;i<noOfCols;i++)
				{
					if(colName[0][i]==pdata2[j]){break;}
				}
				if(j==0)
				{
					for(m=1;m<NoOfRows();m++)
					{
						if(pdata2[j+1]==colName[m][i])
						{
							pkn2[k++]=m;
						}
					}
				continue;
				}
						
		//cout<<pkn2[0]<<pkn2[1]<<pkn2[2]<<endl;	
		for(m=0;m<k;m++)
			{
				if(pkn2[m]>0)
				{
					if (colName[pkn2[m]][i]==pdata2[j+1]);
					else pkn2[m]=-1;
				
				}
			}
		}
  //cout<<pkn2[0]<<pkn2[1]<<pkn2[2]<<endl;
}


//code for OR


int flagdiv;
if(flagor==1){
		pkn2[0]=0;k=1;
		for (int j =0 ;j<countpdata2;j=j+2)
			{
				for(i=0;i<noOfCols;i++)
				{
					if(colName[0][i]==pdata2[j]){break;}
				}
			
		for(m=1;m<NoOfRows();m++)
			{
				flagdiv=1;
                for (int d=k-1;d>=0;--d)
				{
				    if (m==pkn2[d]) flagdiv=0;
				 }   
				 if (flagdiv==1)
                 {   
                                  if (colName[m][i]==pdata2[j+1])pkn2[k++]=m;//cout<<m;
				}
				
				}
			}//cout<<pkn2[0]<<pkn2[1]<<pkn2[2]<<endl;
		}





//finding index for simple 'where' condition 		
						
int vquery, b=1;
vquery=searchJ(pdata2[0],colName);				

if(pdata2[2]==""&& pdata2[0]!="")
	{
	pkn2[0]=0;
	for(int i=1;i<NoOfRows();i++)
		{
		if(colName[i][vquery]==pdata2[1])
			{
			   pkn2[b]=i;b++;//cout<<pkn2[b]<<endl;
			}
		 }
	}







// codes for comparative condition 
// flag condition is needed here //for age or sallery comparisn

int qindex,u=0,s=0;
qindex=searchJ(pdata2[0],colName);
	//in case of < condition
if(flagsmaller==1){pkn2[0]=0;s=1;
		  for(i=0;i<NoOfRows();i++)
			{
			if(colName[i][qindex]<pdata2[1])
				{
				pkn2[s]=i; s++;//cout<<i<<endl;
				}
			}
		   
		    }
	//in case of > condition
if(flaggreater==1){
		  
		for(i=0;i<NoOfRows();i++)
			{
			if(colName[i][qindex]>pdata2[1])
				{
				pkn2[s]=i; s++;//cout<<i<<endl;
				}
			}
		   }

cout<<"=================================="<<endl;
//for(int h1=0;h1<5;h1++){cout<<pkn[h1]<<endl;}
for(int h1=0;h1<5;h1++){cout<<pkn2[h1]<<endl;}
//printing the output

// for printing in simple select command//  

if (pdata2[0]==""){
		   for(int i=0;i<NoOfRows();i++)
                         {
                         for(int k=0;k<noOfCols-1;k++)
                             { 
				if (pkn[k]!=-1)
				  {cout<<colName[i][pkn[k]]<<'\t';}
                         	}
			cout<<endl;
                         }
                   }

//prining output in conditional cases//


if(pdata2[0]!=""){
	               	for(int i=0;i<NoOfRows();i++) 
                            {if(pkn2[i]!=-1)
                              
                                      {
                                      for(int k=0;k<noOfCols-1;k++)
                                           {
						if (pkn[k]!=-1){
                                           		cout<<colName[pkn2[i]][pkn[k]]<<'\t';
                                           			 }
		                                }cout<<endl;
                             		 }
  		             }
			}

                   
 rFile.close();
pn=0; flagstar=0;flagorder=0; flaggroup=0; flaggreater=0; flagsmaller=0; flagor=0;flagand=0; qorder=""; qordertype=0;
pn2=0;
cout<<"Press C to Continue or press any other key to Quit"<<endl;
cin>>key;
input="";
}

return 0;
}
   
    
    



























	
