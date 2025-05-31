#pragma once

#include "cocos2d.h"
#include "managers/UndoManager.h"
#include "views/CardView.h"
#include "views/GameView.h"

USING_NS_CC;
/// <summary>
/// ���ƿ�����
/// </summary>
class CardController
{
private:
	CardModel* _cardModel;
	CardView* _cardView;

public:
	CardController(CardModel*);

	/// <summary>
	/// ��ʼ����ͼ
	/// </summary>
	void initView();

	/// <summary>
	/// ���ڲ���cardView���õ����Ӧ�ص�����
	/// </summary>
	void registerOnClickCallback() const;

	CardModel* getCardModel() const;

	CardView* getCardView() const;

	void hideCardView() const;

	void showCardView() const;
};