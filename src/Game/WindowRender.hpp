#ifndef WINDOWRENDER_HPP
#define WINDOWRENDER_HPP

#include "Core/C++/Render.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

using renderPair = std::pair<sf::Drawable*, sf::Shader*>;

/*
 *Структура WindowRender - основа приложения, оно наследовано от RenderWindow,
 *что позволяет выполнять основные операции с окнами, а также от класса Render,
 *в котором заложен API для работы с блоками данных рендера
 */
struct API_EXPORT WindowRender : public sf::RenderWindow, public Render {
	WindowRender(const sf::Vector2i& _sizeWindow, const char* _nameWindow);

	~WindowRender(void);

	/*
	 *renderFrame рендерит блок данных, полученных из файла уровня
	 */
	const void renderFrame(void);
protected:
	/*
	 *operator<< создан, как более удобный потоковый способ добавления
	 *новых объектов рендера в буфер
	 */
	friend WindowRender& operator<<(WindowRender& _winRender, const renderPair _renderQueue);
};

#endif //!WINDOWRENDER_HPP