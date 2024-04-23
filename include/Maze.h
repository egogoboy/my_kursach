#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#ifndef MAZE_H
#define MAZE_H

class Maze {
    public:

        Maze(int mazeSize) {
            this -> mazeSize = mazeSize;
            initMaze();
            std::cout << "log: maze was created\n";
        }

        void initMaze();

        bool isHorizontalWall(int i, int j);
        int getValueOfCell(int i, int j);
        int getMazeSize();

        void setCellOfSet(int value, int i, int j);
        void setHorizontalWall(int i, int j);
        void setVerticalWall(int i, int j);
        void setMazeSize(int mazeSize);

        void deleteHorizontalWall(int i, int j);
        void deleteVerticalWall(int i, int j);
        void clearMaze();

        void printMaze(Maze& maze, sf::RenderWindow& window);

    protected:

    private:
        int mazeSize;

        std::pair<int, int> start, finish;

        std::vector<std::vector<int>> vecOfSet;
        std::vector<std::vector<bool>> verticalWalls;
        std::vector<std::vector<bool>> horizontalWalls;

        const int PIXEL_MAZE_SIZE{640};
        const int EMPTY_CELL{0};
        //const string MAZE_CREATED = "log: maze was created\n";
        //const string MAZE_CLEARED = "log: maze was cleared\n";
};

#endif
