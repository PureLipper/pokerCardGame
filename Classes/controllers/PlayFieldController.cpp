#include "PlayFieldController.h"

#include "ui/UIButton.h"

PlayFieldController::PlayFieldController(CardStack* cardStack)
{
    this->_cardStack = cardStack;
}

void PlayFieldController::init()
{
    _playFieldView = PlayFieldView::create();

    auto stack = _cardStack->getCardList();
    for (auto card : *stack)
    {
        CardController* controller = new CardController(card);
        _cardControllers.emplace(card, controller);
        CardView* v = controller->getCardView();
        v->setPosition(card->getPosition());
        _playFieldView->addChild(v);
    }

}

PlayFieldView* PlayFieldController::getPlayFieldView() const
{
    return _playFieldView;
}

CardStack* PlayFieldController::getCardStack() const
{
    return _cardStack;
}

CardController* PlayFieldController::getCardControllerByCardModel(CardModel* m)
{
    return _cardControllers[m];
}
