#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <ctime>
using namespace std;


const int WIDTH = 20;
const int HEIGHT = 20;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };

class Position {
public:
    int x, y;
    Position(int x = 0, int y = 0) : x(x), y(y) {}
    bool operator==(const Position& other) const {
        return x == other.x && y == other.y;
    }
};

class Snake {
public:
    vector<Position> body;
    Direction dir;

    Snake() {
        dir = RIGHT; 
        body.push_back(Position(WIDTH / 2, HEIGHT / 2));
    }

    void move() {
        if (dir == STOP) return;

        
        for (int i = body.size() - 1; i > 0; --i)
            body[i] = body[i - 1];

        
        switch (dir) {
        case LEFT:  body[0].x--; break;
        case RIGHT: body[0].x++; break;
        case UP:    body[0].y--; break;
        case DOWN:  body[0].y++; break;
        }
    }

    void grow() {
        body.push_back(body.back());
    }

    bool collided() {
        Position head = body[0];
        
        if (head.x <= 0 || head.x >= WIDTH - 1 || head.y <= 0 || head.y >= HEIGHT - 1)
            return true;
        
        for (int i = 1; i < body.size(); i++)
            if (body[i] == head)
                return true;
        return false;
    }
};


class Game {
private:
    Snake snake;
    Position food;
    int score;
    bool gameOver;

public:
    Game() {
        srand(time(0));
        score = 0;
        gameOver = false;
        spawnFood();
    }

    void spawnFood() {
        while (true) {
            food = Position(rand() % (WIDTH - 2) + 1, rand() % (HEIGHT - 2) + 1);
            bool onSnake = false;
            for (const auto& segment : snake.body) {
                if (food == segment) {
                    onSnake = true;
                    break;
                }
            }
            if (!onSnake)
                break;
        }
    }

    void draw() {
        system("cls");
        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                Position current(x, y);
                if (x == 0 || x == WIDTH - 1 || y == 0 || y == HEIGHT - 1)
                    cout << "#";
                else if (current == snake.body[0])
                    cout << "O"; 
                else if (current == food)
                    cout << "F";
                else {
                    bool isBody = false;
                    for (int i = 1; i < snake.body.size(); i++) {
                        if (current == snake.body[i]) {
                            cout << "o";
                            isBody = true;
                            break;
                        }
                    }
                    if (!isBody)
                        cout << " ";
                }
            }
            cout << endl;
        }
        cout << "Score: " << score << endl;
    }

    void input() {
        if (_kbhit()) {
            char ch = _getch();
            switch (ch) {
            case 'a':
                if (snake.dir != RIGHT) snake.dir = LEFT;
                break;
            case 'd':
                if (snake.dir != LEFT) snake.dir = RIGHT;
                break;
            case 'w':
                if (snake.dir != DOWN) snake.dir = UP;
                break;
            case 's':
                if (snake.dir != UP) snake.dir = DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
            }
        }
    }

    void logic() {
        snake.move();

        
        if (snake.collided()) {
            gameOver = true;
            return;
        }

        
        if (snake.body[0] == food) {
            score += 10;
            snake.grow();
            spawnFood();
        }
    }

    void run() {
        while (!gameOver) {
            draw();
            input();
            logic();
            Sleep(200); 
        }
        cout << "Game Over! Final Score: " << score << endl;
    }
};

int main() {
    Game game;
    game.run();
    return 0;
}