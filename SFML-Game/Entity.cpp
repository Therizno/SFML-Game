//
//  Entity.cpp
//  SFML-Game
//
//  Created by Chief Nelson on 3/6/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#include "Entity.h"


void Entity::setVelocity(sf::Vector2f velocity)
{
    mVelocity = velocity;
}

void Entity::setVelocity(float x, float y)
{
    mVelocity.x = x;
    mVelocity.y = y;
}

sf::Vector2f Entity::getVelocity() const
{
    return mVelocity;
}


void Entity::updateCurrent(sf::Time dt)
{
    move(mVelocity * dt.asSeconds());
}
