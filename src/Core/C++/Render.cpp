#include "stdafx.h"
#include "Render.hpp"

Render::Render(void) {}

Render::~Render(void) {}

const void Render::appendPair(sf::Drawable* _drawable, sf::Shader* _shader) {
	renderMap.insert(std::pair<sf::Drawable*, sf::Shader*>(_drawable, _shader));
}

const void Render::popPair(sf::Drawable& _key) {
	renderMap.erase(&_key);
}

const void Render::replacePair(sf::Drawable& _key, sf::Shader* _newValue) {
	renderMap.erase(&_key);
	appendPair(&_key, _newValue);
}

const void Render::render(sf::RenderTarget& _target) const {
	for (auto iterator = renderMap.begin(); iterator != renderMap.end(); iterator++)
		_target.draw(*iterator->first, iterator->second);
}

const void Render::clearRenderBuffer(void) {
	renderMap.clear();
}