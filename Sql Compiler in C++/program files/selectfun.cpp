#include<string>
#include<cstring>
#include<cstdlib>
#include"general.h"
#include"comfun.h"
#include"tempfun.h"
#include"selectfun.h"
//#include"two_in_one_func.cpp"
//#include"reverse_set_col_number.cpp"
using namespace std;
/*colnum:the position of of the column on which v have to operate
oprtr:the value of operator   
	1:+
	2:-
	3:*
	4:/
value: the value of the operator
*/

int selectexpevaluater(string str ,int oprtr, float value){

	char temparray[100][50];float col_number[100];string hcol=str;char chcol[10];
	int tempvalue=tempselectcolumn(str,temparray);
	if(tempvalue==0){return 0;}
	
	tempvalue=two_in_one_func(temparray,col_number);
	if(tempvalue==0){return 0;}
	switch(oprtr){
		case 1:{
			for(int i=1;i<row;i++)
				col_number[i]+=value;
                                hcol=hcol+" + ";
				break;
				
				}
		case 2:{
			for(int i=1;i<row;i++)
				col_number[i]-=value;
				hcol=hcol+" - ";
				break;
				
				}
		case 3:{
			for(int i=1;i<row;i++)
				col_number[i]*=value;
				hcol=hcol+" * ";
				break;
				
				}
		case 4:{
			for(int i=1;i<row;i++)
				col_number[i]/=value;
				hcol=hcol+" / ";
				break;
				}
			}

sprintf(chcol,"%.4f",value);
hcol=hcol+chcol;
//cout<<hcol<<endl;
tempvalue=findcolumnnumcolumn(str,column);
if(tempvalue==-1){return 0;}
column[0][tempvalue][0]='\0';
int i=0;
for(i=0;i<hcol.length();i++)
column[0][tempvalue][i]=hcol[i];

column[0][tempvalue][i]=',';
i++;
column[0][tempvalue][i]='\0';
reverse_set_col_number(col_number,tempvalue);
return 1;
}
			
				
	
