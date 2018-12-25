#ifndef GAMESETTINGS_HPP
#define GAMESETTINGS_HPP

#include "Core\C++\Setting.hpp"

/*
 *GameSettings - ����� ��� ������ � �������, � ���������, 
 *�����������, �������� � ���������� ������ � ������
 */
class API_EXPORT GameSettings : public Setting {
protected:
	GameSettings(void);

	GameSettings(const char* _base);

	~GameSettings(void);

	/*
	 *append - �������� � ���� �� ���� _fileway ������ _what,
	 *����� ����� �������� ���������� ������ ������� _newValue
	 */
	const void append(const char* _fileway, const char* _what, const char* _newValue = NULL) const;

	/*
	 *clear - �������� ���� �� ���� _fileway
	 */
	const void clear(const char* _fileway) const;

	/*
	 *replaceGameValue - �������� ������ _what ������� _newValue
	 *� ����� �� ���� _fileway
	 */
	const void replaceGameValue(const char* _fileway, const char* _what, const char* _newValue) const;
};

#endif //!GAMESETTINGS_HPP