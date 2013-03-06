/*
>:1
=:2
<:3
*/
#include<cstdlib>
#include<string>
#include<cstring>
#include<iostream>
#include"general.h"
//#include"comfun.h"
//#include"tempfun.h"
//#include"groupby.cpp"
//#include"tempselectcolumn.cpp"
//#include"findcolumnnumcolumn.cpp"
//#include"two_in_one_func.cpp"
using namespace std;
int having(string aggfunc,int inequality,string val){
     int i;
     char temp1[50];
     for(i=0;i<val.length();i++){
                                     temp1[i]=val[i];
                                     }
                                     temp1[i]='\0';
     char*p;
     p=temp1;
     float value=atof(p);
     if(value==0){return 0;}

     int tempval;
     /*int tempval=findcolumnnumcolumn(aggfunc,retgroupby_column);
     if(tempval==-1){
                   cout<<"invalid input";
                   return 0;
                   }*/
     float array[100];
	char temparray[100][50];

	tempval=tempselectretgroupby_column(aggfunc,temparray);
	
	if(tempval==0){return 0;}



     tempval=two_in_one_func(temparray,array);
//cout<<array[1]<<endl;
//cout<<temparray[1]<<endl;
//cout<<array[2]<<endl;
//cout<<temparray[2]<<endl;
     if(tempval==0){return 0;}
     int k,temprow=1;
     if(inequality==1){
//cout<<"rahul"<<endl;
                       for(i=1;i<row;i++){
//cout<<i<<"::"<<array[i]<<endl;
                                          if(array[i]>value){
                                                             temprow++;
//cout<<temprow<<"hi"<<endl;
                                                             for(int a=0;a<col;a++){
                                                                     strcpy(retgroupby_column[temprow-1][a],retgroupby_column[i][a]);
                                                             }
                                                             }
                                                             }
                                                             }

     if(inequality==2){
                       for(i=1;i<row;i++){
                                          if(array[i]==value){
                                                             temprow++;
                                                             for(int a=0;a<col;a++){
                                                                     strcpy(retgroupby_column[temprow-1][a],retgroupby_column[i][a]);
                                                             }
                                                             }
                                                             }
                                                             }
     if(inequality==3){
                       for(i=1;i<row;i++){
                                          if(array[i]<value){
                                                             temprow++;
                                                             for(int a=0;a<col;a++){
                                                                     strcpy(retgroupby_column[temprow-1][a],retgroupby_column[i][a]);
                                                             }
                                                             }
                                                             }
                                                             }
                                                             row=temprow;
                                                             return 1;
                                                             }
                                          
                                          
                        
                        
     
     
                                     
                                     
