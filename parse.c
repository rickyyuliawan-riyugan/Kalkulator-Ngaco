#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stacktkn.h"
#include "parse.h"
#include "token.h"
#include "boolean.h"
#include <math.h>

float parseItem(Stack *tok)
{
    Token t;
    float expr;
    Pop(tok,&t);
    if (isNumber(t)){
        return t.value;
    }
    if (isIdentifier(t)){
        printf("Alphabet cant be entered\n"); 
        exit(-1);
    }
    if (isSymbol(t,'(') == false){
        printf("SYNTAX ERROR\n"); 
        exit(-1);
    }
    expr = parseExpr(tok);
    if (isSymbol(InfoTop(*tok),')') == false){
        printf("SYNTAX ERROR\n"); 
        exit(-1);
    }
    Pop(tok,&t);
    return expr;
}

float parseFactor(Stack *tok)
{
    Token t;
    int sign;
    float result, rhs;

    t = InfoTop(*tok);
    if (isSymbol(t,'-')){
        sign = -1;
    } else {
        sign += 1;
    }
    if ((isSymbol(t,'+')) || (sign < 0 )){
        Pop(tok, &t);
    }
    result = parseItem(tok);
    while (isSymbol(InfoTop(*tok),'^')){
        Pop(tok,&t);
        rhs = parseFactor(tok);
        result = pow(result,rhs);
    }
    return sign*result;
}

float parseTerm(Stack *tok)
{
    float result = parseFactor(tok);
    float rhs;
    Token t;
    Token dummy;

    t = InfoTop(*tok);
    while (isSymbol(t,'*') || isSymbol(t,'/')){
        Pop(tok,&dummy);
        rhs = parseFactor(tok);
        if (isSymbol(t,'/')){
            result = result / rhs;
        } else{
            result = result * rhs;
        }
        t = InfoTop(*tok);
    }
    return result;
}

float parseExpr(Stack *tok){
    float result = parseTerm(tok);
    Token t = InfoTop(*tok);
    Token dummy;
    float rhs;

    while (isSymbol(t,'+') || isSymbol(t,'-')){
        Pop(tok,&dummy);
        rhs = parseTerm(tok);
        if (isSymbol(t,'+')){
            result = result + rhs;
        } else {
            result = result - rhs;
        }
        t = InfoTop(*tok);
    }
    return result;
}

float parse(char s[100]){
    Stack toks;
    float result;

    
    toks = tokenize(s);
    result = parseExpr(&toks);
    if (!isStop(InfoTop(toks))){
        printf("Empty Input, Exiting The Program....\n");
        exit(0);
    }
    return result;
}