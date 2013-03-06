#include<string>
#include<iostream>
#include<cstring>
#include "general.h"

using namespace std;
//int main_col=4;
//char main_array[100][100][50];
int findcolumnnummain(string col_name,char array[100][100][50]){
int i,j;
	char c='c';
	char find[50];	
	int outpt;
	//copying the column name to be found into character string find
	for(i=0;i<col_name.length();i++){
		find[i]=col_name[i];
		}
		find[i]='\0';
		
	char temp[50];
	for(int i=0;i<main_col;i++){
	
		for(j=0;c!=',';j++){
			temp[j]=main_array[0][i][j];
			c=main_array[0][i][j+1];
		}
		temp[j]='\0';
		outpt=strcmp(temp,find);
		if(outpt==0){
                     return i;
                     }
                     }
                     
  return -1;
}


/*int main(){
    string str="age";
    cin>>main_array[0][0];
    int g=findcolumnnum(str,main_array);
    cout<<"column number="<<g;
    system("pause");
    return 0;
}
*/
    
  
