#include <ncurses/curses.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include "game.cpp"
using namespace std;

void print_menu(WINDOW *menu_win, int pilihanTerpilih, const char *opsi[], int jumlahopsi);

	void bendera() {                                                  
    mvprintw(0, 25,"                     @@@                    @@@                      ");
    mvprintw(1, 25,"                    #@@@                    @@@%                     ");
    mvprintw(2, 25,"                      -@@                  @@=                       ");
    mvprintw(3, 25,"                    @@  @@                @@  @@                     ");
    mvprintw(4, 25,"                @@@      @@              @@      @@@                 ");
    mvprintw(5, 25,"         @@@@@@@@@@    @  @@            @@  @    @@@@@@@@@@          ");
    mvprintw(6, 25,"      @@      @@@@@@@@@@@  @@          @@  @@@@@@@@@@@      @@       ");
    mvprintw(7, 25,"    @@@@             @@@@@: @@        @@ .@@@@@             @@@@     ");
    mvprintw(8, 25,"   @@@@@@.@@@@@@      @@     @@      @@     @@      @@@@@@.@@@@@@    ");
    mvprintw(9, 25,"    @@@   #@@@@@@   :@@       @@    @@       @@:   @@@@@@#   @@@     ");
    mvprintw(9, 25,"    @*    =@@@   @@@@@@   @@  @@  @@  @@   @@@@@@   @@@=    +@      ");
    mvprintw(10, 25,"     @%   @%      @@@@@@@        @@      @@@@@@@      #@   %@        ");
    mvprintw(11, 25,"      @@@@@@@  @@@@.            @@            .@@@@  @@@@@@@        ");
    mvprintw(12, 25,"       @@@@@@@                 @@ @                 @@@@@@@         ");
    mvprintw(13, 25,"        @@@+                 :@@  @@:                 +@@@          ");
    mvprintw(14, 25,"         @                  *@@    @@*                  @           ");
    mvprintw(15, 25,"                           @@@      @@@                             ");
    mvprintw(16, 25,"                          @@@        @@@                            ");
    mvprintw(17, 25,"                         @@=          =@@                           ");
    mvprintw(18, 25,"                        @@              @@                          ");
    mvprintw(19, 25,"                       @@                @@                         ");
    mvprintw(20, 25,"                      @@                  @@                        ");
    mvprintw(21, 25,"                      @                    @                        ");
    mvprintw(22, 25,"                                                                    ");
    mvprintw(23, 18,"__________________________       ________ _______ ______________________   ___________");
	mvprintw(24, 18,"__  ___/____  _/___  ____/       ___  __ \\___    |__  ____/____  _/___  | / /__  ____/");
	mvprintw(25, 18,"_____ \\  __  /  __  /_           __  /_/ /__  /| |_  /      __  /  __   |/ / _  / __  ");
	mvprintw(26, 18,"____/ / __/ /   _  __/           _  _, _/ _  ___ |/ /___   __/ /   _  /|  /  / /_/ /  ");
	mvprintw(27, 18,"/____/  /___/   /_/              /_/ |_|  /_/  |_|\\____/   /___/   /_/ |_/   \\____/   ");                                                      
	}
	
	void opening1(WINDOW *win, int tinggi, int lebar) {
    int baris = 1, kolom = 1;
    int baris_akhir = tinggi - 2, kolom_akhir = lebar - 2;

    while (baris <= baris_akhir && kolom <= kolom_akhir) {
        for (int i = kolom; i <= kolom_akhir; i++) {
            mvwprintw(win, baris, i, "O");
            wrefresh(win);
            Sleep(1);
        }
        baris++;

        for (int i = baris; i <= baris_akhir; i++) {
            mvwprintw(win, i, kolom_akhir, "O");
            wrefresh(win);
            Sleep(1);
        }
        kolom_akhir--;

        if (baris <= baris_akhir) {
            for (int i = kolom_akhir; i >= kolom; i--) {
                mvwprintw(win, baris_akhir, i, "O");
                wrefresh(win);
                Sleep(1);
            }
            baris_akhir--;
        }

        if (kolom <= kolom_akhir) {
            for (int i = baris_akhir; i >= baris; i--) {
                mvwprintw(win, i, kolom, "O");
                wrefresh(win);
                Sleep(1);
            }
            kolom++;
        }
    }

    baris = 1, kolom = 1;
    baris_akhir = tinggi - 2, kolom_akhir = lebar - 2;

    while (baris <= baris_akhir && kolom <= kolom_akhir) {
        for (int i = kolom; i <= kolom_akhir; i++) {
            mvwprintw(win, baris, i, " ");
            wrefresh(win);
            Sleep(10);
        }
        baris++;

        for (int i = baris; i <= baris_akhir; i++) {
            mvwprintw(win, i, kolom_akhir, " ");
            wrefresh(win);
            Sleep(20);
        }
        kolom_akhir--;

        if (baris <= baris_akhir) {
            for (int i = kolom_akhir; i >= kolom; i--) {
                mvwprintw(win, baris_akhir, i, " ");
                wrefresh(win);
                Sleep(5);
            }
            baris_akhir--;
        }

        if (kolom <= kolom_akhir) {
            for (int i = baris_akhir; i >= baris; i--) {
                mvwprintw(win, i, kolom, " ");
                wrefresh(win);
                Sleep(10);
            }
            kolom++;
        }
    }
	}

	void opening2(WINDOW *win) {
   		mvwprintw(win, 5, 5, " ######################################");
    	mvwprintw(win, 6, 5, " #                                    # ");
    	mvwprintw(win, 7, 5, " #      OOOOOO   OOOOOO   OOOOOO      #  ");
    	mvwprintw(win, 8, 5, " #      OO         OO     OO          #  ");
    	mvwprintw(win, 9, 5, " #      OOOOOO     OO     OOOOOO      #  ");
    	mvwprintw(win, 10, 5, " #          OO     OO     OO          #  ");
    	mvwprintw(win, 11, 5, " #      OOOOOO   OOOOOO   OO          #  ");
    	mvwprintw(win, 12, 5, " #                                    # ");
    	mvwprintw(win, 13, 5, " ######################################");
    	wrefresh(win);
    	Sleep(100);
	}
	
	void transisi(WINDOW *win) {
    	int y, x;
    	for (y = 24; y > 5; y--) {
        	move(y, 35);
        	clrtoeol();
        	addstr(" ########################################");
        	refresh(); 
        	Sleep(50); 
    }

    	for (y = 5; y < 24; y++) {
        	move(y, 35);
        	clrtoeol();
        	addstr("                                         ");
        	refresh();
        	Sleep(50);
    	}
	}

	void opening3(WINDOW *win) {
   		do {
        	mvwprintw(win, 0, 0, " ########################################");
        	mvwprintw(win, 1, 0, " #                                      #");
        	mvwprintw(win, 2, 0, " #                  HI!                 #");
        	mvwprintw(win, 3, 0, " #              WELCOME TO              #");
        	mvwprintw(win, 4, 0, " #             S.I.F RACING             #");
        	mvwprintw(win, 5, 0, " #                                      #");
        	mvwprintw(win, 6, 0, " #               #  ||  #               #");
        	mvwprintw(win, 7, 0, " #               #      #               #");
        	mvwprintw(win, 8, 0, " #               #  ||  #               #");
        	mvwprintw(win, 9, 0, " #               #      #               #");
        	mvwprintw(win, 10, 0, " #               #  ||  #               #");
        	mvwprintw(win, 11, 0, " #               #      #               #");
        	mvwprintw(win, 12, 0, " #               #  ||  #               #");
        	mvwprintw(win, 13, 0, " #               #      #               #");
        	mvwprintw(win, 14, 0, " #               #  ||  #               #");
        	mvwprintw(win, 15, 0, " #                                      #");
        	mvwprintw(win, 16, 0, " #             PRESS 'Space'            #");
        	mvwprintw(win, 17, 0, " #               TO NEXT                #");
        	mvwprintw(win, 18, 0, " #                                      #");
        	mvwprintw(win, 19, 0, " ########################################");

        	wrefresh(win);
    	}
		while (wgetch(win) != ' ');
            wclear(win);
            wrefresh(win);
	}

