#pragma once
#include "LevelConfigLoader.h"

const std::string LevelConfigLoader::kConfigFolderPath = "config/levelConfig.json";

void LevelConfigLoader::loadAllLevelConfig()
{
	std::string fullPath = FileUtils::getInstance()->fullPathForFilename(kConfigFolderPath);

	std::string fileContent = FileUtils::getInstance()->getStringFromFile(fullPath);

	Document* doc = new Document();
	doc->Parse(fileContent.c_str());

	LevelConfig::registerLevel(1, doc);
}

