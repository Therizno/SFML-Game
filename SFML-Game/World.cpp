//
//  World.cpp
//  SFML-Game
//
//  Created by Chief Nelson on 3/8/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#include "World.hpp"


World::World(sf::RenderWindow& window)
: mWindow(window)
, mWorldView(window.getDefaultView())
, mTextures()
, mSceneGraph()
, mSceneLayers()
, mWorldBounds(0.f, 0.f, mWorldView.getSize().x, 2000.f)
, mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize().y / 2.f)
, mScrollSpeed(-50.f)
, mPlayerAircraft(nullptr)
{
    loadTextures();
    buildScene();

    mWorldView.setCenter(mSpawnPosition);
}


void World::loadTextures()
{
    mTextures.load(Textures::Eagle, "plane.png");
    mTextures.load(Textures::Raptor, "enemy_plane.png");
    mTextures.load(Textures::Desert, "sand.jpg");
}

void World::buildScene()
{
    for (std::size_t i = 0; i < LayerCount; ++i)
    {
        SceneNode::Ptr layer(new SceneNode());
        mSceneLayers[i] = layer.get();
        
        mSceneGraph.attachChild(std::move(layer));
    }
    
    sf::Texture& texture = mTextures.get(Textures::Desert);
    sf::IntRect textureRect(mWorldBounds);
    texture.setRepeated(true);
    
}
