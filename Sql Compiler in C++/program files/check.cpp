#include<iostream>
#include<cstring>
#include<stdio.h>
#include<string>
#include"general.h"

using namespace std;

// no.of columns entered by the user 
// max no. of col and rows in the table are 100 and max string length is 50
//char column_where_evaluation[100][100][50];
char col_where_evaluation[100][50];
char col_distinct[100][100][50];

void read_column(int no_of_tabs,int col_no,FILE * table_name);



int select( char col_name[50], FILE * table_name,int col_no){// fopen the file with pointer table_name 


char linestr[5500], name[50];
int no_of_tabs=0;

fgets(linestr,5499,table_name);
int i=0,k=0;
int flag=0;

while((name[i]=linestr[k])!='\n')
  {
   i=0;
   
  while((name[i++]=linestr[k++])!=',');
  name[i-1]='\0';
  
  
  int g=strcmp(name,col_name);
 /* adding line*/ int m;
  if(g==0)
       {  flag=1;
       	  for( m=0;;m++) 
          {
          column[col_no][0][m]=name[m];
          if(name[m]=='\0')break;
          } 
         read_column(no_of_tabs,col_no,table_name);// read into column[col_no][row_no][content]
          column[col_no][0][m]=',';
          int s=1;
          char c;
          while(((c=linestr[k++])!='\t')&&(c!='\n')){column[col_no][0][m+s]=c; s++;}
          column[col_no][0][m+s]='\0';
          break;
        }
    no_of_tabs++;
    char c;
   while(((c=linestr[k++])!='\t')&&(c!='\n'));
    if(c=='\n')break;
   }

if (flag==0) return (11);
else return (12);
} 


void read_column(int no_of_tabs,int col_no,FILE * table_name)
{
row=0;
char linestr[5500],c;
fgets(linestr,5499,table_name);
int k=0,tabs;
while(!feof(table_name))
  { tabs=0;k=0;
    while((c=linestr[k++])!='\n')
     { 
     if(c=='\t') tabs=tabs+1;
     if(tabs==no_of_tabs)
        {  int i=0;
           row++;
           if(no_of_tabs==0)k=k-1;
           while(((column[col_no][row][i]=linestr[k])!='\t')&&(column[col_no][row][i]!='\n')){ i++;k++;}     
           column[col_no][row][i]='\0';
           
           break; 
         }
       }
              
     fgets(linestr,5499,table_name);
    }
}
 
 
 void select_star(FILE * table_name) // fopen the file with pointer table_name
 { 
col=-1;row=0;
char linestr[5500],name[50];
fgets(linestr,5499,table_name);
int i=0,k=0;

 while((name[i]=linestr[k])!='\n')
  { col++;
  
   i=0;
   
  while(((name[i++]=linestr[k++])!='\t')&& (name[i-1]!='\n'));
  name[i-1]='\0';
  for(int m=0;;m++) 
  {
   column[col][0][m]=name[m];
   if(name[m]=='\0')break;
  } 
   char c;
   while(((c=linestr[k++])!='\t')&&(c!='\n'));
   if(c=='\n')break;
   }
    int dummy_col;
    
   fgets(linestr,5499,table_name);
   while(!feof(table_name))
   { 
     row++;
   	int i=0,k=0;
    dummy_col=-1;
    
    while((name[i]=linestr[k])!='\n')
    {dummy_col++; 
    if(dummy_col>col)col=dummy_col;
     i=0;
     while(((name[i++]=linestr[k++])!='\t')&&(name[i-1]!='\n'));
     name[i-1]='\0';
     for(int m=0;;m++) 
          {
          column[dummy_col][row][m]=name[m];
          if(name[m]=='\0')break;
          } 
     
     if (linestr[k-1]=='\n') break;   
   	}
   	 fgets(linestr,5499,table_name);
   	 
   	}
 }



void distinct()// first read the column in column[0][][] and then use this to store the distinct rows in col_distinct[][][]
{  int flag,g;
   strcpy(col_distinct[0][0],column[0][0]);
   strcpy(col_distinct[0][1],column[0][1]);
   int k=2;		
   for(int i=2;i<=row;i++)
   { flag=0;
   	for(int j=1;j<i;j++)
    {
     g=strcmp(column[0][i],column[0][j]);
     if(g==0) flag=-1;
    }
   if(flag==0)
     { strcpy(col_distinct[0][k],column[0][i]);
       k++;
       
     }

   }
 row=k-1;
 for(int i=2;i<=row;i++) strcpy(column[0][i],col_distinct[0][i]);

}



