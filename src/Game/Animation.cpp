#include "Animation.hpp"

#include <cassert>
#include <typeinfo>

using InterValues = std::vector<double>;
using CoordQuery = std::vector<sf::Vector2f>;

struct Tools {
	//return REVERSE bin value; value length always 4
	static std::vector<bool> dec_to_bin(int _dec) {
		static std::vector<bool> bin;

		for (;_dec; _dec /= 2)
			bin.push_back(_dec % 2);
		
		//size always equal 3
		while (bin.size() < 3)
			bin.push_back(false);

		return bin;
	}

	//search of _count values between _begin and _end
	static InterValues interpolation(double _begin, double _end, double _count) {
		assert(_count++ >= NULL);

		static const float sector = _end - _begin;
		static const float step = sector / _count;

		static InterValues vals;

		for (float i = 0; step < NULL ? i > _end : i < _end; i += step)
			vals.push_back(i);

		//last value always equal _end
		if (vals.back() != _end)
			vals.push_back(_end);

		return vals;
	}

	static CoordQuery interpolation_coords(sf::Vector2f _begin, sf::Vector2f _end, double _count) {
		static const InterValues
			x = Tools::interpolation(_begin.x, _end.x, _count),
			y = Tools::interpolation(_begin.y, _end.y, _count);

		static CoordQuery vals;
		for (int i = 0; i < x.size(); i++)
			vals.push_back(sf::Vector2f(x[i], y[i]));

		return vals;
	}
};

struct Creator {
	static FrameQuery create(sf::Transformable* _frame1, sf::Transformable* _frame2, size_t _qframes, size_t _flag) {
		assert(_qframes && _flag && _flag <= 0x7);
		/*
		 *Example:
		 *	_flag == AT_MOVE & AT_SIZE => Tools::dec_to_bin == { 1, 0, 1 } =>
		 *		=> flag[0] and flag[2] is active
		 */
		static const std::vector<bool> flags = Tools::dec_to_bin(_flag);
		
		CoordQuery
			*move_vals = nullptr,
			*size_vals = nullptr;
		InterValues 
			*rot_vals =  nullptr;

		FrameQuery vals;
		vals.reserve(_qframes);

		if (flags[0]) {
			move_vals = new CoordQuery(Tools::interpolation_coords(_frame1->getPosition(), _frame2->getPosition(), _qframes));

			for (int i = 0; i < move_vals->size(); i++)
				vals[i]->setPosition(move_vals->at(i));
		}
		if (flags[1]) {
			rot_vals = new InterValues(Tools::interpolation(_frame1->getRotation(), _frame2->getRotation(), _qframes));

			for (int i = 0; i < rot_vals->size(); i++)
				vals[i]->setRotation(rot_vals->at(i));
		}
		if (flags[2]) {
			size_vals = new CoordQuery(Tools::interpolation_coords(_frame1->getScale(), _frame2->getScale(), _qframes));

			for (int i = 0; i < size_vals->size(); i++)
				vals[i]->setScale(size_vals->at(i));
		}

		return vals;
	}
};

Animation::Animation() {}

Animation::Animation(sf::Transformable* _frame1, sf::Transformable* _frame2, size_t _qframes, size_t _flag) {
	push(_frame1, _frame2, _qframes, _flag);
}

Animation::~Animation() {}

void Animation::push(sf::Transformable* _frame1, sf::Transformable* _frame2, size_t _qframes, size_t _flag) {
	assert(frames.empty());

	frames = Creator::create(_frame1, _frame2, _qframes, _flag);
}
