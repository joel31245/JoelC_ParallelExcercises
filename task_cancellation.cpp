#include <iostream>

using namespace std;
#define N 40

int main()
{
	char haystack[N+1]="abcabcabczabcabcabcxabcabcabczabcabcabcz";
	char needle='x';
	int pos;
        bool cancel = false;
	#pragma omp parallel 
        #pragma omp for
	for (int i=0; i<N; i++)
         if(haystack[i]==needle)
         {
           pos =i;
            #pragma omp cancel for 
         }
 
       cout << endl<< needle<<"\tfound at position\t"<< pos<<"\tin\t"<< haystack<<endl;
}
