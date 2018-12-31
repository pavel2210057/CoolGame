#ifndef SAVE_HPP
#define SAVE_HPP

#include "GameSettings.hpp"

/*
 *Save - �����, ����������� ��������� � �������
 *������ ���������� � ����� Save.txt
 */
struct API_EXPORT Save : public GameSettings {
	/*
	 *_savedir - ���������� � ������ ����������
	 */
	Save(const char* _savedir);

	~Save(void);

	/*
	 *appendSave - ���������� _record � ����� �����.
	 *���� ����������� �������� ���������� ������
	 *��������� _newValue
	 */
	const void appendSave(const char* _record, const char* _newValue = nullptr) const;

	const void clearSaves(void) const;
};

#endif //!SAVE_HPP