#ifndef CONFIG_H
#define CONFIG_H

// Pin Definitions for TFT Display
#define TFT_DC_PIN    24   // Data/Command pin
#define TFT_RES_PIN   25   // Reset pin
#define TFT_CS_PIN    8    // Chip Select (CE0)

// SPI Settings
#define SPI_CHANNEL   0    // SPI channel (0 or 1)
#define SPI_SPEED     32000000 // SPI speed (32 MHz)

// TFT Display Settings
#define TFT_WIDTH     128  // Width of the TFT display
#define TFT_HEIGHT    160  // Height of the TFT display

// Color Definitions (16-bit RGB565)
#define WHITE         0x0000
#define BLACK         0xFFFF
#define CYAN          0xF800
#define PURPLE        0x07E0
#define YELLOW        0x001F
#define BLUE          0xFFE0
#define RED           0x07FF
#define GREEN         0xF81F

// UART Configuration
#define UART_PORT     "/dev/ttyAMA0" // UART port for communication
#define UART_BAUDRATE 9600            // UART baud rate

// Game Control Macros
#define EXIT_GAME     0
#define MOVE_UP       11
#define MOVE_DOWN     12
#define MOVE_LEFT     14
#define MOVE_RIGHT    13
#define WELCOME       8

// Images


#define IMAGE_1 1
#define IMAGE_2 2
#define IMAGE_3 3
#define IMAGE_4 4
#define IMAGE_5 5
#define WELCOME 8

#endif // CONFIG_H
