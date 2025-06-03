#include "UndoManager.h"

#include "controllers/GameController.h"
#include "utils/GameUtils.h"

void UndoManager::joinUndoModel(UndoModel* model) const
{
	undoStack->push(model);
}

void UndoManager::popTopModel() const
{
	undoStack->pop();
}

UndoModel* UndoManager::getTopModel() const
{
	return undoStack->top();
}

void UndoManager::init()
{
	undoStack = new std::stack<UndoModel*>;
}

bool UndoManager::undo()
{
	if (undoStack->empty()) return false;

	UndoModel* undoModel = undoStack->top();
	undoStack->pop();

	auto m1 = undoModel->getMoveCard();
	auto m2 = undoModel->getRemoveCard();

	auto stackCards = GameController::getInstance()->getStackController()->getCardStack()->getCardList();
	stackCards->pop_back();
	stackCards->push_back(m2);
	GameUtils::getCardControllerByCard(m2)->showCardView();
	GameUtils::getCardControllerByCard(m2)->getCardView()->setEnabled(true);

	auto cards = undoModel->ifInStack() ? 
		GameController::getInstance()->getGameModel()->getStack()->getCardList() :
		GameController::getInstance()->getGameModel()->getPlayField()->getCardList();
	cards->insert(cards->begin() + undoModel->getSourceIndex(), m1);

	auto c = GameUtils::getCardControllerByCard(m1);
	c->getCardView()->runAction(MoveTo::create(0.5, undoModel->getSourcePosition()));

	return true;
}
