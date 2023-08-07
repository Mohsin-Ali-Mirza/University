#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>

int main()
{
 const int n=10000;
 double *arr;
 arr = (double*)malloc(n*sizeof(double));
 if(arr==NULL)
  printf("Memory Not Allocated.\n");

  srand(time(0));
  for(int i=0;i<n;i++)
  arr[i] = rand();
 
  for(int i=0;i<n;i++)
   arr[i] *= rand();

   double sum = 0;

double start = omp_get_wtime();
 #pragma omp parallel for
 for(int i=0;i<n;i++)
 {
  #pragma omp critical
  {
   sum+=arr[i];
  }
 }
 double end = omp_get_wtime();

 printf("Time Elapsed:%f\n",end-start);
 printf("Sum:%f\n",sum);

 free(arr);
 printf("Memory Successfully Freed.\n");
 return 0;
}