#include "StackController.h"

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
        _cardControllers.push_back(controller);
        CardView* v = controller->getCardView();
        v->setPosition(Vec2(start + i * padding, y));
        _stackView->addChild(v);
    }

    CardController* controller = new CardController(stack->back());
    _cardControllers.push_back(controller);
    CardView* top = controller->getCardView();
    top->setPosition(Vec2(top_X, y));
    _stackView->addChild(top);

    auto backspace = ui::Button::create();
    backspace->setTitleText("back");
    backspace->setScale9Enabled(true);
    backspace->setContentSize(Size(100, 50));
    backspace->setPosition(Vec2(950, y));
    //std::string fullPath = FileUtils::getInstance()->fullPathForFilename("fonts/weiruanyahei.ttf");
    backspace->setTitleFontName("fonts/weiruanyahei.ttf");
    backspace->setTitleFontSize(40);
    backspace->addClickEventListener([](Ref* sender)
        {
            //UndoManager::Undo();
        });
    

    _stackView->addChild(backspace);
}

StackView* StackController::getStackView() const
{
    return _stackView;
}

CardStack* StackController::getCardStack() const
{
    return _cardStack;
}
