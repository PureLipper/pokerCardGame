#pragma once

#include "CardController.h"
#include "cocos2d.h"
#include "models/CardStack.h"
#include "ui/UIButton.h"
#include "views/StackView.h"

/// <summary>
/// 手牌区控制器
/// </summary>
class StackController
{
private:
	StackView* _stackView;
	CardStack* _cardStack;
	ui::Button* _backspace;

	std::map<CardModel*, CardController*> _cardControllers;

public:
	float padding;//手牌间隔
	float start;//手牌起始位置
	float y;//CardView的y坐标

	float top_X = 750;//topCard的x坐标

	StackController(CardStack* cardStack);

	/// <summary>
	/// 初始化控制器
	/// </summary>
	void init();

	StackView* getStackView() const;

	CardStack* getCardStack() const;

	/// <summary>
	/// 根据CardModel的指针获取对应的控制器
	/// </summary>
	/// <param name="m">CardModel的指针</param>
	/// <returns>对应控制器</returns>
	CardController* getCardControllerByCardModel(CardModel* m);

	/// <summary>
	/// 启用或禁用回退按钮
	/// </summary>
	/// <param name="f">true/false</param>
	void setBackspaceAvailable(bool f) const;
};
