
# Game Console Project

This project is a **TFT-based Game Console** built using a Raspberry Pi and an STM32F401 microcontroller. 
It includes three games: **SimonSays**, **Snake**, and **Brick Breaker**, with interactive graphics, sound effects, and IR remote control functionality.

## Overview

### Hardware Components
1. **Raspberry Pi**  
   - Handles game logic and TFT graphics display.  
   - Uses SPI communication for TFT screen updates and UART to receive control signals.

2. **STM32F401 Microcontroller**  
   - **IR Remote Control Interface**: Processes player inputs via IR remote.  
   - **UART Communication**: Sends control signals to the Raspberry Pi.  
   - **Sound System**: Implements R-2R DAC for interactive sound effects triggered by game events.  

3. **TFT Display**  
   - Provides graphical output for the games using SPI communication.  

4. **IR Remote Control**  
   - Allows players to control game actions.  

5. **R-2R DAC Sound System**  
   - Produces sound effects for an immersive gameplay experience.  

### Features
- **Graphical Games**: Simon, Snake, and Brick Breaker.  
- **Interactive Gameplay**: Controls via IR remote.  
- **Dynamic Sound Effects**: Triggered during gameplay events like scoring, collisions, or game over.  

## Software Components

### Raspberry Pi Codebase
1. **Main Game Loop** (`main.cpp`)  
   - Displays the welcome screen.  
   - Processes UART inputs from the STM32 to select and play games.  
   - Manages TFT rendering for game graphics.  

2. **Game Logic**  
   - `Simon.cpp` & `Snake.cpp` & `Brick.cpp`: Logic for individual games. 

3. **Hardware Drivers**  
   - `TFT.h`/`TFT.cpp`: SPI-based TFT driver for rendering images and graphics.  
   - `UART.h`/`UART.cpp`: UART communication for receiving commands from the STM32.

### STM32 Codebase
- **IR Remote Control Decoder**: Decodes player input from the IR remote.  
- **UART Protocol**: Sends input commands to the Raspberry Pi.  
- **Sound System**: Generates sounds for specific events using an R-2R DAC.  

### Images
- `images.h`: Contains all game images in `imageData`.  

### Configurations
- `config.h`: Contains game-specific macros, color definitions, and hardware configurations.  

## How It Works
1. The Raspberry Pi starts by displaying the welcome image on the TFT.  
2. When the STM32 sends the "WELCOME" signal, the TFT prompts the player to select a game.  
3. The player uses the IR remote to choose Simon, Snake, or Brick Breaker.  
4. The Raspberry Pi handles game logic and communicates graphical output to the TFT.  
5. The STM32 processes player input and plays sound effects via the DAC.  

## Usage Instructions
1. Connect the hardware:
   - Raspberry Pi to TFT (SPI).  
   - Raspberry Pi to STM32 (UART).  
   - STM32 to DAC and IR receiver.  

2. Compile and upload the STM32 code to the microcontroller.  
3. Deploy the Raspberry Pi game code:  
   ```bash
   g++ -o game main.cpp TFT.cpp UART.cpp simon.cpp snake.cpp brick.cpp -lwiringPi
   ./game
   ```
4. Start playing using the IR remote!  

## Project Structure
```plaintext
.
├──Raspberry Pi
│  ├── Source/
│	│	├──	main.cpp
│  │	├── simon.cpp
│  │	├── snake.cpp
│  │	├── brick.cpp
│  │	├── TFT.cpp
│  │	├── UART.cpp
│  ├── Headers/
│	│	├── simon.h
│	│	├── snake.h
│	│	├── brick.h
│	│	├── TFT.h
│  │	├── UART.h
│  │	├── config.h
│  │	├── images.h
├── STM32F401/
│   ├── Source/
│   │   ├── _initialize_hardware.c
│   │   ├── EXTI_program.c
│   │   ├── GPIO_program.c
│   │   ├── main.c
│   │   ├── NVIC_program.c
│   │   ├── RCC_program.c
│   │   ├── STK_program.c
│   │   ├── stm32f4xx_hal_msp.c
│   │   ├── USART_program.c
│   ├── Headers/
│   │    ├── BIT_MATH.h
│   │    ├── EXTI_config.h
│   │    ├── EXTI_interface.h
│   │    ├── EXTI_private.h
│   │    ├── GPIO_config.h
│   │    ├── GPIO_interface.h
│   │    ├── GPIO_private.h
│   │    ├── NVIC_config.h
│   │    ├── NVIC_interface.h
│	 │    ├── NVIC_private.h
│	 │    ├── RCC_config.h
│	 │    ├── RCC_private.h
│	 │    ├── Sound_Arrays.h
│	 │    ├── RCC_interface.h
│	 │    ├── STD_TYPES.h
│	 │    ├── STK_config.h
│	 │    ├── STK_interface.h
│	 │    ├── STK_private.h
│	 │    ├── stm32f4xx_hal_conf.h
│	 │    ├── USART_config.h
│	 │    ├── USART_interface.h
│	 │    ├── USART_private.h  
├── README.md
```

## Future Enhancements
- Improve sound quality with advanced DAC design.  
- Add more game options and dynamic animations. 
- Add a more advanced game controller using WiFi 


