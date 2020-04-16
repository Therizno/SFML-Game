//
//  MenuState.hpp
//  SFML-Game
//
//  Created by Chief Nelson on 4/14/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#ifndef MenuState_hpp
#define MenuState_hpp

#include "GameState.hpp"

class MenuState : public State
{
    public:
        MenuState(StateStack& stack, Context context);
        
        virtual void draw();
        virtual bool update(sf::Time dt);
        virtual bool handleEvent(const sf::Event& event);
        
        void updateOptionText();
        
    private:
        enum OptionNames
        {
            Play, Exit
        };
        
    private:
        sf::Sprite mBackgroundSprite;
        std::vector<sf::Text> mOptions;
        std::size_t mOptionIndex; 
};

#endif /* MenuState_hpp */
