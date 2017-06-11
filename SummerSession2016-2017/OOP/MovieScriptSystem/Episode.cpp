#include "Episode.h"
#include "Series.h"

void Episode::copyEpisode(const Episode& other){
	this->episodeNum_ = other.episodeNum_;
}

Episode::Episode() : Series() {
	this->episodeNum_ = 0;
}

Episode::Episode(int episodeNum, Series& series) 
: episodeNum_(episodeNum), Series(series)
{}

Episode::Episode(const Episode& other) : Series(other) {
	copyEpisode(other);
}

Episode::~Episode(){}

Episode& Episode::operator=(const Episode& other){
	if(this == &other) return *this;
	
	Series::operator=(other);
	copyEpisode(other);

	return *this;
}

int Episode::getEpisodeNum() {
	return this->episodeNum_;
}

void Episode::setEpisodeNum(int episodeNum) {
	this->episodeNum_ = episodeNum;
}