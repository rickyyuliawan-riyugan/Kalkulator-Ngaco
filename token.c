/* Identifier : semua character a..z atau A..Z atau '_' */
/* Digit : semua angka mulai dari 0..9 dan '.' */
/* Number : semua kombinasi dari digit digit yang tersedia atau ditambah dengan symbol + atau - */
/* Symbol : ^ * / + - */

/* Apabila token berisi sebuah number maka tok.tkn = 'b' */
/* Apabila token berisi sebuah identifier maka tok.tkn = 'i' */
/* Apabila token berisi sebuah stop maka tok.tkn = 'x' */

/*Spek lainnya akan ditulis lebih lanjut di waktu yang lain, semoga yang ini cukup jelas */
#include "stacktkn.h"
#include "token.h"
#include "TokenType.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

boolean isNumber(Token tok)
/* Mengembalikan 'true' apabila tok.tkn == "b" */
{
    return tok.tkn == 'b';
}

boolean isSymbol(Token tok, char s)
/* Mengembalikan 'true' apabila tok.tkn == s */
{
    return tok.tkn == s;
}

boolean isIdentifier(Token tok)
/* Mengembalikan 'true' apabila tok.tkn == "identifier" */
{
    return tok.tkn == 'i';
}

boolean isStop(Token tok)
/* Mengembalikan 'true' apabila tok.tkn == "x" */
{
    return tok.tkn == 'x';
}

Token number(char text[100], int pos)
/* Mengembalikan Token dengan nilai tok.pos = pos, dan tok.tkn = "number" */
{
    Token TTemp;

    TTemp.pos = pos;
    TTemp.tkn = 'b';
    TTemp.value = atof(text);

    return TTemp;
}

Token symbol(char text, int pos)
/* Mengembalikan Token dengan nilai  tok.pos = pos dan tok.tkn = "symbol" */
{
    Token TTemp;

    TTemp.pos = pos;
    TTemp.tkn = text;
    TTemp.value = NaN;

    return TTemp;
}

Token identifier(char text[100], int pos)
/* Mengembalikan Token dengan nilai tok.pos = pos dan tok.tkn = "identifier" */
{
    Token TTemp;

    TTemp.pos = pos;
    TTemp.tkn = 'i';
    TTemp.value = NaN;

    return TTemp;
}

Token stop(int pos)
/* Mengembalikan Token dengan nilai tok.pos = pos dan tok.tkn = "x" */
{
    Token TTemp;

    TTemp.pos = pos;
    TTemp.tkn = 'x';
    TTemp.value = NaN;

    return TTemp;
}
boolean isId(char ch)
/* Mengembalikan 'true' jika ch adalah sebuah Identifier, lihat definisi Identifier diatas */
{
    return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ch == '_';
}

boolean isId1(char ch)
{
    return isId(ch) || ('0' <= ch && ch <= '9');
}
boolean isDigit(char ch)
/* Mengembalikan 'true' jika ch adalah sebuah Digit, lihat definisi Digit diatas */
{
    return (('0' <= ch && ch <= '9') ||(ch == '.'));
}

TokProcess nextToken(char s[100], int pos)
/* Mengembalikan dan membaca token selanjutnya */
{
    int start;
    char ch;
    TokProcess Temp;
    char strtemp[100];

    while ((pos < strlen(s)) && ((s[pos] == ' ') || s[pos] == '\t' || s[pos] == '\r' || s[pos] == '\n')){
        pos++;
    }
    if (pos == strlen(s)){
        Temp.toks = stop(pos);
        Temp.posnow = pos;
        return Temp;
    }
    start = pos;
    ch = s[pos];
    if (isId(ch)){
        while ((pos < strlen(s)) && isId1(s[pos])){
            pos++;
        }
        strncpy(strtemp,s+start, pos-start);
        strtemp[pos-start] = '\0';
        Temp.toks = identifier(strtemp,pos);
        Temp.posnow = pos;
        return Temp;
    }
    if (isDigit(ch)){
        while ((pos < strlen(s)) && (isDigit(s[pos]))){
            pos++;
        }
        char strtemp[100];
        strncpy(strtemp,s+start, pos-start);
        strtemp[pos-start] = '\0';
        Temp.toks = number(strtemp,pos);
        Temp.posnow = pos;
        return Temp;
    }
    Temp.toks = symbol(s[pos], start);
    Temp.posnow = pos+1;
    return Temp;
}

Stack tokenize(char s[100])
/* Mengembalikan sebuah StackOfToken dari hasil pembacaan token */
{
    Stack tokens;
    Stack revtokens;
    int position = 0;
    Token tok;
    TokProcess TP;
    CreateEmpty(&tokens);
    CreateEmpty(&revtokens);
    do {
        TP = nextToken(s, position);
        Push(&tokens,TP.toks);
        position = TP.posnow;
    } while (isStop(TP.toks) == false);
    while (!IsEmpty(tokens)){
        Pop(&tokens,&tok);
        Push(&revtokens,tok);
    }
    return revtokens;
}