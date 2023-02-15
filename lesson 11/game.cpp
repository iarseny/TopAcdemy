#include <termios.h>
#include <unistd.h>
#include <cstdio>
#include <iostream>

struct termios oldt, newt;
int getch() {
   int ch;
   tcgetattr( STDIN_FILENO, &oldt );
   newt = oldt;
   newt.c_lflag &= ~( ICANON | ECHO );
   tcsetattr( STDIN_FILENO, TCSANOW, &newt );
   ch = getchar();
   tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
   return ch;
}

int main() {
    while (true) {
        int c = getch();
        if (c == 49) {
            break;
        } else {
            std::cout << c;
        }
    }

    //49

    //50

    return 0;
}