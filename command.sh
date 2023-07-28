sudo apt -y update
sudo apt -y upgrade
sudo apt-get install libopenmpi-dev
mpicc -o mpi_sum mpi_sum.c
mpiexec -n 4 ./mpi_sum

gcc -o hello_openmp hello_openmp.c -fopenmp
./hello_openmp
