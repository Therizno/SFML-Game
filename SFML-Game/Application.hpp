//
//  Application.hpp
//  SFML-Game
//
//  Created by Chief Nelson on 4/14/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#ifndef Application_hpp
#define Application_hpp


#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

#include "Player.hpp"
#include "StateStack.hpp"


class Application
{
    public:
        Application();
        void run();
        

    private:
        void processInput();
        void update(sf::Time dt);
        void render();

        void updateStatistics(sf::Time dt);
        void registerStates();


    private:
        static const sf::Time TimePerFrame;

        sf::RenderWindow mWindow;
        TextureHolder mTextures;
        FontHolder mFonts;
        Player mPlayer;

        StateStack mStateStack;

        sf::Text mStatisticsText;
        sf::Time mStatisticsUpdateTime;
        std::size_t mStatisticsNumFrames;
};


#endif /* Application_hpp */
