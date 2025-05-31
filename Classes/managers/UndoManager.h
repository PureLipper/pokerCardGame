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
	void popTopModel();

	/// <summary>
	/// ��ȡջ��Model���󣨲�������
	/// </summary>
	/// <returns>ջ������</returns>
	UndoModel* getTopModel();

	/// <summary>
	/// �����ջ��Ӷ���
	/// </summary>
	/// <param name="model">Model����</param>
	void joinUndoModel(UndoModel* model);

	/// <summary>
	/// ��ʼ��Manager
	/// </summary>
	void init();
};