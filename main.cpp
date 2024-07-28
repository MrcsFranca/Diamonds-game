#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>

#define matriz 7
#define dicas 2
#define obstaculos1 3
#define obstaculos2 2
#define diamantes 7

using namespace std;

int main() {
	int i, j, number_players, rounds; 
	char coordenadas[14] = {'0','A', 'B', 'C', 'D', 'E', 'F', '1', '2', '3', '4', '5', '6'};
	string A[matriz][matriz], move;

	srand(time(NULL));

	cout << "quantos jogadores? (2, 3 ou 4) ";
	cin >> number_players;
	int players[number_players] = {0};
	
	rounds = (pow((matriz - 1), 2));


	// criação da matriz
	for (i = 0; i < matriz; i++) {
		for (j = 0; j < matriz; j++) {
			if (i == 0) {
				A[i][j] = coordenadas[j];
			} else if (j == 0) {
				A[i][j] = coordenadas[i + 6];
			} else {
				A[i][j] = A[0][j] + A[i][0];
			}
		}
	}


	// criação dos diamantes
	for (i = 0; i < diamantes; i++) {
		A[(rand()%6) + 1][(rand()%6) + 1] = "D";
	}

	// // criação de dicas
	// for (i = 0; i < dicas; i++) {
	// 	A[(rand()%6) + 1][(rand()%6) + 1] = 'O';
	// }

	// // criação do primeiro tipo de obstaculo
	// for (i = 0; i < obstaculos1; i++) {
	// 	A[(rand()%6) + 1][(rand()%6) + 1] = 'A';
	// }

	// // criação do segundo tipo de obstaculo
	// for (i = 0; i < obstaculos1; i++) {
	// 	A[(rand()%6) + 1][(rand()%6) + 1] = 'a';
	// }


	// jogo
	while (rounds--) {
		//imprimir placar
		cout << "----- PLACAR -----" << endl;
		for (i = 0; i < number_players; i++) {
			cout << "Jogador" << i + 1 << ": " << players[i] << endl;
		}
		cout << "Faltam " << rounds + 1 << " para acabar o jogo" << endl;

		// imprimir matriz
		cout << "----- TABULEIRO -----" << endl;
		for (i = 0; i < matriz; i++) {
			for (j = 0;  j < matriz; j++) {
				cout << setw(9) << A[i][j];
			}
			cout << endl;
		}

		for (i = 0; i < number_players; i++) {
			cout << "Ação do jogador" << i + 1 << ": ";
			cin >> move;
			cout << endl;
		}
	}
}