#include <stdio.h>
#include <string.h>
#include "parse.h"
#include "token.h"
#include <stdlib.h>
#include "stacktkn.h"

int main(){
    float hasil;
    char input[100];

    printf("Selamat Datang di Kalkulator Tubes\n");
    printf("Dibuat dengan segenap cinta oleh:\n");
    printf("->13517007 Mohammad Ridwan Hady Arifin\n");
    printf("->13517025 Ricky Yuliawan\n");
    printf("->13517058 Ahmad Rizqee Nurhani\n\n");
    
    do{
        printf("Input : ");
        scanf("%s", &input);
        hasil = parse(input);
        printf("Hasil = %g\n", hasil);
    } while ((input != "X")&&(input != "Exit"));
}