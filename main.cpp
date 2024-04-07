#include <algorithm>
#include <iostream>
#include <iomanip>

#include "tableau.hpp"

int main() {
    /* Amounts to be calculated in cents here we want to calculate for $1.15 */
    int amount_table[] = {0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100, 105, 110, 115};

    /* Coin values in cents */
    /* 5 cents, 10 cents, 25 cents, 50 cents, 1 dollar, 2 dollars */
    /* We didn't take 1 cent to have a small table for the amount */
    int coin_table[] = {0, 5, 10, 25, 50, 100, 200};

    unsigned int nb_coins = sizeof(coin_table) / sizeof(coin_table[0]) - 1;
    unsigned int nb_amounts = sizeof(amount_table) / sizeof(amount_table[0]) - 1;

    unsigned int dimensions[2] = {nb_coins + 1, nb_amounts + 1};
    Tableau<unsigned int> table(std::vector<unsigned int>(dimensions, dimensions + 2));

    unsigned int infinite = INT_MAX;

    /* Basic case */
    for (unsigned int i = 0; i <= nb_coins; i++) {
        table.at(i, 0) = 0;
    }
    for (unsigned int j = 0; j <= nb_amounts; j++) {
        table.at(0, j) = infinite;
    }

    /* Recursive case */
    for (unsigned int i = 1; i <= nb_coins; i++) {
        for (unsigned int j = 1; j <= nb_amounts; j++) {
            if (coin_table[i - 1] > amount_table[j - 1]) {
                table.at(i, j) = table.at(i - 1, j);
            } else {
                table.at(i, j) = std::min(table.at(i - 1, j), table.at(i, (amount_table[j - 1] - coin_table[i - 1])/5) + 1);
            }
        }
    }

    /* Displaying the header row with amount values */
    std::cout << std::setw(4) << " ";
    for (unsigned int j = 0; j <= nb_amounts; ++j) {
        std::cout << std::setw(4) << amount_table[j];
    }
    std::cout << std::endl;

    /* Looping through rows (coins) and columns (amounts) to display the table */
    for (unsigned int i = 0; i <= nb_coins; ++i) {
        /* Displaying the coin value in the first column */
        if (i == 0) {
            std::cout << std::setw(4) << coin_table[i];
        } else {
            std::cout << std::setw(4) << coin_table[i];
        }

        /* Looping through amounts for each coin and displaying table values */
        for (unsigned int j = 0; j <= nb_amounts; ++j) {
            if (table.at(i, j) == infinite) {
                std::cout << std::setw(4) << (char)236; // Displaying ∞ for infinite values
            } else {
                std::cout << std::setw(4) << table.at(i, j);
            }
        }
        std::cout << std::endl; // Moving to the next line after each row is displayed
    }

    return 0;
}