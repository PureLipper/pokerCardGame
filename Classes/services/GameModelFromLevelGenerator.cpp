#include "GameModelFromLevelGenerator.h"

#include "utils/JsonUtils.h"

GameModel* GameModelFromLevelGenerator::getGameModel(int level)
{
	Document* levelConfig = LevelConfig::getLevelConfig(level);
	std::string json = JsonUtils::toString(levelConfig);
	return GameModel::fromJson(json);
}
