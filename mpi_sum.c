#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int rank, size;
    int array_size = 10;
    int array[array_size];
    int local_sum = 0, global_sum = 0;

    // Initialize MPI
    MPI_Init(&argc, &argv);

    // Get the number of processes and the rank of the current process
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Each process generates its own array with random values
    srand(rank);
    for (int i = 0; i < array_size; i++) {
        array[i] = rand() % 10;
    }

    // Compute the local sum
    for (int i = 0; i < array_size; i++) {
        local_sum += array[i];
    }

    // Reduce the local sums to calculate the global sum
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // Print the results
    if (rank == 0) {
        printf("Array elements:");
        for (int i = 0; i < array_size; i++) {
            printf(" %d", array[i]);
        }
        printf("\n");

        printf("Global sum: %d\n", global_sum);
    }

    // Finalize MPI
    MPI_Finalize();

    return 0;
}
