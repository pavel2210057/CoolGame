#include "stdafx.h"
#include "WindowRender.hpp"

WindowRender::WindowRender(const sf::Vector2i& _sizeWindow, const char* _nameWindow) :
	sf::RenderWindow(sf::VideoMode(_sizeWindow.x, _sizeWindow.y), _nameWindow), Render() {}

WindowRender::~WindowRender(void) {}

const void WindowRender::renderFrame(void) {
	render(*this);
}

WindowRender& operator<<(WindowRender& _winRender, const renderPair _renderQueue) {
	_winRender.appendPair(_renderQueue.first, _renderQueue.second);
	return _winRender;
}