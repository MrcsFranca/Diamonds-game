#include <iostream>
#include <iomanip>
#include <climits> 
#include <cmath>
#include <string>
#include <algorithm>
#include <cstdlib>


#define field 7
#define diamantes 7
#define buffs 7
#define obstacles 5

using namespace std;

int k, number_players, rounds, linha, coluna, randomize, guess; 
char coordenadas[13] = {'0','A', 'B', 'C', 'D', 'E', 'F', '1', '2', '3', '4', '5', '6'};
string Board[field][field], player_board[field][field], movement;

void create_board_game() {
    int i, j;
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
}

void create_board_player() {
	int i, j;
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
}

void create_gems() {
    int i = 0;
	while (i < diamantes) {
	    linha = (rand()%6) + 1;
	    coluna = (rand()%6) + 1;
	    if (Board[linha][coluna] != "D") {
    		Board[linha][coluna] = "D";
    		i++;
	    }
	}
}

void create_buffs() {
    int i = 0;
    while (i < buffs) {
	    linha = (rand()%6) + 1;
	    coluna = (rand()%6) + 1;
	    if (Board[linha][coluna] != "D" && Board[linha][coluna] != "O") {
	 	    Board[linha][coluna] = "O";
	 	    i++;
	    }
    }
}

void create_events() {
    int i = 0;
	while (i < obstacles) {
	    linha = (rand()%6) + 1;
	    coluna = (rand()%6) + 1;
	    if (Board[linha][coluna] != "D" && Board[linha][coluna] != "O" && Board[linha][coluna] != "A") {
	        Board[linha][coluna] = "A";
	        i++;
	    }
	}
}

int duplicate(int duplicated) {
	if (duplicated <= 0) {
		cout << "\x1B[35mVocê poderia ter tido seus diamantes duplicados, mas como não tem nada você vai sentar na graxa véia!\033[0m" << endl;
		duplicated -= 3;
		cout << "\x1B[35mVocê vai ficar me devendo 3 diamantes pela incompetência\033[0m" << endl << "- Homem desconhecido" << endl;
		return duplicated;
	} else {
		duplicated = duplicated * 2;
		cout << "\x1B[35mVocê está com sorte! Seus diamantes foram duplicados\033[0m" << endl << "- Homem desconhecido" << endl;
		return duplicated;
	}
	
}

void new_dungeon() {
	int i, j;
	movement = " ";
	cout << "\x1B[35mVocê explodiu uma jazida de diamantes e acabou alterando tudo, vou tirar tudo que você tem por causa disso. A única certeza que você tem é que agora tem mais diamantes para encontrar, mas fique tranquilo, eu vou te dar mais tempo\033[0m" << endl << "- Homem desconhecido" << endl;

	create_board_game();
	
    create_board_player();

	create_gems();
	
    create_buffs();

	create_events();

	while (k < number_players) {
		k++;
	}

	rounds = (pow((field - 1), 2));
}

int quiz(int subtraction) {
	randomize = (rand()%12) + 1;
	cout << "\x1B[35mVocê tem uma chance para acertar o número que eu estou pensando de 1 a 12. Se errar você me deve 3 diamantes\033[0m" << endl << "- Homem desconhecido" << endl;
	while (cin >> guess && (guess > 12 || guess < 1)) {
		cout << "\x1B[35mVocê sabe o que siginifica de 1 a 12 seu imbecil?\033[0m" << endl << "- Homem desconhecido" << endl;
	}
	if (guess == randomize) {
		cout << "\x1B[35mVocê acertou. Não vou tirar seus diamantes\033[0m" << endl << "- Homem desconhecido" << endl;
		subtraction = subtraction - 0;
	} else {
		cout << "\x1B[35mNa verdade eu estava pensando no número " << randomize << ".\033[0m" << endl;
		subtraction = subtraction - 3;
	}
	return subtraction;;
}

int calculate(int sub_sum) {
	int num1, num2, num3, op;
	cout << "\x1B[35mAcerte a conta ou fica devendo 30 diamantes\033[0m" << endl << "- Homem desconhecido" << endl;
	num1 = (rand()%20) + 1;
	num2 = (rand()%10) + 1;
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
			cout << "\x1B[35mEsse jogo ta muito parado. Eu vou fazer vocês pensarem um pouco\033[0m" << endl << "CHEFE DA MINA HAS JOINED THE GAME" << endl;
			num1 = (rand()%30) + 1;
			num2 = (rand()%15) + 1;
			num3 = (rand()%5) + 1;
			cout << "Quanto é " << "(((" << num1 << " * " << num2 << ") / " << num3 << ") + (" << num2 << " * 2 + " << num1 << "))" << " * " << num3 << "? ";
			op = (((num1 * num2) / num3) + (num2 * 2 + num1)) * num3;
			break;
	}
	cin >> guess;
	if (guess == op) {
		cout << "\x1B[35mIsso foi show de bola. Pode continuar tranquilo\033[0m" << endl << "- Homem desconhecido" << endl;
	} else if (guess == op && op == 14) {
		cout << "\x1B[35mPensou bem. Isso merece uma recompensa\033[0m" << endl;
		sub_sum += 30;
	}
	else {
		cout << "\x1B[35mTu vai sentar na graxa véia KKKKKKKK\033[0m" << endl << "- Homem desconhecido" << endl;
		sub_sum -=  30;
	}
	return sub_sum;
}


