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

void Player::handleRealtimeInput(CommandQueue& commands)
{
    const float playerSpeed = 30.f;
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        Command moveLeft;
        moveLeft.category = Category::PlayerAircraft;
        moveLeft.action = derivedAction<Aircraft>(AircraftMover(-playerSpeed, 0.f));
        commands.push(moveLeft);
    }
}

void Player::handleEvent(const sf::Event& event,
                            CommandQueue& commands)
   {
       if (event.type == sf::Event::KeyPressed
        && event.key.code == sf::Keyboard::P)
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
