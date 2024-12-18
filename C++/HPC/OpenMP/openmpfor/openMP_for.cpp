#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<string.h>

int main(int argc, char** argv) {

	int thread_count = strtol(argv[1], NULL, 10);
	double a[1000], b[1000];
	for (int i = 0; i < 1000; i++) {
		a[i] = i;
		b[i] = 1000 - i;
	}
	double s[1000];
#pragma omp parallel for num_threads(thread_count)
	for (int i = 0; i < 1000; i++)
		s[i] = a[i] + b[i];
	
	printf("%lf	", s[0]);

	return 0;
}