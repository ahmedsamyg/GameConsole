#include "snake.h"
#include <cstdlib>
#include <ctime>

// Constructor
Snake::Snake() {
    std::srand(std::time(0));  // Seed for random number generation
}

// Initialize the game settings with display and serial objects
void Snake::initializeGame(TFT &display, SerialPort &serial) {
    this->display = &display;
    this->serial = &serial;

    snakeBody = {{60, 80}, {50, 80}, {40, 80}};  // Initial snake body
    direction = RIGHT;                           // Initial direction
    gameOver = false;                            // Reset game-over status
    spawnFood();                                 // Initial food spawn

    display.init();
}

// Main game loop that handles input, updates, and rendering
void Snake::runGameLoop() {
    while (!gameOver) {
        uint8_t input;
        if (serial->readData(input)) {
            // Map UART input to direction if valid
            if (input == UP || input == DOWN || input == LEFT || input == RIGHT) {
                updateGame(static_cast<Direction>(input));
            }
        } else {
            // Continue in the current direction if no input is received
            updateGame(direction);
        }

        // Render snake and food
        render();

        // Delay for game speed control
        delay(250);
    }

    // Show game over screen
    display->displayImage(imageData[7],TFT_WIDTH,TFT_HEIGHT);
    delay(5000);
    return;
}

// Update snake's movement, check collisions, and grow if needed
void Snake::updateGame(Direction newDirection) {
    // Update direction if valid
    if ((newDirection == UP && direction !=    DOWN) ||
        (newDirection == DOWN && direction !=  UP) ||
        (newDirection == LEFT && direction !=  RIGHT) ||
        (newDirection == RIGHT && direction != LEFT)) {
        direction = newDirection;
    }

    // Move snake and check for collisions
    move();

    if (checkFoodCollision()) {
        grow();
        spawnFood();
    }

    // Update game-over status if any collision occurs
    if (checkSelfCollision() || checkWallCollision()) {
        gameOver = true;
    }
}

// Move the snake in the current direction
void Snake::move() {
    Point newHead = snakeBody.front();

    switch (direction) {
        case UP:    newHead.y -= blockSize; break;
        case DOWN:  newHead.y += blockSize; break;
        case LEFT:  newHead.x -= blockSize; break;
        case RIGHT: newHead.x += blockSize; break;
    }

    // Insert new head and remove the tail if not growing
    snakeBody.insert(snakeBody.begin(), newHead);
    snakeBody.pop_back();
}

// Check if snake has collided with food
bool Snake::checkFoodCollision() {
    return snakeBody.front().x == foodPosition.x && snakeBody.front().y == foodPosition.y;
}

// Check if snake's head collides with any body segment
bool Snake::checkSelfCollision() const {
    const Point &head = snakeBody.front();
    for (size_t i = 1; i < snakeBody.size(); ++i) {
        if (snakeBody[i].x == head.x && snakeBody[i].y == head.y) {
            return true;
        }
    }
    return false;
}

// Check if snake's head collides with screen boundaries
bool Snake::checkWallCollision() const {
    const Point &head = snakeBody.front();
    return (head.x < 0 || head.x >= TFT_WIDTH || head.y < 0 || head.y >= TFT_HEIGHT);
}

// Spawn food at a random location that avoids the snake's body
void Snake::spawnFood() {
    bool foodOnSnake;
    do {
        foodPosition.x = (std::rand() % (TFT_WIDTH / blockSize)) * blockSize;
        foodPosition.y = (std::rand() % (TFT_HEIGHT / blockSize)) * blockSize;

        foodOnSnake = false;
        for (const auto &segment : snakeBody) {
            if (segment.x == foodPosition.x && segment.y == foodPosition.y) {
                foodOnSnake = true;
                break;
            }
        }
    } while (foodOnSnake);
}

// Grow the snake by adding a new segment at the end
void Snake::grow() {
    snakeBody.push_back(snakeBody.back());
}

// Render snake and food on the display
void Snake::render() {
    display->fillScreen(BLACK); // Clear screen

    // Draw the snake
    for (const auto &segment : snakeBody) {
        display->drawRectangle(segment.x, segment.y, blockSize, blockSize, GREEN);
    }

    // Draw the food
    display->drawRectangle(foodPosition.x, foodPosition.y, blockSize, blockSize, RED);
}
