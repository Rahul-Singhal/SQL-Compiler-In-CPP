#include<iostream>
#include<string>
#include<cstring>
using namespace std;
void intersection(char R1[][100][50],char R2[][100][50],int r1,int r2,int c,char ret[100][100][50])
{	int i,j,k,flag,r=-1;

for(i=0;i<=r2;i++)//comparing each tuple of R2 with each tuple of R1
	{for (j=0;j<=r1;j++)
		{  flag=0;
		   for(k=0;k<=c;k++)
			{ if (strcmp(R2[i][k],R1[j][k]))
			     {flag=1;//rising the flag if an element of a tuple is not the same
			       break;
			     }   	
			}
		}
	if (flag==0)
		{r++;
	 	for (k=0;k<=c;k++)
			{ret[r][k]=R2[i][k];}
		}
	}
	return;
}
