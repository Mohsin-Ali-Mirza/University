#include <omp.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define max_threads 80

struct bucket {
    int n_obj;
    int pos; 
    int begin;
};

int compare (const void * a, const void * b)
{
 return ( *(int*)a - *(int*)b );
}

int main(int argc, char *argv[]) {

    int *A, *B, *temp;
    int length, n_buckets, i, w, limit, num_threads, workload, b_pos;
    struct bucket* buckets;
    double timeRequired;
    float total; 

    printf("Give length of array to sort \n");
    if (scanf("%d", &length) != 1){
        printf("error\n");
        return -1;
    }
    printf("Give number of buckets \n");
    if (scanf("%d", &n_buckets) != 1){
        printf("error\n");
        return -1;
    }
	int *tmp;
    int global_n_obj[n_buckets];
    int global_begining_pos[n_buckets]; 
    memset(global_n_obj, 0, sizeof(int)*n_buckets);
    memset(global_begining_pos, 0, sizeof(int)*n_buckets);

    num_threads = n_buckets;
    omp_set_num_threads(num_threads);

    limit = 100000;
    w = limit/n_buckets;
    A = (int *) malloc(sizeof(int)*length);
    B = (int *) malloc(sizeof(int)*length);

    for(i=0;i<length;i++) {
	    A[i] = random() % limit;
	}

    buckets = (struct bucket *) calloc(n_buckets*num_threads, sizeof(struct bucket));

// ****************************
// The main algorithm
// ****************************

    timeRequired = omp_get_wtime();
#pragma omp parallel
{
    num_threads = omp_get_num_threads();
    if(omp_get_thread_num()==0)
    printf("\n%d",num_threads);

    int j,k;
    int local_pos; 
    int real_bucket_pos;
    int my_id = omp_get_thread_num();
    workload = length/num_threads;
	int prevoius_pos;

   #pragma omp for private(i,local_pos)
    for (i=0; i< length;i++){
        local_pos = A[i]/w;
        if (local_pos > n_buckets-1)
                local_pos = n_buckets-1;
        real_bucket_pos = local_pos + my_id*n_buckets;
        buckets[real_bucket_pos].n_obj++;
	}   
   
	int local_sum=0;
	for (j=my_id; j< n_buckets*num_threads; j=j+num_threads){
		local_sum += buckets[j].n_obj;
	}
	global_n_obj[my_id]=local_sum;
	
	#pragma omp barrier
	
	#pragma omp master
    {
	 for (j=1; j<n_buckets; j++){
		        global_begining_pos[j] = global_begining_pos[j-1] + global_n_obj[j-1];	 
				buckets[j].begin = buckets[j-1].begin + global_n_obj[j-1];
				buckets[j].pos = buckets[j-1].pos + global_n_obj[j-1];
		}
	}

	#pragma omp barrier
	for (j=my_id+n_buckets; j< n_buckets*num_threads; j=j+num_threads){
		int prevoius_pos = j-n_buckets;
		buckets[j].begin = buckets[prevoius_pos].begin + buckets[prevoius_pos].n_obj;
		buckets[j].pos = buckets[prevoius_pos].pos + buckets[prevoius_pos].n_obj;	
	}
	#pragma omp barrier

    #pragma omp for private(i, b_pos)
    for (i=0; i< length ;i++){
        j = A[i]/w;
        if (j > n_buckets -1)
                j = n_buckets-1;
        k = j + my_id*n_buckets;
        b_pos = buckets[k].pos++;
        B[b_pos] = A[i];
    }

#pragma omp for private(i)
    for(i=0; i<n_buckets; i++)
        qsort(B+global_begining_pos[i], global_n_obj[i], sizeof(int), compare);
}
   total = omp_get_wtime() - timeRequired;
	tmp = A;
	A = B;
	B = tmp;

    printf("Sorting %d Elements took %f seconds\n", length,total);

    int isSorted = 1;
    for(i=0;i<length-1;i++) {
        if (A[i] > A[i+1])
            isSorted = 0;
    }
    
    if (!isSorted)
        printf("The data is not Sorted!!!\n");
}
