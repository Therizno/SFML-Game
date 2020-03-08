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
        
        void update(sf::Time dt);
        
    
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
        
        virtual void updateCurrent(sf::Time dt);
        void updateChildren(sf::Time dt);
        
    
    private:
        std::vector<Ptr> mChildren;
        SceneNode* mParent;
};


enum Layer
{
    Background, Air, LayerCount
};

#endif /* SceneNode_hpp */
