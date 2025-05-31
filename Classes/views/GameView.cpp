#include "GameView.h"

#include "controllers/CardController.h"

GameView* GameView::create() {
    GameView* ret = new (std::nothrow) GameView();
    if (ret && ret->_init()) {
        ret->autorelease();
        return ret;
    }
    delete ret;
    return nullptr;
}

bool GameView::_init() {
    if (!Node::init()) return false;

    Size s(1080, 2080);
    this->setContentSize(s);

    return true;
}