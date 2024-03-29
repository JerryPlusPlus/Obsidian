﻿#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

void hello(void) {
	int my_rank = omp_get_thread_num();
	int thread_count = omp_get_num_threads();
	printf("Hello from thread %d of %d.\n", my_rank, thread_count);
}

int main(int argc, char** argv) {
	int thread_count = strtol(argv[1], NULL, 10);
	//int thread_count = strtol(argv[2], NULL, 10);
	//int thread_count = strtol(argv[3], NULL, 10);
#pragma omp parallel num_threads(thread_count)
	hello();

	return 0;
}
