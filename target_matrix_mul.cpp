void init(float* A, float* B, float * C, int N);
void init(float* A, float* B, int MB, int NA, int MB, int NB);
void mat_Mult(int size, float (* restrict A)[size], float (* restrict B)[size], float (* restrict C)[size]);

int main(int argc, char **argv)
{
 float *A, *B, *C;
 int order =5000;
 int N= order*order;

 A =  new float [N];
 B =  new float [N];
 C =  new float [N];


 mat_mult(N);
 delete [] A;
 delete [] B;
 delete [] C;

}

void mat_Mult(int size, float (* restrict A)[size], float (* restrict B)[size], float (* restrict C)[size]) 
{
#pragma offload target(mic:MIC_DEV) 
                in(A:length(size*size)) in( B:length(size*size))    
                out(C:length(size*size))
  {
    // Zero the C matrix
#pragma omp parallel for default(none) shared(C,size)
    for (int i = 0; i < size; ++i)
      for (int j = 0; j < size; ++j)
        C[i][j] =0.f;
     
    // Compute matrix multiplication.
#pragma omp parallel for default(none) shared(A,B,C,size)
    for (int i = 0; i < size; ++i)
      for (int k = 0; k < size; ++k)
        for (int j = 0; j < size; ++j)
          C[i][j] += A[i][k] * B[k][j];
  }
}


void init(float* A, float* B, float *C, int N)
{
  
  srand(0); // Initialize RNG

  for (int i = 0; i < N; i++)
  {
    A[i]=(float)rand() / (float)RAND_MAX;
    B[i]=(float)rand() / (float)RAND_MAX;
  }
}
