#ifndef WINDOWRENDER_HPP
#define WINDOWRENDER_HPP

#include "Core/C++/Render.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

using renderPair = std::pair<sf::Drawable*, sf::Shader*>;

/*
 *��������� WindowRender - ������ ����������, ��� ����������� �� RenderWindow,
 *��� ��������� ��������� �������� �������� � ������, � ����� �� ������ Render,
 *� ������� ������� API ��� ������ � ������� ������ �������
 */
struct API_EXPORT WindowRender : public sf::RenderWindow, public Render {
	WindowRender(const sf::Vector2i& _sizeWindow, const char* _nameWindow);

	~WindowRender(void);

	/*
	 *renderFrame �������� ���� ������, ���������� �� ����� ������
	 */
	const void renderFrame(void);
protected:
	/*
	 *operator<< ������, ��� ����� ������� ��������� ������ ����������
	 *����� �������� ������� � �����
	 */
	friend WindowRender& operator<<(WindowRender& _winRender, const renderPair _renderQueue);
};

#endif //!WINDOWRENDER_HPP