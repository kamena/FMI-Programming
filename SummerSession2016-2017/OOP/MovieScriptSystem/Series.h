#pragma once

class Series {
private:
	char* seriesName_;

	void copySeries(const Series& other);
public:
	Series();
	Series(const char* name);
	Series(const Series& other);
	~Series();

	Series& operator=(const Series& other);

	char* getSeriesName();
	void setSeriesName(const char* name);

};
