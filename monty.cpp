#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

//PrintDoors function declaration (provided).
void printDoors();
void Statistics(double, double, double);
int beginDoor();

int main() {
    int userChoice;
    int winningDoor;
    int doorChose;
    int notWinning;
    int otherDoor;
    int finalChoice;
    double gamesPlayed;
    double userWins;
    double userLoses;


    srand((unsigned int) time(0)); //

    // put entire main in do while loop
    do {
        cout << "\nChoose one the following:" << "\n 1 - Play Game" << "\n 2 - View Stats" << "\n 3 - Restart Stats"
             << "\n 4 - Quit Game" << endl;

        cout << "> ";
        cin >> userChoice;

    // have to be valid num from 1-3

        if (userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 4) {
            cout << "Invalid option, please retry ";
            cout << " > ";
            cin >> userChoice;

    // start game since they pressed 1
        } else if (userChoice == 1) {
            winningDoor = beginDoor();
            gamesPlayed += 1;
            cout << "Pick a door, 1, 2, or 3!\n";
            printDoors();
            cout << "Choice: > ";
            cin >> doorChose;
            cout << "You chose door #" << doorChose << "!";
            cout << "\nI'll now open a door for you that you didn't choose!";

    // initialize loop to know which door to open for contestant that's not winning and not the one they chose
            for (int i = 1; i <= 3; i++) {
                if (i != winningDoor && i != doorChose)
                    notWinning = i;
            }

            otherDoor = 6 - doorChose - notWinning;
            cout << "\nOpening door " << notWinning << " and it's a GOAT!";
            cout << "\nNow, I'll be a kind host and give you the chance to switch your door!";
            cout << "\nWould you like door #" << doorChose << " or #" << otherDoor << "? >";
            cin >> finalChoice;
            cout << "Opening door #" << finalChoice << ".....";

            // randomly reveal which door is winning door

            if (finalChoice == winningDoor) {
                cout << "\nit's a BRAND NEW CAR!!!! YOU WIN!!!!\n";
                userWins += 1;
            } else {
                cout << "\nbaaaaaaaaaaaaa.... it's a GOAT!!!! You LOSE!\n";
                userLoses += 1;
            }

        //prints out user wins, losses, and percentage of wins and losses

        } else if (userChoice == 2) {

            Statistics(userWins, userLoses, gamesPlayed);

        // sets all stats back to 0

        } else if (userChoice == 3) {
            cout << "... Statistics Reset!";
            gamesPlayed = userWins = userLoses = 0;

        // end program

        } else if (userChoice == 4) {
            cout << "Goodbye!";
            break;

        }

    } while (userChoice == 1 || userChoice == 2 || userChoice == 3);
}



/*ASCII Art doors*/
/*THIS FUNCTION PRINTDOORS IS PROVIDED (graciously by ascii artist Melina) by the student wherever needed.*/
void printDoors()
{
    cout << "---------    ---------    ---------- \n";
    cout << "|       |    |  ____ |    |  _____ | \n";
    cout << "|   |   |    |     | |    |      | | \n";
    cout << "|   |   |    |  ___| |    |   ___| | \n";
    cout << "|   |   |    | |     |    |      | | \n";
    cout << "|   |   |    | |____ |    |  ____| | \n";
    cout << "---------    ---------    ---------- \n";

    return;
}
 // randomly picks winning door before player starts game

int beginDoor() {
    int r;
    r = rand() % 3 + 1; // r will be a random number from 1 through 3
    return r;
}

 // sets up calculations for wins, losses, and their percentages

void Statistics(double userWins, double userLosses, double gamesPlayed)						// function to display statistics of the player
{
    double winPercentage, lossPercentage;

    if (gamesPlayed == 0)
        cout << "No Stats to Display, 0 games played." << endl << endl << endl;
    else
    {
        winPercentage = (userWins / gamesPlayed) * 100;
        lossPercentage = (userLosses / gamesPlayed) * 100;

        cout << "Results after " << gamesPlayed << "games:" << endl;
        cout << "Wins: " << userWins << "			Losses: " << userLosses << endl;
        cout << fixed << showpoint << setprecision(1);
        cout << "Win %: " << winPercentage << "			Loss %: " << lossPercentage << endl;
    }
}
