#include "Maze.h"

void Maze::printMaze(Maze& maze, sf::RenderWindow& app) {

    int cell_size = PIXEL_MAZE_SIZE / maze.getMazeSize();
    sf::Font font;
    font.loadFromFile("font/Monocraft.ttf");

    sf::Texture cellTexture,
                vertWallTexture,
                horWallTexture,
                frameTexture,
                startTexture;

    cellTexture.loadFromFile("images/cell.png");
    vertWallTexture.loadFromFile("images/vertical_right_line.png");
    horWallTexture.loadFromFile("images/horizontal_low_line.png");
    frameTexture.loadFromFile("images/frame.png");
    startTexture.loadFromFile("images/start.png");

    sf::Sprite cellSprite,
               vertWallSprite,
               horWallSprite,
               frameSprite,
               startSprite;

    cellSprite.setTexture(cellTexture);
    vertWallSprite.setTexture(vertWallTexture);
    horWallSprite.setTexture(horWallTexture);
    frameSprite.setTexture(frameTexture);
    startSprite.setTexture(startTexture);

    frameSprite.setPosition(55, 20);

    float scale = 10 / float(maze.getMazeSize());

    cellSprite.scale(scale, scale);
    vertWallSprite.scale(scale, scale);
    horWallSprite.scale(scale, scale);
    startSprite.scale(scale, scale);

    std::vector<std::vector<bool>> horizontalWalls = maze.getVectorOfHorWalls(),
                                  verticalWalls = maze.getVectorOfVerWalls();

    app.draw(frameSprite);

    for (int i = 0; i < maze.getMazeSize(); i++) {
        for (int j = 0; j < maze.getMazeSize(); j++) {

            sf::Text text(std::to_string(vecOfSet[i][j]), font, 20);
            text.setColor(sf::Color::Black);
            text.scale(scale, scale);
            text.setPosition(70 + j * 60 * scale, 30 + i * 60 * scale);

            vertWallSprite.setPosition(60 + j * 60 * scale, 20 + i * 60 * scale);
            horWallSprite.setPosition(60 + j * 60 * scale, 20 + i * 60 * scale);
            cellSprite.setPosition(60 + j * 60 * scale, 20 + i * 60 * scale);

            //app.draw(cellSprite);

            if (horizontalWalls[i][j])
                app.draw(horWallSprite);
            if (verticalWalls[i][j])
                app.draw(vertWallSprite);

            //app.draw(text);

            //std::cout << vecOfSet[i][j] << " ";
        }
        //std::cout << std::endl;
    }

    startSprite.setPosition(58 + start.second * 60 * scale, 20 + start.first * 60 * scale);
    app.draw(startSprite);

}

std::vector<std::vector<int>> Maze::getVectorOfSet() {
    return vecOfSet;
}

std::vector<int> Maze::getLineOfSet(int index) {
    return this -> vecOfSet[index];
}

std::vector<std::vector<bool>> Maze::getVectorOfHorWalls() {
    return horizontalWalls;
}

std::vector<bool> Maze::getLineOfHorWalls(int index) {
    return this -> horizontalWalls[index];
}

std::vector<std::vector<bool>> Maze::getVectorOfVerWalls() {
    return verticalWalls;
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
