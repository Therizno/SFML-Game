//
//  Airplane.cpp
//  SFML-Game
//
//  Created by Chief Nelson on 3/6/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#include "Aircraft.hpp"

#include "Utility.hpp"

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
    return Textures::Eagle;
}


Aircraft::Aircraft(Type type, const TextureHolder& textures) : mType(type), mSprite(textures.get(toTextureID(type)))
{
    centerOrigin(mSprite);
}


void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
}

unsigned int Aircraft::getCategory() const
{
    switch (mType) {
    
        case Eagle:
            return Category::PlayerAircraft;
            break;

        default:
            return Category::EnemyAircraft;
    }
}
