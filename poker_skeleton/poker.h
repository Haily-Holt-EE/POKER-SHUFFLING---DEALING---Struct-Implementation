#ifndef POKER_H
#define POKER_H

#define WHOLE_DECK 52
#define HAND 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct card //Uses a struct to create a card, so suit and face value are wrapped together. "is_taken" will indicate whether a card is in use (1) or not (0). 
{
	int face_value;
	char suit[10];
	//char suit;
	int is_taken;
}Card;

void init_deck (Card myDeck[]);
void shuffle_deck (Card myDeck[]);
void print_deck (Card myDeck[], int size);
void deal_cards(Card myDeck[], Card player1[]);


#endif