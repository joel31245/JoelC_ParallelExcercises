#include <iostream>
#include  <omp.h>

using namespace std;
#define N 90000

int main()
{
	 double a[N], b[N], c[N],d0=0.0,  d1=0.0, d2=0.0, t0,t1,t2,t3;

        t0=omp_get_wtime();

        for (int i=0;i<N;i++)
                d0 +=i*(N+1-i);
        t1=omp_get_wtime() - t0;
        
        t0=omp_get_wtime();
	#pragma omp simd reduction(+:d1)
	for (int i=0;i<N;i++)
		d1+=i*(N+1-i);
        t2=omp_get_wtime()- t0;

        t0=omp_get_wtime();
	#pragma omp simd
	for (int i=0; i<N;i++) {
		a[i]=i;
		b[i]=N+1 - i;
	}
	#pragma omp parallel for simd reduction(+:d2)
	for (int i=0; i<N; i++)
		d2+=a[i]*b[i];
        t3=omp_get_wtime()- t0;
	cout << "result0 = "<<d0 <<"\nresult1 = "<<d1 <<"\nresult2 = "<<  d2 <<endl;
        cout <<"nosimd took\t"<<t1 <<" seconds\n"
             <<"OMP SIMD took\t" << t2 << " seconds\n"
             <<"OMP_Thread + SIMD took\t" << t3 <<" seconds\n"; 
return 0;

}
