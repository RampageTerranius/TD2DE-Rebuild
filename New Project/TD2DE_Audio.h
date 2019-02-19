#ifndef _TD2DE_AUDIO_
#define _TD2DE_AUDIO_


namespace TD2DE
{
	class TD2DE_Audio
	{
	private:
		int	mhz,//the speaker frequency to work with, defaulted to 22050
			channels,
			bitRate;//defaulted to 2048kb, more = higher quality but laggier

	public:
		int GetMhz();
		void SetMhz(int newMhz);
		int GetChannels();
		void SetChannels(int newChannels);
		int GetBitRate();
		void SetBitRate(int newBitRate);

	}TD2DE_AUDIO;
}

int TD2DE::TD2DE_Audio::GetMhz()
{
	return mhz;
}

void TD2DE::TD2DE_Audio::SetMhz(int newMhz)
{
	mhz = newMhz;
}

int TD2DE::TD2DE_Audio::GetChannels()
{
	return channels;
}

void TD2DE::TD2DE_Audio::SetChannels(int newChannels)
{
	channels = newChannels;
}

int TD2DE::TD2DE_Audio::GetBitRate()
{
	return bitRate;
}

void TD2DE::TD2DE_Audio::SetBitRate(int newBitRate)
{
	bitRate = newBitRate;
}


#endif
