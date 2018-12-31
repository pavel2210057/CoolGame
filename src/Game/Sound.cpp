#include "stdafx.h"
#include "Sound.hpp"

Sound::Sound(const char* _sounddir) : GameSettings() {}

Sound::~Sound(void) {}

const void Sound::loadFilesAtBuffers(const std::vector<const char*>& _filename) {
	for (int i = 0; i < _filename.size(); i++) {
		sf::SoundBuffer soundBuffer;
		soundBuffer.loadFromFile(std::string(soundDir + _filename[i]).c_str());

		this->soundBuffer.push_back(sf::Sound(soundBuffer));
	}
}

const void Sound::clearBuffers(void) {
	soundBuffer.clear();
}

std::vector<sf::Sound>& Sound::getSoundBuffer(void) {
	return soundBuffer;
}

const void Sound::replaceDefaultVolume(const char* _fileway, const char* _newValue) const {
	replaceGameValue(_fileway, "Volume", _newValue);
}

const void Sound::play(const size_t& _index) {
	soundBuffer[_index].play();
}

const void Sound::pause(const size_t& _index) {
	soundBuffer[_index].pause();
}

const void Sound::startLoop(const size_t& _index) {
	soundBuffer[_index].setLoop(true);
}

const void Sound::stopLoop(const size_t& _index) {
	soundBuffer[_index].setLoop(false);
}