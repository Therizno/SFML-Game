//
//  Button.cpp
//  SFML-Game
//
//  Created by Chief Nelson on 5/2/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#include "Button.hpp"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "Utility.hpp"


namespace GUI
{
  
  
Button::Button (const FontHolder& fonts, const TextureHolder& textures) : mCallback(), mNormalTexture(textures.get(Textures::ButtonNormal)), mSelectedTexture(textures.get(Textures::ButtonSelected)), mPressedTexture(textures.get(Textures::ButtonPressed)), mSprite(), mText("", fonts.get(Fonts::Main), 16), mIsToggle(false)
{
    mSprite.setTexture(mNormalTexture);
    
    sf::FloatRect bounds = mSprite.getLocalBounds();
    mText.setPosition(bounds.width/2.f, bounds.height/2.f);
}
  
void Button::setCallback(Callback callback)
{
    mCallback = std::move(callback);
}

void Button::setText(const std::string& text)
{
    mText.setString(text);
    centerOrigin(mText);
}

void Button::setToggle(bool flag)
{
    mIsToggle = flag;
}

bool Button::isSelectable() const
{
    return true;
}

void Button::select()
{
    Component::select();
    
    mSprite.setTexture(mSelectedTexture);
}

void Button::deselect()
{
    Component::deselect();
    
    mSprite.setTexture(mNormalTexture);
}

void Button::activate()
{
    Component::activate();
    
    if (mIsToggle)
        mSprite.setTexture(mPressedTexture);
        
    if (mCallback)
        mCallback();
        
    // deactivate if this is not a toggle button
    if (!mIsToggle)
        deactivate();
}

void Button::deactivate()
{
    Component::deactivate();
    
    if (mIsToggle)
    {
        // reset button to the right texture depending on if it is selected
        if(isSelected())
            mSprite.setTexture(mSelectedTexture);
        else
            mSprite.setTexture(mNormalTexture);
    }
}

void Button::handleEvent(const sf::Event&) { }

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    
    target.draw(mSprite, states);
    target.draw(mText, states); 
}

  
}
