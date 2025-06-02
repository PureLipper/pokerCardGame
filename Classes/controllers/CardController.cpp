#include "CardController.h"

#include "GameController.h"
#include "services/ReplaceService.h"
#include "utils/GameUtils.h"

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
			auto topCard = GameController::getInstance()->getCurrentGameModel()->getStack()->getCardList()->back();
			if (_cardModel != topCard){
				if (ReplaceService::replace(_cardModel))
				{
					auto c = GameController::getInstance()->getStackController();
					Vec2 p1(c->top_X, c->y);
					Vec2 p2 = GameController::getInstance()->getStackController()->getStackView()->convertToWorldSpace(p1);
					Vec2 p3 = _cardView->getParent()->convertToNodeSpace(p2);

					GameController::getInstance()->setBackspaceAvailable(false);

					auto c0 = GameUtils::getCardControllerByCard(topCard);

					_cardView->stopAllActions();
					auto moveTo = MoveTo::create(0.5, p3);
					auto callback = CallFunc::create([topCard,c0]() {
						c0->hideCardView();
						GameController::getInstance()->setBackspaceAvailable(true);
					});
					auto action = Sequence::create(moveTo, callback, nullptr);
					_cardView->runAction(action);
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