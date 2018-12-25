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
 *Класс Level служит для изъятия и обработки уровня из файла DLL.
 *В файле должны быть 2 обязательные функции:
 **1 - const void RenderMain(WindowRender& _win) - помещает все объекты рендера в _win;
 **2 - const int  EventMain (WindowRender& _win) - обрабатывает все события данного уровня
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
	const int handleEvent(void) const;		//обработчик событий
};

/*
 *LevelManager - класс для работы с уровнями
 */
class API_EXPORT LevelManager : public Level {
	const wchar_t*		curLevelFileName;
public:
	LevelManager(WindowRender& _win, const wchar_t* _levelFileName);

	~LevelManager(void);

	/*
	 *loadLevel - загрузка произвольного уровня по пути "_levelFileName"
	 */
	const void loadLevel(const wchar_t* _levelFileName);

	/*
	 *reloadLevel - перезагрузка уровня
	 */
	const void reloadLevel(void);
};


#endif //!LEVELS_HPP