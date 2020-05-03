//
//  ResourceIdentifiers.h
//  SFML-Game
//
//  Created by Chief Nelson on 4/15/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#ifndef ResourceIdentifiers_h
#define ResourceIdentifiers_h

// Forward declaration of SFML classes
namespace sf
{
    class Texture;
    class Font;
}

namespace Textures
{
    enum ID
    {
        Eagle,
        Raptor,
        Desert,
        TitleScreen,
        
        ButtonNormal,
        ButtonSelected,
        ButtonPressed
    };
}

namespace Fonts
{
    enum ID
    {
        Main,
    };
}

// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID> FontHolder;

#endif /* ResourceIdentifiers_h */
