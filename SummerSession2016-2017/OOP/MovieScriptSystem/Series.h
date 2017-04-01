#pragma once

class Series {
private:
	string seriesName_;
public:
	Series();
	Series(string name);

	string getSeriesName();
	void setSeriesName(string name);

};
