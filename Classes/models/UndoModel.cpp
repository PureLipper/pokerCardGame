#include "UndoModel.h"

UndoModel::UndoModel(CardModel* moveCard, CardModel* removeCard)
{
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