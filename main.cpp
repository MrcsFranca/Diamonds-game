#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>

#define matriz 7
#define diamantes 7
#define dicas 2
#define obstaculos1 3
#define obstaculos2 2

using namespace std;

int main() {
	int i, j, k, number_players, rounds, random, linha, coluna; 
	char coordenadas[14] = {'0','A', 'B', 'C', 'D', 'E', 'F', '1', '2', '3', '4', '5', '6'};
	string Board[matriz][matriz], player_board[matriz][matriz], moves[36], move;


	srand(time(NULL));

	// criação dos jogadores
	cout << "Quantos jogadores? (2, 3 ou 4) ";
	while (cin >> number_players && number_players != 2 && number_players != 3 && number_players != 4) {
		cout << "\033[3;41;30mnúmero de jogadores inválido! \033[0m" << endl;
	}
	int players_score[number_players] = {0};
	string players[number_players];

	for (i = 0; i < number_players; i++) {
		cin >> players[i];
	}
	for (i = 0; i < number_players; i++) {
		cout << players[i] << endl;
	}
	
	rounds = (pow((matriz - 1), 2));
	

	// criação da matriz do jogo
	for (i = 0; i < matriz; i++) {
		for (j = 0; j < matriz; j++) {
			if (i == 0) {
				Board[i][j] = coordenadas[j];
			} else if (j == 0) {
				Board[i][j] = coordenadas[i + 6];
			} else {
				Board[i][j] = "--";
			}
		}
	}
	
	// criação da matriz do jogador
	for (i = 0; i < matriz; i++) {
        for (j = 0; j < matriz; j++) {
	    	if (i == 0) {
				player_board[i][j] = coordenadas[j];
			} else if (j == 0) {
				player_board[i][j] = coordenadas[i + 6];
			} else {
				player_board[i][j] = player_board[0][j] + player_board[i][0];
			}
		}
	}


	// criação dos diamantes
	i = 0;
	while (i < diamantes) {
	    linha = (rand()%6) + 1;
	    coluna = (rand()%6) + 1;
	    if (Board[linha][coluna] != "D") {
    		Board[linha][coluna] = "D";
    		i++;
	    }
	}
	
    // criação de dicas
    i = 0;
    while (i < dicas) {
	    linha = (rand()%6) + 1;
	    coluna = (rand()%6) + 1;
	    if (Board[linha][coluna] != "D" && Board[linha][coluna] != "O") {
	 	    Board[linha][coluna] = "O";
	 	    i++;
	    }
    }

	// criação do primeiro tipo de obstaculo
	i = 0;
	while (i < obstaculos1) {
	    linha = (rand()%6) + 1;
	    coluna = (rand()%6) + 1;
	    if (Board[linha][coluna] != "D" && Board[linha][coluna] != "O" && Board[linha][coluna] != "A") {
	        Board[linha][coluna] = "A";
	        i++;
	    }
	}

	// // criação do segundo tipo de obstaculo
	i = 0;
	while (i < obstaculos2) {
	    linha = (rand()%6) + 1;
	    coluna = (rand()%6) + 1;
	    if (Board[linha][coluna] != "D" && Board[linha][coluna] != "O" && Board[linha][coluna] != "A" && Board[linha][coluna] != "a") {
	        Board[linha][coluna] = "a";
	        i++;
	    }
	}


	// jogo
	while (rounds--) {
		//imprimir placar
		cout << "\033[3;43;30m----- PLACAR -----\033[0m" << endl;
		for (i = 0; i < number_players; i++) {
			cout << "\x1B[3" << i + 1 << "m" << players[i] << ":\033[0m " << players_score[i] << endl;
		}
		cout << "Faltam " << rounds + 1 << " rodadas para acabar o jogo" << endl;

		// imprimir tabuleiro
		cout << "\033[3;43;30m----- TABULEIRO -----\033[0m" << endl;
		for (i = 0; i < matriz; i++) {
			for (j = 0;  j < matriz; j++) {
				cout << setw(9) << Board[i][j];
			}
			cout << endl;
		}

		// imprimir tabuleiro do jogador
		cout << endl << endl;
		for (i = 0; i < matriz; i++) {
			for (j = 0;  j < matriz; j++) {
				cout << setw(9) << player_board[i][j];
			}
			cout << endl;
		}
		cout << endl;
		

		// Ação do jogador
		for (k = 0; k < number_players; k++) {
			cout << "\x1B[3" << k + 1 << "m" << "Ação do jogador " << players[k] << ":\033[0m ";
			cin >> move;
			for (i = 0; i < matriz; i++) {
			    for (j = 0; j < matriz; j++) {
			        if (move == player_board[i][j]) {
						moves[rounds - 1] = move;
			            player_board[i][j] = Board[i][j];
						if (Board[i][j] == "D") {
							players_score[k]++;
						}
			        }
			    }
			}
			cout << endl;
		}
	}
}
