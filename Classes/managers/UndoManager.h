#pragma once
#include "cocos2d.h"
#include "models/UndoModel.h"

USING_NS_CC;

/// <summary>
/// ���˿�����
/// </summary>
class UndoManager
{
private:
	std::stack<UndoModel*>* undoStack;//����ջ

public:
	/// <summary>
	/// ջ����վ
	/// </summary>
	void popTopModel() const;

	/// <summary>
	/// ��ȡջ��Model���󣨲�������
	/// </summary>
	/// <returns>ջ������</returns>
	UndoModel* getTopModel() const;

	/// <summary>
	/// �����ջ��Ӷ���
	/// </summary>
	/// <param name="model">Model����</param>
	void joinUndoModel(UndoModel* model) const;

	/// <summary>
	/// ��ʼ��Manager
	/// </summary>
	void init();

	/// <summary>
	/// ����һ�λ���,�������ջΪ���򷵻�false
	/// </summary>
	bool undo();
};