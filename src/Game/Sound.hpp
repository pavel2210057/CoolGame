#ifndef SOUND_HPP
#define SOUND_HPP

#include "GameSettings.hpp"
#include "SFML\Audio\SoundBuffer.hpp"
#include "SFML\Audio\Sound.hpp"

/*
 *Sound - класс для работы со звуком, хранит все в буфере.
 *Может выполнять стандартные операции
 */
class API_EXPORT Sound : public GameSettings {
	std::vector<sf::Sound>		soundBuffer;
	std::string					soundDir;
public:
	/*
	 *_sounddir - директория со звуками
	 */
	Sound(const char* _sounddir);

	~Sound(void);

	const void loadFilesAtBuffers(const std::vector<const char*>& _filename);

	const void clearBuffers(void);

	std::vector<sf::Sound>& getSoundBuffer(void);

	const void replaceDefaultVolume(const char* _fileway, const char* _newValue) const;

	const void play(const size_t& _index);

	const void pause(const size_t& _index);
	
	const void startLoop(const size_t& _index);

	const void stopLoop(const size_t& _index);
};

#endif //!SOUND_HPP