#include <iostream>
#include <cmath>

#include <omp.h>

using namespace std;
const int N= 5000;


int main()
{
        int i,j, k=0; 
        int imax =N;
        int jmax =N;
        float scale=2.0*asin(1.0); 
         
        float *a= new float [N*N];
        srand(0);

        for (i=0; i<imax; i++) 
        {
          for (j=0;  j<jmax ; j++) a[k++] = (float)rand() / (float)RAND_MAX;
        }
        
	double t0 = omp_get_wtime();
        
	#pragma omp parallel for collapse(2) private (k)
        for (i=0; i<jmax; i++)
        { 
	     for (j=0;  j<jmax ; j++)
                 a[k++]  *= scale ; 
  	}
        double walltime =  omp_get_wtime() - t0; 

        cout << "Parallel Region Execution time:\t"<< walltime <<endl;
}
