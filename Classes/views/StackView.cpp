#include "StackView.h"

#include "ui/UIButton.h"


StackView* StackView::create() {
    StackView* ret = new (std::nothrow) StackView();
    if (ret && ret->_init()) {
        ret->autorelease();
        return ret;
    }
    delete ret;
    return nullptr;
}

bool StackView::_init() {
    if (!Node::init()) return false;

    this->setContentSize(Size(1080, 580));
    auto colorLayer = LayerColor::create(Color4B::MAGENTA);
    colorLayer->setContentSize(this->getContentSize());
    this->addChild(colorLayer, -1);

    return true;
}