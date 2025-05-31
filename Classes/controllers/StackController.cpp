#include "StackController.h"

#include "GameController.h"
#include "ui/UIButton.h"

StackController::StackController(CardStack* cardStack)
{
	this->_cardStack = cardStack;
}

void StackController::init()
{
    _stackView = StackView::create();

    padding = 120;
    start = 250;
    y = _stackView->getContentSize().height / 2;

    auto stack = _cardStack->getCardList();
    for (int i = 0;i < stack->size() - 1;i++)
    {
        CardController* controller = new CardController((*stack)[i]);
        _cardControllers.emplace((*stack)[i], controller);
        CardView* v = controller->getCardView();
        v->setPosition(Vec2(start + i * padding, y));
        _stackView->addChild(v);
    }

    CardController* controller = new CardController(stack->back());
    _cardControllers.emplace(stack->back(),controller);
    CardView* top = controller->getCardView();
    top->setPosition(Vec2(top_X, y));
    _stackView->addChild(top);

    _backspace = ui::Button::create();
    _backspace->setTitleText("back");
    _backspace->setScale9Enabled(true);
    _backspace->setContentSize(Size(100, 50));
    _backspace->setPosition(Vec2(950, y));
    //std::string fullPath = FileUtils::getInstance()->fullPathForFilename("fonts/weiruanyahei.ttf");
    _backspace->setTitleFontName("fonts/weiruanyahei.ttf");
    _backspace->setTitleFontSize(40);
    _backspace->addClickEventListener([](Ref* sender)
        {
            GameController::getInstance()->getUndoManager()->undo();
        });
    

    _stackView->addChild(_backspace);
}

StackView* StackController::getStackView() const
{
    return _stackView;
}

CardStack* StackController::getCardStack() const
{
    return _cardStack;
}


CardController* StackController::getCardControllerByCardModel(CardModel* m)
{
    return _cardControllers[m];
};

void StackController::setBackspaceAvailable(bool f) const
{
    _backspace->setEnabled(f);
    _backspace->setBright(f);
}
