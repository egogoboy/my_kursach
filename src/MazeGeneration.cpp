#include "MazeGeneration.h"

void MazeGeneration::generateMaze(Maze& maze, sf::RenderWindow& app) {

    std::srand(time(0));
    int countOfSet = 1;

    for (int i = 0; i < maze.getMazeSize(); i++) {

        assignUniqueSet(maze, i, countOfSet);
        generateVerticalWalls(maze, i);
        generateHorizontalWalls(maze, i);
        checkHorizontalWalls(maze, i);

        if (i != maze.getMazeSize() - 1)
            createNewLineNext(maze, i);

    }
    createLastLine(maze, countOfSet);

}

void MazeGeneration::createNewLineNext(Maze& maze, int numLine) {

    for (int i = 0; i < maze.getMazeSize(); i++) {
        maze.setCellOfSet(maze.getValueOfCell(numLine, i), numLine + 1, i);
        if (maze.isHorizontalWall(numLine, i))
            maze.setCellOfSet(0, numLine + 1, i);
    }
}

void MazeGeneration::createLastLine(Maze& maze, int& countOfSet) {

    int numLine = maze.getMazeSize() - 1;
    checkEndLine(maze, numLine);

}

void MazeGeneration::checkEndLine(Maze& maze, int numLine) {

    for (int i = 0; i < maze.getMazeSize() - 1; i++) {

        if (maze.getValueOfCell(numLine, i) != maze.getValueOfCell(numLine, i + 1)) {
            maze.deleteVerticalWall(numLine, i);
            mergeSet(maze, numLine, i, maze.getValueOfCell(numLine, i));
        }

        maze.setHorizontalWall(numLine, i);
    }

    maze.setHorizontalWall(numLine, maze.getMazeSize() - 1);

}

void MazeGeneration::assignUniqueSet(Maze& maze, int numLine, int& countOfSet) {

    for (int i = 0; i < maze.getMazeSize(); i++) {
        if (maze.getValueOfCell(numLine, i) == 0) {
            maze.setCellOfSet(countOfSet, numLine, i);
            countOfSet++;
        }
    }
}

void MazeGeneration::generateVerticalWalls(Maze& maze, int numLine) {

    for (int j = 0; j < maze.getMazeSize() - 1; j++) {

        int choise = std::rand() % 10;

        if ((choise < FREQUENCY) || (maze.getValueOfCell(numLine, j) == maze.getValueOfCell(numLine, j + 1))) {
            maze.setVerticalWall(numLine, j);
        }
        else {
            mergeSet(maze, numLine, j, maze.getValueOfCell(numLine, j));
        }

    }

    maze.setVerticalWall(numLine, maze.getMazeSize() - 1);

}

void MazeGeneration::generateHorizontalWalls(Maze& maze, int numLine) {

    for (int i = 0; i < maze.getMazeSize(); i++) {

        int choise = std::rand() % 10;

        if (choise < FREQUENCY - 2 && (calculateUniqueSet(maze, numLine, maze.getValueOfCell(numLine, i)) != 1)) {
            maze.setHorizontalWall(numLine, i);
        }

    }

}

void MazeGeneration::checkHorizontalWalls(Maze& maze, int numLine) {

    for (int i = 0; i < maze.getMazeSize(); i++) {

        if (calculateHorizontalWalls(maze, numLine, maze.getValueOfCell(numLine, i)) == 0) {
            maze.deleteHorizontalWall(numLine, i);
        }
    }
}

int MazeGeneration::calculateHorizontalWalls(Maze& maze, int numLine, int elementOfSet) {

    int result = 0;

    for (int i = 0; i < maze.getMazeSize(); i++) {
        if ((maze.getValueOfCell(numLine, i) == elementOfSet) && (!maze.isHorizontalWall(numLine, i)))
            result++;
    }

    return result;

}

int MazeGeneration::calculateUniqueSet(Maze& maze, int numLine, int elementOfSet) {

    int result = 0;

    for (int i = 0; i < maze.getMazeSize(); i++) {
        if (maze.getValueOfCell(numLine, i) == elementOfSet)
            result++;
    }

    return result;
}

void MazeGeneration::mergeSet(Maze& maze, int numLine, int index, int elementOfSet) {

    int mutableSet = maze.getValueOfCell(numLine, index + 1);

    for (int j = 0; j < maze.getMazeSize(); j++) {
        if (maze.getValueOfCell(numLine, j) == mutableSet) {
            maze.setCellOfSet(elementOfSet, numLine, j);
        }
    }

}
