# 🃏 Blackjack Game in C

This is a simple implementation of the classic Blackjack card game written in C. The project demonstrates the use of basic C programming concepts such as functions, arrays, and user input/output.

## 📁 Files

- `game.c`: The main file that contains the core logic of the Blackjack game, including dealing cards, handling user input, and determining the winner.
- `header.h`: The header file that declares all functions, constants, and structures used in the game.
- `module.c`: Contains additional game logic and helper functions for card shuffling, dealing, and hand evaluation.

## ⚙️ How to Run

1. Clone the repository:

    ```bash
    git clone https://github.com/yourusername/blackjack-game.git
    ```

2. Navigate to the project directory:

    ```bash
    cd blackjack-game
    ```

3. Compile the program:

    ```bash
    gcc game.c module.c -o blackjack
    ```

4. Run the game:

    ```bash
    ./blackjack
    ```

## 📝 Game Rules

- The goal of Blackjack is to get as close to 21 points as possible without going over.
- The player competes against the dealer.
- Each player is dealt two cards. The player can choose to "Hit" (get another card) or "Stand" (keep their current hand).
- The dealer must follow a set of rules (e.g., stand on 17 or higher).
- Aces can count as 1 or 11, face cards (Jack, Queen, King) are worth 10 points, and all other cards are worth their face value.

## 🌟 Features

- Playable against the dealer (AI).
- Option to "Hit" or "Stand."
- Card shuffling and randomization.

