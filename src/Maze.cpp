#include "Maze.h"
#include "MySprite.h"

void Maze::printMaze(Maze& maze, sf::RenderWindow& app) {

    int cell_size = PIXEL_MAZE_SIZE / maze.getMazeSize();
    sf::Font font;
    font.loadFromFile("font/Monocraft.ttf");

    MySprite vertWallSprite("images/vertical_right_line.png");
    MySprite horWallSprite("images/horizontal_low_line.png");
    MySprite frameSprite("images/frame.png");
    MySprite startSprite("images/start.png");

    frameSprite.setPosition(55, 20);

    float scale = 10 / float(maze.getMazeSize());

    vertWallSprite.setScale(scale);
    horWallSprite.setScale(scale);
    startSprite.setScale(scale);

    app.draw(frameSprite.getSprite());

    for (int i = 0; i < maze.getMazeSize(); i++) {
        for (int j = 0; j < maze.getMazeSize(); j++) {

            sf::Text text(std::to_string(vecOfSet[i][j]), font, 20);
            text.setColor(sf::Color::Black);
            text.scale(scale, scale);
            text.setPosition(70 + j * 60 * scale, 30 + i * 60 * scale);

            vertWallSprite.setPosition(60 + j * 60 * scale, 20 + i * 60 * scale);
            horWallSprite.setPosition(60 + j * 60 * scale, 20 + i * 60 * scale);

            if (horizontalWalls[i][j])
                app.draw(horWallSprite.getSprite());
            if (verticalWalls[i][j])
                app.draw(vertWallSprite.getSprite());

            //app.draw(text);
        }
    }

    startSprite.setPosition(58 + start.second * 60 * scale, 20 + start.first * 60 * scale);
    app.draw(startSprite.getSprite());

}

void Maze::setCellOfSet(int val, int i, int j) {
    vecOfSet[i][j] = val;
}

void Maze::setHorizontalWall(int i, int j) {
    horizontalWalls[i][j] = true;
}

void Maze::deleteHorizontalWall(int i, int j) {
    horizontalWalls[i][j] = false;
}

void Maze::deleteVerticalWall(int i, int j) {
    verticalWalls[i][j] = false;
}

void Maze::setVerticalWall(int i, int j) {
    verticalWalls[i][j] = true;
}

int Maze::getMazeSize() {
    return this -> mazeSize;
}

int Maze::getValueOfCell(int i, int j) {
    return this -> vecOfSet[i][j];
}

bool Maze::isHorizontalWall(int i, int j) {
    return this -> horizontalWalls[i][j];
}

void Maze::setMazeSize(int mazeSize) {
    this -> mazeSize = mazeSize;
}

void Maze::clearMaze() {
    for (int i = 0; i < mazeSize; i++)
        for (int j = 0; j < mazeSize; j++) {
            this -> vecOfSet[i][j] = 0;
            this -> horizontalWalls[i][j] = false;
            this -> verticalWalls[i][j] = false;
        }
}

void Maze::initMaze() {

    vecOfSet = std::vector<std::vector<int>> (mazeSize, std::vector<int> (mazeSize, EMPTY_CELL));

    std::vector<std::vector<bool>> sample(mazeSize, std::vector<bool> (mazeSize, EMPTY_CELL));
    this -> verticalWalls = sample;
    this -> horizontalWalls = sample;

    this -> start.first = 0; this -> start.second = 0;
    this -> finish.first = mazeSize - 1; this -> finish.second = mazeSize - 1;

    std::cout << "log: maze was cleared\n";
}
