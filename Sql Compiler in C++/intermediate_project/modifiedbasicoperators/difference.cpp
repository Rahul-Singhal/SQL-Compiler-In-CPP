#include<iostream>
#include<string>
#include<cstring>
using namespace std;
void difference(char R1[][100][50],char R2[][100][50],int r1,int r2,int c,char ret[100][100][50])//if we want R1-R2..r1 &r2 are the no.of rows in each relation and c is the no.of columns
{
	int i,j,k,flag==0,r=-1;
	for(i=0;i<=r1;i++)//comparing each tuple of R1 with each tuple of R1
	{for (j=0;j<=r2;j++)
		{  flag=0;
		   for(k=0;k<=c;k++)
			{ if (strcmp(R2[i][k],R1[j][k]))
			     {flag=1;//rising the flag if an element of a tuple in R1  is not the same with that in R2
			       break;
			     }   	
			}
  	        }
	if(flag==1)
		{r++
		 for(k=0;k<=c;k++)
			{ret[r][k]=R1[i][k];}
		}
	}
	return;
}
