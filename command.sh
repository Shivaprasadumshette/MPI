sudo apt -y update
sudo apt -y upgrade
sudo apt-get install libopenmpi-dev


mpicc mpi_sum.c 
mpiexec -n 4 ./a.out 

gcc -o hello_openmp hello_openmp.c -fopenmp
./hello_openmp



gcc -fopenmp VecAdd.c
./a.out