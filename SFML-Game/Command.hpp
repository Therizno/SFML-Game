//
//  Command.hpp
//  SFML-Game
//
//  Created by Chief Nelson on 3/25/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#ifndef Command_hpp
#define Command_hpp

#include <stdio.h>

#include <SFML/Graphics.hpp>

#include "SceneNode.h"

struct Command
{
    std::function<void (SceneNode&, sf::Time)> action;
};

#endif /* Command_hpp */
