// OS- PP1- Alajaj.cpp : Defines the entry point for the console application.

//
//Abdullah S. Alajaj
//OS3653 - PP1 
//02/19/2017


#include <sys/types.h>
#include <cstdlib>
#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <pthread.h>

int data_share[10000];

void *fibonacci_thread(void* par);
void parent(int* num);

int main() {

	int num = 0; //dcleare var

	pthread_t child; // create thread
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	parent(&num); // get user input and start separate thread.
	pthread_create(&child, &attr, fibonacci_thread, (void*)&num); //starts fibonacci thread
	pthread_join(child, NULL); //waits for the thread 

	//After thread finishes, show result
	for (int i = 0; i <= data_share[i]; i++) {
		printf("%d", data_share[i]);
	}

	return 0;
}

void *fibonacci_thread(void* par) {

	int fib0 = 0, fib1 = 1, next = 0;
	int *pointer;
	pointer = (int*)par;
	int count = *pointer;

	for (int i = 0; i < count; i++) {
		if (i <= 1)
			next = i;
		else {
			next = fib0 + fib1;
			fib0 = fib1;
			fib1 = next;
		}
		next = data_share[i]; //store array in data_share btween parent and child
	}
	//This is for pthread_exit(0);
	return NULL;
}

void parent(int* num) {
	std::cout << "Generate the Fibonacci sequence, Please enter in a number: ";
	std::cin >> *num;

	while (isdigit(*num) != true) {
		std::cout << "What you entered invalid, please enter in a number: ";
		std::cin >> *num;
	}

	return;
}