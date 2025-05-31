#pragma once

#include "CardController.h"
#include "cocos2d.h"
#include "models/CardStack.h"
#include "ui/UIButton.h"
#include "views/StackView.h"

/// <summary>
/// ������������
/// </summary>
class StackController
{
private:
	StackView* _stackView;
	CardStack* _cardStack;
	ui::Button* _backspace;

	std::map<CardModel*, CardController*> _cardControllers;

public:
	float padding;//���Ƽ��
	float start;//������ʼλ��
	float y;//CardView��y����

	float top_X = 750;//topCard��x����

	StackController(CardStack* cardStack);

	/// <summary>
	/// ��ʼ��������
	/// </summary>
	void init();

	StackView* getStackView() const;

	CardStack* getCardStack() const;

	CardController* getCardControllerByCardModel(CardModel* m);

	void setBackspaceAvailable(bool) const;
};
