#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int isPrime(int in);

int checkAndRotate(int x);

void rotate(char* str, int length);

int main(int argc, char** args) {
    int x;
    if(argc < 2) {
        printf("Enter a number to check if it's a circular prime: \n");
        scanf("%i", &x);
    } else{
        x = atoi(args[1]);
    }
    checkAndRotate(x);

    return 0;
}

int checkAndRotate(int x){
    int length = (int)log10(x)+1;
    char* str = (char*)malloc(sizeof(char)*length);
    sprintf(str, "%i", x);
    //printf("%s - %i\n", str, length);

    int primes = 1;

    int i;
    for (i = 0; i < length; ++i) {
        rotate(str, length);
        int num = atoi(str);
        int is_prime = isPrime(num);
        primes &= is_prime;
        printf("%s - %s\n", str, is_prime? "PRIME" : "COMPOSITE");
    }
    printf("Circular Prime: %s\n", (primes)? "YES": "NO");
    free(str);
    return primes;
}

void rotate(char* str, int length){
    char* buffer = (char*)malloc(sizeof(char)*length);
    strcpy(buffer, str);

    for (int i = 0; i < length; ++i) {
        str[i] = buffer[(i+1)%length];
    }

    free(buffer);
}

int isPrime(int in){
    int i;
    int lim = (int)sqrt(in) +1;
    for (i = 2; i < lim; i++) {
        if(in%i == 0){
            return 0;
        }
    }
    return 1;
}