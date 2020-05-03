//
//  SettingsState.hpp
//  SFML-Game
//
//  Created by Chief Nelson on 5/3/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#ifndef SettingsState_hpp
#define SettingsState_hpp

#include "State.hpp"
#include "Player.hpp"
#include "Container.hpp"
#include "Button.hpp"
#include "Label.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <array>


class SettingsState : public State
{
    public:
        SettingsState(StateStack& stack, Context context);

        virtual void draw();
        virtual bool update(sf::Time dt);
        virtual bool handleEvent(const sf::Event& event);


    private:
        void updateLabels();
        void addButtonLabel(Player::Action action, float y, const std::string& text, Context context);


    private:
        sf::Sprite mBackgroundSprite;
        GUI::Container mGUIContainer;
        std::array<GUI::Button::Ptr, Player::ActionCount> mBindingButtons;
        std::array<GUI::Label::Ptr, Player::ActionCount> mBindingLabels;
};

#endif /* SettingsState_hpp */
