#include "GameScene.h"

#include "configs/LevelConfigLoader.h"
#include "controllers/GameController.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    return GameScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool GameScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    auto gc = GameController::getInstance();
    gc->initGame();
    gc->startGame(1);
    gc->addViewToScene(this);

    return true;
}
