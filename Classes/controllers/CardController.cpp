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
			if (_cardModel != GameController::getInstance()->getCurrentGameModel()->getStack()->getCardList().back()){
				if (ReplaceService::replace(_cardModel))
				{
					_cardView->runAction(MoveTo::create(0.5, Vec2()));
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