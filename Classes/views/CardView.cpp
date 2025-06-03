#include "CardView.h"
#include "models/CardModel.h"

CardView* CardView::create(CardModel* card) {
    CardView* ret = new (std::nothrow) CardView();
    if (ret && ret->_init(card)) {
        ret->autorelease();
        return ret;
    }
    delete ret;
    return nullptr;
}

bool CardView::_init(CardModel* card) {
    if (!Node::init()) return false;

    auto textureCache = Director::getInstance()->getTextureCache();
    _background = Sprite::createWithTexture(textureCache->getTextureForKey("res/card_general.png"));
    this->setContentSize(_background->getContentSize());
	_smallNumber = Sprite::createWithTexture(textureCache->getTextureForKey("res/number/small_" + card->getResName() + ".png"));
    _bigNumber= Sprite::createWithTexture(textureCache->getTextureForKey("res/number/big_" + card->getResName() + ".png"));
    _suit = Sprite::createWithTexture(textureCache->getTextureForKey("res/suits/" + card->getSuitName() + ".png"));

    _background->setPosition(0, 0);
    _smallNumber->setPosition(-50, 100);
    _bigNumber->setPosition(0, -30);
    _suit->setPosition(50, 100);

    this->addChild(_background);
    this->addChild(_smallNumber);
    this->addChild(_bigNumber);
    this->addChild(_suit);

    this->setPosition(card->getPosition());

    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = [this](Touch* touch, Event* event) -> bool
        {
            if (!_enabled) return false;
            Vec2 locationInNode = this->convertToNodeSpace(touch->getLocation());
            Size size = this->getContentSize();
            Rect rect(-size.width/2, -size.height/2, size.width, size.height);

            if (rect.containsPoint(locationInNode)) {
                _onClick();
                CCLOG("CardModel touched");
                return true;
            }
            return false;
        };
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);

    return true;
}

void CardView::setOnClick(std::function<void()> onClick)
{
    _onClick = onClick;
}

void CardView::setEnabled(bool b)
{
    _enabled = b;
}
