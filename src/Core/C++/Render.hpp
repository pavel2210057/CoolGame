#ifndef RENDER_HPP
#define RENDER_HPP

#include "Core\C++\API.hpp"
#include "SFML\Graphics\Drawable.hpp"
#include "SFML\Graphics\Shader.hpp"
#include "SFML\Graphics\RenderTarget.hpp"
#include <map>

/*
 *Render - класс, хранящий и обрабатывающий буфер
 *рендера. Использовать напрямую нельзя, для этого
 *написан более "высокий" класс WindowRender
 */
class API_EXPORT Render {
	std::map <sf::Drawable*, sf::Shader*>	renderMap;
protected:
	Render(void);

	~Render(void);

	const void render(sf::RenderTarget& _target) const;
public:
	const void appendPair(sf::Drawable* _drawable, sf::Shader* _shader = nullptr);

	const void popPair(sf::Drawable& _key);

	const void replacePair(sf::Drawable& _key, sf::Shader* _newValue);

	const void clearRenderBuffer(void);
};

#endif //!RENDER_HPP