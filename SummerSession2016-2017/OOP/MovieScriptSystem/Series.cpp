#include "Series.h"

void Series::copySeries(const Series& other) {
	this->seriesName_ = new char[strlen(other.seriesName_) + 1];
	strcpy(this->seriesName_, other.seriesName_);
}

Series::Series(){
	this->seriesName_ = NULL;
}

Series::Series(const char* name){
	this->seriesName_ = new char[strlen(name) + 1];
	strcpy(this->seriesName_, name);
}

Series::Series(const Series& other){
	copySeries(other);
}
Series::~Series(){
	delete [] this->seriesName_;
}

Series& Series::operator=(const Series& other){
	if(this == &other) return *this;
	delete [] this->seriesName_;
	copySeries(other);

	return *this;
}

char* Series::getSeriesName() {
	return this->seriesName_;
}

void Series::setSeriesName(const char* name) {
	this->seriesName_ = new char[strlen(name) + 1];
	strcpy(this->seriesName_, name);
}