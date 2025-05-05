Craps Game Simulator Description
This C++ program simulates a simplified version of the casino game Craps, focusing on the "Don't Pass" betting strategy with additional backup bets (Lay bets for points 4, 5, 9, 10, and Place bets for points 6, 8). The program is designed to allow users to play multiple rounds of Craps, specifying the number of rolls and minimum bet, with a starting balance of $500 that resets each game. It provides a realistic simulation of casino Craps payouts, with the exception of omitting the standard 5% commission (vig) on Lay bets.
Features
User Input:
Prompts the user to enter the number of rolls and the minimum bet for each game.
Validates input to ensure positive values for both.
Player Balance:
Starts with $500, reset to $500 at the start of each new game.
Tracks and displays the player's balance after each roll and at the game’s end.
Betting Mechanics:
Don't Pass Bet:
Placed with the user-specified minimum bet (e.g., $10).
Come-out roll:
7 or 11: Lose the bet.
2 or 3: Win even money (1:1, e.g., $10 bet returns $20).
12: Push (bet returned).
4, 5, 6, 8, 9, or 10: Establishes a point.
After point:
7: Win even money (e.g., $10 bet returns $20).
Point: Lose the bet.
Backup Bets:
Points 4 or 10:
Lay bet of $60 (betting a 7 will be rolled before the point).
7: Win $30 payout + $60 returned (total $90).
Point: Lose $60.
Points 5 or 9:
Lay bet of $45.
7: Win $30 payout + $45 returned (total $75).
Point: Lose $45.
Points 6 or 8:
Place bet of $12 on the point (betting the point will be rolled before a 7).
Point: Win $14 payout + $12 returned (total $26, based on 7:6 odds).
7: Lose $12.
Game Flow:
Simulates dice rolls using a random number generator (rand() seeded with time(0)).
Continues rolling until the specified number of rolls is reached or the player’s balance falls below the minimum bet.
Displays detailed outcomes for each roll, including come-out rolls, points, bet results, and updated player balance.
Replay Option:
After each game, prompts the user to play again (y or n).
If y, resets the player’s balance to $500 and starts a new game with new inputs for rolls and minimum bet.
If n, exits with a thank-you message.
Output:
Shows only the player’s balance, omitting any house-related financial tracking.
Provides clear messages for each roll’s outcome (e.g., “7 out, you win $10 but lose Place bet $12” or “Point hit, you lose $10 but win Place bet $14 + $12 returned”).
Alignment with Casino Rules
Accurate:
The "Don't Pass" bet follows standard casino rules, including a push on 12.
Place bets on 6 or 8 pay 7:6 odds ($12 wins $14 + $12 returned), matching casino payouts.
Lay bets on 4, 5, 9, or 10 use correct odds (2:1 for 4/10, 3:2 for 5/9) with the bet returned, as in casinos.
Deviation:
Omits the 5% commission (vig) typically charged on Lay bets (e.g., $3 on $60 for 4/10, $2.25 on $45 for 5/9), making Lay bets slightly more favorable to the player.
Assumes the house can always cover bets, with no finite house pot, aligning with real casino practices.
Usage
Compile and run the program in a C++ environment.
Enter the desired number of rolls and minimum bet when prompted.
Follow the game’s progress through detailed console output, showing each roll’s result and the player’s balance.
At the end of the game, choose to play again (y) or exit (n).
If replaying, the balance resets to $500, and new inputs are requested.
Example Gameplay
Input: 5 rolls, $10 minimum bet.
Sample Roll (Point is 6):
Bet $10 on "Don't Pass", $12 Place bet on 6.
If 6 is rolled: Lose $10, win $26 ($14 + $12). Output: Point hit, you lose $10 but win Place bet $14 + $12 returned. Net: +$16.
If 7 is rolled: Win $20, lose $12. Output: 7 out, you win $10 but lose Place bet $12. Net: +$8.
Sample Roll (Point is 4):
Bet $10 on "Don't Pass", $60 Lay bet.
If 4 is rolled: Lose $10 + $60. Output: Point hit, you lose $10 and Lay $60. Net: -$70.
If 7 is rolled: Win $20 + $90 ($30 + $60). Output: 7 out, you win $10 and Lay payout $30 + $60 returned. Net: +$110.
End: Shows final balance (e.g., Final Player Balance: $520) and prompts for replay.
Purpose
This program is ideal for users who want to simulate a "Don't Pass" Craps strategy with specific backup bets, offering a near-authentic casino experience. It’s useful for understanding Craps mechanics, testing betting strategies, or enjoying a simplified casino game simulation. The omission of the Lay bet vig makes it slightly player-friendly compared to real casinos.
Notes
The program uses a random number generator for dice rolls, ensuring fair but simulated outcomes.
To fully align with casino rules, a 5% vig could be added to Lay bets, which would require minor code changes.
The program is designed for educational or entertainment purposes and does not involve real money.
For further customization (e.g., adding the vig, modifying bet amounts, or including other Craps bets), the code can be easily extended.
