#include <stdio.h>
#include <stdlib.h>

_Bool is_prime(int a) {
    if (a == 1 | a== 0 | a == -1 ) return 0;
    for(int i = 2; i*i < labs(a); i++) {
        if (a % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int a;
    while(a != 0) {
        printf("\nEnter the number(0 - exit): ");
        scanf("%d",&a);
        if (is_prime(a)) {
            printf("The number is prime\n");
        } else {
            printf("The number is not prime\n");
        }
    }
}