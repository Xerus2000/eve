#include "main.h"

#define WIDTH 1000
#define HEIGHT 1000
#define ENERGY 100

int main(int argc, char * argv[]) {
    Controller(WIDTH, HEIGHT, ENERGY).run();
    return 0;
}