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

#include <map>

#include "Command.hpp"

class CommandQueue;

class Player
{
    public:
        enum Action
        {
            MoveLeft,
            MoveRight,
            MoveUp,
            MoveDown,
            ActionCount
        };
        
        Player();
        
        void assignKey(Action action, sf::Keyboard::Key key);
        sf::Keyboard::Key getAssignedKey(Action action) const;
        
        void handleEvent(const sf::Event& event, CommandQueue& commands);
        void handleRealtimeInput(CommandQueue& commands);
        
    private:
        static bool isRealTimeAction(Action action);
        
    private:
        std::map<sf::Keyboard::Key, Action> mKeyBinding;
        std::map<Action, Command> mActionBinding;

};


#endif /* Player_hpp */
