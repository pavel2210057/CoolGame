#ifndef WINDOWRENDER_HPP
#define WINDOWRENDER_HPP

#include "Core/C++/Render.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

#define UNDEFINED NULL

using renderPair = std::pair<sf::Drawable*, sf::Shader*>;

/*
 *��������� WindowRender - ������ ����������, ��� ����������� �� RenderWindow,
 *��� ��������� ��������� �������� �������� � ������, � ����� �� ������ Render,
 *� ������� ������� API ��� ������ � ������� ������ �������
 */
class API_EXPORT WindowRender : public sf::RenderWindow, public Render {
	unsigned int	FPS = UNDEFINED;
public:
	WindowRender(const sf::Vector2i& _sizeWindow, const char* _nameWindow, int _style = sf::Style::Default, const sf::ContextSettings& _settings = sf::ContextSettings());

	~WindowRender(void);
	/*
	 *setFPS ������������� ������� ������ ����
	 */
	const void setFPS(unsigned int _fps);

	/*
	 *getFPS ���������� ������� ������� ������ ����
	 */
	const unsigned int getFPS(void) const;

	/*
	 *renderFrame �������� ���� ������, ���������� �� ����� ������
	 */
	const void renderFrame(void);

	/*
	 *operator bool. true - ���� �������
	 */
	operator bool(void);
protected:
	/*
	 *operator<< ������, ��� ����� ������� ��������� ������ ����������
	 *����� �������� ������� � �����
	 */
	friend API_EXPORT WindowRender& operator<<(WindowRender& _winRender, const renderPair _renderQueue);
};

#endif //!WINDOWRENDER_HPP