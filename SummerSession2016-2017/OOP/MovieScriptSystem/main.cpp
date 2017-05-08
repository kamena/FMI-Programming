#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#include "Series.cpp"
#include "Episode.cpp"
#include "Character.cpp"
#include "Action.cpp"
#include "Emotions.cpp"

int main()
{
	Series series("Game of Thrones");
	Episode episode(1, "Game of Thrones");
	cout << "1 - series name get by episode: \t" << episode.getSeriesName() << endl;

	// vector<Character> CharactersVector;

	Character me("Kamena", 18, "female", episode);
    // CharactersVector.push_back( me );

    cout << "2 - Series name get by character: \t" << me.getSeriesName() << endl;

    Character him("Hristo", 19, "male", episode);

    Action action(me, him, RELATIONSHIP, episode);

    cout << "3 - series name get by action: \t\t" << action.getSeriesName() << endl;

    Emotions emotions(me, him, 0, 99, true);

    cout << "4 - series name get by emotions: \t" << emotions.getSeriesName() << endl;

    cout << "4.1 - episode num get by emotions: \t" << emotions.getEpisodeNum() << endl;

    cout << "5 - hate level get by emotions:\t\t" << emotions.getHate() << endl;

    Emotions emotions1(him, me, 5, 98, true);
    cout << "6 - hate level get be emotions1: \t" << emotions1.getHate() << endl;

    cout << "7: " << emotions.getName() << " likes " << emotions.getEmotionsTo().getName() << " " << emotions.getLike() << " times." << endl;

    Action action1(me, him, ARGUE, episode);

    Emotions emotions2(me, him, 5, 98, true);

    cout << "8: " << action1.getBetween1().getName() << " is arguing with " << action1.getBetween2().getName() << "." << endl;

    cout << "9: " << emotions2.getName() << " likes " << emotions2.getEmotionsTo().getName() << " " << emotions2.getLike() << " times." << endl;


    // CharactersVector.push_back( him );

	// for(vector<Character>::iterator it = CharactersVector.begin(); it != CharactersVector.end(); ++it) {
	//     cout << it->getName() << endl;
	// }

	// vector<Emotions> EmotionsVector;

	// Emotions e1(me, him, 0, 99, true);
	// Emotions e2(him, me, 0, 98, true);

	// EmotionsVector.push_back( e1 );
	// EmotionsVector.push_back( e2 );
	// me.setEmotion(emotions);

	// cout << me.getName() << endl;
	// cout << emotions.getLike() << endl;

	// cout << emotions.getEmotionsFrom() == "Kamena";

    return 0;
}
