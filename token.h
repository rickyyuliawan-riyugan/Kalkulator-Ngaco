/* Identifier : semua character a..z atau A..Z atau '_' */
/* Digit : semua angka mulai dari 0..9 dan '.' */
/* Number : semua kombinasi dari digit /* Identifier : semua character a..z atau A..Z atau '_' */
/* Digit : semua angka mulai dari 0..9 dan '.' */
/* Number : semua kombinasi dari digit digit yang tersedia atau ditambah dengan symbol + atau - */
/* Symbol : ^ * / + - */

/* Apabila token berisi sebuah number maka tok.tkn = 'b' */
/* Apabila token berisi sebuah identifier maka tok.tkn = 'i' */
/* Apabila token berisi sebuah stop maka tok.tkn = 'x' */

/*Spek lainnya akan ditulis lebih lanjut di waktu yang lain, semoga yang ini cukup jelas */
#ifndef token_H
#define token_H

#include "TokenType.h"
#include "boolean.h"
#include "stacktkn.h"
#include <math.h>

boolean isNumber(Token tok);
/* Mengembalikan 'true' apabila tok.tkn == "b" */

boolean isSymbol(Token tok, char s);
/* Mengembalikan 'true' apabila tok.tkn == s */

boolean isIdentifier(Token tok);
/* Mengembalikan 'true' apabila tok.tkn == "identifier" */

boolean isStop(Token tok);
/* Mengembalikan 'true' apabila tok.tkn == "x" */

Token number(char text[100], int pos);
/* Mengembalikan Token dengan nilai tok.pos = pos, dan tok.tkn = "number" */

Token symbol(char text, int pos);
/* Mengembalikan Token dengan nilai  tok.pos = pos dan tok.tkn = "symbol" */

Token identifier(char text[100], int pos);
/* Mengembalikan Token dengan nilai tok.pos = pos dan tok.tkn = "identifier" */

Token stop(int pos);
/* Mengembalikan Token dengan nilai tok.pos = pos dan tok.tkn = "x" */

boolean isId(char ch);
/* Mengembalikan 'true' jika ch adalah sebuah Identifier, lihat definisi Identifier diatas */

boolean isId1(char ch);
/* Mengembalikan 'true' jika ch adalah sebuah Identifier, lihat definisi Identifier diatas */

boolean isDigit(char ch);
/* Mengembalikan 'true' jika ch adalah sebuah Digit, lihat definisi Digit diatas */

TokProcess nextToken(char s[100], int pos);
/* Mengembalikan dan membaca token selanjutnya */

Stack tokenize(char s[100]);
/* Mengembalikan sebuah StackOfToken dari hasil pembacaan token */

#endif