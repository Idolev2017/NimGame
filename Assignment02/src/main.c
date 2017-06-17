/*
 ============================================================================
 Name        : Assignment02.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "main_aux.h"
#include "sp_nim.h"
#include "SPBufferset.h"
#define MAXSIZE 32

int main(void) {

	SP_BUFF_SET();
	int heapSizes[MAXSIZE];
	int NumOfHeaps=0,tempHeapSize=0,player=0,turn=1;    //player = 0 - comp's turn, and 1 - player's turn. turn - the turn's number.
	printf("Enter the number of heaps:\n");
	scanf("%d",&NumOfHeaps);
	if(!checkNumOfHeaps(NumOfHeaps)) return 0;  //input is not valid

	printf("Enter the heap sizes:\n");
	for(int i = 0; i < NumOfHeaps; ++i){   //get heaps sizes
		scanf("%d",&tempHeapSize);
		if(tempHeapSize <= 0) {    //heap size is non positive
			printf("Error: the size of heap %d should be positive.\n",i+1);
			return 0;
		}
		heapSizes[i] = tempHeapSize;
	}
	while(!checkIfWin(heapSizes,NumOfHeaps)){    //loop that
		printStatusText(turn,heapSizes,NumOfHeaps);   //print the status of the game.
		if(player == 1) printStatus(heapSizes,NumOfHeaps);  //if it is the user game, print the how many object in each heap.
		playturn(heapSizes,NumOfHeaps,player);     //play the turn. the funct decide who will play, the comp or the user.
		++turn;
		player = 1 - player;
	}
	printWinner(1-player);
	return 0;
}
