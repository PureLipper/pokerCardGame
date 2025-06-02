#pragma once
#include "cocos2d.h"

USING_NS_CC;

/// <summary>
/// ��Ϸ��ͼ������һ����Ϸ�����е���ͼ
/// </summary>
class GameView : public Node
{
private:

	/// <summary>
	/// ��GameView���г�ʼ��
	/// </summary>
	/// <param name="s">��ͼ�ߴ�</param>
	/// <returns>�Ƿ��ʼ���ɹ�</returns>
	bool _init(Size s);

public:
	/// <summary>
	/// ����GameView����
	/// </summary>
	/// <param name="gm">�󶨵�GameModel����</param>
	/// <param name="s>��ͼ�ߴ�</param>
	/// <returns>ʵ������GameView����</returns>
	static GameView* create(Size s);
};