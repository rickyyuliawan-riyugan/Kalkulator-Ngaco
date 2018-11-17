#ifndef tokentype_H
#define tokentype_H
#define NaN 0

typedef struct{
   int pos;
   char tkn;
   float value;
} Token;

typedef struct{
    Token toks;
    int posnow;
} TokProcess;

#endif