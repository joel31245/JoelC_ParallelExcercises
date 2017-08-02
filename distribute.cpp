#include <cstdio>
#include <omp.h>
int main()
{
      int ntprocs;
      #pragma omp target map(from:ntprocs)
      ntprocs = omp_get_num_procs();
      int ncases=2240, nteams=4, chunk=ntprocs*2;
      #pragma omp target
      #pragma omp teams num_teams(nteams) thread_limit(ntprocs/nteams)
      #pragma omp distribute
      for (int starti=0; starti<ncases; starti+=chunk)
	#pragma omp parallel for
	for (int i=starti; i<starti+chunk; i++)
		printf("case i=%d/%d by team=%d/%d thread=%d/%d\n",
		i+1, ncases,
		omp_get_team_num()+1, omp_get_num_teams(),
		omp_get_thread_num()+1, omp_get_num_threads());
}