int main() {
	int i, j, l, moves_pos, win_pos, movement_analysis, amount = 0, maior = INT_MIN;
	string next_round;
	bool discount = false, draw_check = false;

	srand(time(NULL));

	cout << "---------- COMO JOGAR ----------" << endl << "(1) Esse é um jogo baseado em RNG" << endl << "(2) A difuculdade faz parte da aleatoriedade" << endl << "(3) As respostas das contas é apenas a parte inteira do resultado" << endl << "(4) Ações que não estão no escopo do tabuleiro serão consideradas como uma ação para pular a vez" << endl << "(5) Cada ação de um jogador é turno" << endl << endl;

	cout << "Pronto para iniciar o jogo? Digite 'S' para continuar..." << endl;
	while (next_round != "S") {
		cin >> next_round;
		transform(next_round.begin(), next_round.end(), next_round.begin(), ::toupper);
	}
	next_round = " ";

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
	
	rounds = (pow((field - 1), 2));
	moves_pos = rounds * number_players;
	string moves[moves_pos];

    create_board_game();
	
    create_board_player();

    create_gems();
	
    create_buffs();

    create_events();


	rounds--;
	moves_pos--;
	movement_analysis = moves_pos;
	system("clear||cls");
	while (rounds >= 0) {
		cout << "\033[3;43;30m----- PLACAR -----\033[0m" << endl;
		for (i = 0; i < number_players; i++) {
			cout << "\x1B[3" << i + 1 << "m" << players[i] << ":\033[0m " << players_score[i] << endl;
		}
		cout << "Faltam " << rounds + 1 << " rodadas para acabar o jogo" << endl << endl;

		cout << "Jogadas realizadas: ";
		for (i = movement_analysis; i >= moves_pos; i--) {
			cout << moves[i] << ' ';
		}
		cout << endl;

		cout << "\033[3;43;30m----- TABULEIRO -----\033[0m" << endl;
		for (i = 0; i < field; i++) {
			for (j = 0;  j < field; j++) {
				cout << setw(9) << player_board[i][j];
			}
			cout << endl;
		}
		cout << endl;
		
		for (k = 0; k < number_players; k++) {
			cout << "\x1B[3" << k + 1 << "m" << "Ação do jogador " << players[k] << ":\033[0m ";
			cin >> movement;
			transform(movement.begin(), movement.end(), movement.begin(), ::toupper);
			if (discount == true) {
				cout << "\x1B[35mVocê tem que pagar 5 diamantes por não ter conseguido se equilibrar\033[0m" << endl << "- Homem desconhecido" << endl;
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
									cout << "\x1B[35mVocê deu uma rasteira no seu primo" << endl << "Ele tem que pagar 5 diamantes\033[0m" << endl << "- Homem Desconhecido" << endl;
									break;
							}
						} else if (Board[i][j] == "A") {
							randomize = rand()%15;
							switch (randomize) {
								case 0 ... 6:
									players_score[k] = quiz(players_score[k]);
									break;
								case 7 ... 13:
									players_score[k] = calculate(players_score[k]);
									break;
								case 14:
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
			rounds--;
		}

		if (rounds >= 0) {
			cout << "Pronto para o próximo turno? Digite 'S' para continuar..." << endl;
			while (next_round != "S") {
				cin >> next_round;
				transform(next_round.begin(), next_round.end(), next_round.begin(), ::toupper);
			} 
		}
		next_round = " ";
		system("clear||cls");
	}

	cout << "\033[3;43;30m----- PLACAR -----\033[0m" << endl;
	for (i = 0; i < number_players; i++) {
		cout << "\x1B[3" << i + 1 << "m" << players[i] << ":\033[0m " << players_score[i] << endl;
	}

	moves_pos++;
	cout << "Jogadas realizadas: ";
	for (i = movement_analysis; i >= moves_pos; i--) {
		cout << moves[i] << " ";
	}
	cout << endl;
	
	cout << "\033[3;43;30m----- TABULEIRO -----\033[0m" << endl;
	for (i = 0; i < field; i++) {
		for (j = 0;  j < field; j++) {
			cout << setw(9) << player_board[i][j];
		}
		cout << endl;
	}
	cout << endl;
	
	for (i = 0; i < number_players; i++) {
		for (j = 0; j < number_players; j++) {
			if ((players_score[i] == players_score[j]) && (i != j)) {
				draw_check = true;
			}
		}
		if (players_score[i] > maior) {
			maior = players_score[i];
			win_pos = i;
		} else if (players_score[i] == maior) {
			draw_check = true;
		}
	}
	
	if (maior < 0) {
		cout << "\x1B[35mTodos foram incompetentes e ficaram devendo diamantes! Ninguém ganhou.\033[0m" << endl << "- Homem desconhecido" << endl;
	} else if (maior == 0) {
		cout << "\x1B[35mVocês não conseguiram fazer o básico! Como ninguém tem diamantes ninguém ganhou.\033[0m" << endl << "- Homem desconhecido" << endl;
	} else if (draw_check == true && maior <= 0) {
		cout << "\x1B[35mO jogo empatou! Logo, ninguém ganhou.\033[0m" << endl << "- Homem desconhecido" << endl;
	} else {
		cout << "\x1B[35mO jogo chegou ao fim!\033[0m" << endl << "\033[3;43;30mO vencedor é:\033[0m \x1B[3" << win_pos + 1 << "m" << players[win_pos] << "\033[0m com \033[3;104;30m" << players_score[win_pos] << " quilates\033[0m" << endl << "- Homem desconhecido" << endl;
	}
}