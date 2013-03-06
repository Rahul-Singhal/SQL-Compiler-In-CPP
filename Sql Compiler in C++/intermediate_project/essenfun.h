#ifndef ESSENFUN_H
#define ESSENFUN_H
#include <string>
using namespace std;


int conditionEval();
int groupby(string colname,string oprndcolname,int n);

int having(string aggfunc,int inequality,string val);
int orderby(string str, int ordernum);

#endif 
