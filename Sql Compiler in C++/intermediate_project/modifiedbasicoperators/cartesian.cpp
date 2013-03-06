#include<string>
#include<cstring>
using namespace std;
void cartesian(char R1[][100][50],char R2[][][],int r1,int r2,int c1,int c2,char ret[10000][200][50])

{ int i,j,k,r=-1;
 
 for(i=o;i<r1;i++)//iterating through rows of r1
	{for(j=0;j<r2;j++)//iterating through rows of r2
		{r++;
		  for (k=0;k<c1;k++)//filling the array to be returned with elements of R1(in rth row)		
			{ret[r][k]=R1[i][k];}
		  for (k=c1;k<(c1+c2);k++)

			{ret[r][k]=R2[j][k];}//filling the array to be returned with elements of R2(in rth row
		}
	}
return;
}

