#pragma once
#include "cocos2d.h"
#include "models/UndoModel.h"

USING_NS_CC;

/// <summary>
/// 回退控制器
/// </summary>
class UndoManager
{
private:
	std::stack<UndoModel*>* undoStack;//回退栈

public:
	/// <summary>
	/// 栈顶出站
	/// </summary>
	void popTopModel();

	/// <summary>
	/// 获取栈顶Model对象（不弹出）
	/// </summary>
	/// <returns>栈顶对象</returns>
	UndoModel* getTopModel();

	/// <summary>
	/// 向回退栈添加对象
	/// </summary>
	/// <param name="model">Model对象</param>
	void joinUndoModel(UndoModel* model);

	/// <summary>
	/// 初始化Manager
	/// </summary>
	void init();
};