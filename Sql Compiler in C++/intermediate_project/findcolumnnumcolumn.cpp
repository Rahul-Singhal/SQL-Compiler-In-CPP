#include<string>
#include<iostream>
#include<cstring>
#include"general.h"
using namespace std;
//int main_col=4;
//char main_array[100][100][50];
int findcolumnnumcolumn(string col_name,char array[100][100][50]){
int i,j;
	//char c='c';
	char find[50];	
	int outpt;
	//char string find contains the column name that has to be found
    for(i=0;i<col_name.length();i++){
		find[i]=col_name[i];
		}
		find[i]='\0';
		
	char temp[50];
	for(i=0;i<col;i++){
	
		for(j=0;column[0][i][j]!=',';j++){
			temp[j]=column[0][i][j];
			//c=column[0][i][j+1];
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
    string str="age";col=1;row=1;
    cin>>main_array[0][0];
    int g=findcolumnnumcolumn(str,main_array);
    cout<<"column number="<<g;
   // system("pause");
    return 0;
}

    */
  
