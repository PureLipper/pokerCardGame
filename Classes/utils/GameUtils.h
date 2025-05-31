#pragma once
#include "controllers/CardController.h"
#include "models/CardModel.h"

class GameUtils
{
public:
	static CardController* getCardControllerByCard(CardModel*);
};
