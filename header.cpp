#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h> 

const int WIDTH = 20;
const int HEIGHT = 10;
const char BIRD_CHAR = '@';
const char PIPE_CHAR = '|';
const int PIPE_GAP = 4;

void drawGame(int birdY, int pipeX, int topPipeHeight) 
{
    system("cls");
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j)
        {
            if (j == pipeX) {
                if (i < topPipeHeight)
                {
                    std::cout << PIPE_CHAR;
                } else if (i >= topPipeHeight + PIPE_GAP) {
                    std::cout << PIPE_CHAR;
                } else {
                    std::cout << " ";
                }
            }
            else if (j == WIDTH / 4 && i == birdY) {
                std::cout << BIRD_CHAR;
            }
            else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    int birdY = HEIGHT / 2;
    int pipeX = WIDTH;
    int topPipeHeight = rand() % (HEIGHT - PIPE_GAP);
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

        if (pipeX < 0) {
            pipeX = WIDTH;
            topPipeHeight = rand() % (HEIGHT - PIPE_GAP);
        }

        drawGame(birdY, pipeX, topPipeHeight);

        if (birdY <= 0 || birdY >= HEIGHT) {
            std::cout << "Game Over!" << std::endl;
            break;
        }

        Sleep(100);
    }
    return 0;
}
