#include "GameModel.h"

std::string GameModel::toJson() const
{
	return "{\"Playfield\":" + _playField->toJson() + ","
		+ "\"Stack\":" + _stack->toJson() + "}";
}


GameModel* GameModel::fromJson(const std::string& json)
{
	Document doc;
	doc.Parse(json.c_str());

	StringBuffer buffer1;
	Writer<StringBuffer> writer1(buffer1);
	doc["Playfield"].Accept(writer1);

	StringBuffer buffer2;
	Writer<StringBuffer> writer2(buffer2);
	doc["Stack"].Accept(writer2);

	std::string json1 = buffer1.GetString();
	std::string json2 = buffer2.GetString();

	CardStack* s1 = CardStack::fromJson(json1);
	CardStack* s2 = CardStack::fromJson(json2);

	GameModel* res = new GameModel(s1, s2);
	return res;
}

CardStack* GameModel::getPlayField()
{
	return _playField;
}

CardStack* GameModel::getStack()
{
	return _stack;
}