int parseData(char *fname,string in)//reads the file using the pointer fname & selects the corresponding from in
{
FILE * table_name;//file pointer
FILE *t1;int i,j,k;int star=0;int stcount=0;

table_name=fopen(fname,"r");
if(table_name==NULL){cout<<"TABLE NOT FOUND"<<endl;return 0;}
char* p;size_t length;
int not_valid=0;
char buffer[1000];
length=in.copy(buffer,in.length(),0);
buffer[length]='\0';
//cout<<"enter command: ";
//cin.getline(input,1000);
char ch[50];
string temp;
temp=p=strtok(buffer," ");
 
col=1; i=0,k=0;
     int spos=0, pos=0;
     table_name=fopen(fname,"r");
     char linestr[5500],name[50];
     fgets(linestr,5499,table_name);
     while(linestr[k]!='\n')
     { 
     if(linestr[k]==',')
   		{
   			pos=k;i=0;
   			for(int l=spos;l<pos;l++,i++)
   			name[i]=linestr[l];
   			name[i]='\0';
   			t1=fopen(fname,"r");
   			
            int not_valid=select(name,t1,col);
            col++;
   			
		}
		if(linestr[k]=='\t')
		spos=k+1;
		k++;

}

	for(int l=0 ; l<=row ;l++)//store all the contents of the file into main_array
	for(int m=1; m<=col;m++)
	{
		 temp=column[m][l];
		 for(k=0;k<temp.length();k++)
	     main_array[l][m-1][k]=temp[k];
	     main_array[l][m-1][k]='\0';    
    }
for(int l=0 ; l<=row ;l++)
for(int m=0; m<=col;m++)
column[m][l][0]='\0';
row++;
main_row=row;row=0;
main_col=col-1;col=0;


temp=p=strtok(NULL," ");
while(temp!="FROM")//reads the columns to be selected
{

  
     if(temp == "*"&&stcount==0)  
     { star=1;
   for(int l=0;l<main_row;l++)
	for(int m=0;m<main_col;m++)
	{   temp=main_array[l][m];
		for( k=0;k<temp.length();k++)
		column[l][m][k]=temp[k];
		column[l][m][k]='\0';
		
	}
	row=main_row;
	col=main_col;
    
     break;
   }

            else if(temp == ","||temp=="\("||temp==")"||temp=="SUM"||temp=="MIN"||temp=="MAX"||temp=="AVG"||temp=="COUNT"||temp=="ALL"||temp=="DISTINCT");
            else if(temp=="/"||temp=="+"||temp=="*"||temp=="-")temp=p=strtok(NULL," ") ;
                 else
                  {
                   col++;      
                   int i;
                   for ( i=0;temp[i]!='\0';i++)
                    {
                     ch[i]=temp[i];
                    }
                   ch[i]='\0' ;
                   table_name=fopen(fname,"r");
                   not_valid=select(ch,table_name,col);
                  
                   if(not_valid==11)
                    { 
           		cout<<"INVALID COLUMN NAME"<<endl;
           		
               return 0;
               
                     } 

                   }
                   temp=p=strtok(NULL," "); 
                   stcount=1;
}
char temparr[100][100][50];i=0;j=0;

//storing contents of the selected columns in column array
	if(star==0)
	{
	for(int l=0 ; l<=row ;l++)
	for(int m=1; m<=col;m++)
	{
		 temp=column[m][l];
		 for(k=0;k<temp.length();k++)
	     temparr[l][m-1][k]=temp[k];
	     temparr[l][m-1][k]='\0';    
    }

    
  row++;  
    
    for(int l=0;l<col;l++)
    for(int m=0;m<row; m++)
    {
    	temp=temparr[m][l];
    	for(k=0;k<temp.length();k++)
    	column[m][l][k]=temp[k];
    	
    	column[m][l][k]='\0';
    }
    
	
    
}






return 1;

}
/*int main()
{   
	char k[10]="info.txt";
    char *f=k;
    set s;
    s.parseData(f);
  //  for(int l=0 ; l<row ;l++){
	//for(int m=0 ; m<col;m++) cout<<column[l][m]<<'\t';
	//cout<<endl;}
int l,m;
//cin>>l;
//cin>>m;
//cout<<main_col<<main_row;
//cout<<col<<row;
//cout<<column[0][0]<<endl;
cout<<row<<" "<<col<<endl;
for(l=0;l<row;l++)
{
	for(m=0;m<col;m++)
	cout<<column[l][m]<<"\t";
	cout<<endl;
}
cout<<column[0][0]<<endl;

cout<<main_row<<" "<<main_col<<endl;
for(l=0;l<main_row;l++)
{
	for(m=0;m<main_col;m++)
	cout<<main_array[l][m]<<"\t";
	cout<<endl;
}
return 0;
}*/

 

                
