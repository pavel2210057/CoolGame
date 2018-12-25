#ifndef LEVELS_HPP
#define LEVELS_HPP

#include "Core\C++\Loader.hpp"
#include "Game\WindowRender.hpp"
#include "SFML\Window\Event.hpp"

struct Pair {
	sf::Drawable**	first;
	sf::Shader**	second;

	size_t			structSize;
};

/*
 *����� Level ������ ��� ������� � ��������� ������ �� ����� DLL.
 *� ����� ������ ���� 2 ������������ �������:
 **1 - const void RenderMain(WindowRender& _win) - �������� ��� ������� ������� � _win;
 **2 - const int  EventMain (WindowRender& _win) - ������������ ��� ������� ������� ������
 */
class API_EXPORT Level : public Loader {
	typedef	const void(*handle)(WindowRender&);

	handle			importedHandleEvent;

	WindowRender*	winRenderPtr;
protected:
	Level(WindowRender& _win, const wchar_t* _levelFileName);

	~Level(void);

	const void updateState(const wchar_t* _newFileName);
public:
	const int handleEvent(void) const;		//���������� �������
};

/*
 *LevelManager - ����� ��� ������ � ��������
 */
class API_EXPORT LevelManager : public Level {
	const wchar_t*		curLevelFileName;
public:
	LevelManager(WindowRender& _win, const wchar_t* _levelFileName);

	~LevelManager(void);

	/*
	 *loadLevel - �������� ������������� ������ �� ���� "_levelFileName"
	 */
	const void loadLevel(const wchar_t* _levelFileName);

	/*
	 *reloadLevel - ������������ ������
	 */
	const void reloadLevel(void);
};


#endif //!LEVELS_HPP