//
//  MenuState.cpp
//  SFML-Game
//
//  Created by Chief Nelson on 4/14/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#include "MenuState.hpp"

#include "Utility.hpp"

#include "Button.hpp"
#include "Utility.hpp"
#include "ResourceHolder.h"


MenuState::MenuState(StateStack& stack, Context context) : State(stack, context), mOptions(), mOptionIndex(0)
{
    sf::Texture& texture = context.textures->get(Textures::TitleScreen);
    mBackgroundSprite.setTexture(texture);
    
    auto playButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
    playButton->setPosition(100, 250);
    playButton->setText("Play");
    playButton->setCallback([this] ()
    {
        requestStackPop();
        requestStackPush(States::Game);
    });
    
    auto settingsButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
    settingsButton->setPosition(100, 300);
    settingsButton->setText("Settings");
    settingsButton->setCallback([this] ()
    {
        requestStackPush(States::Settings);
    });

    auto exitButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
    exitButton->setPosition(100, 350);
    exitButton->setText("Exit");
    exitButton->setCallback([this] ()
    {
        requestStackPop();
    });


    mGUIContainer.pack(playButton);
    mGUIContainer.pack(settingsButton);
    mGUIContainer.pack(exitButton);
}


void MenuState::draw()
{
    sf::RenderWindow& window = *getContext().window;

    window.setView(window.getDefaultView());
    
    window.draw(mBackgroundSprite);
    window.draw(mGUIContainer);
}

bool MenuState::update(sf::Time)
{
    return true;
}

bool MenuState::handleEvent(const sf::Event& event)
{
    mGUIContainer.handleEvent(event);
    return false;
}


