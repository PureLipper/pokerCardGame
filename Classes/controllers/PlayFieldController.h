#pragma once

#include "CardController.h"
#include "cocos2d.h"
#include "models/CardStack.h"
#include "views/PlayFieldView.h"

/// <summary>
/// 桌面牌区控制器
/// </summary>
class PlayFieldController
{
private:
	PlayFieldView* _playFieldView;
	CardStack* _cardStack;

	std::map<CardModel*, CardController*> _cardControllers;

public:
	PlayFieldController(CardStack* cardStack);

	/// <summary>
	/// 初始化控制器
	/// </summary>
	void init();

	PlayFieldView* getPlayFieldView() const;

	CardStack* getCardStack() const;

	/// <summary>
	/// 根据CardModel的指针获取对应的控制器
	/// </summary>
	/// <param name="m">CardModel的指针</param>
	/// <returns>对应控制器</returns>
	CardController* getCardControllerByCardModel(CardModel* m);
};
