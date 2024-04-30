#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h> // only for Windows
#include <windows.h> 

const int WIDTH = 20;
const int HEIGHT = 10;
const char BIRD_CHAR = '@';
const char PIPE_CHAR = '|';

void drawGame(int birdY, int pipeX) {
    system("cls");
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if ((j == pipeX || j == pipeX + 1) && (i == 0 || i == HEIGHT - 1)) {
                std::cout << PIPE_CHAR;
            } else if (j == WIDTH / 4 && i == birdY) {
                std::cout << BIRD_CHAR;
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}
int main() {
    int birdY = HEIGHT / 2;
    int pipeX = WIDTH;
    srand(time(NULL));
    while (true) {
        if (_kbhit()) {
            char key = _getch();
            if (key == ' ') {
                birdY -= 2;
            }
        }
        birdY++; 
        pipeX--; 
        if (birdY <= 0 || birdY >= HEIGHT) {
            std::cout << "Game Over!" << std::endl;
            break;
        }
        if (pipeX < 0) {
            pipeX = WIDTH;
        }
        drawGame(birdY, pipeX);
        Sleep(100);
    }
    return 0;
}
