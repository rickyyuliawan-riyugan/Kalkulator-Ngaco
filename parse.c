#include <stdio.h>
#include <string.h>
#include "token.c"
#include <math.h>

double parItem(Token *tok)
{
    Token t = tok[0];
    tok.pop(0);
    if (isNumber(t))
    {
        return t.val;
    }
    if (isIdentifie(t)){
        return error;
    }
    if (!isSymbol(t,"(")){
        return error;
    }
    expr = parseExpression();
    if (!isSymbol(tok[0]),")"){
        return error;
    }
    tok.pop[0];
    return expr;
}

double parseFactor()
{
    Token t = tok[0];
    if isSymbol("-"){
        sign = -1;
    } else {
        sign += 1;
    }
    if isSymbol("+") || (sign < 0 ){
        tok.pop[0];
    }
    result = parseItem();
    while isSymbol("^"){
        tok.pop[0];
        rhs = parseFactor();
        result = pow(result,rhs);
    }
    return sign*result;
}

double parseTerm()
{
    result = parseFactor();
    t = tok[0];
    while isSymbol("*") || isSymbol("/"){
        tok.pop(0)
        rhs = parseFactor(tok)
    }
    if isSymbol("/"){
        result = result / rhs;
    } else{
        result = result * rhs;
    }
    t = tok[0];
    return result;
}

double parseExpression()
{
    result = parseTerm(tok);
    t = tok[0];
    while t.isSymbol("+") || t.isSymbol("-"){
        tok.pop(0);
        rhs = parseTerm();
    }
    if isSymbol("+"){
     result = result + rhs;
    } else {
        result = result - rhs;
    }
    t = tok[0];
    return result;
}

double parse(string s)
{
    toks = tokens.tokenize(s);
    result = parse_expression(toks);
    if not toks[0].isStop(){
        return error;
    }
    return result;
}