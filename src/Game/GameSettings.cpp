#include "stdafx.h"
#include "GameSettings.hpp"

GameSettings::GameSettings(void) : Setting() {}

GameSettings::GameSettings(const char* _base) : Setting(_base) {}

GameSettings::~GameSettings(void) {}

const void GameSettings::append(const char* _fileway, const char* _what, const char* _newValue) const {
	if (dataWriteLine(_fileway, _what) && _newValue)
		dataReplace(_fileway, _what, _newValue);
}

const void GameSettings::clear(const char* _fileway) const {
	dataClear(_fileway);
}

const void GameSettings::replaceGameValue(const char* _fileway, const char* _what, const char* _newValue) const {
	dataReplace(_fileway, _what, _newValue);
}