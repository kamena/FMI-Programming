#pragma once
class Character;

class Series {
private:
	char* seriesName_;
    Character** characters_;
    int charactersCount_;
    int capacity_;	

	void copySeries(const Series& other);
	void resizeSeries();
public:
	Series();
	Series(const char* name, Character** characters, int charactersCount);
	Series(const Series& other);
	~Series();

	Series& operator=(const Series& other);

	char* getSeriesName();
	int getCharactersCount();

	void setSeriesName(const char* name);

	void addCharacter(Character* newCharacter);
	void printCharacters();
	char* printCharacterFromList(int i);
};
