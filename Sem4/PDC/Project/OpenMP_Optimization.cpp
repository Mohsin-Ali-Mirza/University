#include <iomanip>
#include <omp.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main()
{

	double start, end;

	int N = 10000;

	double** mat = (double**)malloc(N * sizeof(double));
	for (int i = 0; i < N; i++)
		mat[i] = (double*)malloc(N * sizeof(double));

	double* b = (double*)malloc(N * sizeof(double));

	srand(time(NULL));

	for (int i = 0; i < N; i++)
	{
		int num = abs(rand() % 100);
		b[i] = num;
		//cout << b[i] << " ";
		for (int j = 0; j < N; j++)
		{
			int num2 = abs(rand() % 100);
			mat[i][j] = num2;

		}
	}

	//cout << "Randomly Generated Matrix\n";
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		cout << mat[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	start = omp_get_wtime();
	int threads;
	for (int i = 0; i < N - 1; i++)
	{

		cout << i << "\n";

#pragma omp parallel for num_threads(4)
		for (int j = i; j < N; j++)
		{
			threads = omp_get_num_threads();
			if (mat[i][i] == 0) {
				mat[i][i]++;
			}
			double ratio = mat[j][i] / mat[i][i];
			for (int k = i; k < N; k++)
			{
				mat[j][k] -= (ratio * mat[i][k]);
				b[j] -= (ratio * b[i]);
			}
		}
	}
	end = omp_get_wtime();

	cout << endl;
	//cout << "Calculated Matrix After Gaussian Elimination\n";

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		cout << mat[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	cout << endl;
	cout << "\nSize of Array = " << N << " x " << N << endl;
	cout << "Number of threads: " << threads << "\n";

	cout << "Time taken by program is : " << setprecision(5) << end - start;
	cout << " sec " << endl;



}