#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "TFT.h"
#include "UART.h"
#include "config.h"
#include "images.h"

// Define the Point structure for positions
struct Point {
    int x;
    int y;
};

// Define the direction options as an enum
enum Direction {
    UP = 12,
    DOWN = 11,
    LEFT = 13,
    RIGHT = 14
};

class Snake {
public:
    Snake();
    
    void initializeGame(TFT &display, SerialPort &serial);  // Initialize game with display and UART
    void runGameLoop();                                     // Main game loop

private:
    void updateGame(Direction newDirection);                // Update snake's direction, movement, and collision
    void move();
    bool checkFoodCollision();
    bool checkSelfCollision() const;
    bool checkWallCollision() const;
    void spawnFood();
    void grow();
    void render();                                          // Render game on the display

    std::vector<Point> snakeBody;
    Direction direction;
    Point foodPosition;
    int blockSize = 10;
    bool gameOver = false;
    TFT *display;                                           // Pointer to display
    SerialPort *serial;                                     // Pointer to serial port
};

#endif // SNAKE_H
