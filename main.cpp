#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <vector>
#include <Maze.h>
#include <MazeGeneration.h>

using namespace sf;

int main() {

    RenderWindow app(VideoMode(1280, 720), "backtracking");

    CircleShape circle;
    circle.setRadius(100);
    circle.setPosition(500, 300);
    circle.setFillColor(Color::Magenta);
    circle.setOutlineColor(Color::Green);

    sf::Font font;
    font.loadFromFile("font/Monocraft.ttf");

    RectangleShape rect;
    //rect.setSize()

    Maze maze(5);

    sf::Text gen("press 'g' to generate maze", font, 20);
    sf::Text es("press 'esc' to finish program", font, 20);
    gen.setPosition(700, 70);
    gen.setColor(Color::Black);
    es.setPosition(700, 120);
    es.setColor(Color::Black);

    while (app.isOpen()) {
        Event event;
        while (app.pollEvent(event)) {
            if (event.type == Event::Closed)
                app.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape))
            app.close();

        if (Keyboard::isKeyPressed(Keyboard::G)) {
            maze.clearMaze();
            MazeGeneration::generateMaze(maze, app);
        }

        circle.move(0.1, 0);

        app.clear(Color::White);

        app.draw(gen);
        app.draw(es);

        maze.printMaze(maze, app);

        app.display();
    }

    return EXIT_SUCCESS;
}
