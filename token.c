typedef struct{
    int Mem[100];
    int Neff;
} Array;
typedef char* string;
typedef struct{
   string token;
   int posnow;
} Token;

boolean isNumber();

boolean isSymbol();

boolean isIdentifier();

void number();

void symbol();

void identifier();

void stop();

boolean isIdentifier(char ch)
{
    return (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ch == '_');
}

boolean isDigit(char ch)
{
    return ((ch == '0') || (ch == '1') || (ch == '2') || (ch == '3') || (ch == '4') || (ch == '5') ||(ch == '6') || (ch == '7') ||(ch == '8') || (ch == '9') ||(ch == '.'));
}

Token nextToken(string s, int position)
{
    while position < strlen(s){
        position += 1;
    }
    int start = position;
}

Array tokenize(string s)
{
    Array tokens;
    int position = 0;
    Token tok;
    int i;
    
    tokens.Neff = 0;
    while 1 {
        tok = nextToken(s, position);
        i = tokens.Neff;
        tokens.Mem[i];
        token.Neff += 1;
        if isStop(){
            return tokens;
        }
        pos = tok.posnow;
    }
}