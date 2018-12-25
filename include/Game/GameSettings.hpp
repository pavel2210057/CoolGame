#ifndef GAMESETTINGS_HPP
#define GAMESETTINGS_HPP

#include "Core\C++\Setting.hpp"

/*
 *GameSettings - класс для работы с файлами, а конкретно, 
 *добавлением, очисткой и изменением данных в файлах
 */
class API_EXPORT GameSettings : public Setting {
protected:
	GameSettings(void);

	GameSettings(const char* _base);

	~GameSettings(void);

	/*
	 *append - добавить в файл по пути _fileway запись _what,
	 *также можно заменить предыдущую запись строкой _newValue
	 */
	const void append(const char* _fileway, const char* _what, const char* _newValue = NULL) const;

	/*
	 *clear - очистить файл по пути _fileway
	 */
	const void clear(const char* _fileway) const;

	/*
	 *replaceGameValue - изменить строку _what строкой _newValue
	 *в файле по пути _fileway
	 */
	const void replaceGameValue(const char* _fileway, const char* _what, const char* _newValue) const;
};

#endif //!GAMESETTINGS_HPP