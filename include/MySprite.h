#ifndef MYSPRITE_H
#define MYSPRITE_H
#include <SFML/Graphics.hpp>

class MySprite
{
    public:

        MySprite(std::string fileName) {
            this -> texture.loadFromFile(fileName);
            this -> sprite.setTexture(texture);
        }

        void setPosition(float x, float y);
        void setScale(float scale);
        sf::Sprite getSprite();

    protected:

    private:
        sf::Texture texture;
        sf::Sprite sprite;
        float x, y;
};

#endif
