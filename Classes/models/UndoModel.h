#pragma once
#include "CardModel.h"

/// <summary>
/// 记录一次操作，UndoManager可以根据此操作进行回档
/// </summary>
class UndoModel
{
private:

	/// <summary>
	/// 本次移动的卡牌是否在手牌区
	/// </summary>
	bool _isInStack;

	/// <summary>
	/// 本次移动的卡牌在原数组中的位置
	/// </summary>
	int _sourceIndex;

	/// <summary>
	/// 本次移动的卡牌的原坐标
	/// </summary>
	Vec2 _sourcePosition;

	/// <summary>
	/// 本次行动进行了移动的牌（点击的卡牌）
	/// </summary>
	CardModel* _moveCard;

	/// <summary>
	/// 本次行动被移除的牌（手牌顶部牌）
	/// </summary>
	CardModel* _removeCard;

public:
	UndoModel(bool, int, Vec2, CardModel*, CardModel*);

	bool ifInStack() const;

	CardModel* getMoveCard() const;

	CardModel* getRemoveCard() const;

	int getSourceIndex() const;

	Vec2 getSourcePosition() const;

	//Document* toJsonDocument();

	//UndoModel* fromJson(const std::string& json);

};