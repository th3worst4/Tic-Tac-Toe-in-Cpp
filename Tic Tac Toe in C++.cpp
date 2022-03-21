#include <iostream> 
#include <conio.h> 
#include <random>
#include <string>

void metadatas() {
    std::cout << "Tic Tac Toe game done in C++\n";
    std::cout << "Version Beta +2\n";
    std::cout << "Made by Caio Silva Couto\n";
    std::cout << "GitHub: https://github.com/th3worst4" << std::endl << std::endl;
}

int destiny() {
    int coin;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist2(0, 1);
    return coin = dist2(rng);
}

bool check_victory(char top_row[3], char middle_row[3], char bottom_row[3]) {
    for (int i = 0; i <= 2; i++) /*checking columns*/ {
        if (top_row[i] == middle_row[i] && top_row[i] == bottom_row[i]){
            return true;
        }
    }

    if (top_row[0] == top_row[1] && top_row[0] == top_row[2]) {
        return true;
    }
    if (middle_row[0] == middle_row[1] && middle_row[0] == middle_row[2]) {
        return true;
    }
    if (bottom_row[0] == bottom_row[1] && bottom_row[0] == bottom_row[2]) {
        return true;
    }

    if (top_row[0] == middle_row[1] && top_row[0] == bottom_row[2]) {
        return true;
    }
    if (bottom_row[0] == middle_row[1] && bottom_row[0] == top_row[2]) {
        return true;
    }
}

void new_game(bool player_round) {
    int round = 1;
    bool victory = false;
    char top_row[3] = { ' ',' ',' ' };
    char middle_row[3] = { ' ',' ',' ' };
    char bottom_row[3] = { ' ',' ',' ' };
    char symb;
    int col, row;

    while(round<=9 && !victory) {
        if (player_round) {
            symb = 'X';
        }
        else {
            symb = 'O';
        }
        std::cout << "We are on the " << round << " round!\n";
        std::cout << "It's " << symb << " turn!\n";
        std::cout << "  " << 1 << "|" << 2 << "|" << 3 << "|" << std::endl;
        std::cout << 1 << '|';
        for (char c : top_row) {
            std::cout << c << '|';
        }
        std::cout << std::endl;
        std::cout << 2 << '|';
        for (char c : middle_row) {
            std::cout << c << '|';
        }
        std::cout << std::endl;
        std::cout << 3 << '|';
        for (char c : bottom_row) {
            std::cout << c << '|';
        }
        std::cout << std::endl << std::endl;
        player_round = !player_round;

        insert_column:
        std::cout << "Insert the column number where you wish to position: ";
        std::cin >> col;
        if (col > 3 || col < 1) {
            std::cout << "Insert a valid column!" << std::endl;
            goto insert_column;
        }
        
        insert_row:
        std::cout << "Insert the row number where you wish to position: ";
        std::cin >> row;
        if (row > 3 || row < 1) {
            std::cout << "Insert a valid row!" << std::endl;
            goto insert_row;
        }

        switch (row) {
        case 1: if (top_row[col - 1] == ' ') {
            top_row[col - 1] = symb;
        }
              else {
            std::cout << "You can not position here!" << std::endl;
            goto insert_column;
        } break;
        case 2: if (middle_row[col - 1] == ' ') {
            middle_row[col - 1] = symb;
        }
              else {
            std::cout << "You can not position here!"<<std::endl;
            goto insert_column;
        } break;
        case 3: if (middle_row[col - 1] == ' ') {
            middle_row[col - 1] = symb;
        }
              else {
            std::cout << "You can not position here!" << std::endl;
            goto insert_column;
        } break;
        }
        round++;
        std::cout << std::endl;
        if (round >= 6) {
            victory = check_victory(top_row, middle_row, bottom_row);
        }
    }
    if (victory) {
        std::cout << "  " << 1 << "|" << 2 << "|" << 3 << "|" << std::endl;
        std::cout << 1 << '|';
        for (char c : top_row) {
            std::cout << c << '|';
        }
        std::cout << std::endl;
        std::cout << 2 << '|';
        for (char c : middle_row) {
            std::cout << c << '|';
        }
        std::cout << std::endl;
        std::cout << 3 << '|';
        for (char c : bottom_row) {
            std::cout << c << '|';
        }
        std::cout << std::endl << std::endl;

        switch (!player_round) {
        case true: std::cout << "X win!\n";
            break;
        case false: std::cout << "O win!\n";
            break;
        }
    }

}

int main(){
    metadatas();

    bool player_round; //true = x, false = o

    std::string play_first;
    int coin = destiny();
    question:

    std::cout << "Who will play first?\n1-X\n2-O\n3-Random\n";
    std::cin >> play_first;

    if (play_first.size() > 1) {
        std::cout << "Wrong input!";
        goto question;
    }
    else {
        char p_first = (char)play_first[0];
        
        switch (p_first) {
        case '1': 
            std::cout << "X plays first!\n"; 
            player_round = true;
            break;
        case '2': 
            std::cout << "O plays first!\n"; 
            player_round = false;
            break;
        case '3':
            if (coin) {
                std::cout << "The destiny has chosen!\n";
                std::cout << "X plays first!\n";
                player_round = true;
            }
            else {
                std::cout << "The destiny has chosen!\n";
                std::cout << "O plays first!\n";
                player_round = false;
            }
            break;
        default:  
            std::cout << "Wrong input!\n";
            goto question;
        }
    
        new_game(player_round);
    }


    std::cout << "Press any key to exit";
    _getch();
}
