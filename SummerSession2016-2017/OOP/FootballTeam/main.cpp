#include <iostream>
#include <string>
using namespace std;

#include "Player.cpp"
#include "Team.cpp"


int main() {
	Player player1("Kamena", 2, 12, 3000);
	Player player2("Hristo", 8, 2, 3000);
	Player player3("Krisi", 4, 8, 4000);
	Player player4("Ivan", 6, 14, 5000);

	int playersCount = 4;
	Player* players = new Player[playersCount];

	players[0].copyPlayer(player1);
	players[1].copyPlayer(player2);
	players[2].copyPlayer(player3);
	players[3].copyPlayer(player4);

	Team team("TeamName", players, playersCount, 15045);

	Player player5("Pesho", 4, 5, 45);

	team.addPlayer(player5);

	team.printTeamInfo();

	Player player6("Hope", 7, 6, 450);

	team.isBudgetEnough();

	team.addPlayer(player6);

	team.printTeamInfo();

	team.isBudgetEnough();

	delete [] players;

	return 0;
}