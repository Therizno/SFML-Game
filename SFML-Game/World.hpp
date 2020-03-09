//
//  World.hpp
//  SFML-Game
//
//  Created by Chief Nelson on 3/8/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#ifndef World_hpp
#define World_hpp

#include <array>

#include <SFML/Graphics.hpp>

#include "SceneNode.h"
#include "Aircraft.hpp"
#include "SpriteNode.hpp"


class World : private sf::NonCopyable
{
    public:
        explicit World(sf::RenderWindow& window);
        void update(sf::Time dt);
        void draw();
        
    private:
        void loadTextures();
        void buildScene();
        
    private:
        enum Layer
        {
            Background, Air, LayerCount
        };

    private:
        sf::RenderWindow& mWindow;
        sf::View mWorldView;
        Textures::TextureHolder mTextures;
        SceneNode mSceneGraph;
        std::array<SceneNode*, LayerCount> mSceneLayers;
        
        sf::FloatRect mWorldBounds;
        sf::Vector2f mSpawnPosition;
        float mScrollSpeed;
        Aircraft* mPlayerAircraft;
        
};

#endif /* World_hpp */
