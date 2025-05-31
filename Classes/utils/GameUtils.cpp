#include "GameUtils.h"

#include "controllers/GameController.h"

CardController* GameUtils::getCardControllerByCard(CardModel* m)
{
	auto c = GameController::getInstance()->getStackController()->getCardControllerByCardModel(m);
	if (c == nullptr)
	{
		c = GameController::getInstance()->getPlayFieldController()->getCardControllerByCardModel(m);
	}
	return c;
}
