#pragma once
#include"cocos2d.h"
#include"models/CardModel.h"

USING_NS_CC;

/// <summary>
/// 自定义CardView，使用时只需要指定绑定的Card对象
/// </summary>
class CardView : public Node{
private:
	Sprite* _background;//背景图片
	Sprite* _smallNumber;//小数字Sprite
	Sprite* _bigNumber;//大数字Sprite
	Sprite* _suit;//花色Sprite
	std::function<void()> _onClick;//点击事件回调函数
	
	/// <summary>
	/// 对CardView进行初始化
	/// </summary>
	/// <returns>是否初始化成功</returns>
	bool _init(CardModel* card);

public:
	/// <summary>
	/// 创建CardView对象
	/// </summary>
	/// <param name="card">绑定的Card对象</param>
	/// <returns>实例化的CardView对象</returns>
	static CardView* create(CardModel* card);

	/// <summary>
	/// 设置回调函数
	/// </summary>
	/// <param name="f">具体回调函数</param>
	void setOnClick(std::function<void()> f);
};