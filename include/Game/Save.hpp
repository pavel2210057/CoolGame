#ifndef SAVE_HPP
#define SAVE_HPP

#include "GameSettings.hpp"

/*
 *Save - �����, ����������� ��������� � �������
 *������ ���������� � �����
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
	const void appendSave(const char* _record) const;

	const void clearSaves(void) const;
};

#endif //!SAVE_HPP