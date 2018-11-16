#ifndef tokentype_H
#define tokentype_H
#define NaN 0

typedef struct{
   int pos;
   char tkn;
   double value;
} Token;

typedef struct{
    Token toks;
    int posnow;
} TokProcess;

#endif