#include <iostream>
#include <omp.h>

using namespace std;
const int N=1000;
void init(float* A, float* B, int N)
{

  srand(0); // Initialize RNG

  for (int i = 0; i < N; i++)
  {
    A[i]=(float)rand() / (float)RAND_MAX;
    B[i]=(float)rand() / (float)RAND_MAX;
  }
}

void output(float* A, int N)
{
  for (int i =0;i<N;i++)
  {
   for (int j=0;j< 10;j++)
   cout << A[i] <<" ";
  } 
  cout <<endl;
}

void vec_mult(int N)
{        
        int i;
	float p[N], v1[N], v2[N];
         
	init(v1, v2, N);
	
        #pragma omp target data map(to: v1[0:N], v2[:N]) map(from: p[0:N])
        { 
	  #pragma omp target
	  #pragma omp parallel for simd
	  for (i=0; i<N; i++)
		p[i] = v1[i] * v2[i];
	}
        output(p, N);
}

int main(int argc, char **argv)
{
 vec_mult(N); 
}
