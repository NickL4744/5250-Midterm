#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>
#include <chrono>
// g++ <filename>.c -o <filename>.exe -fopenmp using namespace std::chrono;
int main(int argc, char argv[])
{
    // clock_t begin = clock();
    auto begin = steady_clock::now();
    int search_max = strtol(argv[1], NULL, 10);
    int sqrt_search_max = (int)sqrt(search_max);
    int thread_count = strtol(argv[2], NULL, 10);
    intprimes;
    primes = (int )malloc(search_max sizeof(int));
    for (int i = 0; i < search_max; i++)
    {
        primes[i] = i + 1;
    }
#pragma omp parallel num_threads(thread_count)
    {
        for (int i = 1; i < sqrt_search_max; i++)
        {
            int current_prime = primes[i];
            if (current_prime != 0)
{
#pragma omp for

 }
} }
for (int j = i + current_prime; j < search_max; j += current_prime)
{
    primes[j] = 0;
}
    // printf("The prime numbers are: ");
    // for (int i = 1; i < search_max; i++)
    // {
    //     if (primes[i] != 0)
    // }
    free(primes);
    printf("End of program reached.\n");
    // clock_t end = clock();
    auto end = steady_clock::now();
auto time_spent = duration_cast<microseconds>(end - begin).count(); printf("The program took %lld microseconds to run.\n", time_spent); // double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
// printf("The program took %f seconds to run.\n", time_spent); return 0;
}
[10:19 PM]
###################