//
//  Category.h
//  SFML-Game
//
//  Created by Chief Nelson on 3/25/20.
//  Copyright © 2020 Chief Nelson. All rights reserved.
//

#ifndef Category_h
#define Category_h

namespace Category {
  enum Type
  {
    None = 0,
    Scene = 1 << 0,
    PlayerAircraft = 1 << 1,
    AlliedAircraft = 1 << 2,
    EnemyAircraft = 1 << 3
  };
}

#endif /* Category_h */
