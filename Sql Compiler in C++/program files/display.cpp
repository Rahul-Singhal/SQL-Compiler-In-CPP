#include<iostream>
#include<string>
#include<cstring>
#include<ctype.h>
#include"selectfun.cpp"
#include"aggregate.cpp"
#include"general.h"


using namespace std;
//displays the final output

int display(char A[100][100][50])
{

int distinct=0;
string prev="";  //stores the previous column name


int op;//stores value of arithmatic operation +=1 -=2 *=3 /=4
float val;//stores the value of the arithmatic operand
int ag;//stores value of aggregate function 1-max,2-min,3-sum,4-avg,5-count
int pos=0;
string st; size_t length;
char buffer[1000];int n;
length=input.copy(buffer,input.length(),0);
buffer[length]='\0';
char*p=strtok(buffer," ");
st=p;
st=p=strtok(NULL," ");
//searches the column name for arithmatic operators
if(st!="*")
{
while(st!="FROM")
{
if(st=="DISTINCT")
distinct=1;
if((st=="SUM"||st=="AVG"||st=="MAX"||st=="MIN"||st=="COUNT")&& agcount>0)
{
if(st=="MAX")ag=1;
if(st=="MIN")ag=2;
if(st=="SUM")ag=3;
if(st=="AVG")ag=4;
if(st=="COUNT")ag=5;
st=p=strtok(NULL," ");
st=p=strtok(NULL," ");
if(!aggregate(ag,st,pos)){cout<<"INCOMPATIBLE OPERATION"<<endl;return 0;}
pos++;
}


if(st=="+"||st=="-"||st=="*"||st=="/")
{

if(st=="+")op=1;
if(st=="-")op=2;
if(st=="*")op=3;
if(st=="/")op=4;
st=p=strtok(NULL," ");
val=atof(p);
//uses the selectexpevaluator to perform the operations and modify the column array
if(!selectexpevaluater(prev,op,val)){cout<<"INCOMPATIBLE OPERATION"<<endl;return 0;}
}
prev=st;
st=p=strtok(NULL," ");

}
}

//if distinct keyword is present eliminates multiple entries
if(distinct==1)
{
for(int i=0;i<row;i++)
Selected[i]=1;

for(int i=1;i<row;i++)
for(int j=i+1;j<row;j++)
if(!(strcmp(column[i][0],column[j][0])))
Selected[j]=0;

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


}

//printing the final output on terminal
if(pos>0)
row=2;

cout<<"RESULT :"<<endl<<endl;

for(int i=0;i<col;i++)
{
for(int k=0;;k++)
{
if(A[0][i][k]!=',')
cout<<A[0][i][k];
else
{cout<<"\t\t";break;}
}
}

cout<<endl;
cout<<endl;

for(int i=1;i<row;i++)
{
for(int j=0;j<col;j++)
cout<<A[i][j]<<"\t\t";
cout<<endl;
}
cout<<endl;

return 1;

}
