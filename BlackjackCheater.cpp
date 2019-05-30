#include <iostream>
#include <ctime>
#include <cmath>
#include <vector>
#include <clocale>
using namespace std;

/////////////////////////////// Global Variables ///////////////////////////////

const int blackJack = 21;		// Holds blackjack
const int softSeventen = 17;	// Holds soft seventeen for dealer to hit
int userSelection;				// Holds user selection for title screen
int playAgain;					// Allows user to play again
bool playerChoice;				// Hold true false value to play again
char hit_or_stand;				// Allows player to hit or stand
int dealerCard1;				// Holds 1st dealer card
int dealerCard2;				// Holds 2nd dealer card
int dealerCardTotal;			// Holds dealer card total
int playerCard1;				// Holds 1st player card
int playerCard2;				// Holds 2nd player card
int playerCardTotal;			// Holds player card total

int Ace = 1;
int Jack = 10;
int Queen = 10;
int King = 10;

vector<int>	deckofCards = { Ace,2,3,4,5,6,7,8,9,10,Jack,Queen,King,
							Ace,2,3,4,5,6,7,8,9,10,Jack,Queen,King,
							Ace,2,3,4,5,6,7,8,9,10,Jack,Queen,King,
							Ace,2,3,4,5,6,7,8,9,10,Jack,Queen,King, };

//////////////// Functions Prototypes ////////////////

void bustDiplay();
void blackjackWinner();
int digitalDealer();

void dealerHand();
void playerHand();
bool checkEmptyDeck();
void subDeck();
void mainDeck();
void playGame();
void gameRules();
void titleScreen();

////////////// End Functions Prototypes //////////////

// Adds a card to the player or dealer

void hitMe()
{
	deckofCards.push_back(digitalDealer());
}

// Bust Display (DONE)

void bustDiplay()
{
	cout << " ____  _  _  ____  ________" << endl;
	cout << "| __ )| || |/ ___||___  ___|" << endl;
	cout << "|  _  | || |\\___ \\   |  |" << endl;
	cout << "| |_) | || | __/ /   |  |" << endl;
	cout << "|____/\\____/|___/    |__|" << endl << endl;
}// End of bustDiplay

// Blackjack Winner Display (DONE)

void blackjackWinner()
{	
	cout << " ____  _            _     _            _        " << endl;
	cout << "| __ )| | __ _  ___| | __(_) __ _  ___| | __    " << endl;
	cout << "|  _  | |/ _` |/ __| |/ /| |/ _` |/ __| |/ /    " << endl;
	cout << "| |_) | | (_| | (__|   < | | (_| | (__|   <     " << endl;
	cout << "|____/|_|\\__,_|\\___|_|\\_\\/ |\\__,_|\\___|_|\\_\\    " << endl;
	cout << "                       |__/                     " << endl << endl;
} // End of blackjackWinner

// Shuffles the deck

void deckShuffler() 
{
	srand((unsigned)time(0));
	for (int i = 0; i < 52; i++)
		swap(deckofCards[i], deckofCards[rand() % 52]);
	cout << "******The deck has been shuffled!******" << endl;
}

// Digital deck of cards (DONE)
// This also converts the vector into Spades, Hearts, Clubs, and Diamonds

//void subDeck()
//{
//	deckofCards = { Ace,2,3,4,5,6,7,8,9,10,Jack,Queen,King,
//					Ace,2,3,4,5,6,7,8,9,10,Jack,Queen,King,
//					Ace,2,3,4,5,6,7,8,9,10,Jack,Queen,King,
//					Ace,2,3,4,5,6,7,8,9,10,Jack,Queen,King, };
//} // End of mainDeck

  // Deals the cards (DONE)

int digitalDealer()
{
	int card = deckofCards.front();
	deckofCards.erase(deckofCards.begin());
	return card;
}

// Checks if deck is empty (DONE)

bool checkEmptyDeck()
{
	return deckofCards.empty();
} // End of checkEmptyDeck

// Controls all deck action (DONE)

void mainDeck()
{
	deckShuffler();
	digitalDealer();
	checkEmptyDeck();
}

// Dealer Hand (TODO)

