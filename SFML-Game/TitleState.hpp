//
//  TitleState.hpp
//  SFML-Game
//
//  Created by Chief Nelson on 4/14/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#ifndef TitleState_hpp
#define TitleState_hpp

#include <SFML/Graphics.hpp>

#include "StateStack.hpp"


class TitleState : public State
{
    public:
        TitleState(StateStack& stack, State::Context context);
        
        virtual void draw();
        virtual bool update(sf::Time dt);
        virtual bool handleEvent(const sf::Event& event);
        
    private:
        sf::Sprite mBackgroundSprite;
        sf::Text mText;
        
        bool mShowText;
        sf::Time mTextEffectTime; 

};

#endif /* TitleState_hpp */
