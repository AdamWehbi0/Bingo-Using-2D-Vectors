#include "BingoCard.h"


// Constructor initializing a bingo card with a specific size.
BingoCard::BingoCard(int size) : board_size(size), board(new vector<vector<int>*>(size)), marked(new vector<vector<bool>*>(size)) {
    // Initialize the board and marked vectors with new vectors for each row.
    for (int i = 0; i < board_size; i++) {
        board->at(i) = new vector<int>(board_size);
        marked->at(i) = new vector<bool>(board_size, false);
    }
    // Fill the board with random numbers.
    fill();
}

// Converts the board to a string representation, marking called numbers.
string BingoCard::toString() {
    stringstream ss;
    // Iterate through each cell to create the string representation.
    for (int col = 0; col < board_size; col++) {
        for (int row = 0; row < board_size; row++) {
            // Mark called numbers with parentheses.
            if (marked->at(col)->at(row)) {
                ss << "(" << setw(2) << board->at(col)->at(row) << ")";
            } else {
                ss << " " << setw(2) << board->at(col)->at(row) << " ";
            }
            // Add column separators except for the last column.
            if (row < board_size - 1) {
                ss << " | ";
            }
        }
        // Add row separators except for the last row.
        if (col < board_size - 1) {
            ss << "\n" << string(board_size * 7 - 1, '-') << "\n";
        }
    }
    ss << "\n";
    return ss.str();
}

// Marks a number on the board as called.
void BingoCard::call(int num) {
    cout << "Calling " << num << ": " << endl;
    // Check each cell to find and mark the called number.
    for (int col = 0; col < board_size; col++) {
        for (int row = 0; row < board_size; row++) {
            if (board->at(col)->at(row) == num) {
                marked->at(col)->at(row) = true;
            }
        }
    }
}

// Clears all marks from the board.
void BingoCard::clearBoard() {
    // Set all marked flags to false.
    for (int col = 0; col < board_size; col++) {
        for (int row = 0; row < board_size; row++) {
            marked->at(col)->at(row) = false;
        }
    }
}

// Fills the board with unique random numbers.
void BingoCard::fill() {
    std::vector<int> range{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    std::random_device rd; // Non-deterministic seed for randomness.
    std::mt19937 g(rd()); // Mersenne Twister for generating random numbers.
    // Assign unique random numbers to each board cell.
    for (int col = 0; col < board_size; col++) {
        shuffle(range.begin(), range.end(), g);
        for (int row = 0; row < board_size; row++) {
            board->at(row)->at(col) = range.at(row) + (15 * col);
            marked->at(row)->at(col) = false;
        }
    }
}

// Checks for a complete vertical line.
bool BingoCard::checkVertical() {
    // Check each column for a complete line of marked cells.
    for (int col = 0; col < board_size; col++) {
        int bing = 0;
        for (int row = 0; row < board_size; row++) {
            if (marked->at(row)->at(col)) {
                bing += 1;
            }
        }
        if (bing == board_size) {
            return true;
        }
    }
    return false;
}

// Checks for a complete horizontal line.
bool BingoCard::checkHorizontal() {
    // Check each row for a complete line of marked cells.
    for (int row = 0; row < board_size; row++) {
        int bing = 0;
        for (int col = 0; col < board_size; col++) {
            if (marked->at(row)->at(col)) {
                bing += 1;
            }
        }
        if (bing == board_size) {
            return true;
        }
    }
    return false;
}

// Checks for a complete diagonal line.
bool BingoCard::checkDiagonal() {
    int diag1 = 0;
    int diag2 = 0;
    // Check both diagonals for a complete line of marked cells.
    for (int i = 0; i < board_size; i++) {
        if (marked->at(i)->at(i)) {
            diag1 += 1;
        }
        if (marked->at(i)->at(board_size - i - 1)) {
            diag2 += 1;
        }
    }
    if (diag1 == board_size || diag2 == board_size) {
        return true;
    }
    return false;
}

// Checks if there is a bingo (complete line vertically, horizontally, or diagonally).
bool BingoCard::checkBingo() {
    // Return true if any of the check functions return true.
    if (checkVertical() || checkHorizontal() || checkDiagonal()) {
        return true;
    } else {
        return false;
    }
}


int randomfunc(int j) {
    return rand() % j;
}

int badRand(int j) {
    return 100 % j;
}