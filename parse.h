#ifndef parse_h
#define parse_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "token.h"
#include "stacktkn.h"
#include "boolean.h"
#include <math.h>

float parseItem(Stack *tok);

float parseFactor(Stack *tok);

float parseTerm(Stack *tok);

float parseExpr(Stack *tok);

float parse(char s[100]);

#endif