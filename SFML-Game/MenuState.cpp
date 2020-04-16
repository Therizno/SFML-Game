//
//  MenuState.cpp
//  SFML-Game
//
//  Created by Chief Nelson on 4/14/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#include "MenuState.hpp"

#include "Utility.hpp"


MenuState::MenuState(StateStack& stack, Context context) : State(stack, context), mOptions(), mOptionIndex(0)
{
    sf::Texture& texture = context.textures->get(Textures::TitleScreen);
    sf::Font& font = context.fonts->get(Fonts::Main);
    
    mBackgroundSprite.setTexture(texture);
    
    
    //code for menu display
    sf::Text playOption;
    
    playOption.setFont(font);
    playOption.setString("Play");
    
    centerOrigin(playOption);
    
    playOption.setPosition(context.window->getView().getSize()/2.f);
    mOptions.push_back(playOption);
    
    
    sf::Text exitOption;
    
    exitOption.setFont(font);
    exitOption.setString("Exit");
    
    centerOrigin(exitOption);
    
    exitOption.setPosition(playOption.getPosition() + sf::Vector2f(0.f, 30.f));
    mOptions.push_back(exitOption);
    
}


void MenuState::draw()
{
    sf::RenderWindow& window = *getContext().window;

    window.setView(window.getDefaultView());
    window.draw(mBackgroundSprite);

    for(const sf::Text& text : mOptions)
        window.draw(text);
}

bool MenuState::update(sf::Time)
{
    return true;
}

bool MenuState::handleEvent(const sf::Event& event)
{
    if(event.type != sf::Event::KeyPressed)
        return false;
        
    if(event.key.code == sf::Keyboard::Return)
    {
        if(mOptionIndex == Play)
        {
            requestStackPop();
            requestStackPush(States::Game);
        }
        else if (mOptionIndex == Exit)
        {
            // game quits when stack is empty
            requestStackPop();
        }
    }
    else if (event.key.code == sf::Keyboard::Up)
    {
        if(mOptionIndex > 0)
        {
            mOptionIndex--;
        }
        else
        {
            mOptionIndex = mOptions.size() - 1;
        }
        
        updateOptionText();
    }
    else if (event.key.code == sf::Keyboard::Down)
    {
        if(mOptionIndex < mOptions.size() - 1)
        {
            mOptionIndex++;
        }
        else
        {
            mOptionIndex = 0;
        }
        
        updateOptionText();
    }
    
    return true;
}

void MenuState::updateOptionText()
{
    if(mOptions.empty())
    {
        return;
    }
    
    for(sf::Text& text : mOptions)
    {
        text.setColor(sf::Color::White);
    }
    
    //highlight selected text 
    mOptions[mOptionIndex].setColor(sf::Color::Red);
}
