//
//  SceneNode.cpp
//  SFML-Game
//
//  Created by Chief Nelson on 3/6/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#include "SceneNode.h"

void SceneNode::attachChild(Ptr child)
{
    child->mParent = this;
    mChildren.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detatchChild(const SceneNode& node)
{
    auto found = std::find_if(mChildren.begin(), mChildren.end(),
    [&] (Ptr& p) -> bool { return p.get() == &node;});
    
    assert(found != mChildren.end());
    
    Ptr result = std::move(*found);
    result->mParent = nullptr;
    mChildren.erase(found);
    return result;
}
