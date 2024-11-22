#ifndef TFT_H
#define TFT_H

#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <cstdint>
#include "config.h"

class TFT {
public:
    TFT();
    void init();
    void fillScreen(uint16_t color);
    void drawRectangle(int x, int y, int width, int height, uint16_t color);
    void displayImage(const uint16_t* imageData, int width, int height);
    void sendCommand(uint8_t cmd);
    void sendData(uint8_t data);

private:
    
};

#endif // TFT_H
