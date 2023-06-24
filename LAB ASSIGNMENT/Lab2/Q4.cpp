#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Teams {
    private:
        int numPlayers;
        int hits;
    public:
        Teams() {
            numPlayers = rand() % 5 + 1;
            hits = 0;
        }
        int NumPlayers() {
            return numPlayers;
        }
        int getHits() {
            return hits;
        }
        void countHit() {
            hits++;
        }
};

int main() {
    srand(time(NULL));
    Teams myTeam, enemyTeam;
    int numHits = myTeam.NumPlayers();
	cout<<"TOTAL NUMBER OF PLAYERS IN YOUR TEAM: "<<myTeam.NumPlayers();
    for (int i = 0; i < numHits; i++) {
		cout<<endl;
		cout<<"pair of numbers:"<<endl;
        int num1 = rand() % 10 + 1; 
        int num2 = rand() % 10 + 1;
		cout<<"Number1: "<<num1<<endl;
		cout<<"Number2: "<<num2<<endl;

        if (num1 == num2) {
            cout << "Enemy got hit by your team!" << endl;
            myTeam.countHit();
        } else {
            cout << "You got hit by the enemy team!" << endl;
            enemyTeam.countHit();
        }
    }
    if (myTeam.getHits() > enemyTeam.getHits()) {
        cout << "Game Over! You won!" << endl;
    } else if (myTeam.getHits() < enemyTeam.getHits()) {
        cout << "Game Over! You lost." << endl;
    } else {
        cout << "It's a tie!" << endl;
    }
    return 0;
}