#include <stdio.h>
#include <math.h>

int main() {
    const int search_max = 1000;
    int sqrt_search_max = (int)sqrt(search_max);

    int primes[search_max];

    for (int i = 0; i < search_max; i++) {
        primes[i] = i + 1;
    }

    for (int i =1; i < sqrt_search_max; i++) {
        int current_prime = primes[i];
        if (current_prime != 0) {
            for (int j = i + current_prime; j < search_max; k += current_prime) {
                primes[j] = 0
            }
        }
    }

    printf("The prime numbers are: ");
    for (int i = 1; i < search_max; i++) {
        if (primes[i] != 0) printf("%d ", primes[i]);
    }

    printf("End of program reached.\n");
    return 0;
}