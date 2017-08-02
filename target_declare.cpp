#include <iostream>
#include <cstdlib>
#include <omp.h>

#pragma omp declare target
using namespace std;
void init(float* A, float* B, int N)
{
  
  srand(0); // Initialize RNG

  for (int i = 0; i < N; i++)
  {
    A[i]=(float)rand() / (float)RAND_MAX;
    B[i]=(float)rand() / (float)RAND_MAX;
  }
}


void vec_mult(int N)
{        
        int i;
        float *p  = new float[N];
        float *v1 = new float[N];
        float *v2 = new float[N];
         
	init( v1, v2, N);
	for (i=0; i<N; i++)
		p[i] = v1[i] * v2[i];

     delete [] p;
     delete [] v1;
     delete [] v2;
}
#pragma omp end declare target

int main(int argc, char **argv)
{
    int N = 100;
    cout << "\nEnter Vector Size:\t\t";
    cin   >>N; 
     #pragma omp target if( N> 1000)
     vec_mult(N); 
}
