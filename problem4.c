
/* Integer sorting is a class of sorting where the keys are integers. Often the range of possible key values is smaller than the number 
 of keys, in which case the sorting can be very efficiently 
 accomplished using an array of “buckets” in which to count keys. 
 Below is the bucket sort code for sorting the array key  
 into a new array, key2 . Parallelize the code using parallel regions.
*/


int bucket[NUMBUKS], key[NUMKEYS], key2[NUMKEYS];

for (i=0;i < NUMBUKS; i++)
	bucket[i] = 0;


for (i=0;i < NUMKEYS; i++)
	bucket[key[i]] = bucket[key[i]] + 1;


for (i=1; i < NUMBUKS; i++)
	bucket[i] = bucket[i] + bucket[i – 1];


for (i=0; i < NUMBUKS; i++){
	key2[bucket[key[i]]]] = key[i];
	bucket[key[i]] = bucket[key[i]] – 1;
}

