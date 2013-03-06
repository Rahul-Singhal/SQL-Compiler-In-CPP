#include<iostream>
#include<cstring>
#include"general.h"
using namespace std;

//int row=5;
//remember the first row of the array col_number will be some garbage float value
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
/*int main(){
char ch[100][50];
cin>>ch[1];//="45";
cin>>ch[2];//="798.78";
cin>>ch[3];//="798";
cin>>ch[4];//="678";
float chr[100];
int g=two_in_one_func(ch,chr);
if(g==0){cout<<"wrong input"<<endl;return 0;}
cout<<chr[1]<<endl;
cout<<chr[2]<<endl;
cout<<chr[3]<<endl;
cout<<chr[4]<<endl;
return 0;
}
*/
