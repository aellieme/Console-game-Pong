#include <stdio.h>
int run_racket1(int symbol, int racket1);
int run_racket2(int symbol, int racket2);
int directionY(int height, int bally, int speedY);
int directionX(int width, int ballx, int bally, int speedX, int racket1, int racket2);
void create(int height, int width, int racket1, int racket2, int ballsx, int ballsy, int count1, int count2);

int main(void) {
    int width = 80, height = 25, count1 = 0, count2 = 0, racket1 = 12, racket2 = 12, ballx = width / 2,
        bally = height / 2, speedX = 1, speedY = 1;
    char ch_0 = '\0';
    while (((count1 < 21) && (count2 < 21)) && (ch_0 != 'q')) {
        scanf("%c", &ch_0);
        printf("\033[H\033[J");
        while (getchar() != '\n') {
        }
        int ch = (int)ch_0;
        if (ch == 97 || ch == 65 || ch == 122 || ch == 90) racket1 = run_racket1(ch, racket1);
        if (ch == 107 || ch == 75 || ch == 109 || ch == 77) racket2 = run_racket2(ch, racket2);

        if (ballx == width - 1) {
            count1 += 1;
            ballx = width / 2;
            bally = height / 2;
            racket1 = 12;
            racket2 = 12;
        }
        if (ballx == 0) {
            count2 += 1;
            ballx = width / 2;
            bally = height / 2;
            racket1 = 12;
            racket2 = 12;
        }

        ballx += speedX;
        bally += speedY;
        speedY = directionY(height, bally, speedY);
        speedX = directionX(width, ballx, bally, speedX, racket1, racket2);
        create(height, width, racket1, racket2, ballx, bally, count1, count2);
        if (count1 == 21) {
            printf("\033[H\033[J");
            printf("Поздравляем первого игрока с победой. Счет первого игрока: %d || второго игрока: %d\n",
                   count1, count2);
        }
        if (count2 == 21) {
            printf("\033[H\033[J");
            printf("Поздравляем второго игрока с победой. Счет первого игрока: %d || второго игрока: %d\n",
                   count1, count2);
        }
    }
}

int run_racket1(int symbol, int racket1) {
    switch (symbol) {
        case 65:
            if (racket1 - 2 != 0) racket1 = racket1 - 1;
            break;

        case 97:
            if (racket1 - 2 != 0) racket1 = racket1 - 1;
            break;
        case 90:
            if (racket1 + 3 != 25) racket1 = racket1 + 1;
            break;
        case 122:
            if (racket1 + 3 != 25) racket1 = racket1 + 1;
            break;
    }
    return racket1;
}

int run_racket2(int symbol, int racket2) {
    switch (symbol) {
        case 75:
            if (racket2 - 2 != 0) racket2 = racket2 - 1;
            break;
        case 107:
            if (racket2 - 2 != 0) racket2 = racket2 - 1;
            break;
        case 77:
            if (racket2 + 3 != 25) racket2 = racket2 + 1;
            break;
        case 109:
            if (racket2 + 3 != 25) racket2 = racket2 + 1;
            break;
    }
    return racket2;
}

int directionY(int height, int bally, int speedY) {
    if (bally == 1 || bally == height - 2) speedY = -speedY;
    return speedY;
}
int directionX(int width, int ballx, int bally, int speedX, int racket1, int racket2) {
    if ((ballx == 2 && (bally == racket1 - 1 || bally == racket1 || bally == racket1 + 1)) ||
        (ballx == width - 3 && (bally == racket2 - 1 || bally == racket2 || bally == racket2 + 1)))
        speedX = -speedX;
    return speedX;
}

void create(int height, int width, int racket1, int racket2, int ballsx, int ballsy, int count1, int count2) {
    printf("\t\t\tПервый игрок: %d | Второй игрок: %d\n", count1, count2);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (y == 0 || y == height - 1 || x == 0 || x == width - 1) {
                printf("*");
            } else if ((x == 1 && (y == racket1 - 1 || y == racket1 || y == racket1 + 1)) ||
                       (x == width - 2 && (y == racket2 - 1 || y == racket2 || y == racket2 + 1))) {
                printf("|");
            } else if (x == ballsx && y == ballsy) {
                printf("0");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
