// Name: Rosa Rivera Soto
// Date: 11/5/2023

#include "Card.hpp"

// Default Constructor
Card::Card() {}

// Copy Constructor
Card::Card(const Card& rhs) {
    // empty head
}

// Copy Assignment Operator
Card& Card::operator=(const Card& rhs) {
    if (this != &rhs) {
        // empty mind
    }
    return *this;
}

// Move Constructor
Card::Card(Card&& rhs) {
    // empty brain
}

// Move Assignment Operator
Card& Card::operator=(Card&& rhs) {
    if (this != &rhs) {
        // soup
    }
    return *this;
}

// Destructor
Card::~Card() {
    // mmm
}
