//
//  CommandQueue.hpp
//  SFML-Game
//
//  Created by Chief Nelson on 3/25/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#ifndef CommandQueue_hpp
#define CommandQueue_hpp

#include <stdio.h>

#include <queue>

#include "Command.hpp"

class CommandQueue
{
    public:
        void push(const Command& command);
        Command pop();
        bool isEmpty() const;
        
    private:
        std::queue<Command> mQueue;
};

#endif /* CommandQueue_hpp */