void dealerHand()
{
	bool stopLoopDealer;

	if (dealerCardTotal == 21)
	{
		cout << "Dealer has \n\n";
		blackjackWinner();
	}
		
	do 
	{
		// Will hit if the dealer's initial card's total is under 17

		if (dealerCardTotal < softSeventen)
		{
			//dealerCardTotal = dealerCardTotal + cardValue;
			stopLoopDealer = false;
		}

		if ((dealerCardTotal >= 17) && (dealerCardTotal < 21))
			stopLoopDealer = true;

		if (dealerCardTotal == 21)
		{
			cout << "Dealer has 21\n\n";
			stopLoopDealer = true;
		}

		if (dealerCardTotal > 21)
		{
			stopLoopDealer = true;
			bustDiplay();
		}

	} while (stopLoopDealer = false);
} // End of dealerHand

// Player Hand (TODO)

void playerHand()
{
	bool stopLoopPlayer = false;
	
	//hitMe();
	/*hand.push_back(digitalDealer());
	hand.push_back(digitalDealer());*/

	do
	{
		bool invalidEntry = false;

		cout << "Player total: " << playerCardTotal << endl << endl;
		cout << "Dealer total: " << dealerCardTotal << endl << endl;

		// Display if player has blackjack

		if (playerCardTotal == 21)
		{
			stopLoopPlayer = true;
			cout << "Player has \n\n";
			blackjackWinner();
		}

		// If there is not blackjack then player will be allowed to play on

		else
		{
			cout << "Would you like to Hit(H) or Stand(S)?\n\n";
			cin >> hit_or_stand;

			// Will loop until proper selection is made (TODO)

			/*do {
				cin >> hit_or_stand;

				if ((hit_or_stand == 'H') || (hit_or_stand == 'h') || (hit_or_stand == 'S') || (hit_or_stand == 's'))
					invalidEntry = false;
				else
					invalidEntry = true;				

				if (invalidEntry = true)
					cout << "Invalid choice.  Please type \'H\' to hit or \'S\' to stand.  Press [ENTER] after selection is made\n\n";

			} while (invalidEntry == true);*/

			// Will add another card value to the running total

			if ((hit_or_stand == 'H') || (hit_or_stand == 'h'))
			{
				stopLoopPlayer = false;
				hitMe();
				//playerCardTotal = playerCardTotal + cardValue;
			}
			if ((hit_or_stand == 'S') || (hit_or_stand == 's'))
				stopLoopPlayer = true;

			// Player bust display

			if (playerCardTotal > 21)
			{
				stopLoopPlayer = true;
				bustDiplay();
			}
		}
	} while (stopLoopPlayer == false);
} // End playerHand

// Play main game (TODO)

void playGame()
{
	mainDeck();
	// Obtain the initial cards for both player and dealer

	for (auto i : deckofCards)
	{
		cout << "Card:" << i << endl;
		playerCardTotal += i;
	}
	hitMe();
	int sum = 0;
	cout << "Dealer Hand:" << endl;
	for (auto i : deckofCards) {
		if (i == 1 && sum + 11 <= 21) i = 11;
		cout << "Card:" << i << endl;
		sum += i;
	}

	playerCardTotal = playerCard1 + playerCard1;
	dealerCardTotal = dealerCard1 + dealerCard2;

	//playerHand();
	//dealerHand();

	////// Winning conditions //////

	// Player wins

	if (((playerCardTotal > dealerCardTotal) && (playerCardTotal <= blackJack)) ||
		((playerCardTotal <= blackJack) && (dealerCardTotal > 21)))
	{
		cout << "Player wins!!!\n\n";
	}

	// Dealer wins

	if (((dealerCardTotal > playerCardTotal) && (dealerCardTotal <= blackJack)) ||
		((dealerCardTotal <= blackJack) && (playerCardTotal > 21)))
	{
		cout << "Player wins!!!\n\n";
	}

	// No winner

	if ((dealerCardTotal = playerCardTotal) && (dealerCardTotal <= blackJack))
	{
		cout << "No winner!!!\n\n";
	}

	// Dealer and Player bust

	if ((dealerCardTotal > blackJack) && (playerCardTotal > blackJack))
	{
		cout << "No winner!!!\n\n";
	}
} // End of playGame

// Game rules (DONE)

