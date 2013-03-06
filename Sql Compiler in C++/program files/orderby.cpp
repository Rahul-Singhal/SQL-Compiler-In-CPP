#include<iostream>
#include<string>
#include<cstring>
#include"general.h"
#include"comfun.h"
#include"tempfun.h"
using namespace std;


/* order ... the value of ordernum is 
1: ascending
2:descending
*/
//string str is the name of the column which we have to sort

int orderby(string str, int ordernum){
            
            int i,j;
            char temparray[100][50];
            int tempvalue1=tempselectmain(str,temparray);
            if(tempvalue1==0){return 0;}
            i=0;
            while(temparray[0][i]!=','){
                                        i++;
                                        }
            char c=temparray[0][i+1];
            if(c=='I' || c=='F'){
	    //it means the selected column is a int or float type row and we have to sort according to numbers
                      if(ordernum==1){
                      //ascending order
                      float temp1[100];
                      float min;
                      int pos;
		      float  swap;
                      char swapstr[50];
                      tempvalue1=two_in_one_func(temparray,temp1);
                      if(tempvalue1==0){return 0;}

                      for(i=1;i<row;i++){
                                         min=temp1[i];
                                         pos=i;
                                         for(j=i+1;j<row;j++){
                                                              if(min>temp1[j]){
                                                                              min=temp1[j];
                                                                              pos=j;


                                                                              }
                                                                              }
					swap=temp1[i]; temp1[i]=temp1[pos];temp1[pos]=swap;
                                         for(int k=0;k<col;k++){
							
                                                          strcpy(swapstr,column[i][k]);
                                                          strcpy(column[i][k],column[pos][k]);
                                                          strcpy(column[pos][k],swapstr);
                                                          }
                                                          }
                                                          }
                       else{
                            // descending order
			cout<<"rahul"<<endl;
                      float temp1[100];
                      float max,swap;
                      int pos;
                      char swapstr[50];
                      tempvalue1=two_in_one_func(temparray,temp1);
                      if(tempvalue1==0){return 0;}
                      for(i=1;i<row;i++){
                                         max=temp1[i];
                                         pos=i;
                                         for(j=i+1;j<row;j++){
                                                              if(max<temp1[j]){
                                                                              max=temp1[j];
                                                                              pos=j;
                                                                              }
                                                                              }
				swap=temp1[i]; temp1[i]=temp1[pos];temp1[pos]=swap;
                                       for(j=0;j<col;j++){
                                                          strcpy(swapstr,column[i][j]);
                                                          strcpy(column[i][j],column[pos][j]);
                                                          strcpy(column[pos][j],swapstr);
                                                          }
                                                          }
                                                          }
                                                          }
                      else{

                           //sort according to strings
                           char swapstr[50];
                           int k,val;
                           if(ordernum==1){
                           //ascending order
                           for(i=1;i<row;i++){
                                              for(j=i+1;j<row;j++){
                                                                   val=strcmp(temparray[i],temparray[j]);
                                                                   if(val>0){
								strcpy(swapstr,temparray[i]);
								strcpy(temparray[i],temparray[j]);
								strcpy(temparray[j],swapstr);
                                                                              for(k=0;k<col;k++){
                                                                              strcpy(swapstr,column[i][k]);
                                                                              strcpy(column[i][k],column[j][k]);
                                                                              strcpy(column[j][k],swapstr);
                                                                              }
                                                                              }
                                                                              }
                                                                              }
                                                                              }
                           else{
                            //descending order
                           for(i=1;i<row;i++){
                                              for(j=i+1;j<row;j++){
                                                                   val=strcmp(temparray[i],temparray[j]);
                                                                   if(val<0){
								strcpy(swapstr,temparray[i]);
								strcpy(temparray[i],temparray[j]);
								strcpy(temparray[j],swapstr);
                                                                              for(k=0;k<col;k++){
                                                                              strcpy(swapstr,column[i][k]);
                                                                              strcpy(column[i][k],column[j][k]);
                                                                              strcpy(column[j][k],swapstr);
                                                                              }
                                                                              }
                                                                              }
                                                                              }
                                                                              }
                                                                              }
                                                                              return 1;
                                                                              }
                                                                              
                                                                              
      
                                
                                                                             
                                              
                                                                              
                                                                              
                                                                              
                                                                              
                                                                              
                                                                              
                                                                              
                                                                              
                                                                              
                                                                              
                                                                              
