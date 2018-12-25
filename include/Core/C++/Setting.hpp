#ifndef SETTING_HPP
#define SETTING_HPP

#include "Core\C++\API.hpp"
#include <fstream>
#include <vector>
#include "Python.h"

/*
 *Setting - "������" ����� ��� ����������� ������ � �������.
 *�������� ����������� �� ���������, ��� ������ ������������
 *����� ������� ����� GameSettings, ����������� ���������� ������.
 */
class API_EXPORT Setting {
private:
	std::string		base;
protected:
	Setting(void);

	Setting(const char* _base);

	~Setting(void);

	const void dataWrite(const char* _fileway, const char* _what) const;

	const bool dataWriteLine(const char* _fileway, const char* _what) const;

	const void dataClear(const char* _fileway) const;

	const void dataReplace(const char* _fileway, const char* _what, const char* _newValue) const;

	const bool isEmpty(const char* _fileway) const;

	const std::vector<std::string> parse(const char* _fileway, const char* _parameter) const;
private:
	const std::vector<std::string> devide(const char* _parsedStr) const;
};

#endif //!SETTING_HPP