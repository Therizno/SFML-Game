//
//  Player.cpp
//  SFML-Game
//
//  Created by Chief Nelson on 3/25/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//
#include <iostream>

#include "Player.hpp"

#include "Aircraft.hpp"

#include "CommandQueue.hpp"

struct AircraftMover
{
    sf::Vector2f velocity;
    
    AircraftMover(float vx, float vy) : velocity(vx, vy) { }
    
    void operator() (Aircraft& aircraft, sf::Time) const
    {
        aircraft.accelerate(velocity.x, velocity.y);
    }
};

Player::Player() 
{
    const float playerSpeed = 250.f;
    
    mKeyBinding[sf::Keyboard::Left] = MoveLeft;
    mKeyBinding[sf::Keyboard::Right] = MoveRight;

    mActionBinding[MoveLeft].action = derivedAction<Aircraft>(AircraftMover(-playerSpeed, 0.f));
    mActionBinding[MoveRight].action = derivedAction<Aircraft>(AircraftMover(+playerSpeed, 0.f));
       
       for (auto& pair : mActionBinding)
           pair.second.category = Category::PlayerAircraft;
}

void Player::handleRealtimeInput(CommandQueue& commands)
{
    for(auto pair : mKeyBinding)
    {
        if (sf::Keyboard::isKeyPressed(pair.first) && isRealTimeAction(pair.second))
        {
            commands.push(mActionBinding[pair.second]);
        }
    }
}

void Player::handleEvent(const sf::Event& event,
                            CommandQueue& commands)
{
       if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
       {
           Command output;
           output.category = Category::PlayerAircraft;
           output.action = [] (SceneNode& s, sf::Time)
           {
               std::cout << s.getPosition().x << ","
                         << s.getPosition().y << "\n";
};
           commands.push(output);
       }
 }


void Player::assignKey(Action action, sf::Keyboard::Key key)
{
    // Remove all keys that already map to action
    for (auto itr = mKeyBinding.begin(); itr != mKeyBinding.end(); )
    {
        if (itr->second == action)
            mKeyBinding.erase(itr++);
        else
            ++itr;
    }

    // Insert new binding
    mKeyBinding[key] = action;
}

sf::Keyboard::Key Player::getAssignedKey(Action action) const
{
    for(auto pair : mKeyBinding)
    {
        if (pair.second == action)
            return pair.first;
    }

    return sf::Keyboard::Unknown;
}


bool Player::isRealTimeAction(Action action)
{
    switch (action)
    {
        case MoveLeft:
        case MoveRight:
        case MoveDown:
        case MoveUp:
            return true;

        default:
            return false;
    }
}


