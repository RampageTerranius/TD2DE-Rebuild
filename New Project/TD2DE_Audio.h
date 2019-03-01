#ifndef _TD2DE_AUDIO_
#define _TD2DE_AUDIO_


namespace TD2DE
{
	class TD2DE_Audio
	{
	private:
		int	frequency = 22050,//the speaker frequency to work with, defaulted to 22050
			channels = 2,
			chunkSize = 4096;//defaulted to 4096kb, more = higher quality but laggier

	public:
		int GetFrequency();
		void SetFrequency(int newfrequency);
		int GetChannels();
		void SetChannels(int newChannels);
		int GetChunkSize();
		void SetChunkSize(int newChunkSize);

	}TD2DE_AUDIO;
}

int TD2DE::TD2DE_Audio::GetFrequency()
{
	return frequency;
}

void TD2DE::TD2DE_Audio::SetFrequency(int newfrequency)
{
	frequency = newfrequency;
}

int TD2DE::TD2DE_Audio::GetChannels()
{
	return channels;
}

void TD2DE::TD2DE_Audio::SetChannels(int newChannels)
{
	channels = newChannels;
}

int TD2DE::TD2DE_Audio::GetChunkSize()
{
	return chunkSize;
}

void TD2DE::TD2DE_Audio::SetChunkSize(int newChunkSize)
{
	chunkSize = newChunkSize;
}


#endif