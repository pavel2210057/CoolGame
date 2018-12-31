#include "stdafx.h"
#include "Loader.hpp"

Loader::Loader(void) {}

Loader::Loader(const char* _DLLName) :
	hModule(LoadLibrary((LPCWSTR)_DLLName)) {}

Loader::~Loader(void) {}

const void Loader::loadDLL(const char* _DLLName) {
	hModule = LoadLibrary((LPCWSTR)_DLLName);
}

const void Loader::freeDLL(void) {
	FreeLibrary(hModule);
}

const void Loader::replaceDLL(const char* _newDLLName) {
	freeDLL();
	loadDLL(_newDLLName);
}