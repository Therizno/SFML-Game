//
//  Entity.h
//  SFML-Game
//
//  Created by Chief Nelson on 3/6/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#ifndef Entity_h
#define Entity_h

#include <SFML/System.hpp>

class Entity
{
    public:
        void setVelocity(sf::Vector2f velocity);
        void setVelocity(float x, float y);
        sf::Vector2f getVelocity() const;
    
    private:
        sf::Vector2f mVelocity;
};


#endif /* Entity_h */
