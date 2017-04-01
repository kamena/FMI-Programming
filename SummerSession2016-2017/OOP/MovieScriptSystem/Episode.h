#pragma once

class Episode : public Series {
private:
	int episodeNum_;
public:
	Episode();
	Episode(int episodeNum, string seriesName);

	int getEpisodeNum();

	void setEpisodeNum(int episodeNum);

};
