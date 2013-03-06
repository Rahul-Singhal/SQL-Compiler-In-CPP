#include<iostream>
#include<string>
#include"wherefun.cpp"
#include"general.h"

//global arrary Selected;
//+=1;-=2;*=3;/=4;
//<=1;>=2;==3;
using namespace std;

string ap;

int conditionEval()
{
string st;
char*p;int i=0;string col; int op; string val;int lop; string lval;
int A[100];

if(st=="UNION"||st=="INTERSECT"||st=="EXCEPT"||st=="GROUP"||st=="ORDER"||st==";")return 1; 
 if(st==")")
 {
 do
 {
 st=p=strtok(NULL," ");
 }
 while(st!=")");
 }
 st=p=strtok(NULL," ");
 
 if(st=="\(")
 {

 if(!conditionEval())return 0;
 for(i=0;i<row;i++)
 A[i]=Selected[i];
 st=p=strtok(NULL," ");

 }
 else if(st=="NOT")
 {
  if(!conditionEval())return 0;
  st=ap;
  A[0]=1;
  for(i=1;i<row;i++)
  {
  	if(Selected[i]==1)A[i]=0;
  	else
  	A[i]=1;

 }
}
 else
 {

 col=st;
 st=p=strtok(NULL," ");
 if(st=="+")op=1;
 else if(st=="-")op=2;
 else if(st=="*")op=3;
 else if(st=="/")op=4;
 else op=0;
 val="";
 if(op!=0)
 {
  st=p=strtok(NULL," ");
  val= st;
  st=p=strtok(NULL," ");
 }
 if(st=="<")lop=3;
 if(st==">")lop=1;
 if(st=="=")lop=2;
 st=p=strtok(NULL," ");
 lval=st;
 //cout<<col<<op<<val<<lop<<lval;
if(!where_exp_evaluate(col,op,val,lop,lval,A))return 0;
 //cout<<st;
st=p=strtok(NULL," ");
 }
 

 
 if(st==")")
 {
 /*do
 {
 st=p=strtok(NULL," ");
 }
 while(st!=")");
 */
 for(i=0;i<row;i++)
 Selected[i]=A[i];
 ap=st;
 return 1;
 }
 
 if(!(st=="AND"||st=="OR"))
 {
 for(i=0;i<row;i++)
 Selected[i]=A[i];
 ap=st;

 return 1;
 }
 if(st=="AND")
 {  
        
 	if(!conditionEval())return 0;
 	for(i=0;i<row;i++)
 	if(Selected[i]==1&&A[i]==1)
 	Selected [i]=1;
 	else
 	Selected [i]=0;
 	
 	
 }
 if(st=="OR")
 {
 	if(!conditionEval())return 0;
 	for(i=0;i<row;i++)
 	if(Selected[i]==1||A[i]==1)
 	Selected [i]=1;
 	else
 	Selected [i]=0;
 	
 }
 //cout<<ap<<endl;
 //ap=st;
 return 1;
}


 
