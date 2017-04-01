#include "Series.h"

Series::Series(){
	this->seriesName_ = "";
}

Series::Series(string name){
	this->seriesName_ = name;
}

string Series::getSeriesName() {
	return this->seriesName_;
}

void Series::setSeriesName(string name) {
	this->seriesName_ = name;
}