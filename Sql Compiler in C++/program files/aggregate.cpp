#include<cstring>
#include<string>
#include"general.h"
#include"comfun.h"
#include"tempfun.h"

using namespace std;
int aggregate(int aggr,string colname,int pos)//1-max,2-min,3-sum,4-avg,5-count
{

char temp[100][50]; float temp1[100];char name[50];

if(!tempselectcolumn(colname,temp))return 0;
if(!two_in_one_func(temp,temp1))return 0;
int i,j;float max,min,sum,avg;int l;



if(aggr==5)
{
name[0]='C';name[1]='O';name[2]='U';name[3]='N';name[4]='T';name[5]='(';
for(l=6;l<colname.length()+6;l++)
name[l]=colname[l-6];
name[l]=')';
name[++l]=',';
name[++l]='\0';
strcpy(column[0][pos],name);
sprintf(column[1][pos],"%f",(float)(row-1));

		
return 1;


}

for(l=4;l<colname.length()+4;l++)
name[l]=colname[l-4];
name[l]=')';
name[++l]=',';
name[++l]='\0';
switch (aggr){
case 1:{
max=temp1[1];

for(i=1;i<row;i++)
	{
	if(max<temp1[i]){

		max=temp1[i];} 
	}
	name[0]='M';name[1]='A';name[2]='X';name[3]='(';
	strcpy(column[0][pos],name);
	sprintf(column[1][pos],"%.4f",max);

	return 1;
	
	break;}
case 2:{
	min=temp1[1];
	for(i=1;i<row;i++)
	{
		if(min>temp1[i])
		{min=temp1[i];}
	}
	name[0]='M';name[1]='I';name[2]='N';name[3]='(';
	strcpy(column[0][pos],name);
	sprintf(column[1][pos],"%.4f",min);

	return 1;
		
	break;}
case 3:{
        sum=0;
		for(i=0;i<row;i++)
		{sum+=temp1[i];}
		name[0]='S';name[1]='U';name[2]='M';name[3]='(';
	    strcpy(column[0][pos],name);
	    sprintf(column[1][pos],"%.4f",sum);
	    
		return 1;
		
		
	break;
	}
case 4:{sum=0;
		for(i=0;i<row;i++)
		{sum+=temp1[i];}
		
		avg=(sum/row);
		name[0]='A';name[1]='V';name[2]='G';name[3]='(';
	    strcpy(column[0][pos],name);
	    sprintf(column[1][pos],"%.4f",avg);
	    
		
	return 1;
		break;
	}
       
}
}
