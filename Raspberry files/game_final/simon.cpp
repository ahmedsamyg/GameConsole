#include "simon.h"
#include <iostream>
#include <unistd.h>

// Constructor
Simon::Simon(const char* portName) : serial(portName), spi_handle(0), receivedData(255), currentImage(-1) {}

// Destructor
Simon::~Simon() {
    // Clean up if needed, e.g., close SPI or UART resources
}

// Initialize the game components
void Simon::init() {
    // Setup for UART, TFT, and other initializations
    wiringPiSetupGpio();                // Setup GPIO for Raspberry Pi
    pinMode(TFT_DC_PIN, OUTPUT);
    pinMode(TFT_RES_PIN, OUTPUT);
    pinMode(TFT_CS_PIN, OUTPUT);
    wiringPiSPISetup(0, 32000000);      // SPI setup with 32 MHz speed
    tft.init();                         // Initialize TFT

    // Display the welcome screen
    displayWelcomeScreen();
}

// Main game loop
void Simon::run() {
    std::cout << "Simon game started! Waiting for input..." << std::endl;

    uint8_t lastReceivedData = receivedData;  // Track the last received data

    while (true) {
        // Read UART data
        if (serial.readData(receivedData) && receivedData != lastReceivedData) {
            // Update only if received data has changed
            lastReceivedData = receivedData;
            displayImageForInput();  // Show the image based on the new input
        }
        
        usleep(100000); // Short delay to avoid rapid looping
    }
}

// Display the welcome screen
void Simon::displayWelcomeScreen() {
    tft.displayImage(imageData[5], 128, 160);  // Show the welcome image
    std::cout << "Displaying Welcome image" << std::endl;
}

// Display image based on input
void Simon::displayImageForInput() {
    switch (receivedData) {
        case EXIT_GAME:
            std::cout << "Exiting game..." << std::endl;
            exit(0);  // Exit the game
        case IMAGE_1:
            currentImage = 0;  // Moon
            break;
        case IMAGE_2:
            currentImage = 1;  // Car
            break;
        case IMAGE_3:
            currentImage = 2;  // Pi Logo
            break;
        case IMAGE_4:
            currentImage = 3;  // Tree
            break;
        case IMAGE_5:
            currentImage = 4;  // Flower
            break;
        case WELCOME:
            currentImage = 6;  // Welcome image
            break;
    }

    // Display the selected image if valid
    if (currentImage >= 0) {
        tft.displayImage(imageData[currentImage], 128, 160);  // Show the image
        std::cout << "Displaying image " << (currentImage + 1) << std::endl;
    }
}
