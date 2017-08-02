// LICENSE : GPL 3, see file LICENSE_GPL-3.txt

#ifndef N
#define N 5
#endif
#ifndef FS
#define FS 37 
#endif
#define MULTCOUNT 10000000

//  Under the covers, process_work() computes fibonacci numbers
//  these #defines govern which numbers to start with and how many iterations to compute
//  Fibonacci was chosen because it is a simple way to vary the amount of computation 
//  by changing the input "seed" parameter.  In other words, process_work(1) takes 
//  no time to compute, while process_work(42) takes exponentially more computation time.

//  This example can show how the overhead of task scheduling versus computation time
//  impacts the scalability of this task based decomposition

//  small values of FS = 3 and small iterations N = 2
//  will cause the parallel version of the app to run slower than the serial version
//  larger values, FS=37 and N=5 will give each thread enough computation to
//  make the task scheduling effort worthwhile

//  The more work each thread performs, the better the scaling of this application

