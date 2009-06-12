#ifndef soundmixer_h
#define soundmixer_h

#include "Sound.h"
#include <vector>

class SoundMixer
{
private:
	vector<Sound*> sounds;
public:

	SoundMixer()
	{

	}

	void addSound(Sound* sound)
	{
		sounds.push_back(sound);
	}
};

#endif
