#include<string>
#include<stdio.h>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include"general.h"
#include"comfun.h"
using namespace std;
//function to find the column index of a given attribute name i.e col_name from column[100][100][50] i.e the array formed after the operation on the input string by user till file name.
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

//function to find the column index of a given attribute name i.e col_name from retgroupby_column[100][100][50] i.e the array formed after the operation on the input string by user till group by command.
int findcolumnnumretgroupby_column(string col_name,char array[100][100][50]){
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
	
		for(j=0;retgroupby_column[0][i][j]!=',';j++){
			temp[j]=retgroupby_column[0][i][j];
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

//function to find the column index of a given attribute name i.e col_name from main_array[100][100][50] i.e the array formed so as to access the main data stored in the concerned file.
int findcolumnnummain(string col_name,char array[100][100][50]){
int i,j;
	//char c='c';
	char find[50];	
	int outpt;
	//copying the column name to be found into character string find
	for(i=0;i<col_name.length();i++){
		find[i]=col_name[i];
		}
		find[i]='\0';
		
	char temp[50];
	for(i=0;i<main_col;i++){
	
		for(j=0;main_array[0][i][j]!=',';j++){
			temp[j]=main_array[0][i][j];
			//c=main_array[0][i][j+1];
		}
		temp[j]='\0';
		outpt=strcmp(temp,find);
		if(outpt==0){
                     return i;
                     }
                     }
                     
  return -1;
}

void reverse_set_col_number(float col_number[100],int colnum)
{
     for(int i=1;i<row;i++){
             column[i][colnum][0]='\0';
             sprintf(column[i][colnum],"%.4f",col_number[i]);
             
}
}



int two_in_one_func(char col_where_eval[100][50],float col_number[100]) {
     int i,j,k;
     int tempnum;                     //variables to be used for increment or decrement in for loop.
     int flag=-1;                   // variable to take care for "." in floating numbers.
     float exp=1;                   //variable for produce the final number using unitary summation method.
     for(i=0;i<100;i++){
                        col_number[i]=0;
                        }
     for(i=1;i<row;i++){
             for(j=0; col_where_eval[i][j]!='\0' && j<50 ;j++){
			 if(col_where_eval[i][j]=='.'){				
				flag=j;
				}
                continue;
            }
    if(flag==-1){                  //flag = 1 means the number is an integer.
             for(k=j-1;k>=0;k--){
                                 tempnum=col_where_eval[i][k]-48;//cout<<tempnum<<endl;
                                 if(tempnum<0 || tempnum>=10){return 0;}
                     col_number[i]=col_number[i]+exp*tempnum;
			
                     exp*=10;
                                }

		       }
    else{                          // this means the number is not an integer.
	         for(k=flag-1;k>=0;k--){
                                 tempnum=col_where_eval[i][k]-48;//cout<<tempnum<<endl;
                                 if(tempnum<0 || tempnum>=10){return 0;}
                     col_number[i]=col_number[i]+exp*tempnum;
                     exp*=10;
             }
             exp=0.1;
	         for(k=flag+1;k<=j-1;k++){
                                 tempnum=col_where_eval[i][k]-48;//cout<<tempnum<<endl;
                                 if(tempnum<0 || tempnum>=10){return 0;}
		     col_number[i]=col_number[i]+exp*tempnum;
		     exp=exp/10;
                               		 }
	  }
      exp=1;
      flag=-1;
      }

      return 1;
}


