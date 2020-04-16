//
//  StateStack.cpp
//  SFML-Game
//
//  Created by Chief Nelson on 4/9/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#include "StateStack.hpp"

StateStack::StateStack(State::Context context) : mStack(), mPendingList(), mContext(context), mFactories() { }


void StateStack::update(sf::Time dt)
{
    //Iterate from top to bottom, stop as soon as update() returns false
    for (auto itr = mStack.rbegin(); itr != mStack.rend(); ++itr)
    {
        if (!(*itr)->update(dt))
            break;
    }

    applyPendingChanges();
}

void StateStack::draw()
{
    // Draw all active states
    for(State::Ptr& state : mStack)
        state->draw();
}

State::Ptr StateStack::createState(States::ID stateID)
{
    auto found = mFactories.find(stateID);
    assert(found != mFactories.end());
    
    return found->second();
}

//Iterate from top to bottom, stop as soon as handleEvent() returns false
void StateStack::handleEvent(const sf::Event& event)
{
    for (auto itr = mStack.rbegin(); itr != mStack.rend(); ++itr)
    {
        if(!(*itr)->handleEvent(event))
        {
            return;
        }
        
        applyPendingChanges();
    }
}


void StateStack::applyPendingChanges()
{
    for(PendingChange change : mPendingList)
    {
        switch(change.action)
        {
            case Push:
                mStack.push_back(createState(change.stateID));
                break;
                
            case Pop:
                mStack.pop_back();
                break;
                
            case Clear:
                mStack.clear();
                break;
        }
    }
    
    mPendingList.clear(); 
}
