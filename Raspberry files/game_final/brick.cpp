#include "brick.h"
#include <unistd.h>  // For usleep function

BrickBreaker::BrickBreaker(const char* uartPort) : uart(uartPort) {
    
    TFT tft;
}

void BrickBreaker::init() {
    // Initialize paddle and ball positions and set up TFT display
    paddle = {TFT_WIDTH / 2 - 10, TFT_HEIGHT - 20};
    ball = {TFT_WIDTH / 2, TFT_HEIGHT / 2, 6, -6}; // Start ball with initial dx, dy (larger steps)
    tft.init();
    initBricks();
    drawGame();
}

void BrickBreaker::initBricks() {
    // Initialize bricks array (larger bricks)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            bricks[i][j] = true;
        }
    }
}

void BrickBreaker::run() {
    while (gameRunning) {
        // Move the ball on every loop iteration
        moveBall();

        // Handle UART input (non-blocking), but don't block game loop
        uint8_t input;
        if (uart.readData(input)) {  // UART input is checked but doesn't block
            std::cout << "Received UART Input: " << (int)input << std::endl;  // Debug print
            movePaddle(input);
        }

        // Draw updated game elements (ball, paddle, bricks)
        drawGame();

        // Control game loop speed (e.g., update every 100ms)
        usleep(150000);  // 100ms delay per loop iteration (controls game speed)
    }
}


void BrickBreaker::movePaddle(uint8_t direction) {
    // Move paddle based on UART input (left or right)
    if (direction == MOVE_LEFT && paddle.x < TFT_WIDTH - 40) {  // Move right on left command
        paddle.x += 5;  // Increase movement to the right
    } else if (direction == MOVE_RIGHT && paddle.x > 0) {  // Move left on right command
        paddle.x -= 5;  // Increase movement to the left
    }
}


void BrickBreaker::moveBall() {
    // Update ball position and check wall collisions
    ball.x += ball.dx;
    ball.y += ball.dy;

    // Debugging: Print ball position to check if it's moving
    std::cout << "Ball Position - X: " << ball.x << " Y: " << ball.y << std::endl;

    // Check for collisions with walls
    if (ball.x <= 0 || ball.x >= TFT_WIDTH) {
        ball.dx = -ball.dx;
    }
    if (ball.y <= 0) {
        ball.dy = -ball.dy;
    } else if (ball.y >= TFT_HEIGHT) {
        GameOver();  // Reset game if ball hits the bottom wall
        gameRunning = false;
    }

    checkCollisions();
}

void BrickBreaker::checkCollisions() {
    // Check ball collision with paddle
    if (ball.y >= paddle.y && ball.y <= paddle.y + 8 &&
        ball.x >= paddle.x && ball.x <= paddle.x + 40) {
        ball.dy = -ball.dy;
    }

    // Check ball collision with bricks
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            if (bricks[i][j]) {
                int brickX = j * 14; // Increase brick width
                int brickY = i * 10; // Increase brick height
                if (ball.x >= brickX && ball.x <= brickX + 12 &&
                    ball.y >= brickY && ball.y <= brickY + 8) {
                    bricks[i][j] = false;
                    ball.dy = -ball.dy;
                    return;
                }
            }
        }
    }
}

void BrickBreaker::drawGame() {
    // Clear screen, draw paddle, ball, and bricks
    tft.fillScreen(BLACK);
    tft.drawRectangle(paddle.x, TFT_HEIGHT - paddle.y - 8, 40, 8, WHITE);  // Adjust for flipped Y
    tft.drawRectangle(ball.x, TFT_HEIGHT - ball.y - 8, 8, 8, WHITE);       // Adjust for flipped Y

    // Draw remaining bricks (adjust for flipped Y)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            if (bricks[i][j]) {
                int brickX = j * 14;
                int brickY = TFT_HEIGHT - (i * 10 + 8); // Adjust for flipped Y
                tft.drawRectangle(brickX, brickY, 12, 8, GREEN); // Larger bricks
            }
        }
    }
}


void BrickBreaker::GameOver() {
    tft.displayImage(imageData[7],TFT_WIDTH,TFT_HEIGHT);
    usleep(5000000);
    
    
}
