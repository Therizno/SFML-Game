//
//  Container.hpp
//  SFML-Game
//
//  Created by Chief Nelson on 5/1/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#ifndef Container_hpp
#define Container_hpp

#include "Component.hpp"

#include <vector>
#include <memory>


namespace GUI
{

class Container : public Component
{
    public:
        typedef std::shared_ptr<Container> Ptr;
            
    public:
        Container();

        void pack(Component::Ptr component);

        virtual bool isSelectable() const;
        virtual void handleEvent(const sf::Event& event);


    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        bool hasSelection() const;
        void select(std::size_t index);
        void selectNext();
        void selectPrevious();


    private:
        std::vector<Component::Ptr> mChildren;
        int mSelectedChild; 
};

}

#endif /* Container_hpp */
