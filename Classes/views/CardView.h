#pragma once
#include"cocos2d.h"
#include"models/CardModel.h"

USING_NS_CC;

/// <summary>
/// �Զ���CardView��ʹ��ʱֻ��Ҫָ���󶨵�Card����
/// </summary>
class CardView : public Node{
private:
	Sprite* _background;//����ͼƬ
	Sprite* _smallNumber;//С����Sprite
	Sprite* _bigNumber;//������Sprite
	Sprite* _suit;//��ɫSprite
	std::function<void()> _onClick;//����¼��ص�����
	
	/// <summary>
	/// ��CardView���г�ʼ��
	/// </summary>
	/// <returns>�Ƿ��ʼ���ɹ�</returns>
	bool _init(CardModel* card);

public:
	/// <summary>
	/// ����CardView����
	/// </summary>
	/// <param name="card">�󶨵�Card����</param>
	/// <returns>ʵ������CardView����</returns>
	static CardView* create(CardModel* card);

	/// <summary>
	/// ���ûص�����
	/// </summary>
	/// <param name="f">����ص�����</param>
	void setOnClick(std::function<void()> f);
};