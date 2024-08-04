#include <iostream>
#include <iomanip> //setw
// #include <ctime> 
#include <cmath> //power
#include <string> //getline
#include <algorithm> //transform
#include <cstdlib> //begin e end para usar no transform


#define field 7
#define diamantes 7
#define buffs 7
#define obstacles 5

using namespace std;

int i, j, k, l, movement_analysis, number_players, rounds, linha, coluna, amount = 0, moves_pos, randomize, guess; 
char coordenadas[13] = {'0','A', 'B', 'C', 'D', 'E', 'F', '1', '2', '3', '4', '5', '6'};
string Board[field][field], player_board[field][field], movement, next_round;
bool discount = false;


int duplicate(int duplicated) {
	if (duplicated == 0) {
		cout << "Você poderia ter tido seus diamantes duplicados, mas como não tem nada você vai sentar na graxa véia!" << endl;
		duplicated -= 3;
		cout << "Você vai ficar me devendo 3 diamantes pela incompetência" << endl << "- Homem desconhecido" << endl;
		return duplicated;
	} else {
		duplicated = duplicated * 2;
		cout << "Você está com sorte!" << endl << "Seus diamantes foram duplicados" << endl << "- Homem desconhecido" << endl;
		return duplicated;
	}
	
}

void new_dungeon() {
	movement = " ";
	cout << "Você explodiu uma jazida de diamantes e acabou alterando tudo, vou tirar tudo que você tem por causa disso. A única certeza que você tem é que agora tem mais diamantes para encontrar, mas fique tranquilo, eu vou te dar mais tempo" << endl << "- Homem desconhecido" << endl;

	// criação da matriz do jogo
	for (i = 0; i < field; i++) {
		for (j = 0; j < field; j++) {
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
	for (i = 0; i < field; i++) {
        for (j = 0; j < field; j++) {
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
	while (i < (diamantes * 2)) {
	    linha = (rand()%6) + 1;
	    coluna = (rand()%6) + 1;
	    if (Board[linha][coluna] != "D") {
    		Board[linha][coluna] = "D";
    		i++;
	    }
	}
	
    // criação de buffs
    i = 0;
    while (i < buffs) {
	    linha = (rand()%6) + 1;
	    coluna = (rand()%6) + 1;
	    if (Board[linha][coluna] != "D" && Board[linha][coluna] != "O") {
	 	    Board[linha][coluna] = "O";
	 	    i++;
	    }
    }

	// criação do primeiro tipo de obstaculo
	i = 0;
	while (i < obstacles) {
	    linha = (rand()%6) + 1;
	    coluna = (rand()%6) + 1;
	    if (Board[linha][coluna] != "D" && Board[linha][coluna] != "O" && Board[linha][coluna] != "A") {
	        Board[linha][coluna] = "A";
	        i++;
	    }
	}

	while (k < number_players) {
		k++;
	}

	//rounds = (pow((field - 1), 2));
	rounds = 3;
}

int quiz(int subtraction) {
	randomize = (rand()%12) + 1;
	cout << "Você tem uma chance para acertar o número que eu estou pensando de 1 a 12. Se errar você me deve 10 diamantes" << endl << "- Homem desconhecido" << endl;
	while (cin >> guess && (guess > 12 || guess < 1)) {
		cout << "Você sabe o que siginifica de 1 a 12 seu imbecil?" << endl << "- Homem desconhecido" << endl;
	}
	if (guess == randomize) {
		cout << "Você acertou. Não vou tirar seus diamantes" << endl << "- Homem desconhecido" << endl;
		subtraction = subtraction - 0;
	} else {
		cout << "Na verdade eu estava pensando no número " << randomize << "." << endl;
		subtraction = subtraction - 10;
	}
	return subtraction;;
}

int calculate(int subtraction) {
	int num1, num2, num3, op;
	cout << "Acerte a conta ou fica devendo 30 diamantes" << endl << "- Homem desconhecido" << endl;
	num1 = (rand()%20) + 1;
	num2 = (rand()%3) + 1;
	num3 = (rand()%2) + 1;
	op = rand()%15;
	switch(op) {
		case 0 ... 6:
			cout << "Quanto é " << num1 << " + " << num2  << " / " << num3 << "? ";
			op = (num1 + num2) / num3;
			break;
		case 7 ... 12:
			cout << "Quanto é " << num1 << " * " << "(" << num2  << " + " << num3 << ")" << "? ";
			op = num1 * (num2 + num3);
			break;
		case 13:
			cout << "Quanto é " << num1 << " + " << num2  << " + " << num3 << "? ";
			op = (num1 + num2) + num3;
			break;
		case 14:
			cout << "Quanto é " << "(((" << num1 << " X " << num2 << ") / " << num3 << ") + (" << num2 << " * 2 + " << num1 << "))" << "*" << num3 << "? ";
			op = (((num1 * num2) / num3) + (num2 * 2 + num1)) * num3;
			break;
	}
	cin >> guess;
	if (guess == op) {
		cout << "Isso foi show de bola. Pode continuar tranquilo" << endl << "- Homem desconhecido" << endl;
	} else {
		cout << "Tu vai sentar na graxa véia KKKKKKKK" << endl << "- Homem desconhecido" << endl;
		subtraction = subtraction - 30;
	}
	return subtraction;
}


int main() {
	srand(time(NULL));

	// criação dos jogadores
	cout << "Quantos jogadores? (2, 3 ou 4) ";
	while (cin >> number_players && number_players != 2 && number_players != 3 && number_players != 4) {
		cout << "\033[3;41;30mnúmero de jogadores inválido! Digite um número aceitável \033[0m" << endl;
	}
	int players_score[number_players] = {0};
	string players[number_players];

	for (i = 0; i < number_players; i++) {
		cout << "\x1B[3" << i + 1 << "m" << "Nome do jogador " << i + 1 << ": \033[0m";
		while (players[i] == "") {
			getline(cin, players[i]);
		}
	}
	cout << endl;
	
	//rounds = (pow((field - 1), 2));
	rounds = 3;
	moves_pos = rounds * number_players;
	string moves[moves_pos];

	// criação da matriz do jogo
	for (i = 0; i < field; i++) {
		for (j = 0; j < field; j++) {
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
	for (i = 0; i < field; i++) {
        for (j = 0; j < field; j++) {
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
	
    // criação de buffs
    i = 0;
    while (i < buffs) {
	    linha = (rand()%6) + 1;
	    coluna = (rand()%6) + 1;
	    if (Board[linha][coluna] != "D" && Board[linha][coluna] != "O") {
	 	    Board[linha][coluna] = "O";
	 	    i++;
	    }
    }

	// criação de obstaculo
	i = 0;
	while (i < obstacles) {
	    linha = (rand()%6) + 1;
	    coluna = (rand()%6) + 1;
	    if (Board[linha][coluna] != "D" && Board[linha][coluna] != "O" && Board[linha][coluna] != "A") {
	        Board[linha][coluna] = "A";
	        i++;
	    }
	}


	// jogo
	rounds--;
	moves_pos--;
	movement_analysis = moves_pos;
	while (rounds >= 0) {
		//imprimir placar
		cout << "\033[3;43;30m----- PLACAR -----\033[0m" << endl;
		for (i = 0; i < number_players; i++) {
			cout << "\x1B[3" << i + 1 << "m" << players[i] << ":\033[0m " << players_score[i] << endl;
		}
		cout << "Faltam " << rounds + 1 << " rodadas para acabar o jogo" << endl << endl;

		// jogadas já realizadas
		cout << "Jogadas realizadas: ";
		for (i = movement_analysis; i >= moves_pos; i--) {
			cout << moves[i] << ' ';
		}
		cout << endl;

		// imprimir tabuleiro
		cout << "\033[3;43;30m----- TABULEIRO -----\033[0m";
		cout << endl;
		for (i = 0; i < field; i++) {
			for (j = 0;  j < field; j++) {
				cout << setw(9) << Board[i][j];
			}
			cout << endl;
		}

		// imprimir tabuleiro do jogador
		cout << endl << endl;
		for (i = 0; i < field; i++) {
			for (j = 0;  j < field; j++) {
				cout << setw(9) << player_board[i][j];
			}
			cout << endl;
		}
		cout << endl;
		

		// Ação do jogador
		for (k = 0; k < number_players; k++) {
			cout << "\x1B[3" << k + 1 << "m" << "Ação do jogador " << players[k] << ":\033[0m ";
			cin >> movement;
			transform(movement.begin(), movement.end(), movement.begin(), ::toupper);
			if (discount == true) {
				cout << "Você tem que pagar 5 diamantes por não ter conseguido se equilibrar" << endl << "- Homem desconhecido" << endl;
				players_score[k] += -5;
				discount = false;
			}
			for (i = 0; i < field; i++) {
			    for (j = 0; j < field; j++) {
			        if (movement == player_board[i][j]) {
						moves[moves_pos] = movement;
			            player_board[i][j] = Board[i][j];
						if (Board[i][j] == "D") {
							amount = (rand()%10) + 1;
							players_score[k] += amount;
							cout << "\x1B[3" << k + 1 << "m" << players[k] << " encontrou " << amount << " quilates:\033[0m ";
							cout << endl;
						} else if (Board[i][j] == "O") {
							randomize = rand()%5;
							switch (randomize) {
								case 0 ... 2:
									players_score[k] = duplicate(players_score[k]);
									break;
								case 3 ... 4:
									discount = true;
									cout << "Você deu uma rasteira no seu primo" << endl << "Ele tem que pagar 5 diamantes" << endl << "- Homem Desconhecido" << endl;
									break;
							}
						} else if (Board[i][j] == "A") {
							randomize = rand()%15;
							switch (randomize) {
								case 0 ... 6:
									players_score[k] = quiz(players_score[k]);
									break;
								case 7 ... 11:
									players_score[k] = calculate(players_score[k]);
									break;
								case 12 ... 14:
									new_dungeon();
									for (l = movement_analysis; l >= moves_pos; l--) {
										moves[l] = "";
									}
									moves_pos = movement_analysis + 1;
									for (l = 0; l < number_players; l++) {
										players_score[l] = 0;
									}
									break;
							}
						}
						moves_pos--;
			        }
			    }
			}
		}

		rounds--;
		if (rounds >= 0) {
			cout << "Pronto para o próximo turno? Digite 'S' para continuar..." << endl;
			while (next_round != "S") {
			cin >> next_round;
			transform(next_round.begin(), next_round.end(), next_round.begin(), ::toupper);
			} 
		} else {
			cout << "Você não tem mais turnos para jogar" << endl;
		}
		next_round = " ";
		//system("clear||cls");
	}


	//imprimir placar final
	cout << "\033[3;43;30m----- PLACAR -----\033[0m" << endl;
	for (i = 0; i < number_players; i++) {
		cout << "\x1B[3" << i + 1 << "m" << players[i] << ":\033[0m " << players_score[i] << endl;
	}

	// jogadas já realizadas
	moves_pos++;
	cout << "Jogadas realizadas: ";
	for (i = 5; i >= moves_pos; i--) {
		cout << moves[i] << " ";
	}
	cout << endl;
	
	//imprimir tabuleiro final
	cout << "\033[3;43;30m----- TABULEIRO -----\033[0m" << endl;
	for (i = 0; i < field; i++) {
		for (j = 0;  j < field; j++) {
			cout << setw(9) << player_board[i][j];
		}
		cout << endl;
	}
	cout << endl;
	
	//resultado do jogo
	cout << "O jogo chegou ao fim!" << endl;
}