//
//  Component.cpp
//  SFML-Game
//
//  Created by Chief Nelson on 5/1/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#include "Component.hpp"

namespace GUI
{

Component::Component() : mIsSelected(false), mIsActive(false) { }

Component::~Component() { }

bool Component::isSelected() const
{
    return mIsSelected;
}

void Component::select()
{
    mIsSelected = true;
}

void Component::deselect()
{
    mIsSelected = false;
}

bool Component::isActive() const
{
    return mIsActive;
}

void Component::activate()
{
    mIsActive = true;
}

void Component::deactivate()
{
    mIsActive = false;
}

}
