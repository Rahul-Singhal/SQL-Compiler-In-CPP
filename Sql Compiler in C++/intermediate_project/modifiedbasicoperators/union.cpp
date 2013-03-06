#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int r1,r2,c;
void uni(int c,  char R1[][100][50],  int r1,char  R2[][100][50],  int r2,  char ret[200][100][]50)
{
	
	int i,j,k,r=0,flag;
	
	for (i=0;i<=r1;i++)/*transfering all the contents of one relation to output array*/
	{
	  for(j=0;j<=c;j++)
		{ret [i][j]=R1[i][j];}
	}
	
	for(i=0;i<=r2;i++)//comparing each tuple of R2 with each tuple of R1

	{for (j=0;j<=r1;j++)
		{  flag=0;
		   for(k=0;k<=c;k++)
			{ if (strcmp(R2[i][k],R1[j][k]))
			     {flag=1;//rising the flag if an element of a tuple is not the same
			       break;
			     }   	
			}
		   if(flag==1)
			{	r++;
			    for(k=0;k<=c;k++)
				{ ret[r+r1][k]= R1[j][k];}
			}
		}
	}	
  return; 	 
}
