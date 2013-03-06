/*1:min
2:max
3:count
5:avg
4:sum
when u see groupby define achar array with dim=100,2,50 i.e.,retgroupby_column[100][2][50]*/
#include<string>
#include<cstring>
#include"general.h"
#include"comfun.h"
#include"tempfun.h"

//#include"tempselectcolumn.cpp"
//#include"two_in_one_func.cpp"
using namespace std;

/*group by function to be called if the user uses group by syntax
the syntax give by the user is of the form     select colname , aggregate_function(oprndcolname)...group by colname...
*/
int groupby(string colname,string oprndcolname,int n){
string s;
char* p;int i,j,count=0;
int foundcol,foundopcol;
//foundcol will tell the column.no of the col acc to which we've to grp,foundopcol will tell the col.no of the col what we've to grp
	char columnname[50]; char operandcolname[50];
	for(i=0;i<colname.length();i++){
	columnname[i]=colname[i];
                             }
    columnname[i]='\0';
	for(i=0;i<oprndcolname.length();i++){
	operandcolname[i]=oprndcolname[i]; 
                                       }
    operandcolname[i]='\0';
 
	//function to find foundcol
	foundcol=findcolumnnumcolumn(colname,column);
	if(foundcol==-1){return 0;}
	
	char temparr1[100][50];
	//selecting column named colname from column[100][100][50] and storing that column into temparr1
	int tempvalue1=tempselectcolumn(colname,temparr1);
	if(tempvalue1==0){return 0;}
	//function to find foundopcol
	foundopcol=findcolumnnumcolumn(oprndcolname,column);
	if(foundopcol==-1){return 0;}
	char temparr2[100][50];
	//selecting column named oprndcolname from column[100][100][50] and storing that column into temparr2
	tempvalue1=tempselectcolumn(oprndcolname,temparr2);
	if(tempvalue1==0){return 0;}
	
	int temparray[100];
	for(i=0;i<=100;i++)
		{temparray[i]=i;}
	    char temp[50];
		for(i=0;i<row;i++){
			strcpy(temp,column[i][foundcol]);
			for( j=i+1;j<row;j++){
			
			if(!strcmp(temp,column[j][foundcol]))
				{
					if(temparray[j]>i)
						{temparray[j]=i;}	
				}}}
				
				/*for(i=0;i<row;i++)
				cout<<temparray[i]<<endl;*/
				
//copying column names to the array to be returned from the main array(column)				
strcpy(retgroupby_column[count][0],column[0][foundcol]);
count++;				
				
			
int temprow=1;
//using switch to switch according to the aggregate function as defined at the top				
switch(n){
//MAX is the aggregate function
case 1:{
	strcpy(retgroupby_column[count-1][1],"MIN,");
float col_number[100];
tempvalue1=two_in_one_func(temparr2,col_number);     //use 2 in 1 function

if(tempvalue1==0){return 0;}
int minindex;
for(i=1;i<row;i++,temprow++){
if( temparray[i]<i){
    temprow--;
    continue;}
	float min=col_number[i];
	minindex=i;

	for(j=i+1;j<row;j++)
	{
	if(temparray[i]==temparray[j])
		{temparray[j]=-1;
			if(min>col_number[j])
			{min=col_number[j];	minindex=j;}	
		}
	}
strcpy(retgroupby_column[count][0],column[minindex][foundcol]);
strcpy(retgroupby_column[count][1],column[minindex][foundopcol]);
count++;
}
break;
}
//MIN is the aggregate function
case 2:	{
	strcpy(retgroupby_column[count-1][1],"MAX,");
		float col_number[100];
tempvalue1=two_in_one_func(temparr2,col_number);       //use 2 in 1 function
if(tempvalue1==0){return 0;}
int maxindex;
for(i=1;i<row;i++,temprow++){
if( temparray[i]<i)
{temprow--;
    continue;}
float max=col_number[i];
maxindex=i;

	for(j=i+1;j<row;j++)
	{
	if(temparray[i]==temparray[j])
		{temparray[j]=-1;
			if(max<col_number[j])
			{max=col_number[j];	maxindex=j;}	
		}
	
	}
strcpy(retgroupby_column[count][0],column[maxindex][foundcol]);
strcpy(retgroupby_column[count][1],column[maxindex][foundopcol]);
count++	;
}	
break;
}
//SUM is the aggregate function
case 4:	{
	strcpy(retgroupby_column[count-1][1],"SUM,");


		float col_number[100];
tempvalue1=two_in_one_func(temparr2,col_number);//cout<<tempvalue1<<"here";  //use 2 in 1 function
//for(int y=1;y<row;y++){cout<<col_number<<"asdf"<<endl;}
if(tempvalue1==0){return 0;}
for(i=1;i<row;i++,temprow++){
//cout<<i<<"gh"<<endl;
//cout<<temprow<<"hi"<<endl;
if( temparray[i]<i)
{temprow--;
    continue;}
float sum=col_number[i];


	for(j=i+1;j<row;j++)
	{
	if(temparray[i]==temparray[j])
		{temparray[j]=-1;
//cout<<col_number[j]<<"hi bro"<<endl;
			sum+=col_number[j];	
		}
	
	}
//cout<<"the sum is"<<sum<<endl;
strcpy(retgroupby_column[count][0],column[i][foundcol]);
sprintf(retgroupby_column[count][1],"%.4f",sum);
count++;	
}
//cout<<"hello";
//cout<<retgroupby_column[0][1]<<endl;	
break;
}
//AVG is the aggregate function
case 5:	{
	strcpy(retgroupby_column[count-1][1],"AVG,");

		float col_number[100];
tempvalue1=two_in_one_func(temparr2,col_number);       //use 2 in 1 function
if(tempvalue1==0){return 0;}
for(i=1;i<row;i++,temprow++){
if( temparray[i]<i)
{temprow--;
    continue;}
float sum=col_number[i];
float flag=1;


	for(j=i+1;j<row;j++)
	{

	if(temparray[i]==temparray[j])
		{temparray[j]=-1;
			sum+=col_number[j];	
			flag++;
		}

	}
strcpy(retgroupby_column[count][0],column[i][foundcol]);
sprintf(retgroupby_column[count][1],"%.4f",(float)(sum/flag));
count++;	
}	
break;
}
//COUNT is the aggregate function	
case 3:	{
	strcpy(retgroupby_column[count-1][1],"COUNT,");

for(i=1;i<row;i++,temprow++){
if( temparray[i]<i)
{temprow--;
    continue;}
int flag=1;

	for(j=i+1;j<row;j++)
	{
	if(temparray[i]==temparray[j])
		{temparray[j]=-1;
			flag++;	
		}
	
	}
strcpy(retgroupby_column[count][0],column[i][foundcol]);
sprintf(retgroupby_column[count][1],"%d",flag);
count++;	
}
break;	
}
}

row=temprow;
return 1;
}
//int main(){return 0;}
