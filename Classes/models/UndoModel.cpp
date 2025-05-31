#include "UndoModel.h"

UndoModel::UndoModel(bool ifInStack, int sourceIndex, Vec2 sourcePosition, CardModel* moveCard, CardModel* removeCard)
{
	_isInStack = ifInStack;
	_sourceIndex = sourceIndex;
	_sourcePosition = sourcePosition;
	_moveCard = moveCard;
	_removeCard = removeCard;
}

CardModel* UndoModel::getMoveCard() const
{
	return _moveCard;
}

CardModel* UndoModel::getRemoveCard() const
{
	return _removeCard;
}

int UndoModel::getSourceIndex() const
{
	return _sourceIndex;
}

Vec2 UndoModel::getSourcePosition() const
{
	return _sourcePosition;
}

bool UndoModel::ifInStack() const
{
	return _isInStack;
}