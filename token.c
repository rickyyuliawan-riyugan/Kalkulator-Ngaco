/* Identifier : semua character a..z atau A..Z atau '_' */
/* Digit : semua angka mulai dari 0..9 dan '.' */
/* Number : semua kombinasi dari digit digit yang tersedia atau ditambah dengan symbol + atau - */
/* Symbol : ^ * / + - */

/* Apabila token berisi sebuah number maka tok.sbl = 'b' */
/* Apabila token berisi sebuah identifier maka tok.sbl = 'i' */
/* Apabila token berisi sebuah stop maka tok.sbl = 's' */

/*Spek lainnya akan ditulis lebih lanjut di waktu yang lain, semoga yang ini cukup jelas */
#include "stacktkn.h"
typedef struct{
   int pos;
   char* text;
   char* tkn;
   char sbl;
   double value;
} Token;
typedef struct{
    Token token;
} ArrayOfToken;

boolean isNumber(Token *tok);
/* Mengembalikan 'true' apabila tok.tkn == "number" */

boolean isSymbol(Token *tok, char s);
/* Mengembalikan 'true' apabila tok.tkn == "symbol" DAN tok.sbl == s */

boolean isIdentifier(Token *tok);
/* Mengembalikan 'true' apabila tok.tkn == "identifier" */

boolean isStop(Token *tok);
/* Mengembalikan 'true' apabila tok.tkn == "stop" */

Token number(char* text, int pos);
/* Mengembalikan Token dengan nilai tok.text = text, tok.pos = pos, dan tok.tkn = "number" */

Token symbol(char* text, int pos);
/* Mengembalikan Token dengan nilai tok.text = text, tok.pos = pos dan tok.tkn = "symbol" */

Token identifier(char* text, int pos);
/* Mengembalikan Token dengan nilai tok.text = text, tok.pos = pos dan tok.tkn = "identifier" */

Token stop(int pos);
/* Mengembalikan Token dengan nilai tok.text = "" tok.pos = pos dan tok.tkn = "stop" */

boolean isIdentifier(char ch)
/* Mengembalikan 'true' jika ch adalah sebuah Identifier, lihat definisi Identifier diatas */
{
    return (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ch == '_');
}

boolean isDigit(char ch)
/* Mengembalikan 'true' jika ch adalah sebuah Digit, lihat definisi Digit diatas */
{
    return ((ch == '0') || (ch == '1') || (ch == '2') || (ch == '3') || (ch == '4') || (ch == '5') ||(ch == '6') || (ch == '7') ||(ch == '8') || (ch == '9') ||(ch == '.'));
}

Token nextToken(string s, int position);
/* Mengembalikan dan membaca token selanjutnya */

Stack tokenize(string s)
/* Mengembalikan sebuah ArrayOfToken dari hasil pembacaan token */
{
    Stack tokens;
    int position = 0;
    Token tok;
    int i;
    
    tokens.Neff = 0;
    while 1 {
        tok = nextToken(s, position);
        Push(&tokens,tok);
        if isStop(){
            return tokens;
        }
        pos = tok.posnow;
    }
}