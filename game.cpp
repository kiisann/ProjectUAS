#include <iostream>
#include <ncurses/ncurses.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int SCREEN_HEIGHT = 26;
const int SCREEN_WIDTH = 90;
const int WIN_WIDTH = 70;
const int ROAD_LEFT = 18;
const int ROAD_RIGHT = 52;

int carPos = WIN_WIDTH / 2;
int enemyX[2], enemyY[2], enemyActive[2];
int score = 0, level = 1, speed = 1;

//-------MOBIL PEMAIN-------
char car[4][4] = {
    {' ', '#', '#', ' '},
    {'#', '#', '#', '#'},
    {' ', '#', '#', ' '},
    {'#', '#', '#', '#'}
};

//-------MOBIL MUSUH-------
char enemy[4][4] = {
    {'*', '*', '*', '*'},
    {' ', '*', '*', ' '},
    {'*', '*', '*', '*'},
    {' ', '*', '*', ' '}
};

//-----------------BORDER JALAN----------------------
void drawBorder() {
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < 18; j++) {
            mvprintw(i, 0 + j, "#");
            mvprintw(i, WIN_WIDTH - j, "#");
        }
    }
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        mvprintw(i, SCREEN_WIDTH, "##########");
    }
}

void initEnemy(int Enemyidx) {
    enemyX[Enemyidx] = ROAD_LEFT + 2 + rand() % (ROAD_RIGHT - ROAD_LEFT - 6);
    enemyY[Enemyidx] = -4;
    enemyActive[Enemyidx] = 1;
}

void drawEnemy(int Enemyidx) {
    if (enemyActive[Enemyidx]) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                mvprintw(enemyY[Enemyidx] + i, enemyX[Enemyidx] + j, "%c", enemy[i][j]);
            }
        }
    }
}

void eraseEnemy(int Enemyidx) {
    if (enemyActive[Enemyidx]) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                mvprintw(enemyY[Enemyidx] + i, enemyX[Enemyidx] + j, " ");
            }
        }
    }
}

void drawCar() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            mvprintw(SCREEN_HEIGHT - 6 + i, carPos + j, "%c", car[i][j]);
        }
    }
}

void eraseCar() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            mvprintw(SCREEN_HEIGHT - 6 + i, carPos + j, " ");
        }
    }
}

bool CekCrash(int Enemyidx) {
    if (enemyActive[Enemyidx] &&
        enemyY[Enemyidx] + 4 >= SCREEN_HEIGHT - 6 &&
        enemyY[Enemyidx] < SCREEN_HEIGHT - 2 &&
        enemyX[Enemyidx] + 4 > carPos &&
        enemyX[Enemyidx] < carPos + 4) {
        return true;
    }
    return false;
}

void gameOver() {
    clear();
    mvprintw(SCREEN_HEIGHT / 2 - 1, WIN_WIDTH / 2 - 7, "GAME OVER");
    mvprintw(SCREEN_HEIGHT / 2, WIN_WIDTH / 2 - 12, "Press 'Q' to quit or 'R' to restart...");
    refresh();
    while (1) {
        char choice = getch();
        if (choice == 'q' || choice == 'Q') {
            endwin();
            exit(0);
        } else if (choice == 'r' || choice == 'R') {
            return;
        }
    }
}

void updateScoreAndLevel() {
    mvprintw(6, WIN_WIDTH + 7, "Score: %d", score);
    mvprintw(7, WIN_WIDTH + 7, "Level: %d", level);
    mvprintw(8, WIN_WIDTH + 7, "Speed: %d", speed);
}

void playGame() {
    while (1) {

    carPos = (WIN_WIDTH / 2) - 2;
    score = 0;
    level = 1;
    speed = 1;

    for (int i = 0; i < 2; i++) {
        initEnemy(i);
    }

    clear();
    drawBorder();
    drawCar();
    updateScoreAndLevel();

    mvprintw(3, WIN_WIDTH + 6, "SIF Racing");
    mvprintw(5, WIN_WIDTH + 5, "------------");
    mvprintw(9, WIN_WIDTH + 5, "------------");
    mvprintw(18, WIN_WIDTH + 7, "Control");
    mvprintw(19, WIN_WIDTH + 4, "-------------");
    mvprintw(20, WIN_WIDTH + 4, "A Key - Left");
    mvprintw(21, WIN_WIDTH + 4, "D Key - Right");

    mvprintw(8, 25, "Press any key to start");
    getch();
    mvprintw(8, 25, "                      ");

    while (1) {
        timeout(50 - speed * 5);
        char ch = getch();
        if (ch == 'a' || ch == 'A') {
            if (carPos > ROAD_LEFT + 2) {
                eraseCar();
                carPos -= 4;
                drawCar();
            }
        } else if (ch == 'd' || ch == 'D') {
            if (carPos < ROAD_RIGHT - 6) {
                eraseCar();
                carPos += 4;
                drawCar();
            }
        } else if (ch == 27) { 
            endwin();
            exit(0);
        }

        for (int i = 0; i < 2; i++) {
            if (enemyActive[i]) {
                eraseEnemy(i);
                enemyY[i]++;
                if (enemyY[i] > SCREEN_HEIGHT - 1) {
                    enemyActive[i] = 0;
                    initEnemy(i);
                    score++;
                        if (score % 2 == 0) {
                        level++;
                        speed++;
                        }
                        if (level > 9) {
                        level = 9;
                        }
                        if (speed > 9) {
                        speed = 9;
                        }
                    updateScoreAndLevel();
                }
                drawEnemy(i);
            }
        }

        for (int i = 0; i < 2; i++) {
            if (CekCrash(i)) {
                gameOver();
                break;
            }
        }

        drawBorder();
        refresh();

        if (CekCrash(0) || CekCrash(1)) {
            break;
            }
        }
    }
}
