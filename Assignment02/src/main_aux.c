/*
 * main_aux.c
 *
 *  Created on: 7 במאי 2017
 *      Author: Dolev
 */
#include "main_aux.h"
#include <stdio.h>
#include <stdlib.h>
//check if the input(number of heaps) that the user entered is legal.
int checkNumOfHeaps(int N){
	if( N<1 || N>32){
		printf("Error: the number of heaps must be between 1 and 32.\n");
		return 0;
	}
	return 1;
}
// print the status of the game.
//param: the heaps and their number
void printStatus(int heapSizes[],int N){
	int maxheap = maxinArray(heapSizes,N);
	for(int i = maxheap;0<i;--i){
		for(int j = 0; j < N; ++j){
			if(heapSizes[j] >= i){
				printf("*");
			}
			else printf (" ");
			if(j<N-1) printf("\t");
		}
		printf("\n");
	}
}
//return the max number in int array.
int maxinArray(int heapSizes[],int N){
	int max = 0;
	for(int i =0; i<N; ++i){
		if(max < heapSizes[i]) max = heapSizes[i];
	}
	return max;
}
//print the status of the game in text. it means how many object there is in any heap.
void printStatusText(int turn,int heapSizes[],int N){
	printf("In turn %d heap sizes are:",turn);
	for(int i = 0; i < N; ++i){
		printf(" h%d=%d",i+1,heapSizes[i]);
	}
	printf(".\n");
}
//print who won the game
void printWinner (int player){
	char* str = (player == 0) ? "Computer wins!\n" : "You win!\n";
	printf("%s",str);
}


