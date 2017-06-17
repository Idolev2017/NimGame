/*
 * sp_nim.c
 *
 *  Created on: 7 במאי 2017
 *      Author: Dolev
 */
#include "sp_nim.h"
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 32
//check if all heaps are empty, it means the last player that played win.
//param: heaps and number of heaps.
//return 1 if all heaps are empty.
int checkIfWin(int heapsize[],int N){
	for(int i =0; i < N; ++i){
		if (heapsize[i] != 0) return 0;
	}
	return 1;
}
//decide if this is the player's turn or computer's turn.
//call to the function's turn.
int playturn(int heapSizes[],int N,int player){
	if (player == 1){
		playturnUser(heapSizes,N);
		return 0;
	}
	playturnComputer(heapSizes,N);
	return 1;
}
//play the computer's turn.
//param: the array that contains the heaps, and the number of heaps.
void playturnComputer(int heapSizes[],int N){
	int nimSum,minIWinner=N-1,minIsize = N-1;
	int heapNimSum[MAXSIZE];
	if(N==1)
		nimSum=heapSizes[0];
	else{
		nimSum=heapSizes[0]^heapSizes[1];
		for(int i=2;i<N;++i)
			nimSum^=heapSizes[i];
	}
	for(int i = 0; i < N; ++i){
		heapNimSum[i] = heapSizes[i]^nimSum;
		if(heapNimSum[i] < heapSizes[i] && i < minIWinner) minIWinner = i;
		if(0 < heapSizes[i] && i < minIsize) minIsize=i;
	}
	if(nimSum != 0){
		int removed = heapSizes[minIWinner] - heapNimSum[minIWinner];
		heapSizes[minIWinner] = heapNimSum[minIWinner];
		printf("Computer takes %d objects from heap %d.\n",removed ,minIWinner + 1);
	}
	else{
		heapSizes[minIsize] -= 1;
		printf("Computer takes %d objects from heap %d.\n",1,minIsize + 1);
	}

}
//play the user's turn.
// the func asked for a input and play for the user.
void playturnUser(int heapSizes[],int N){
	int heapIndex,numObjects,scanCheck;
	printf("Your turn: please enter the heap index and the number of removed objects.\n");
	scanCheck = scanf("%d%d",&heapIndex,&numObjects);
	while (scanCheck != 2 || heapIndex <1 || heapIndex > N || numObjects <=0 || heapSizes[heapIndex-1] < numObjects ){  //check if input is valid
		printf("Error: Invalid input.\nPlease enter again the heap index and the number of removed objects.\n");
		scanCheck = scanf("%d%d",&heapIndex,&numObjects);
	}
	heapSizes[heapIndex-1] -= numObjects;
	printf("You take %d objects from heap %d.\n",numObjects,heapIndex);
}


