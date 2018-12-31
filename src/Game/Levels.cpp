#include "stdafx.h"
#include "Levels.hpp"

Level::Level(WindowRender& _win) :
	winRenderPtr(&_win) {
	loadDLL("Data/Levels/MainMenu.MAINMENU");

	((handle)GetProcAddress(hModule, "RenderMain"))(_win);

	importedHandleEvent = (handle)GetProcAddress(hModule, "EventMain");
}

Level::Level(WindowRender& _win, const char* _levelFileName) :
	winRenderPtr(&_win) {
	loadDLL(_levelFileName);

	((handle)GetProcAddress(hModule, "RenderMain"))(_win);

	importedHandleEvent = (handle)GetProcAddress(hModule, "EventMain");
}

Level::~Level(void) {}

const void Level::handleEvent(void) const {
	importedHandleEvent(*winRenderPtr);
}

const void Level::updateState(const char* _newFileName) {
	winRenderPtr->clearRenderBuffer();

	((handle)GetProcAddress(hModule, "RenderMain"))(*winRenderPtr);

	importedHandleEvent = (handle)GetProcAddress(hModule, "EventMain");
}

LevelManager::LevelManager(WindowRender& _win) :
	Level(_win), curLevelFileName("MainMenu.MAINMENU") {}

LevelManager::LevelManager(WindowRender& _win, const char* _levelFileName) :
	Level(_win, _levelFileName), curLevelFileName(_levelFileName) {}

LevelManager::~LevelManager(void) {}

const void LevelManager::loadLevel(const char* _levelFileName) {
	curLevelFileName = _levelFileName;
	replaceDLL(curLevelFileName);
	updateState(curLevelFileName);
}

const void LevelManager::reloadLevel(void) {
	replaceDLL(curLevelFileName);
	updateState(curLevelFileName);
}