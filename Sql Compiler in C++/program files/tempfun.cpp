#include<string>
#include<iostream>
#include"general.h"
//#include"comfun.h"
//#include"tempfun.h"
//#include"comfun.cpp"
using namespace std;
//function to temporary select a specified column named col_name from the array selected by the user according to the syntax upto file name
int tempselectcolumn(string col_name,char array[100][50]){
    int value=-1;
	
    value=findcolumnnumcolumn(col_name,main_array);
	
	if(value!=-1){
		for(int k=0;k<row;k++){
		strcpy(array[k],column[k][value]);
		}
		return 1;
	}
	else
	{cout<<"INVALID COLUMN NAME"<<endl;
	                    return 0;
		}
	}
//function to select a specified column named col_name from the main_array 
int tempselectmain(string col_name,char array[100][50]){
    int value=-1;
	
    value=findcolumnnummain(col_name,main_array);

	if(value!=-1){
		for(int k=0;k<main_row;k++){
		strcpy(array[k],main_array[k][value]);
		}
		return 1;
	}
	else
	{cout<<"INVALID COLUMN NAME"<<endl;
	                    return 0;
		}
	}
//function to select a specified column named col_name from the array retgroupby_column formed after the calling of the group by syntax by the user
int tempselectretgroupby_column(string col_name,char array[100][50]){
    int value=-1;
	
    value=findcolumnnumretgroupby_column(col_name,retgroupby_column);


	if(value!=-1){
		for(int k=0;k<row;k++){
		strcpy(array[k],retgroupby_column[k][value]);
		}
		return 1;
	}
	else
	{cout<<"INVALID COLUMN NAME"<<endl;
	                    return 0;
		}
	}

