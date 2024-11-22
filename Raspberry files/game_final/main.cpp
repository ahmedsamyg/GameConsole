#include <iostream>
#include <unistd.h>
#include "TFT.h"
#include "UART.h"
#include "config.h"
#include "simon.h"
#include "snake.h"
#include "brick.h"


// Initialize TFT display and UART communication
TFT tft;
SerialPort serial(UART_PORT);

// Initialize game objects
Simon simonGame(UART_PORT);
Snake snakeGame;
BrickBreaker brickGame(UART_PORT);

int main() {
    // Initialize TFT display and UART
    tft.init();


    // Show the welcome image 
    tft.displayImage(imageData[5], TFT_WIDTH, TFT_HEIGHT);
    std::cout << "Welcome screen displayed" << std::endl;

    uint8_t receivedData;
    
    while (true) {
        // Read UART input for "WELCOME" signal
        if (serial.readData(receivedData) && receivedData == WELCOME) {
            // Show the menu image (imageData[8])
            tft.displayImage(imageData[8], TFT_WIDTH, TFT_HEIGHT);
            std::cout << "Game selection screen displayed" << std::endl;
            
            // Wait for the user to choose a game
            while (true) {
                if (serial.readData(receivedData)) {
                    if (receivedData == 1) {
                        std::cout << "Starting Simon game..." << std::endl;
                        simonGame.init();  // Initialize the Simon game
                        simonGame.run();   // Run the Simon game
                        break;
                    } else if (receivedData == 2) {
                        std::cout << "Starting Snake game..." << std::endl;
                        snakeGame.initializeGame(tft, serial);  // Initialize Snake game
                        snakeGame.runGameLoop();  // Run the Snake game
                        break;
                    } else if (receivedData == 3) {
                        std::cout << "Starting Brick Breaker game..." << std::endl;
                        brickGame.init();  // Initialize Brick Breaker game
                        brickGame.run();   // Run the Brick Breaker game
                        break;
                    }
                }
            }

        }

        usleep(100000);  // Avoid tight looping
        // Show the welcome image 
        
        tft.displayImage(imageData[5], TFT_WIDTH, TFT_HEIGHT);
        std::cout << "Welcome screen displayed" << std::endl;
    }

    return 0;
}
