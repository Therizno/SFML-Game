//
//  SpriteNode.cpp
//  SFML-Game
//
//  Created by Chief Nelson on 3/8/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#include "SpriteNode.hpp"

SpriteNode::SpriteNode(const sf::Texture& texture) : mSprite(texture) {}

SpriteNode::SpriteNode(const sf::Texture& texture, const sf::IntRect& rect) : mSprite(texture, rect) {}


void SpriteNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
}
