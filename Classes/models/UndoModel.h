#pragma once
#include "CardModel.h"

/// <summary>
/// ��¼һ�β�����UndoManager���Ը��ݴ˲������лص�
/// </summary>
class UndoModel
{
private:

	/// <summary>
	/// �����ƶ��Ŀ����Ƿ���������
	/// </summary>
	bool _isInStack;

	/// <summary>
	/// �����ƶ��Ŀ�����ԭ�����е�λ��
	/// </summary>
	int _sourceIndex;

	/// <summary>
	/// �����ƶ��Ŀ��Ƶ�ԭ����
	/// </summary>
	Vec2 _sourcePosition;

	/// <summary>
	/// �����ж��������ƶ����ƣ�����Ŀ��ƣ�
	/// </summary>
	CardModel* _moveCard;

	/// <summary>
	/// �����ж����Ƴ����ƣ����ƶ����ƣ�
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