void daftarAkun(WINDOW *win) {
    string user, pass;
    bool username_terdaftar = false;

    wclear(win);
    box(win, 0, 0);
    mvwprintw(win, 1, 2, "Registration: ");

    do {
        mvwprintw(win, 2, 2, "Enter username: ");
        wrefresh(win);

        char username[20];
        mvwgetnstr(win, 3, 2, username, sizeof(username) - 1);
        user = username;

        ifstream file_cek("akun.txt");
        string userFile, passFile;
        username_terdaftar = false;

        if (file_cek.is_open()) {
            while (file_cek >> userFile >> passFile) {
                if (userFile == user) {
                    username_terdaftar = true;
                    break;
                }
            }
            file_cek.close();
        }

        if (username_terdaftar) {
            mvwprintw(win, 4, 2, "Username already exists. Try another.");
            wrefresh(win);
        }
    } while (username_terdaftar);

    mvwprintw(win, 5, 2, "Enter password: ");
    wrefresh(win);

    char password[20];
    mvwgetnstr(win, 6, 2, password, sizeof(password) - 1);
    pass = password;

    ofstream file("akun.txt", ios::app);
    if (!file.is_open()) {
        mvwprintw(win, 7, 2, "Error: Unable to open file!");
        wrefresh(win);
        wgetch(win);
        return;
    }
    file << user << " " << pass << endl;
    file.close();

    mvwprintw(win, 7, 2, "Registration successful! Welcome, %s!", user.c_str());
    mvwprintw(win, 8, 2, "Press any key to continue...");
    wrefresh(win);
    wgetch(win);
    wclear(win);
}

