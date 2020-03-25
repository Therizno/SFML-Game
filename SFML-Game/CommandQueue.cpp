//
//  CommandQueue.cpp
//  SFML-Game
//
//  Created by Chief Nelson on 3/25/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#include "CommandQueue.hpp"

void CommandQueue::push(const Command& command)
{
    mQueue.push(command);
}

Command CommandQueue::pop()
{
    Command command = mQueue.front();
    mQueue.pop();
    return command;
}

bool CommandQueue::isEmpty() const
{
    return mQueue.empty();
}
