#pragma once

#include "cocos2d.h"
#include "managers/UndoManager.h"
#include "views/CardView.h"
#include "views/GameView.h"

USING_NS_CC;
/// <summary>
/// 卡牌控制器
/// </summary>
class CardController
{
private:
	CardModel* _cardModel;
	CardView* _cardView;

public:
	CardController(CardModel*);

	/// <summary>
	/// 初始化视图
	/// </summary>
	void initView();

	/// <summary>
	/// 给内部的cardView配置点击响应回调函数
	/// </summary>
	void registerOnClickCallback() const;

	CardModel* getCardModel() const;

	CardView* getCardView() const;

	void hideCardView() const;

	void showCardView() const;
};