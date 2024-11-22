#ifndef UART_H
#define UART_H

#include <iostream>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <cstring>
#include <sys/select.h> // For select()

class SerialPort {
public:
    SerialPort(const char* portName);
    ~SerialPort();
    
    void writeData(uint8_t data);
    bool readData(uint8_t &buffer);

private:
    int fd;

    void configurePort();
};

#endif // UART_H
