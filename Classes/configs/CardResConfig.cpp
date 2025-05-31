#include "CardResConfig.h"

void CardResConfig::loadAllResource() {
	Director* _director = Director::getInstance();
	auto textureCache = _director->getTextureCache();
	std::string size[2] = {"big","small"};
	std::string color[2] = { "black","red" };

	textureCache->addImage("res/card_general.png");
	textureCache->addImage("res/suits/club.png");
	textureCache->addImage("res/suits/diamond.png");
	textureCache->addImage("res/suits/heart.png");
	textureCache->addImage("res/suits/spade.png");
	

	for (int i = 1;i <= 13;i++) {
		std::string number;
		switch (i) {
		case 1:
			number = "A";
			break;
		case 11:
			number = "J";
			break;
		case 12:
			number = "Q";
			break;
		case 13:
			number = "K";
			break;
		default:
			number = std::to_string(i);
			break;
		}
		textureCache->addImage("res/number/" + size[0] + "_" + color[0] + "_" + number + ".png");
		textureCache->addImage("res/number/" + size[0] + "_" + color[1] + "_" + number + ".png");
		textureCache->addImage("res/number/" + size[1] + "_" + color[0] + "_" + number + ".png");
		textureCache->addImage("res/number/" + size[1] + "_" + color[1] + "_" + number + ".png");
	}
}