#include "poker.h"

//Fills array of type Card with all possible card combinations. To use a char for the suit instead of a string, comment out string copies and uncomment commented line directly below the string copy.
void init_deck( Card myDeck[] )
{
	int i = 0, j = 0, loc = 0;
	char suits[4][10] = {"hearts", "diamonds", "clubs", "spades"};

	for (i = 0; i < 13; i++)
	{
		for (j = 0; j < 4; j++)
		{
			myDeck[loc].face_value = i + 1;
			strcpy(myDeck[loc].suit, suits[j]);
			//myDeck[loc].suit = suits[j];
			myDeck[loc].is_taken = 0;
			loc++;
		}
	}
}

//Uses a basic swap function into random locations to shuffle the cards. To use a char for the suit instead of a string, comment out string copies and uncomment commented line directly below each string copy.
void shuffle_deck( Card myDeck[] )
{
	int i = 0, rand_loc = 0;
	Card temp;

	for (i = 0; i < 52; i++)
	{
		rand_loc = rand() % 52;

		if (rand_loc != i)
		{
			temp.face_value = myDeck[i].face_value;
			strcpy(temp.suit, myDeck[i].suit);
			//temp.suit = myDeck[i].suit;

			myDeck[i].face_value = myDeck[rand_loc].face_value;
			strcpy(myDeck[i].suit, myDeck[rand_loc].suit);
			//myDeck[i].suit = myDeck[rand_loc].suit;
			myDeck[i].is_taken = 0;

			myDeck[rand_loc].face_value = temp.face_value;
			strcpy(myDeck[rand_loc].suit, temp.suit);
			//myDeck[rand_loc].suit = temp.suit;
			myDeck[rand_loc].is_taken = 0;
		}
	}
}

//Prints either the full deck of cards or just a hand, depending on the size passed in (which are #defined). 
void print_deck( Card myDeck[], int size )
{
	int i = 0;

	for (i = 0; i < size; i++)
	{
		printf("%d  %s\n", myDeck[i].face_value, myDeck[i].suit);
	}
}

//Deals a hand of cards to one player. To use a char for the suit instead of a string, comment out string copy and uncomment commented line below it.
void deal_cards( Card myDeck[], Card player1[] )
{
	int i = 0, j = 0;

	for (i = 0; myDeck[i].is_taken != 0; i++);//Finds the first unused card in the deck by checking the "is_taken" variable in each array location up to the first unused card.

	for (j = 0; j < 5; j++)//Assigns next five unused cards to the player.
	{
		myDeck[i].is_taken = 1;//Indicates card being assigned are now in use by the player.
		player1[j].face_value = myDeck[i].face_value;
		strcpy(player1[j].suit, myDeck[i].suit);
		//player1[j].suit = myDeck[i].suit;
		player1[j].is_taken = myDeck[i].is_taken;

		i++;
	}

}