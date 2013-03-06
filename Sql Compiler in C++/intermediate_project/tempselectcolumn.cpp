#include<string>
#include<iostream>
#include"general.h"
#include"comfun.h"
//#include"findcolumnnumcolumn.cpp"
using namespace std;

int tempselectcolumn(string col_name,char array[100][50]){
     int value=-1;
	
    value=findcolumnnumcolumn(col_name,main_array);
	
	if(value!=-1){
		for(int k=0;k<row;k++){
		strcpy(array[k],column[k][value]);
		}
		return 1;
	}
	else{cout<<"invalid column name";
	                    return 0;
		}
	}
