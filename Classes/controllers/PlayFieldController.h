#pragma once

#include "CardController.h"
#include "cocos2d.h"
#include "models/CardStack.h"
#include "views/PlayFieldView.h"

/// <summary>
/// ��������������
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
	/// ��ʼ��������
	/// </summary>
	void init();

	PlayFieldView* getPlayFieldView() const;

	CardStack* getCardStack() const;

	/// <summary>
	/// ����CardModel��ָ���ȡ��Ӧ�Ŀ�����
	/// </summary>
	/// <param name="m">CardModel��ָ��</param>
	/// <returns>��Ӧ������</returns>
	CardController* getCardControllerByCardModel(CardModel* m);
};
