#include "MySprite.h"

void MySprite::setPosition(float x, float y) {
    this -> x = x;
    this -> y = y;
    this -> sprite.setPosition(x, y);
}

void MySprite::setScale(float scale) {
    this -> sprite.scale(scale, scale);
}

sf::Sprite MySprite::getSprite() {
    return this -> sprite;
}
