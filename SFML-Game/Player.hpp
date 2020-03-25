//
//  Player.hpp
//  SFML-Game
//
//  Created by Chief Nelson on 3/25/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <SFML/Window/Event.hpp>

#include "Command.hpp"

class CommandQueue;

class Player
{
    public:
        void handleEvent(const sf::Event& event, CommandQueue& commands);
        void handleRealtimeInput(CommandQueue& commands);
};


#endif /* Player_hpp */
