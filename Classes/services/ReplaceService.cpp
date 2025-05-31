#include "ReplaceService.h"

#include "UndoService.h"
#include "controllers/GameController.h"

bool ReplaceService::replace(CardModel* m)
{
	auto gc = GameController::getInstance();
	auto gm = gc->getCurrentGameModel();
	auto playField = gm->getPlayField()->getCardList();
	auto stack = gm->getStack()->getCardList();
	//如果this在Playfield中
	if (std::find(playField.begin(), playField.end(), m) != playField.end())
	{
		if (UndoService::ifMatch(m, stack.back()))
		{
			gc->addUndoHistory(new UndoModel(m, stack.back()));

			playField.erase(
				std::remove_if(playField.begin(), playField.end(), [&](CardModel* c) {
					return c == m;
					}),
				playField.end()
			);
			stack.pop_back();
			stack.push_back(m);
			return true;
		}
		return false;
	}
	//如果this在Stack中
	else if (std::find(stack.begin(), stack.end(), m) != stack.end())
	{
		gc->addUndoHistory(new UndoModel(m,stack.back()));

		stack.erase(
			std::remove_if(stack.begin(), stack.end(), [&](CardModel* c) {
				return c == m;
				}),
			stack.end()
		);
		stack.pop_back();
		stack.push_back(m);
		return true;
	}
	return false;
}
