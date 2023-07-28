/*
 * Author: Dr. Nileshchandra Pikle
 * Email: nilesh.pikle@gmail.com
 * Contact No: 7276834418
 * Program Name: Hello.c
 * Compilation: gcc -fopnemp Hello.c
 *         Run: .\a.exe (on windows) or ./a.out (on Linux)
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    #pragma omp parallel // This parallel directive start the parallel region by creating (forking) threads
    {
        printf("\n Hello world open_mp is working "); // This statement gets executed by number of threads available in the parallel region
    }// Parallel region termibates here and threads get destroyed (Joining)
    return 0;
}