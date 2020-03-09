//
//  SpriteNode.hpp
//  SFML-Game
//
//  Created by Chief Nelson on 3/8/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#ifndef SpriteNode_hpp
#define SpriteNode_hpp

#include <SFML/Graphics.hpp>

#include "SceneNode.h"

class SpriteNode : public SceneNode 
{
    public:
        explicit SpriteNode(const sf::Texture& texture);
        SpriteNode(const sf::Texture& texture, const sf::IntRect& rect);
        
    private:
        virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
        
    private:
        sf::Sprite mSprite;

};

#endif /* SpriteNode_hpp */
