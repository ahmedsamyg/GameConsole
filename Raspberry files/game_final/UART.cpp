#include "UART.h"

SerialPort::SerialPort(const char* portName) {
    fd = open(portName, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        std::cerr << "Error opening serial port " << portName << std::endl;
    } else {
        fcntl(fd, F_SETFL, 0);
        configurePort();
    }
}

SerialPort::~SerialPort() {
    close(fd);
}

void SerialPort::writeData(uint8_t data) {
    if (fd != -1) {
        fcntl(fd, F_SETFL, O_NONBLOCK);  // Set non-blocking mode
        ssize_t bytesWritten = write(fd, &data, 1);
        if (bytesWritten < 0) {
            std::cerr << "Error writing data to serial port" << std::endl;
        }
    }
}

bool SerialPort::readData(uint8_t &input) {
    if (fd != -1) {
        // Set the file descriptor to non-blocking mode
        fcntl(fd, F_SETFL, O_NONBLOCK);

        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(fd, &read_fds);

        // Check if there is data available to read
        struct timeval timeout = {0, 0};  // No waiting time
        int ret = select(fd + 1, &read_fds, NULL, NULL, &timeout);
        
        if (ret > 0 && FD_ISSET(fd, &read_fds)) {
            int bytesRead = read(fd, &input, 1);  // Read one byte
            return (bytesRead > 0);  // Return true if data is successfully read
        }
    }
    return false;  // No data available
}

void SerialPort::configurePort() {
    struct termios options;
    tcgetattr(fd, &options);

    // Configure the serial port settings
    options.c_cflag = B9600 | CS8 | CLOCAL | CREAD; // 9600 baud, 8 data bits, no parity, 1 stop bit
    options.c_iflag = IGNPAR; // Ignore framing errors and parity errors
    options.c_oflag = 0;
    options.c_lflag = 0;

    // Apply the configuration
    tcflush(fd, TCIFLUSH);
    tcsetattr(fd, TCSANOW, &options);
}
