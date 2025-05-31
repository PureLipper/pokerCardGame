#include "ReplaceService.h"

#include "MatchService.h"
#include "controllers/GameController.h"
#include "utils/GameUtils.h"

int findCardModel(std::vector<CardModel*>* cards, CardModel* m)
{
	for (int i = 0;i < cards->size();i++)
	{
		if ((*cards)[i] == m)
		{
			return i;
		}
	}
	return -1;
}

bool ReplaceService::replace(CardModel* m)
{
	auto gc = GameController::getInstance();
	auto gm = gc->getCurrentGameModel();
	auto playField = gm->getPlayField()->getCardList();
	auto stack = gm->getStack()->getCardList();
	int index = findCardModel(playField, m);
	if (index != -1)
	{
		if (MatchService::ifMatch(m, stack->back()))
		{
			gc->addUndoHistory(new UndoModel(false, index, m->getPosition(), m, stack->back()));
			playField->erase(playField->begin() + index);
			stack->pop_back();
			stack->push_back(m);
			return true;
		}
		return false;
	}else
	{
		index = findCardModel(stack, m);
		gc->addUndoHistory(new UndoModel(true, index, GameUtils::getCardControllerByCard(m)->getCardView()->getPosition(), m, stack->back()));
		stack->erase(stack->begin() + index);
		stack->pop_back();
		stack->push_back(m);
		return true;
	}
	return false;
}
