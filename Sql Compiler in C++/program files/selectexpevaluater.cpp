#include<string>
#include<cstring>
#include<cstdlib>
#include"general.h"
#include"comfun.h"
#include"tempfun.h"
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
//it is a function that has to be called if the user want to initially select a column with some modifications like if there is some attribute named salary and the user wants to select salary/2 then he has to call selectexpevaluater(salary,operator value as specified above,12 )
int selectexpevaluater(string str ,int oprtr, float value){
	char temparray[100][50];
	//collecting the column to be modified into array called temparray[100][50]
	int tempvalue=tempselectcolumn(str,temparray);
	if(tempvalue==0){return 0;}
	//converting the temparray into another float array names col_number[100]
	tempvalue=two_in_one_func(temparray,col_number);
	if(tempvalue==0){return 0;}
	switch(oprtr){
	//modifying the elements of the col_number according to the cases specified at the top
		case 1:{
			for(int i=1;i<row;i++){
				col_number[i]+=value;
				break;
				}
				}
		case 2:{
			for(int i=1;i<row;i++){
				col_number[i]-=value;
				break;
				}
				}
		case 3:{
			for(int i=1;i<row;i++){
				col_number[i]*=value;
				break;
				}
				}
		case 4:{
			for(int i=1;i<row;i++){
				col_number[i]/=value;
				}
				}
			}
//calling this function to again print the modified values in the col_number[100] to the strings of the column of the selected array which has been modified 
reverse_set_col_number(col_number,colnum);
return 1;
}
			
				
	
