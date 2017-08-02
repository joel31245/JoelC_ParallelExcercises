#include <iostream>
#include <omp.h>

int main()
{
    long num_steps = 1000000000; 
    double step; 
    double pi, sum = 0.0; 
    step = 1.0/(double) num_steps; 
 
    #pragma omp target
    #pragma omp parallel
    { 
        int i;
        double x; 
        #pragma omp for reduction(+:sum) 
        for (i=1; i<= num_steps; i++)
        { 
            x = (i-0.5)*step; 
            sum = sum + 4.0/(1.0+x*x); 
        }
    }
 
    pi = step * sum;  
    std::cout<<"The computed value of Pi is: "<< pi<<std::endl; 

  
}
