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
    for (int i = 0;i < stack.size() - 1;i++)
    {
        CardController* controller = new CardController(stack[i]);
        _cardControllers.push_back(controller);
        CardView* v = controller->getCardView();
        v->setPosition(Vec2(start + i * padding, y));
        _stackView->addChild(v);
    }

    CardController* controller = new CardController(stack.back());
    _cardControllers.push_back(controller);
    CardView* top = controller->getCardView();
    top->setPosition(Vec2(750, y));
    _stackView->addChild(top);

    auto backspace = ui::Button::create();
    backspace->setTitleText("»ØÍË");
    backspace->setContentSize(Size(400, 200));
    backspace->setPosition(Vec2(950, y));
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
