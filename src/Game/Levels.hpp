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
 *����� Level ������ ��� ������� ������ �� ����� DLL
 *(�� ��������� ��� ���� MainMenu.MAINMENU).
 *� ����� ������ ���� 2 ������������ �������:
 **1 - const void RenderMain(WindowRender& _win) - �������� ��� ������� ������� � _win;
 **2 - const void EventMain(WindowRender& _win) - ������������ ��� ������� ������� ������
 */
class API_EXPORT Level : public Loader {
	typedef	const void(*handle)(WindowRender&);
	handle			importedHandleEvent;
	WindowRender*	winRenderPtr;
protected:
	Level(WindowRender& _win);

	Level(WindowRender& _win, const char* _levelFileName);

	~Level(void);

	const void updateState(const char* _newFileName);
public:
	const void handleEvent(void) const;		//���������� �������
};

/*
 *LevelManager - ����� ��� ������� ������ � ��������
 */
class API_EXPORT LevelManager : public Level {
	const char*		curLevelFileName;
public:
	LevelManager(WindowRender& _win);

	LevelManager(WindowRender& _win, const char* _levelFileName);

	~LevelManager(void);

	/*
	 *loadLevel - �������� ������������� ������ �� ���� "_levelFileName"
	 */
	const void loadLevel(const char* _levelFileName);

	/*
	 *reloadLevel - ������������ ������
	 */
	const void reloadLevel(void);
};

#endif //!LEVELS_HPP