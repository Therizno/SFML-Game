//
//  Airplane.hpp
//  SFML-Game
//
//  Created by Chief Nelson on 3/6/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#ifndef Airplane_hpp
#define Airplane_hpp

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
        explicit Aircraft(Type type);
    
    private:
        Type mType;
};

#endif /* Airplane_hpp */
