#include "stdafx.h"
#include "Save.hpp"

Save::Save(const char* _savedir) : GameSettings(_savedir) {}

Save::~Save(void) {}

const void Save::appendSave(const char* _record, const char* _newValue) const {
	append("", _record, _newValue);
}

const void Save::clearSaves(void) const {
	clear("");
}