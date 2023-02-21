#pragma once
#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>



void rule();
void Display_menu();
void play();
void creat_deck();
void devide_card_begin(struct player* x, struct player dealer);
void update_begin(struct player* x, struct player dealer);
void hit_stay(struct player* p);
void anouncement(struct player* p);
bool play_again(); 
void dealer_work(struct player* p, struct player dealer);