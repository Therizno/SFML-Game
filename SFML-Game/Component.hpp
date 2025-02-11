//
//  Component.hpp
//  SFML-Game
//
//  Created by Chief Nelson on 5/1/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#ifndef Component_hpp
#define Component_hpp
#include <SFML/System/NonCopyable.hpp>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Window.hpp>

namespace GUI
{
class Component : public sf::Drawable, public sf::Transformable, private sf::NonCopyable
{
    public:
        typedef std::shared_ptr<Component> Ptr;
        
    public:
        Component();
        virtual ~Component();
        
        virtual bool isSelectable() const = 0;
        bool isSelected() const;
        virtual void select();
        virtual void deselect();
        
        virtual bool isActive() const;
        virtual void activate();
        virtual void deactivate();
        
        virtual void handleEvent(const sf::Event& event) = 0;
        
    private:
        bool mIsSelected;
        bool mIsActive; 
};
}

#endif /* Component_hpp */
