#ifndef MAZEGENERATION_H
#define MAZEGENERATION_H

#include <Maze.h>
#include <random>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

class MazeGeneration {
    public:
        static void generateMaze(Maze& maze, sf::RenderWindow& app);

    protected:

    private:
        static void assignUniqueSet(Maze& maze, int numLine, int& countOfSet);
        static void mergeSet(Maze& maze, int numLine, int index, int elementOfSet);
        static void generateVerticalWalls(Maze& maze, int numLine);
        static void generateHorizontalWalls(Maze& maze, int numLine);
        static int calculateUniqueSet(Maze& maze, int numLine, int elementOfSet);
        static void checkHorizontalWalls(Maze& maze, int numLine);
        static int calculateHorizontalWalls(Maze& maze, int numLine, int elementOfSet);
        static void createNewLineNext(Maze& maze, int numLine);
        static void createLastLine(Maze& maze, int& countOfSet);
        static void checkEndLine(Maze& maze, int numLine);

        static const int FREQUENCY = 6;
};

#endif
