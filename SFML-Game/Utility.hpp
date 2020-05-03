//
//  Utility.hpp
//  SFML-Game
//
//  Created by Chief Nelson on 4/14/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#ifndef Utility_hpp
#define Utility_hpp

#include <SFML/Window/Keyboard.hpp>

#include <string>

namespace sf
{
    class Sprite;
    class Text;
}

void centerOrigin(sf::Sprite& sprite);
void centerOrigin(sf::Text& text);

std::string toString(sf::Keyboard::Key key);

#endif /* Utility_hpp */
