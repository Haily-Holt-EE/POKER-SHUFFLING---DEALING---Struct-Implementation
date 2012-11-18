#include "poker.h"

//THIS DOES NOT PLAY POKER. ONLY DEMONSTRATES WHAT THE FUNCTIONS CREATED ARE DOING AND THAT THEY ARE WORKING PROPERLY. 
int main (void)
{
	Card deck[52];
	Card player1_deck[5];
	Card player2_deck[5];

	srand(time(NULL));

	init_deck(deck);
	printf("****INITIALIZED****\n");
	print_deck(deck, WHOLE_DECK);
	printf("\n\n\n\n");

	shuffle_deck(deck);
	printf("****SHUFFLED****\n");
	print_deck(deck, WHOLE_DECK);
	printf("\n\n\n\n");

	deal_cards(deck, player1_deck);
	deal_cards(deck,player2_deck);

	printf("****PLAYER ONE HAND****\n");
	print_deck(player1_deck, HAND);

	printf("\n\n");

	printf("****PLAYER TWO HAND****\n");
	print_deck(player2_deck, HAND);
	printf("\n\n");

	return 0;
}