#pragma once

#include "CardController.h"
#include "cocos2d.h"
#include "models/CardStack.h"
#include "views/StackView.h"

/// <summary>
/// ������������
/// </summary>
class StackController
{
private:
	StackView* _stackView;
	CardStack* _cardStack;

	std::vector<CardController*> _cardControllers;

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
};
