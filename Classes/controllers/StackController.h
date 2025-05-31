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

	float padding;//���Ƽ��
	float start;//������ʼλ��
	float y;//CardView��y����

	std::vector<CardController*> _cardControllers;

public:
	StackController(CardStack* cardStack);

	/// <summary>
	/// ��ʼ��������
	/// </summary>
	void init();

	StackView* getStackView() const;

	CardStack* getCardStack() const;
};
