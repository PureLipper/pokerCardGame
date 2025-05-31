#pragma once

#include "CardController.h"
#include "cocos2d.h"
#include "models/CardStack.h"
#include "views/StackView.h"

/// <summary>
/// 手牌区控制器
/// </summary>
class StackController
{
private:
	StackView* _stackView;
	CardStack* _cardStack;

	float padding;//手牌间隔
	float start;//手牌起始位置
	float y;//CardView的y坐标

	std::vector<CardController*> _cardControllers;

public:
	StackController(CardStack* cardStack);

	/// <summary>
	/// 初始化控制器
	/// </summary>
	void init();

	StackView* getStackView() const;

	CardStack* getCardStack() const;
};
