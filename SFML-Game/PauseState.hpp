//
//  PauseState.hpp
//  SFML-Game
//
//  Created by Chief Nelson on 4/21/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#ifndef PauseState_hpp
#define PauseState_hpp

#include <SFML/Graphics.hpp>

#include "State.hpp"

#include "Container.hpp"

class PauseState : public State
{
    public:
        PauseState(StateStack& stack, Context context);
        
        virtual void draw();
        virtual bool update(sf::Time dt);
        virtual bool handleEvent(const sf::Event& event);
        
    private:
        sf::Sprite mBackgroundSprite;
        sf::Text mPausedText;
        sf::Text mInstructionText;
        
        
        GUI::Container mGUIContainer;
};

#endif /* PauseState_hpp */
