//
//  Application.cpp
//  SFML-Game
//
//  Created by Chief Nelson on 4/14/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#include "Application.hpp"

#include "MenuState.hpp"
#include "PauseState.hpp"
#include "SettingsState.hpp"

const sf::Time Application::TimePerFrame = sf::seconds(1.f/60.f);

Application::Application()
: mWindow(sf::VideoMode(640, 480), "States", sf::Style::Close)
, mTextures()
, mFonts()
, mPlayer()
, mStateStack(State::Context(mWindow, mTextures, mFonts, mPlayer))
, mStatisticsText()
, mStatisticsUpdateTime()
, mStatisticsNumFrames(0)
{
    mWindow.setKeyRepeatEnabled(false);

    mFonts.load(Fonts::Main, "Sansation.ttf");
    
    mTextures.load(Textures::TitleScreen, "TitleScreen.jpg");
    mTextures.load(Textures::ButtonNormal, "ButtonNormal.png");
    mTextures.load(Textures::ButtonSelected, "ButtonSelected.png");
    mTextures.load(Textures::ButtonPressed, "ButtonPressed.png");

    mStatisticsText.setFont(mFonts.get(Fonts::Main));
    mStatisticsText.setPosition(5.f, 5.f);
    mStatisticsText.setCharacterSize(10u);

    registerStates();
    mStateStack.pushState(States::Title);
}

void Application::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (mWindow.isOpen())
    {
        sf::Time dt = clock.restart();
        timeSinceLastUpdate += dt;
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;

            processInput();
            update(TimePerFrame);

            // Check inside this loop, because stack might be empty before update() call
            if (mStateStack.isEmpty())
                mWindow.close();
        }

        render();
    }
}

void Application::registerStates()
{
    mStateStack.registerState<TitleState>(States::Title);
    mStateStack.registerState<MenuState>(States::Menu);
    mStateStack.registerState<GameState>(States::Game);
    mStateStack.registerState<PauseState>(States::Pause);
    mStateStack.registerState<SettingsState>(States::Settings);
}

void Application::processInput()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        mStateStack.handleEvent(event);

        if (event.type == sf::Event::Closed)
            mWindow.close();
    }
}

void Application::update(sf::Time dt)
{
    mStateStack.update(dt);
}

void Application::render()
{
    mWindow.clear();

    mStateStack.draw();

    mWindow.setView(mWindow.getDefaultView());
    mWindow.draw(mStatisticsText);

    mWindow.display();
}
