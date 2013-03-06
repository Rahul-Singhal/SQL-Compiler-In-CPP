
#ifndef general_H
#define general_H
#include <string>
#include <cstring>
using namespace std;
string input="";//To store the sql query given by the user
int col=0,row=0;//Stores the no of rows and columns in column[][][]
char column[100][100][50];//array which stores the selected columns
char main_array[100][100][50];//array which stores the entire contents of the file
int main_col,main_row;//To store no of rows and columns in the main_array[][][]
char retgroupby_column[100][100][50];//To store the grouped contents
char *file_name;//stores the pointer to the selected file
int Selected[100];//Stores 1 if the row is selected 0 if not
int agcount=0;//stores status of the use of aggregate functions

#endif 
