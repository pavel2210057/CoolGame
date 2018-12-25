#ifndef WINDOWRENDER_HPP
#define WINDOWRENDER_HPP

#include "Core/C++/Render.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

#define UNDEFINED NULL

using renderPair = std::pair<sf::Drawable*, sf::Shader*>;

/*
 *Структура WindowRender - основа приложения, оно наследовано от RenderWindow,
 *что позволяет выполнять основные операции с окнами, а также от класса Render,
 *в котором заложен API для работы с блоками данных рендера
 */
class API_EXPORT WindowRender : public sf::RenderWindow, public Render {
	unsigned int	FPS = UNDEFINED;
public:
	WindowRender(const sf::Vector2i& _sizeWindow, const char* _nameWindow, int _style = sf::Style::Default, const sf::ContextSettings& _settings = sf::ContextSettings());

	~WindowRender(void);
	/*
	 *setFPS устанавливает частоту кадров окна
	 */
	const void setFPS(unsigned int _fps);

	/*
	 *getFPS возвращает текущую частоту кадров окна
	 */
	const unsigned int getFPS(void) const;

	/*
	 *renderFrame рендерит блок данных, полученных из файла уровня
	 */
	const void renderFrame(void);

	/*
	 *operator bool. true - окно открыто
	 */
	operator bool(void);
protected:
	/*
	 *operator<< создан, как более удобный потоковый способ добавления
	 *новых объектов рендера в буфер
	 */
	friend API_EXPORT WindowRender& operator<<(WindowRender& _winRender, const renderPair _renderQueue);
};

#endif //!WINDOWRENDER_HPP