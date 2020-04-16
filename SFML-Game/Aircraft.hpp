//
//  Airplane.hpp
//  SFML-Game
//
//  Created by Chief Nelson on 3/6/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#ifndef Airplane_hpp
#define Airplane_hpp

#include <SFML/Graphics.hpp>

#include "ResourceHolder.inl"

#include "Entity.h"

class Aircraft : public Entity
{
    public:
        enum Type
        {
            Eagle,
            Raptor
        };
    
    public:
        explicit Aircraft(Type type, const Textures::TextureHolder& textures);
        virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
        
        virtual unsigned int getCategory() const;
    
    private:
        Type mType;
        sf::Sprite mSprite; 
};

#endif /* Airplane_hpp */
