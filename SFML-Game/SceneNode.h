//
//  SceneNode.h
//  SFML-Game
//
//  Created by Chief Nelson on 3/6/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#ifndef SceneNode_h
#define SceneNode_h

#include <SFML/Graphics.hpp>

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
    public:
        typedef std::unique_ptr<SceneNode> Ptr;
    
    public:
        SceneNode();
        void attachChild(Ptr child);
        Ptr detatchChild(const SceneNode& node);
    
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const; 
    
    private:
        std::vector<Ptr> mChildren;
        SceneNode* mParent;
};

#endif /* SceneNode_hpp */
