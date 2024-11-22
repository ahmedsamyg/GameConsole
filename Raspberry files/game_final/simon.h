#ifndef SIMON_H
#define SIMON_H

#include "UART.h"
#include "TFT.h"
#include "images.h"
#include "config.h"

class Simon {
public:
    Simon(const char* portName);  // Constructor to initialize UART port
    ~Simon();                    // Destructor to clean up resources

    void init();                 // Initialize the game (UART, TFT, etc.)
    void run();                  // Main game loop

private:
    SerialPort serial;           // UART object for communication
    int spi_handle;              // SPI handle for TFT display
    uint8_t receivedData;        // To store UART input
    int currentImage;            // Track the currently displayed image
    void displayWelcomeScreen(); // Display the welcome screen
    void displayImageForInput(); // Display the image based on received input
    TFT tft;
};

#endif