void gameRules()
{
	char letsContinue;

	cout << "\nA blackjack game has a dealer and one or more players.Each player plays against the dealer. All players\n";
	cout << "are initially dealt two cards and the dealer is dealt one card face down and one face up (these are called\n";
	cout << "the hole card and up card respectively).Each player can then hit(ask for an additional card) until her \n";
	cout << "total exceeds 21 (this is called busting) or she decides to stand(stop taking cards for the rest of the hand).\n";
	cout << "Face cards count as 10 and an ace may be counted as 1 or 11. After all of the players have finished, the\n";
	cout << "dealer reveals the hole card and plays the hand with a fixed strategy : hit on 16 or less and stand on 17 or more.\n\n";
	cout << "The player loses if she busts and wins if she does not bust and the dealer does(observe that if both the player\n";
	cout << "and the dealer bust, the player loses).Otherwise, the player wins if her total is closer to 21 than the dealer's.\n";
	cout << "If the player wins, she gets twice her bet; if she loses, she loses her money.If the dealer and player tie it is\n";
	cout << "called a \"push;\" the player keeps her bet but does not earn any additional money.If the player's first two cards\n";
	cout << "total 21, this is a blackjack and she wins 1.5 times her bet(unless the dealer also has a blackjack, in which\n";
	cout << "case a tie results), so she gets back 2.5 times her bet.\n\n";

	cout << "Type any letter and press [ENTER] to continue.\n\n";
	cin >> letsContinue;
	cout << endl;
} // End of gameRules

// Will display title screen (exception handling, will continue to loop if non numbers are entered) (TODO)

void titleScreen()
{
	// Main Screen options

	do // Will continue to loop until user makes a valid selection
	{
		cout << "Please make your selection from the choices below.\n\n";
		cout << "\t1  ----  Play Blackjack.\n";
		cout << "\t2  ----  Rules.\n";
		cout << "\t3  ----  Exit.\n";
		cout << "\nPlease type 1, 2 or 3 and press [ENTER] to continue.\n\n";
		cin >> userSelection;

		switch (userSelection)
		{
		case 1: // Begin the game
			do // Will allow user to play multiple times
			{
				playGame();

				cout << "\nWould you like to play again?  Type \'1\' for yes and \'0\' for no.\n";
				cout << "Press [ENTER] after choice.\t";
				cin >> playAgain;

				if (playAgain == 1)
				{
					cout << "\nGet ready.\n" << "Cards are being shuffled.\n";
					playerChoice = true;
				}

				else if (playAgain == 0)
				{
					cout << "\nThank you for playing BlackJack with us.\n\n";
					playerChoice = false;
					exit(0);
				}
				else
					cout << "\nINVALID ENTRY.\n";

			} while (playerChoice = true); // End while 				
			break;

		case 2: // Show rules
			gameRules();
			break;

		case 3: // Exits the game
			cout << "\nYou have chose to exit the game.  Goodbye.\n\n";
			exit(0);
			break;

		default:
			cout << "Invalid input\n\n";
		} // End switch case
	} while ((userSelection != 1) || (userSelection != 2) || (userSelection != 3));
} // End of titleScreen

// Main Function (Done)

int main()
{
	cout << "Welcome to \n";
	cout << " ____  _            _     _            _        " << endl;
	cout << "| __ )| | __ _  ___| | __(_) __ _  ___| | __    " << endl;
	cout << "|  _  | |/ _` |/ __| |/ /| |/ _` |/ __| |/ /    " << endl;
	cout << "| |_) | | (_| | (__|   < | | (_| | (__|   <     " << endl;
	cout << "|____/|_|\\__,_|\\___|_|\\_\\/ |\\__,_|\\___|_|\\_\\    " << endl;
	cout << "                       |__/                     " << endl;
	cout << "Cheater's Edition\n\n";

	// Winning odds message

	cout << "\tWith this version of blackjack, we like to give the winning edge to the player and not the dealer.\n";
	cout << "\tAfter the first to cards are dealt, we will display the chances of you winning according to you\n";
	cout << "\tand and the dealer's. This game will also allow you to see the all of the deaers card, to better\n";
	cout << "\tyour odds of winning.\n\n";

	titleScreen();

	return 0;
} // End of main function
