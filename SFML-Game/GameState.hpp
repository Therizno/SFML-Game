//
//  GameState.hpp
//  SFML-Game
//
//  Created by Chief Nelson on 4/14/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#ifndef GameState_hpp
#define GameState_hpp

#include "World.hpp"
#include "State.hpp"

#include "Player.hpp"

class GameState : public State
{
    public:
        GameState(StateStack& stack, Context context);
        
        virtual void draw();
        virtual bool update(sf::Time dt);
        virtual bool handleEvent(const sf::Event& event);
        
    private:
        World mWorld;
        Player& mPlayer;
};

#endif /* GameState_hpp */
