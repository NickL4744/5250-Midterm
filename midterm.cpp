#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>
#include <chrono>
#include <vector>

//use this command to run
//g++ -g -Wall -fopenmp -o exename filename.cpp

//add namespace for chrono
using namespace std::chrono;

int main(int argc, char* argv[])
{
    auto begin = steady_clock::now();

    //search_max becomes command line argument, also is an int
    int search_max = strtol(argv[1], NULL, 10);
    int sqrt_search_max = (int)sqrt(search_max);

    //number of threads
    int thread_count = strtol(argv[2], NULL, 10);

    //initialize primes to be a vector of size search_max
    std::vector<int> primes(search_max);

#   pragma omp parallel for num_threads(thread_count)    
    for (int i = 0; i < search_max; i++)
    {
        primes[i] = i + 1;
    }
#   pragma omp parallel num_threads(thread_count)
    {
        for (int i = 1; i < sqrt_search_max; i++)
        {
            int current_prime = primes[i];
            if (current_prime != 0)
            {
#           pragma omp for
                for (int j = i + current_prime; j < search_max; j += current_prime) 
                {
                  primes[j] = 0;
                }
            } 
        }
    }
    
    //output when program is finished running
    printf("End of program reached.\n");
    
    //save the time into variable end
    auto end = steady_clock::now();

//calculate the execution time
auto time_spent = duration_cast<microseconds>(end - begin).count(); 

//output print the execution time
printf("The program took %lld microseconds to run.\n", time_spent); // double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

return 0;
}
