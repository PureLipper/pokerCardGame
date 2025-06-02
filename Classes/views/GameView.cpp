#include "GameView.h"

#include "controllers/CardController.h"

GameView* GameView::create(Size s) {
    GameView* ret = new (std::nothrow) GameView();
    if (ret && ret->_init(s)) {
        ret->autorelease();
        return ret;
    }
    delete ret;
    return nullptr;
}

bool GameView::_init(Size s) {
    if (!Node::init()) return false;

    this->setContentSize(s);

    return true;
}