#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int rollDice() {
    return (rand() % 6 + 1) + (rand() % 6 + 1);
}

void playGame(double& playerMoney) {
    int numRolls;
    double minBet;

    // Get user input
    cout << "Enter number of rolls: ";
    cin >> numRolls;
    cout << "Enter minimum bet: ";
    cin >> minBet;

    // Validate input
    if (minBet <= 0 || numRolls <= 0) {
        cout << "Invalid input. Minimum bet and number of rolls must be positive." << endl;
        return;
    }

    cout << "\nStarting with $" << playerMoney << endl;

    for (int roll = 1; roll <= numRolls && playerMoney >= minBet; roll++) {
        cout << "\nRoll " << roll << ": ";

        double currentBet = minBet;
        playerMoney -= minBet;

        // Come-out roll
        int firstRoll = rollDice();
        cout << "Come-out roll: " << firstRoll;

        if (firstRoll == 7 || firstRoll == 11) {
            // Lose Don't Pass bet
            cout << " - 7/11, you lose $" << minBet;
            continue;
        }
        else if (firstRoll == 2 || firstRoll == 3) {
            // Win Don't Pass bet
            playerMoney += minBet * 2;
            cout << " - 2/3, you win $" << minBet;
            continue;
        }
        else if (firstRoll == 12) {
            // Push (tie)
            playerMoney += minBet;
            cout << " - 12, push";
            continue;
        }

        // Point established
        int point = firstRoll;
        cout << " - Point is " << point;

        // Place backup bet
        double backupBet = 0;
        bool isPlaceBet = false;
        if (point == 4 || point == 10) {
            backupBet = 60.0;
            cout << ", Lay bet $" << backupBet;
        }
        else if (point == 5 || point == 9) {
            backupBet = 45.0;
            cout << ", Lay bet $" << backupBet;
        }
        else if (point == 6 || point == 8) {
            backupBet = 12.0;
            isPlaceBet = true; // Mark as Place bet
            cout << ", Place bet $" << backupBet << " on " << point;
        }

        if (backupBet > 0) {
            if (playerMoney >= backupBet) {
                playerMoney -= backupBet;
            }
            else {
                cout << " - Insufficient funds for backup bet";
                backupBet = 0;
                isPlaceBet = false;
            }
        }

        // Roll until point or 7
        while (true) {
            int nextRoll = rollDice();
            cout << "\nNext roll: " << nextRoll;

            if (nextRoll == point) {
                // Lose Don't Pass bet
                cout << " - Point hit, you lose $" << minBet;
                if (backupBet > 0) {
                    if (isPlaceBet) {
                        // Win Place bet on 6 or 8
                        playerMoney += 26.0; // $12 bet returned + $14 payout
                        cout << " but win Place bet $14 + $12 returned";
                    }
                    else {
                        // Lose Lay bet for 4, 5, 9, 10
                        cout << " and Lay $" << backupBet;
                    }
                }
                break;
            }
            else if (nextRoll == 7) {
                // Win Don't Pass bet
                playerMoney += minBet * 2;
                cout << " - 7 out, you win $" << minBet;
                if (backupBet > 0) {
                    if (isPlaceBet) {
                        // Lose Place bet on 6 or 8
                        cout << " but lose Place bet $" << backupBet;
                    }
                    else {
                        // Win Lay bet for 4, 5, 9, 10
                        if (point == 4 || point == 10) {
                            playerMoney += 90.0; // $60 bet returned + $30 payout
                            cout << " and Lay payout $30 + $60 returned";
                        }
                        else if (point == 5 || point == 9) {
                            playerMoney += 75.0; // $45 bet returned + $30 payout
                            cout << " and Lay payout $30 + $45 returned";
                        }
                    }
                }
                break;
            }
        }

        cout << "\nPlayer: $" << playerMoney;
    }

    // Final results
    cout << "\n\nGame Over!" << endl;
    cout << "Final Player Balance: $" << playerMoney << endl;

    if (playerMoney < minBet) {
        cout << "You ran out of money!" << endl;
    }
}

int main() {
    srand(time(0));
    double playerMoney = 500.0;
    char playAgain;

    do {
        playGame(playerMoney);

        // Ask if the user wants to play again
        cout << "\nDo you want to play another game? (y/n): ";
        cin >> playAgain;

        // Reset playerMoney to 500 for a new game
        if (playAgain == 'y' || playAgain == 'Y') {
            playerMoney = 500.0;
            cout << "\nStarting a new game with player money reset to $500.\n";
        }

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thank you for playing!\n";
    return 0;
}