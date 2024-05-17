#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#ifndef MAZE_H
#define MAZE_H
//#include <SFML/

class Maze {
    public:

        Maze(int mazeSize) {
            this -> mazeSize = mazeSize;
            initMaze();
            std::cout << "log: maze was created\n";
        }
        //virtual ~Maze();

        void initMaze() {
            vecOfSet = std::vector<std::vector<int>> (mazeSize, std::vector<int> (mazeSize, EMPTY_CELL));

            std::vector<std::vector<bool>> sample(mazeSize, std::vector<bool> (mazeSize, EMPTY_CELL));
            verticalWalls = sample;
            horizontalWalls = sample;

            start.first = 0; start.second = 0;
            finish.first = mazeSize - 1; finish.second = mazeSize - 1;

            std::cout << "log: maze was cleared\n";
        }

        void setMazeSize(int mazeSize) {
            this -> mazeSize = mazeSize;
        }

        int getMazeSize() {
            return this -> mazeSize;
        }

        void clearMaze() {
            for (int i = 0; i < mazeSize; i++)
                for (int j = 0; j < mazeSize; j++) {
                    vecOfSet[i][j] = 0;
                    horizontalWalls[i][j] = false;
                    verticalWalls[i][j] = false;
                }
        }

        std::vector<std::vector<int>> getVectorOfSet();
        std::vector<int> getLineOfSet(int index);
        std::vector<std::vector<bool>> getVectorOfHorWalls();
        std::vector<bool> getLineOfHorWalls(int index);
        std::vector<std::vector<bool>> getVectorOfVerWalls();

        bool isHorizontalWall(int i, int j) {
            return horizontalWalls[i][j];
        }

        int getValueOfCell(int i, int j) {
            return vecOfSet[i][j];
        }

        void setCellOfSet(int value, int i, int j);
        void setHorizontalWall(int i, int j);
        void setVerticalWall(int i, int j);

        void deleteHorizontalWall(int i, int j);
        void deleteVerticalWall(int i, int j);

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

#endif // MAZE_H
