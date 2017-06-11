#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>

using namespace std;

#include "Series.cpp"
#include "Episode.cpp"
#include "Character.cpp"
#include "Action.cpp"
#include "Emotions.cpp"

int getInput() {
    int choice;    
    cin >> choice;

    return choice;
}

void displayMainMenu() {
    cout << "Main Menu\n";
    cout << "Please make your selection\n";
    cout << "1 - Add series\n";
    cout << "2 - Quit\n";
    cout << "Selection: ";
}

void displaySecondaryMenu() {
    cout << "Main Menu\n";
    cout << "Please make your selection\n";
    cout << "1 - Add episode\n";
    cout << "2 - Back to Main Menu\n";
    cout << "Selection: ";
}

void displayEpisodeMenu() {
    cout << "Episode Menu\n";
    cout << "Please make your selection\n";
    cout << "1 - Add character\n";
    cout << "2 - Add action\n";
    cout << "3 - Back to Secondary Menu\n";
    cout << "Selection: ";
}

void secondaryMenu(Series& series, int num);

void episodeMenu(Series& series, int num, Episode* episode) {
    int choice = 0;
    do {
        // system("cls");
        displayEpisodeMenu();
        choice = getInput();
        switch(choice) {
            case 1:
            {
                // system("cls");
                cout << "What is the name of the character? ";
                cin.ignore();
                char characterName[30];
                cin.getline(characterName, 30);

                cout << "How old is the character? ";
                int characterAge;
                cin >> characterAge;

                cout << "What gander is the character? ";
                cin.ignore();
                char characterGander[30];
                cin.getline(characterGander, 30);

                Character* character = new Character(characterName, characterAge, characterGander, episode);
                cout << character->getName() << endl << endl;
                series.addCharacter(character);

                cout << "What do you want to do next? " << endl;
                // secondaryMenu(series, num++);
                break;
            }
            case 2:
                // system("cls");
                if(series.getCharactersCount() <= 0) {
                    cout << "There are no characters yet." << endl << endl;
                    break;
                }
                cout << "Pleace select the number of the characters that are involved in the action." << endl;
                cout << "Note: if the action is for only one person (born, die, sick, etc) please type the number of the character twice." << endl;
                
                series.printCharacters();
                
                int character1, character2;
                cout << "Character 1: ";
                cin >> character1;
                cout << "Character 2: ";
                cin >> character2;

                cout << endl;
                cout << "Select an action: " << endl;
                cout << "1. RELATIONSHIP, 2. CHEAT, 3. DEATH, 4. ARGUE, 5. BRAKEUP, 6. SEX, 7. KILL, 8. KISS";
                ActionType actionType;
                cin >> actionType;

                cout << series.printCharacterFromList(character1) << actionType << series.printCharacterFromList(character2) << endl;
                break;
            case 3:
                break;
            default:
                break;
        }
    } while(choice != 3);
}

void secondaryMenu(Series& series, int num) {
    int choice = 0;
    do {
        // system("cls");
        displaySecondaryMenu();
        choice = getInput();
        switch(choice) {
            case 1:
            {
                Episode* episode = new Episode(num, series);
                episodeMenu(series, num, episode);
                break;
            }
            case 2:
                break;
            default:
                break;
        }
    } while(choice != 2);
}

int main() {

    int choice = 0;
    int num = 0; 

    do {
        displayMainMenu();
        choice = getInput();
        switch(choice) {
            case 1:
            {
                cout << "What is the name of the series?";
                cin.ignore();
                char seriesName[30];
                cin.getline(seriesName, 30);

                Character** characters;
                Series series(seriesName, characters, 0);
                secondaryMenu(series, num);
                break;
            }
            case 2: 
                cout << "Your series are created! You've done a great job!";
                break;
            default: 
            break;
        }
    } while(choice != 2);
/*
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

*/
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
