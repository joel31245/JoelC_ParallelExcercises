/*Use OpenMP directives to express as much parallelism  in the following code segement from Winograd's matrix multiplication algorithm
adapted from  Baase and Van Gelder [5] */


for (i=0; i<m; i++) {
   rowterm[i] = 0.0;
   for (j=0; j<p ;j++)
     rowterm[i]+=a[i][2*j]  *  a[i][2*j+1];
}


for (i=0; i< q; i++){
 colterm[i] = 0.0; 
 for (j=0; j<p; j++)
  colterm[i] += b[2*j][i] * b[2*j+1][i];
}

 
