/*

arth_oprtr:
           0=no arithmatic operator
           1=+
           2=-
           3=*
           4=/
inequality:
           1= >
           2= =
           3= <
int *array is the pointer to the array in which the true(1) or false(0) values r to b stored

*/

#include<string>
#include<iostream>
#include<cstdlib>
#include"general.h"
#include"comfun.h"
#include"tempfun.h"
#include"wherefun.h"
/*function to evaluate the expressions given in the input after where
/parameters are 
str is the attribute or column name in the table concerned
arth_oprtr is the value of arithmatic operator as defined above
val1 is the value after the arithmatic operator
inequality is the value of inequalities and equality as defined above
arry is a int array to store the result i,e 1 if true and 2 if false
*/
int where_exp_evaluate( string str ,int arth_oprtr, string val1,int inequality, string val2, int array[100]){

     
     //call tempselectmain function to store the values of column named string from main_array into a temp array i.e temp1[100][50]
     char temp1[100][50];
     array[0]=1;
     int tempvalue1=tempselectmain(str,temp1);
     if(tempvalue1==0){return 0;}
     //checking if the comparision is made between strings or numbers 
	if(val2[0]=='\''){
	//function will get into this if loop if the comparision is made between strings 
	int i;
	//storing the string to be compared in compstring after removing initial and final inverted commas i.e ' '
	char compstring[50];
	for(i=1;i<val2.length()-1;i++){
		compstring[i-1]=val2[i];	
	}
	compstring[i-1]='\0';
	//loop to store the true or false values into array[100] by checking condition
	for(i=1;i<main_row;i++){
		if(inequality==3){
		int tempnum=strcmp(compstring,temp1[i]);
			array[i]=tempnum>0?1:0;
		}
		if(inequality==2){
		int tempnum=strcmp(compstring,temp1[i]);
			array[i]=tempnum==0?1:0;
		}
		if(inequality==1){
		int tempnum=strcmp(compstring,temp1[i]);
			array[i]=tempnum<0?1:0;
		}
		}
		}

	else{
     // if function gets here it means the comparision is made between numbers
     //two in one function to store the corresponding values of temparrar into float temp2[100]
     float temp2[100];
     int tempvalue2=two_in_one_func(temp1,temp2);
     if(tempvalue2==0){return 0;}
     //this float array temp2 will contain garbage in first row i.e index 0
    char p[50];  
    int i;
    char*p1;
    float value1;
    if(!(val1=="\0"))
    {
    
    //copying the string val1 into value1 that is a char string
    for( i=0;i<val1.length();i++){
            p[i]=val1[i];
            }
            p[i]='\0';
    
    p1=p;   
    //calling atof() function to convert the value stored in val1 directly into a float number i.e value2
    value1=atof(p1);
    if(value1==0){return 0;}
    
    //using switch function to process upon the selected temp2[100] according to the arithmatic operator
           switch (arth_oprtr){
                              
                              case 0:{
                                      break;
                                           }
                                                     
                              case 1:{
                                   for(int i=1;i<row;i++){
                                           temp2[i]=temp2[i]+value1;
                                           }
                                           break;
                                           }
                              case 2:{
                                   for(int i=1;i<row;i++){
                                           temp2[i]=temp2[i]-value1;
                                           }
                                           break;
                                           }
                              case 3:{
                                   for(int i=1;i<row;i++){
                                           temp2[i]=temp2[i]*value1;
                                           
                                           }
                                           break;
                                           }
                              case 4:{
                                   for(int i=1;i<row;i++){
                                           temp2[i]=temp2[i]/value1;
                                          }
                                           break;
                                           }
                                           }
    }
    //converting the val2 into float value2 using atof() function                                       
    float value2;
    for( i=0;i<val2.length();i++){
            p[i]=val2[i];
            }
            p[i]='\0';
    p1=p;       
    value2=atof(p1);
    if(value2==0){return 0;}
    //using switch to process on the array[100] to be used further according to the given condition
                       switch (inequality){
                              
                              case 1:{
                                   for(int i=1;i<row;i++){
                                           array[i]=temp2[i]>value2?1:0;
                                          }
                                           break;
                                           }
                              case 2:{
                                   for(int i=1;i<row;i++){
                                           array[i]=temp2[i]==value2?1:0;
                                           }
                                           break;
                                           }
                              case 3:{
                                   for(int i=1;i<row;i++){
                                           array[i]=temp2[i]<value2?1:0;
                                          }
                                           break;
                                           }
                                           } 
						}  

 						return 1;  
                                           }
                                           
                                           
                                           
                                           
                                           
    
