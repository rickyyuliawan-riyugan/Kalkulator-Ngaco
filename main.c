#include <stdio.h>
#include <string.h>

int main(){
    char* hasil;
    char input[100];
    printf("Selamat Datang di Kalkulator Tubes\n");
    printf("Dibuat dengan segenap cinta oleh:\n");
    printf("->13517007 Mohammad Ridwan Hady Arifin\n");
    printf("->13517025 Ricky Yuliawan\n");
    printf("->13517058 Ahmad Rizqee Nurhani\n\n");
    
    do{
        printf("Input : ");
        scanf("%s", &input);
        printf("%s\n", input);
        hasil = parse(input);
        if hasil != "Error"{
            printf("Hasil => %f", hasil);
        } else {
            printf("%s", hasil);
        }
    } while ((input != 'X')&&(input != "Exit"));
}