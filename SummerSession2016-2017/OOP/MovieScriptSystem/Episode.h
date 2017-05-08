#pragma once

class Episode : public Series {
private:
	int episodeNum_;

	void copyEpisode(const Episode& other);
public:
	Episode();
	Episode(int episodeNum, const char* seriesName);
	Episode(const Episode& other);
	~Episode();

	Episode& operator=(const Episode& other);

	int getEpisodeNum();

	void setEpisodeNum(int episodeNum);

};