bool cekLogin(WINDOW *win) {
    string user, pass;
    string userFile, passFile;
    bool login_berhasil = false;

    wclear(win);
    box(win, 0, 0);
    mvwprintw(win, 1, 2, "Login: ");

    mvwprintw(win, 2, 2, "Enter username: ");
    wrefresh(win);
    char username[20];
    mvwgetnstr(win, 3, 2, username, sizeof(username) - 1);
    user = username;

    mvwprintw(win, 4, 2, "Enter password: ");
    wrefresh(win);
    char password[20];
    mvwgetnstr(win, 5, 2, password, sizeof(password) - 1);
    pass = password;

    ifstream file("akun.txt");
    if (!file.is_open()) {
        mvwprintw(win, 6, 2, "Error: Unable to open file!");
        wrefresh(win);
        wgetch(win);
        return false;
    }

    while (file >> userFile >> passFile) {
        if (userFile == user && passFile == pass) {
            login_berhasil = true;
            break;
        }
    }
    file.close();

    if (login_berhasil) {
        mvwprintw(win, 6, 2, "Login successful! Welcome, %s!", user.c_str());
    } else {
        mvwprintw(win, 6, 2, "Invalid username or password.");
    }
    mvwprintw(win, 7, 2, "Press any key to continue...");
    wrefresh(win);
    wgetch(win);
    wclear(win);

    return login_berhasil;
}

void loading() {
    for (int i = 0; i < 3; i++) {
        mvprintw(29, 25, "================================================================");
        mvprintw(30, 25, "                                                                ");
        mvprintw(31, 25, "================================================================");
        
        for (int f = 1; f < 50; f++) {
            mvprintw(30, 25 + f, "|");
            refresh();
            Sleep(3);
        }
        
        mvprintw(30, 25, "                                      ");
    }
}

	int main(){
        srand(time(0));
        initscr();
        cbreak();
  	    curs_set(0);
  	
  	int tinggi = 20, lebar = 50;
    WINDOW *win = newwin(tinggi, lebar, (LINES - tinggi) / 2, (COLS - lebar) / 2);
    box(win, 0, 0);
    wrefresh(win);

    mvwprintw(win, 10, 2, "Welcome to the system!");
    wrefresh(win);
	opening2(win);
    opening1(win, tinggi, lebar);
    transisi(win);
    opening3(win);
    daftarAkun(win);
    cekLogin(win);
    bendera();
    loading();
    playGame();

    delwin(win);
    endwin();  
   	return 0;
	}
