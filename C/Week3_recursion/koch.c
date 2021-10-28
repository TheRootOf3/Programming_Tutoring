// Code for generating a koch snowflake fractal using external graphics.c lib
// and drawapp.jar Generally on unix machines compile using the -lm flag.

#include <math.h>
#include <stdio.h>

#include "graphics.h"

int SCREEN_WIDTH = 1000;
int SCREEN_HEIGHT = 1000;

void koch(int x0, int y0, int step, int side_l, double angle) {
    // Straight line for step 0
    if (step == 0) {
        drawLine(x0, SCREEN_HEIGHT - y0, x0 + (int)(cos(angle) * side_l),
                 SCREEN_HEIGHT - (y0 + (int)(sin(angle) * side_l)));
        return;
    }

    // 1st segment
    koch(x0, y0, step - 1, (int)(side_l / 3), angle);

    // 2nd segment
    koch(x0 + (int)(cos(angle) / 3 * side_l),
         y0 + (int)(sin(angle) / 3 * side_l), step - 1, (int)(side_l / 3),
         angle + M_PI / 3);

    // 3rd segment
    int x0_new = x0 + (int)(cos(angle) / 3 * side_l);
    int y0_new = y0 + (int)(sin(angle) / 3 * side_l);
    koch(x0_new + (int)(cos(angle + M_PI / 3) / 3 * side_l),
         y0_new + (int)(sin(angle + M_PI / 3) / 3 * side_l), step - 1,
         (int)(side_l / 3), angle - M_PI / 3);

    // 4th segment
    koch(x0 + (int)(cos(angle) * 2 / 3 * side_l),
         y0 + (int)(sin(angle) * 2 / 3 * side_l), step - 1, (int)(side_l / 3),
         angle);
}

int main(int argc, char const *argv[]) {
    setWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    int side_l = 600;
    int x0 = 200;
    int y0 = 400;
    int step = 12;

    koch(x0, y0, step, side_l, M_PI / 3);
    koch(x0 + (int)(side_l / 2), y0 + (int)(side_l * sqrt(3) / 2), step, side_l,
         -1 * M_PI / 3);
    koch(x0 + side_l, y0, step, side_l, M_PI);

    return 0;
}
