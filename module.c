#include "header.h"



int sum_status = 0;
int Num_of_player;
int deck[52];
enum j_q_k_a { J = 10, Q = 10, K = 10, A = 11 };
//------------------------------------------------
struct player {
	char name[80];
	int card[5];
	int turn;
	int sum;
	int status; //0=on going, 1 = win, 2 = loose
};
struct player* p;
struct player dealer;
//------------------------------------------------
void creat_deck() {
	int location = 0;
	for (int j = 1; j <= 4; j++) {
		for (int i = 2; i <= 10; i++) {
			deck[location] = i;
			location++;
		}
	}
	for (int i = 1; i <= 4; i++) {
		deck[location] = J;
		location++;
	}
	for (int i = 1; i <= 4; i++) {
		deck[location] = Q;
		location++;
	}
	for (int i = 1; i <= 4; i++) {
		deck[location] = K;
		location++;
	}
	for (int i = 1; i <= 4; i++) {
		deck[location] = A;
		location++;
	}
}
//------------------------------------------------
void Display_menu() {
	printf("\t\t\t\t\t**************************\n");
	printf("\t\t\t\t\t*   THE BLACKJACK GAME   *\n");
	printf("\t\t\t\t\t*  Creator: Vincent Bui  *\n");
	printf("\t\t\t\t\t*                        *\n");
	printf("\t\t\t\t\t*  PLAY: press 1         *\n");
	printf("\t\t\t\t\t*  RULE: press 2         *\n");
	printf("\t\t\t\t\t*  QUIT: press 0         *\n");
	printf("\t\t\t\t\t**************************\n");
}
//-------------------------------------------------
void rule() {
	system("cls");
	printf("                  BLACKJACK RULE!!!\n");
	printf("1. First enter the number of player and name of player.\n");
	printf("2. Your goal is to get as much score as possible in the range from 16 to 21\n");
	printf("3. Each player, including the dealer, first get 2 cards.\n");
	printf("4. J, Q, K have value of 10. A (Ace) has value of 11.\n");
	printf("5. If your score is under 16, you have to get more. If your score is over 21, you are busted!\n");
	printf("6. You can either choose to Hit or Stay (1/0)\n");
	printf("7. After everyone has already finished hitting, the dealer the start to get more card if needed.\n");
	printf("8. If you haven't busted and have more points than the dealer, you win. Otherwise, you loose.\n");
	printf("                  LET'S GAMBLING!!!\n\n");
	system("pause");

}
//-------------------------------------------------
void devide_card_begin(struct player *x, struct player *dealer) {
	srand(time(NULL));
	int temp;
	for (int i = 0; i < Num_of_player; i++) {
		for (int j = 0; j < 2; j++) {
		int random = rand() % 52;
		if (deck[random] != 0) {
			temp = deck[random];
			deck[random] = x[i].card[j];
			x[i].card[j] = temp;
		}
		else{
			do {
				random = rand() % 52;
			} while (deck[random] = 0);
			temp = deck[random];
			deck[random] = x[i].card[j];
			x[i].card[j] = temp;
		}
		}
	}

	for (int j = 0; j < 2; j++) {
		for (int j = 0; j < 2; j++) {
			int random = rand() % 52;
			if (deck[random] != 0) {
				temp = deck[random];
				deck[random] = dealer->card[j];
				dealer->card[j] = temp;
			}
			else {
				do {
					random = rand() % 52;
				} while (deck[random] = 0);
				temp = deck[random];
				deck[random] = dealer->card[j];
				dealer->card[j] = temp;
			}
		}
	}
}
//-------------------------------------------------
void update_begin(struct player* x, struct player *dealer) {
	system("cls");
	for (int i = 0; i < Num_of_player; i++) {
		printf("---------------------------\n");
		printf("[%s]! ", x[i].name);
		printf("You have: ");

		for (int j = 0; j < 5; j++) {
			if (x[i].card[j] != 0) {
				printf("%d ", x[i].card[j]);
			}
			else {
				continue;
			}
		}
		p[i].sum = x[i].card[0] + x[i].card[1] + x[i].card[2] + x[i].card[3] + x[i].card[4];
		printf("\nPoints: [%d]\n", x[i].card[0] + x[i].card[1] + x[i].card[2] + x[i].card[3] + x[i].card[4]);
	}
	printf("---------------------------\n");
	printf("[Dealer] has: ");
	for (int j = 0; j < 5; j++) {
		if (dealer->card[j] != 0) {
			printf("%d ", dealer->card[j]);
		}
		else {
			continue;
		}
		
	}
	printf("\nPoints: [%d]\n", dealer->card[0] + dealer->card[1] + dealer->card[2] + dealer->card[3] + dealer->card[4]);
	dealer->sum = dealer->card[0] + dealer->card[1] + dealer->card[2] + dealer->card[3] + dealer->card[4];
	printf("\n");
	printf("\n");
}
//-------------------------------------------------
void update(struct player* p, int i) {
	printf("You have: ");

	for (int j = 0; j < 5; j++) {
		if (p[i].card[j] != 0) {
			printf("%d ", p[i].card[j]);
		}
		else {
			continue;
		}
		p[i].sum = p[i].card[0] + p[i].card[1] + p[i].card[2] + p[i].card[3] + p[i].card[4];
	}
	printf("\nPoints: [%d]\n", p[i].card[0] + p[i].card[1] + p[i].card[2] + p[i].card[3] + p[i].card[4]);
	printf("---------------------\n");
}
//-------------------------------------------------
void hit_stay(struct player *p, struct player *dealer) {
	for (int i = 0; i < Num_of_player; i++) {
		printf("================================\n");
		for (int j = 1; j <= 5; j++) {
			if ((p[i].card[0] + p[i].card[1] + p[i].card[2] + p[i].card[3] + p[i].card[4]) <= 21) {
				int option;
				printf("Hi [%s], you have [%d] points. Do you want to hit or stay? (1/0)\n", p[i].name ,p[i].card[0] + p[i].card[1] + p[i].card[2] + p[i].card[3] + p[i].card[4]);
				scanf("%d", &option);
				if (option == 1) {
					int temp;
					int random = rand() % 52;
					if (deck[random] != 0) {
						temp = deck[random];
						deck[random] = p[i].card[(p[i].turn) + 2];
						p[i].card[(p[i].turn) + 2] = temp;
						(p[i].turn)++;
						update(p, i);
					}
					else {
						while (deck[random] = 0) {
							random = rand() % 52;
						}
						temp = deck[random];
						deck[random] = p[i].card[(p[i].turn) + 2];
						p[i].card[(p[i].turn) + 2] = temp;
						(p[i].turn)++;
						update(p, i);
					}
					
				}
				else {
					break;
				}
			}
			else {
				printf("you are busted!\n");
				p[i].status = 2;
				break;
			}

		}

	}
	printf("==================================\n");
	
	for (int i = 0; i < Num_of_player; i++) {
		sum_status += p[i].status;
	}

	if (sum_status == Num_of_player * 2) {//if both busted
		system("pause");
		return;
	}
	else {
		for (int i = 2; i < 5; i++) {
			if (dealer->sum < 17) {
				int random = rand() % 52;
				if (deck[random] != 0) {
					dealer->card[i] = deck[random];
					dealer->sum = dealer->card[0] + dealer->card[1] + dealer->card[2] + dealer->card[3] + dealer->card[4];

				}
				else {
					do {
						int random = rand() % 52;
					} while (deck[random] = 0);
					dealer->card[i] = deck[random];
				}
			}

			else if (dealer->sum > 21) {
				printf("[Dealer] has: ");
				for (int j = 0; j < 5; j++) {
					if (dealer->card[j] != 0) {
						printf("[%d] ", dealer->card[j]);
					}
					else {
						continue;
					}

				}
				printf("Points: [%d]\n", dealer->card[0] + dealer->card[1] + dealer->card[2] + dealer->card[3] + dealer->card[4]);
				dealer->sum = dealer->card[0] + dealer->card[1] + dealer->card[2] + dealer->card[3] + dealer->card[4];
				for (int i = 0; i < Num_of_player; i++) {
					if (p[i].status != 2) {
						p[i].status = 1;
					}
				}
				printf("The [Dealer] is busted!\n");
				system("pause");
				break;
			}

			else {
				printf("[Dealer] has: ");
				for (int j = 0; j < 5; j++) {
					if (dealer->card[j] != 0) {
						printf("[%d] ", dealer->card[j]);
					}
					else {
						continue;
					}

				}
				printf("\nPoints: [%d]\n", dealer->card[0] + dealer->card[1] + dealer->card[2] + dealer->card[3] + dealer->card[4]);
				dealer->sum = dealer->card[0] + dealer->card[1] + dealer->card[2] + dealer->card[3] + dealer->card[4];
				break;
			}
		}
	}
}
//-------------------------------------------------
void anouncement(struct player* p) {
	printf("======================================\n");
	for (int i = 0; i < Num_of_player; i++) {
		if (p[i].status == 2) {
			printf("Sorry [%s], you lost!\n", p[i].name);
		}
		else {
			printf("congratulation [%s], you won!\n", p[i].name);
		}
	}
}
//-------------------------------------------------
void dealer_work(struct player* p, struct player dealer) {
	for (int i = 0; i < Num_of_player; i++) {
		if (p[i].status == 0) {
			if (p[i].sum > dealer.sum) {
				p[i].status = 1;
			}
			else {
				p[i].status = 2;
			}
		}
	}
}
//-------------------------------------------------
bool play_again() {
	int i;
	printf("Do you want to play again?\n");
	printf(" Yes(1) or No(0)\n");

	scanf("%d", &i);
	if (i == 1) {
		return true;
	}
	else {
		return false;
	}
}
//-------------------------------------------------
void play() {
	printf("How many player are playing:\t");
	scanf("%d", &Num_of_player);

	p = calloc(Num_of_player, Num_of_player * sizeof(struct player));

	for (int i = 0; i < Num_of_player; i++) {
		printf("\n");
		printf("please input the name of player %d:", i+1);
		scanf("%s", p[i].name);
		
		for (int j = 0; p[i].name[j] != '\0'; j++) {//convert name input to uppercase
			if (p[i].name[j] >= 'a' && p[i].name[j] <= 'z') {
				p[i].name[j] = p[i].name[j] - 32;
			}
		}
	}

	creat_deck();
	devide_card_begin(p, &dealer);
	update_begin(p, &dealer);

	system("pause");
	system("cls");

	hit_stay(p, &dealer);
	dealer_work(p, dealer);
	anouncement(p);
	system("pause");
}