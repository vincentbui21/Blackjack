#define _CRT_SECURE_NO_WARNINGS
#include "header.h"

bool idea = true;

int main(int argc, char** argv) {
	srand(time(NULL));
	int choice;

		while(idea == true) {
			system("cls");
			Display_menu();
			printf("\tEnter choice:\t");

			scanf("%d", &choice);

			switch (choice) {
			case 1:
				system("cls");
				play();
				system("cls");
				idea=play_again();
				if (idea == true) {
					continue;
				}
				else {
					break;
				}
			case 2:
				rule();
				break;
			case 0:
				exit(0);
			default:
				printf(" please enter a valid number!!!\n");
				system("pause");
			}
		}
}



