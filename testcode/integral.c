#include <stdio.h>
#include <omp.h>
#include <time.h>

static long num_steps = 1000000;
double step;

int parallel(){
  double x, pi, sum = 0.0;

  step = 1.0/(double) num_steps;
#pragma omp parallel
  {
    int i = 0;
    double time = omp_get_wtime();
    int tid = omp_get_thread_num();
    if (tid == 0)
      {
        int  nthreads = omp_get_num_threads();
        printf("Number of threads = %d\n", nthreads);
      }
    for(i = 0; i <num_steps; i++){
      x = (i+0.5)*step;
      sum = sum + 4/(1.0+x*x);
    };
    printf("%s%f", "executed one thread: ", omp_get_wtime()-time);
  }
  pi = step*sum;
  printf("%s%f\n", "Parallel Result: ", pi);
  return pi;
}

int serial(){
  int i; double x, pi, sum = 0.0;

  step = 1.0/(double) num_steps;
  double time = clock();
  
  for(i = 0; i <num_steps; i++){
    x = (i+0.5)*step;
    sum = sum + 4/(1.0+x*x);
  };
  printf("%s%f", "executed serial: ", (clock()-time)/CLOCKS_PER_SEC);
  pi = step*sum;
  printf("%s%f\n", "Serial Result: ", pi);
  return pi;
}
int main(){
  
  int pi = parallel();
  int pi_serial = serial();
  
}


