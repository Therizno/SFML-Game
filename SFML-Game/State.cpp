//
//  State.cpp
//  SFML-Game
//
//  Created by Chief Nelson on 4/9/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#include "State.hpp"

#include "StateStack.hpp"

State::Context::Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, Player& player) : window(&window), textures(&textures), fonts(&fonts), player(&player) { }

State::State(StateStack& stack, Context context) : mStack(&stack), mContext(context) { } 

State::~State()
{
}

void State::requestStackPush(States::ID stateID)
{
    mStack->pushState(stateID);
}

void State::requestStackPop()
{
    mStack->popState();
}

void State::requestStateClear()
{
    mStack->clearStates();
}

State::Context State::getContext() const
{
    return mContext;
}
