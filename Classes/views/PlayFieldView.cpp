#include "PlayFieldView.h"

PlayFieldView* PlayFieldView::create() {
    PlayFieldView* ret = new (std::nothrow) PlayFieldView();
    if (ret && ret->_init()) {
        ret->autorelease();
        return ret;
    }
    delete ret;
    return nullptr;
}

bool PlayFieldView::_init() {
    if (!Node::init()) return false;

    this->setContentSize(Size(1080, 1500));
    auto colorLayer = LayerColor::create(Color4B::ORANGE);
    colorLayer->setContentSize(this->getContentSize());
    this->addChild(colorLayer, -1);

    return true;
}