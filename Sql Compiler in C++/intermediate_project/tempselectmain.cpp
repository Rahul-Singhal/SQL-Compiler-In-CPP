
//we have to access the 3 d array  i.e main_array[100][100][50], with main_row & main_col
#include<string>
#include<iostream>
#include"general.h"
#include"comfun.h"
using namespace std;
//int main_col=4;
//int main_row=4;
//char main_array[100][100][50];
/*int findcolumnnum(string col_name,char array[100][100][50]){
int i,j;
	char c;
	char find[50];	
	int outpt;
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
}*/
int tempselectmain(string col_name,char array[100][50]){
     int value=-1;
	
    value=findcolumnnummain(col_name,main_array);
	
	if(value!=-1){
		for(int k=0;k<main_row;k++){
		strcpy(array[k],main_array[k][value]);
		}
		return 1;
	}
	else{cout<<"invalid column name";
	                    return 0;
		}
	}

/*int main(){
    string str="age";
    cin>>main_array[0][0];
    cin>>main_array[1][0];
    cin>>main_array[2][0];
    cin>>main_array[3][0];
    char fg[100][50];
    int g=findcolumnnum(str,main_array);
    cout<<"column number="<<g;
    int h=tempselect(str,fg);
    for(int i=0;i<main_row;i++){
    cout<<fg[i]<<endl;
}
    system("pause");
    return 0;
}*/

