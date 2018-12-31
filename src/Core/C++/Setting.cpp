#include "stdafx.h"
#include "Setting.hpp"

Setting::Setting(void) {}

Setting::Setting(const char* _base): base(_base) {}

Setting::~Setting(void) {}

const void Setting::dataWrite(const char* _fileway, const char* _what) const {
	std::ofstream file(std::string(base + _fileway).c_str(), std::ios::binary | std::ios::app);
	file << _what;
	file.close();
}

const bool Setting::dataWriteLine(const char* _fileway, const char* _what) const {
	bool flag = false;
	std::ofstream file(std::string(base + _fileway).c_str(), std::ios::binary | std::ios::app);

	if (!isEmpty(_fileway)) {
		flag = true;
		file << "\n";
	}
	file << _what;

	file.close();

	return flag;
}

const void Setting::dataClear(const char* _fileway) const {
	std::ofstream file(std::string(base + _fileway).c_str(), std::ios::binary);
	file.clear();
	file.close();
}

const void Setting::dataReplace(const char* _fileway, const char* _what, const char* _newValue) const {
	Py_Initialize();

	PyRun_SimpleString("import sys\nsys.path.append('../CoolGame')");
	
	PyObject* const moduleName = PyUnicode_FromString("Tools.Python.PyTools");

	PyObject* const modulePython = PyImport_Import(moduleName);
	
	Py_DECREF(moduleName);

	PyObject* const function = PyObject_GetAttrString(modulePython, "dataReplace");

	Py_DECREF(modulePython);

	PyObject* const args = PyTuple_New(3);
	PyTuple_SetItem(args, 0, PyUnicode_FromString(std::string(base + _fileway).c_str()));
	PyTuple_SetItem(args, 1, PyUnicode_FromString(_what));
	PyTuple_SetItem(args, 2, PyUnicode_FromString(_newValue));

	PyObject* const call = PyObject_CallObject(function, args);

	Py_XDECREF(args);
	Py_XDECREF(call);
}

const bool Setting::isEmpty(const char* _fileway) const {
	std::ifstream check(std::string(base + _fileway).c_str(), std::ios::binary);
	char checkVal;

	check >> checkVal;

	check.close();

	return !checkVal;
}

const std::vector<std::string> Setting::parse(const char* _fileway, const char* _parameter) const {
	Py_Initialize();

	PyRun_SimpleString("import sys\nsys.path.append('../CoolGame')");
	PyObject* const filewayData = PyUnicode_FromString("Tools.Python.PyTools");
	PyObject* const fileway = PyImport_Import(filewayData);

	Py_DECREF(filewayData);

	PyObject* const function = PyObject_GetAttrString(fileway, "parse");

	Py_DECREF(fileway);

	PyObject* const args = PyTuple_New(2);
	PyTuple_SetItem(args, 0, PyUnicode_FromString(_fileway));
	PyTuple_SetItem(args, 1, PyUnicode_FromString(_parameter));

	PyObject* const resultPy = PyObject_CallObject(function, args);

	Py_DECREF(function);
	Py_DECREF(args);

	const char* const result = PyUnicode_AsUTF8(resultPy);

	Py_Finalize();

	return devide(result);
}
const std::vector<std::string> Setting::devide(const char* _parsedStr) const {
	std::vector<std::string> devided(1);
	devided[0] = "";

	for (; *_parsedStr != ';'; _parsedStr++)
		if (*_parsedStr == ',')
			devided.push_back("");
		else
			devided[devided.size() - 1] += *_parsedStr;

	return devided;
}