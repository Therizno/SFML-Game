//
//  State.hpp
//  SFML-Game
//
//  Created by Chief Nelson on 4/9/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#ifndef State_hpp
#define State_hpp

#include "StateIdentifiers.h"
#include "ResourceHolder.cpp"

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include <memory>


namespace sf
{
    class RenderWindow;
}

class StateStack;
class Player;

class State
{
    public:
        typedef std::unique_ptr<State> Ptr;

        struct Context
        {
            Context(sf::RenderWindow& window, Textures::TextureHolder& textures, Fonts::FontHolder& fonts, Player& player);

            sf::RenderWindow* window;
            Textures::TextureHolder* textures;
            Fonts::FontHolder* fonts;
            Player* player;
        };


    public:
        State(StateStack& stack, Context context);
        virtual ~State();

        virtual void draw() = 0;
        virtual bool update(sf::Time dt) = 0;
        virtual bool handleEvent(const sf::Event& event) = 0;


    protected:
        void requestStackPush(States::ID stateID);
        void requestStackPop();
        void requestStateClear();

        Context getContext() const;


    private:
        StateStack* mStack;
        Context mContext;
};

#endif /* State_hpp */
