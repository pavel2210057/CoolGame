#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "SFML\Graphics\Transformable.hpp"

#include <vector>

//Animation types
#define AT_MOVE     0x1
#define AT_ROTATE   0x2
#define AT_SIZE     0x4
#define AT_ALL      AT_MOVE | AT_ROTATE | AT_SIZE

using FrameQuery = std::vector<sf::Transformable*>;

class Animation {
	FrameQuery            frames;
public:
	Animation();

	Animation(sf::Transformable* _frame1, sf::Transformable* _frame2, size_t _qframes, size_t _flag = AT_ALL);

	~Animation();

	//setter
	void push(sf::Transformable* _frame1, sf::Transformable* _frame2, size_t _qframes, size_t _flag = AT_ALL);

	//getters
	inline FrameQuery getFrames() const { return frames; }

	inline operator FrameQuery() const { return frames; }

	inline operator FrameQuery::iterator() { return frames.begin(); }
};

#endif //!ANIMATION_HPP