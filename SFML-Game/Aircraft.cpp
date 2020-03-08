//
//  Airplane.cpp
//  SFML-Game
//
//  Created by Chief Nelson on 3/6/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#include "Aircraft.hpp"

//global function
Textures::ID toTextureID(Aircraft::Type type)
{
    switch (type) {
    
        case Aircraft::Eagle:
            return Textures::Eagle;
            break;

        case Aircraft::Raptor:
            return Textures::Raptor;
            break;
    }
}


Aircraft::Aircraft(Type type, const Textures::TextureHolder& textures) : mType(type), mSprite(textures.get(toTextureID(type))){}

void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
}
