#include "TFT.h"

// Constructor
TFT::TFT() {
    wiringPiSetupGpio(); // Setup GPIO using BCM numbering
    pinMode(TFT_DC_PIN, OUTPUT);
    pinMode(TFT_RES_PIN, OUTPUT);
    pinMode(TFT_CS_PIN, OUTPUT);
    wiringPiSPISetup(SPI_CHANNEL, SPI_SPEED); // Setup SPI channel
}

// Initialize the TFT display
void TFT::init() {
    digitalWrite(TFT_RES_PIN, LOW);
    delay(100);
    digitalWrite(TFT_RES_PIN, HIGH);
    
    // Initialization commands
    sendCommand(0x01); // Software reset
    delay(150);
    sendCommand(0x11); // Sleep out
    delay(500);
    sendCommand(0x3A); // Set color mode
    sendData(0x05);    // 16-bit color
    sendCommand(0x29); // Display on
}

// Fill the screen with a color
void TFT::fillScreen(uint16_t color) {
    drawRectangle(0, 0, TFT_WIDTH, TFT_HEIGHT, color);
}

// Draw a filled rectangle
void TFT::drawRectangle(int x, int y, int width, int height, uint16_t color) {
    if (x < 0 || x >= TFT_WIDTH || y < 0 || y >= TFT_HEIGHT) return;
    if (x + width > TFT_WIDTH) width = TFT_WIDTH - x;
    if (y + height > TFT_HEIGHT) height = TFT_HEIGHT - y;

    sendCommand(0x2A); // Column address set
    sendData(x >> 8);  // X0
    sendData(x & 0xFF);
    sendData((x + width - 1) >> 8); // X1
    sendData((x + width - 1) & 0xFF);

    sendCommand(0x2B); // Row address set
    sendData(y >> 8);  // Y0
    sendData(y & 0xFF);
    sendData((y + height - 1) >> 8); // Y1
    sendData((y + height - 1) & 0xFF);

    sendCommand(0x2C); // Memory write
    for (int i = 0; i < width * height; i++) {
        sendData(color >> 8); // High byte
        sendData(color & 0xFF); // Low byte
    }
}



// Send command to TFT
void TFT::sendCommand(uint8_t cmd) {
    digitalWrite(TFT_DC_PIN, LOW); // DC low for command
    digitalWrite(TFT_CS_PIN, LOW);  // Select the device
    wiringPiSPIDataRW(SPI_CHANNEL, &cmd, 1); // Send command
    digitalWrite(TFT_CS_PIN, HIGH); // Deselect the device
}

// Send data to TFT
void TFT::sendData(uint8_t data) {
    digitalWrite(TFT_DC_PIN, HIGH); // DC high for data
    digitalWrite(TFT_CS_PIN, LOW);  // Select the device
    wiringPiSPIDataRW(SPI_CHANNEL, &data, 1); // Send data
    digitalWrite(TFT_CS_PIN, HIGH); // Deselect the device
}

// Display an image (example implementation)
void TFT::displayImage(const uint16_t* imageData, int width, int height) {
    //fillScreen(BLACK); // Clear the screen before displaying
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            drawRectangle(x, y, 1, 1, imageData[y * width + x]);
        }
    }
}

