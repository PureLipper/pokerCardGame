#pragma once

#include "cocos2d.h"
USING_NS_CC;

/// <summary>
/// ��������ͼ
/// </summary>
class StackView : public Node
{
private:
	/// <summary>
	/// ��StackView���г�ʼ��
	/// </summary>
	/// <returns>�Ƿ��ʼ���ɹ�</returns>
	bool _init();

public:
	/// <summary>
	/// ����StackView����
	/// </summary>
	/// <returns>ʵ������StackView����</returns>
	static StackView* create();

};
