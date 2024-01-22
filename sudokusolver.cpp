#include <iostream>
#include <Windows.h>
using namespace std;

const int yatay = 9;
const int dikey = 9;

char board[9][9] = { '5','3',' ',' ','7',' ',' ',' ',' ',
                    '6',' ',' ','1','9','5',' ',' ',' ',
                    ' ','9','8',' ',' ',' ',' ','6',' ',
                    '8',' ',' ',' ','6',' ',' ',' ','3',
                    '4',' ',' ','8',' ','3',' ',' ','1',
                    '7',' ',' ',' ','2',' ',' ',' ','6',
                    ' ','6',' ',' ',' ',' ','2','8',' ',
                    ' ',' ',' ','4','1','9',' ',' ','5',
                    ' ',' ',' ',' ','8',' ',' ','7','9' };

void showboard() {
    system("cls");

    for (int d = 0; d < dikey; d++) {
        for (int y = 0; y < yatay; y++) {
            cout << board[d][y] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool kontrol(char sayi, int hdikey, int hyatay) {
    // Dikey ve yatay kontrol
    for (int i = 0; i < 9; i++) {
        if (board[hdikey][i] == sayi || board[i][hyatay] == sayi) {
            return false;
        }
    }

    // Kare kontrol
    int basdik = (hdikey / 3) * 3;
    int basyat = (hyatay / 3) * 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + basdik][j + basyat] == sayi) {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku() {
    for (int d = 0; d < dikey; d++) {
        for (int y = 0; y < yatay; y++) {
            if (board[d][y] == ' ') {
                for (char c = '1'; c <= '9'; c++) {
                    if (kontrol(c, d, y)) {
                        board[d][y] = c;
                        if (solveSudoku()) {
                            return true;
                        }
                        board[d][y] = ' ';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {

    setlocale(LC_ALL, "Turkish");

    showboard();

    if (solveSudoku()) {
        showboard();
        cout << "Sudoku başarılı bir şekilde çözüldü:" << endl;
        cout << "METEHAN SOYLU" << endl << endl;
    }
    else {
        cout << "Herhangi bir çözüm mevcut değil." << endl;
    }

    return 0;
}