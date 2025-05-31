#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "models/CardStack.h"
#include "models/CardModel.h"
#include "configs/CardResConfig.h"
#include "SimpleAudioEngine.h"

/// <summary>
/// ÓÎÏ·Ö÷³¡¾°
/// </summary>
class GameScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(GameScene);
};

#endif // __GAME_SCENE_H__
