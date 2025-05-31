#pragma once
#include "CardModel.h"

/// <summary>
/// 记录一次操作，UndoManager可以根据此操作进行回档
/// </summary>
class UndoModel
{
private:

	/// <summary>
	/// 本次行动进行了移动的牌（点击的卡牌）
	/// </summary>
	CardModel* _moveCard;

	/// <summary>
	/// 本次行动被移除的牌（手牌顶部牌）
	/// </summary>
	CardModel* _removeCard;

public:
	UndoModel(CardModel*, CardModel*);

	CardModel* getMoveCard() const;

	CardModel* getRemoveCard() const;

	//Document* toJsonDocument();

	//UndoModel* fromJson(const std::string& json);

};