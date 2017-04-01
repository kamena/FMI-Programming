#include "Episode.h"

Episode::Episode(){
	this->episodeNum_ = 1;
}

Episode::Episode(int episodeNum, string seriesName) 
: episodeNum_(episodeNum), Series(seriesName)
{}

int Episode::getEpisodeNum() {
	return this->episodeNum_;
}

void Episode::setEpisodeNum(int episodeNum) {
	this->episodeNum_ = episodeNum;
}