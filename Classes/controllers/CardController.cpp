#include "CardController.h"

#include "GameController.h"
#include "services/ReplaceService.h"
#include "services/UndoService.h"

CardController::CardController(CardModel* cardModel) :
	_cardModel(cardModel)
{
	initView();
	registerOnClickCallback();
}

void CardController::initView()
{
	_cardView = CardView::create(_cardModel);
}


void CardController::registerOnClickCallback() const
{
	if (_cardView != nullptr)
	{
		_cardView->setOnClick([this](){
			if (_cardModel != GameController::getInstance()->getCurrentGameModel()->getStack()->getCardList()->back()){
				if (ReplaceService::replace(_cardModel))
				{
					auto c = GameController::getInstance()->getStackController();
					Vec2 p1(c->top_X, c->y);
					Vec2 p2 = GameController::getInstance()->getStackController()->getStackView()->convertToWorldSpace(p1);
					Vec2 p3 = _cardView->getParent()->convertToNodeSpace(p2);
					_cardView->runAction(MoveTo::create(0.5, p3));
					
				}
			}
		});
	}
}

CardView* CardController::getCardView() const
{
	return _cardView;
}

CardModel* CardController::getCardModel() const
{
	return _cardModel;
}

void CardController::hideCardView() const
{
	_cardView->setVisible(false);
}

void CardController::showCardView() const
{
	_cardView->setVisible(true);
}