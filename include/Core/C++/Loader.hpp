#ifndef LOADER_HPP
#define LOADER_HPP

#include "Core\C++\API.hpp"
#include <Windows.h>

/*
 *Loader - класс для загрузки, выгрузки и замены файлов DLL
 */
class API_EXPORT Loader {
protected:
	HMODULE		hModule;
	
	Loader(void);

	Loader(const wchar_t* _DLLName);

	~Loader(void);

	const void loadDLL(const wchar_t* _DLLName);

	const void freeDLL(void);

	const void replaceDLL(const wchar_t* _newDLLName);
};

#endif //!LOADER_HPP