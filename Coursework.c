#include <stdio.h>
#include <string.h>

#define MAX 100

// Unused board array 
char arr[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

int game = 1;

// Game structure - details of games 
struct game {
	int game;
	char p1[20];
	char p2[20];
	char winner[20];
	int choice[100];
	int XOrO[100];
	int goes;
};

void start();
int check();
void board();
void theGame();
void replay();

// Array of game struct - for saving details of games 
struct game arr_game[MAX];

int main() { 
	
	char again[10];
	int loop = 1;
	char str1[100];
	
	printf("\n Lets play Noughts & Crosses!!! ");
	
	start();
	theGame();
	
	do {
		printf("\n\n Play Again? (1):  ");
		printf("\n Replay Games? (2):  ");
		printf("\n Exit? (3):  ");
		
		int theChoice;
		scanf("%[^0-9]%d",str1,&theChoice);
		
		if(theChoice == 1) {
			printf("\n");
			theGame();
		}
		else if(theChoice == 2)	{
			
			printf("\n\n                       Games\n");
			
			// Display the players and winner of all games that have been played
			for(int h = 1; h < game; h++) {
				printf("\n Game: %d   Player 1: %s   Player 2: %s   Winner: %s", arr_game[h].game, arr_game[h].p1, arr_game[h].p2, arr_game[h].winner);
			}	
			
			// Get which game the player would like to see 
			printf("\n\n Pick A Game: ");
			int chosenGame;
			scanf("%[^0-9]%d",str1,&chosenGame);
			replay(chosenGame);
		}
		else if(theChoice == 3)	{
			loop = 0;
			printf("\n\n Thanks for playing!\n");	
		}
		
	} while(loop == 1);
}

// The game 
void theGame() {

    // Resets the board	
	arr[0] = '1';
	arr[1] = '2';
	arr[2] = '3';
	arr[3] = '4';
	arr[4] = '5';
	arr[5] = '6';
	arr[6] = '7';
	arr[7] = '8';
	arr[8] = '9';
	
	char player1[20];
	char player2[20];
	
	// Get the first players name
	printf("\n Player 1 please enter your name:  ");
	scanf("%s", &player1);
	
	// Get the second players name
	printf("\n Player 2 please enter your name:  ");
	scanf("%s", &player2);
	
	printf("\n Hello %s and %s, Lets Play!\n\n", player1, player2);
	
	printf(" %s (X)  -  %s (O)\n\n", player1, player2);
	
	board();
		
	int num1;
	int num2;
	int theGo = 1;
	char str[100];
	int i;
	int j;
	int invalid1 = 0;
	int invalid2 = 0;
	int in1 = 0;
	int in2 = 0;
	
	do {	
		do {
			invalid1 = 0;
			in1 = 0;
			
			// Get the players choice of move
			printf("\n %s please pick a number:  ", player1);
			scanf("%[^0-9]%d",str,&num1);												
		
			if (num1 == 1 && arr[0] == '1')
				arr[0] = 'X';
			
			else if (num1 == 2 && arr[1] == '2')
				arr[1] = 'X';
            
			else if (num1 == 3 && arr[2] == '3')
				arr[2] = 'X';
				
			else if (num1 == 4 && arr[3] == '4')
				arr[3] = 'X';
            
			else if (num1 == 5 && arr[4] == '5')
				arr[4] = 'X';
            
			else if (num1 == 6 && arr[5] == '6')
				arr[5] = 'X';
            
			else if (num1 == 7 && arr[6] == '7')
				arr[6] = 'X';
            
			else if (num1 == 8 && arr[7] == '8')
				arr[7] = 'X';
            
			else if (num1 == 9 && arr[8] == '9')
				arr[8] = 'X';
			
			else {
				printf("\n Invalid Move (X): %d\n\n", num1);
				invalid1 = 1;
				in1 = 1;
			}
			
			// Save the players choice and whether they are X or O to the struct array
		    	arr_game[game].choice[theGo] = num1;
			arr_game[game].XOrO[theGo] = 1;	
			
			theGo++;	

			printf("\n %s (X)  -  %s (O)\n\n", player1, player2);
		
			board();
		
			i = check();
		
			// Checks if player 1 has won
			if (i != - 1) {
				break;
			}

			if (in1 == 0) {
				int undo1;
				printf("\n Undo Move (1 = Yes)(Any Other Number To Continue): ");
				scanf("%[^0-9]%d",str,&undo1);
		
				// Undos the players move
				if(undo1 == 1) {
					invalid1 = 1;
					char c = arr_game[game].choice[theGo-1] + '0'; 
					arr[arr_game[game].choice[theGo-1] - 1] = c;
			
					// Save the players choice and whether they are X or O to the struct array
					arr_game[game].choice[theGo] = 10;
					arr_game[game].XOrO[theGo] = 1;		
			
					theGo++;
			
					printf("\n %s (X)  -  %s (O)\n\n", player1, player2);
		
					board();
			
					int redo1;
					printf("\n Redo Move (1 = Yes)(Any Other Number To Continue): ");
					scanf("%[^0-9]%d",str,&redo1);
		
					// Redos the players move
					if(redo1 == 1) {
						invalid1 = 0;
						arr[arr_game[game].choice[theGo-2] - 1] = 'X';
			
						// Save the players choice and whether they are X or O to the struct array
						arr_game[game].choice[theGo] = 11;
						arr_game[game].XOrO[theGo] = 1;		
			
						theGo++;
			
						printf("\n %s (X)  -  %s (O)\n\n", player1, player2);
		
						board();
					}
				}
			}
			
		}while(invalid1 == 1);
		
		i = check();
		
		// Checks if player 1 has won
		if (i != - 1) {
			break;
		}		
		
		do {
			invalid2 = 0;
			in2 = 0;
			
			// Get the players choice of move
			printf("\n %s please pick a number:  ", player2);	
			scanf("%[^0-9]%d",str,&num2);
		
			if (num2 == 1 && arr[0] == '1')
				arr[0] = 'O';
			
			else if (num2 == 2 && arr[1] == '2')
				arr[1] = 'O';
            
			else if (num2 == 3 && arr[2] == '3')
				arr[2] = 'O';
            
			else if (num2 == 4 && arr[3] == '4')
				arr[3] = 'O';
            
			else if (num2 == 5 && arr[4] == '5')
				arr[4] = 'O';
            
			else if (num2 == 6 && arr[5] == '6')
				arr[5] = 'O';
            
			else if (num2 == 7 && arr[6] == '7')
				arr[6] = 'O';
            
			else if (num2 == 8 && arr[7] == '8')
				arr[7] = 'O';
            
			else if (num2 == 9 && arr[8] == '9')
				arr[8] = 'O';
            
			else {
				printf("\n Invalid Move (O): %d\n\n", num2);	
				invalid2 = 1;
				in2 = 1;
			}
			
			// Save the players choice and whether they are X or O to the struct array
		    	arr_game[game].choice[theGo] = num2;
			arr_game[game].XOrO[theGo] = 2;
			
			theGo++;
			
			printf("\n %s (X)  -  %s (O)\n\n", player1, player2);
	
			board();
			
			j = check();
		
			// Checks if player 2 has won
			if (j != - 1) {
				break;
			}
			
			if (in2 == 0) {
				int undo2;
				printf("\n Undo Move (1 = Yes)(Any Other Number To Continue): ");
				scanf("%[^0-9]%d",str,&undo2);
		
				// Undos the players move
				if(undo2 == 1) {
					invalid2 = 1;
					char c = arr_game[game].choice[theGo-1] + '0';
					arr[arr_game[game].choice[theGo-1] - 1] = c; 			
			
					// Save the players choice and whether they are X or O to the struct array
					arr_game[game].choice[theGo] = 10;
					arr_game[game].XOrO[theGo] = 2;		
			
					theGo++;
			
					printf("\n\n %s (X)  -  %s (O)\n\n", player1, player2);
		
					board();
			
					int redo2;
					printf("\n Redo Move (1 = Yes)(Any Other Number To Continue): ");
					scanf("%[^0-9]%d",str,&redo2);
		
					// Redos the players move
					if(redo2 == 1) {	
						invalid2 = 0; 
						arr[arr_game[game].choice[theGo-2] - 1] = 'O';
			
						// Save the players choice and whether they are X or O to the struct array
						arr_game[game].choice[theGo] = 11;
						arr_game[game].XOrO[theGo] = 2;		
			
						theGo++;
			
						printf("\n %s (X)  -  %s (O)\n\n", player1, player2);
		
						board();
					}
				}
			}
					
		}while(invalid2 == 1);		
		
	}while(j == - 1);
		
	char winner[20];
	
	// Checks which player has won or if the game was a draw
    	if (i == 1) {
		printf(" Player %s wins!!!\n", player1);
		strcpy(winner, player1);
	}
	else if (j == 1) {
		printf(" Player %s wins!!!\n", player2);
		strcpy(winner, player1);
	}
    	else {
        	printf(" The Game is a draw...\n");	
		strcpy(winner, "Draw");
	}
	
	// Saves the game, the players names, the winner and the number of goes to the struct array
	arr_game[game].game = game;
	strcpy(arr_game[game].p1, player1);
	strcpy(arr_game[game].p2, player2);
	strcpy(arr_game[game].winner, winner);
	arr_game[game].goes = theGo;
	
	game++;
}

// Starts the game if enter is pressed
void start() {
	
	printf(" Press enter to continue:\n");
	int enter = 0;
	
	// Continue if enter is pressed
	while (enter != '\r' && enter != '\n') { 
		enter = getchar(); 
	}	
}

// Replays chosen games
void replay(int chosenGame) {
	
	// Resets the board
	arr[0] = '1';
	arr[1] = '2';
	arr[2] = '3';
	arr[3] = '4';
	arr[4] = '5';
	arr[5] = '6';
	arr[6] = '7';
	arr[7] = '8';
	arr[8] = '9';
	
	char p1[20];
	char p2[20];
	
	// Gets the players names and the number of goes from the chosen game
	strcpy(p1, arr_game[chosenGame].p1);
	strcpy(p2, arr_game[chosenGame].p2);
	int numGoes = arr_game[chosenGame].goes;
	
	// Replays the chosen game
	for(int go = 1; go < numGoes; go++) {
		
		printf("\n %s (X)  -  %s (O)\n\n", p1, p2);
		
		// Gets the players choice of move
		int move = arr_game[chosenGame].choice[go];
		
		// Displays the 'X' player moves
		if(arr_game[chosenGame].XOrO[go] == 1) {			
			if (move == 1 && arr[0] == '1') {
				arr[0] = 'X';
				board();
			} else if (move == 2 && arr[1] == '2') {
				arr[1] = 'X';
				board();	
			} else if (move == 3 && arr[2] == '3') {
				arr[2] = 'X'; 
				board();
			} else if (move == 4 && arr[3] == '4') {
				arr[3] = 'X'; 
				board();	
			} else if (move == 5 && arr[4] == '5') {
				arr[4] = 'X';  
				board();				
			} else if (move == 6 && arr[5] == '6') {
				arr[5] = 'X';
				board();				
			} else if (move == 7 && arr[6] == '7') {
				arr[6] = 'X'; 
				board();				
			} else if (move == 8 && arr[7] == '8') {
				arr[7] = 'X'; 
				board();				
			} else if (move == 9 && arr[8] == '9') {
				arr[8] = 'X'; 
				board();				
			} else if (move == 10) {
				printf(" Previous Move Undid\n\n");
				char c = arr_game[chosenGame].choice[go-1] + '0';
				arr[arr_game[chosenGame].choice[go-1] - 1] = c; 
				board();				
			} else if (move == 11) {
				printf(" Previous Move Redid\n\n");
				arr[arr_game[chosenGame].choice[go-2] - 1] = 'X'; 
				board();				
			} else {
				printf(" Invalid Move (X): %d\n", move);	
			}	
		// Displays the 'O' players moves	
		} else if(arr_game[chosenGame].XOrO[go] == 2) {
			
			if (move == 1 && arr[0] == '1') {
				arr[0] = 'O';
				board();
			} else if (move == 2 && arr[1] == '2') {
				arr[1] = 'O';
				board();	
			} else if (move == 3 && arr[2] == '3') {
				arr[2] = 'O'; 
				board();
			} else if (move == 4 && arr[3] == '4') {
				arr[3] = 'O'; 
				board();	
			} else if (move == 5 && arr[4] == '5') {
				arr[4] = 'O';  
				board();				
			} else if (move == 6 && arr[5] == '6') {
				arr[5] = 'O';
				board();				
			} else if (move == 7 && arr[6] == '7') {
				arr[6] = 'O'; 
				board();				
			} else if (move == 8 && arr[7] == '8') {
				arr[7] = 'O'; 
				board();				
			} else if (move == 9 && arr[8] == '9') {
				arr[8] = 'O'; 
				board();				
			} else if (move == 10) {
				printf(" Previous Move Undid\n\n");
				char ch = arr_game[chosenGame].choice[go-1] + '0';
				arr[arr_game[chosenGame].choice[go-1] - 1] = ch;
				board();
			} else if (move == 11) {
				printf(" Previous Move Redid\n\n");
				arr[arr_game[chosenGame].choice[go-2] - 1] = 'O'; 
				board();				
			} else {
				printf(" Invalid Move (O): %d\n", move);	
			}		
		}	
		
		printf("\n");
	}	
}

// The game board
void board() {
	
	printf("           |           |\n");		
	printf("     %c     |     %c     |      %c\n", arr[0], arr[1], arr[2]);
	printf("           |           |\n");		
	
	for (int i=0; i<36; i++) {
		printf("-");
	}
	printf("\n");
	
	printf("           |           |\n");		
	printf("     %c     |     %c     |      %c\n", arr[3], arr[4], arr[5]);
	printf("           |           |\n");
	
	for (int i=0; i<36; i++) {
		printf("-");
	}
	printf("\n");
	
	printf("           |           |\n");		
	printf("     %c     |     %c     |      %c\n", arr[6], arr[7], arr[8]);
	printf("           |           |\n");
}

// Checks if the game is won or a draw
int check() {
	
    if (arr[0] == arr[1] && arr[1] == arr[2])
        return 1;
        
    else if (arr[3] == arr[4] && arr[4] == arr[5])
        return 1;
        
    else if (arr[6] == arr[7] && arr[7] == arr[8])
        return 1;
        
    else if (arr[0] == arr[3] && arr[3] == arr[6])
        return 1;
        
    else if (arr[1] == arr[4] && arr[4] == arr[7])
        return 1;
        
    else if (arr[2] == arr[5] && arr[5] == arr[8])
        return 1;
        
    else if (arr[0] == arr[4] && arr[4] == arr[8])
        return 1;
        
    else if (arr[2] == arr[4] && arr[4] == arr[6])
        return 1;
        
    else if (arr[0] != '1' && arr[1] != '2' && arr[2] != '3' &&
        arr[3] != '4' && arr[4] != '5' && arr[5] != '6' && arr[6] 
        != '7' && arr[7] != '8' && arr[8] != '9')

	// Game is a draw
        return 0;
    else
	// Game is not finshed yet
        return  - 1;
}



