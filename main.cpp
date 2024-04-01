// 5_Takehome.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BingoCard.h"
using namespace std;

// This function checks if the input BingoCard has achieved a bingo and prints the result.
void checkAndPrint(BingoCard* input) {
    // Checks if the input BingoCard has a bingo.
    if(input->checkBingo()){
        // If a bingo is found, print "Bingo!"
        cout << "Bingo!" << endl;
    } else {
        // If no bingo is found, print "No Bingo!"
        cout << "No Bingo!" << endl;
    }
    // Prints the current state of the BingoCard to the console.
    cout << input->toString();
    // Clears all marks from the board for a new game.
    input->clearBoard();
}

int main()
{
    BingoCard *bc = new BingoCard(5);
    
    bc->call(03);
    bc->call(12);
    bc->call(25);
    bc->call(37);
    bc->call(61);
    bc->call(64);
    checkAndPrint(bc);

    bc->call(14);
    bc->call(22);
    bc->call(31);
    bc->call(55);
    bc->call(73);
    checkAndPrint(bc);

    bc->call(28);
    bc->call(30);
    bc->call(22);
    bc->call(26);
    bc->call(23);
    checkAndPrint(bc);

    bc->call(10);
    bc->call(30);
    bc->call(31);
    bc->call(54);
    bc->call(73);
    checkAndPrint(bc);

    bc->call(12);
    bc->call(26);
    bc->call(31);
    bc->call(68);
    bc->call(48);
    checkAndPrint(bc);
}
