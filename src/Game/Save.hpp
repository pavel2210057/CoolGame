#ifndef SAVE_HPP
#define SAVE_HPP

#include "GameSettings.hpp"

/*
 *Save - класс, позволяющий добавлять и удалять
 *записи сохранений в файле Save.txt
 */
struct API_EXPORT Save : public GameSettings {
	/*
	 *_savedir - директория с файлом сохранений
	 */
	Save(const char* _savedir);

	~Save(void);

	/*
	 *appendSave - записывает _record в конец файла.
	 *Есть возможность заменить предыдущую запись
	 *значением _newValue
	 */
	const void appendSave(const char* _record, const char* _newValue = nullptr) const;

	const void clearSaves(void) const;
};

#endif //!SAVE_HPP