#ifndef BRICK_H
#define BRICK_H

#include "TFT.h"  
#include "UART.h"
#include "images.h"



// Updated Position class with dx, dy for movement direction
class Position {
public:
    int x, y;
    int dx, dy;  // Add direction (dx, dy)

    Position() : x(0), y(0), dx(0), dy(0) {}
    Position(int x, int y, int dx = 0, int dy = 0) : x(x), y(y), dx(dx), dy(dy) {}
};

class BrickBreaker {
public:
    BrickBreaker(const char* uartPort);
    void run();
    void init();

private:
    
    void initBricks();
    void movePaddle(uint8_t direction);
    void moveBall();
    void checkCollisions();
    void drawGame();
    void GameOver();
    
    TFT tft;
    SerialPort uart;
    Position paddle;
    Position ball;
    bool bricks[5][10];
    bool gameRunning = true;
};

#endif // BRICK_H
