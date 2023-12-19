/*
CSCI335 Fall 2023
Assignment 2 – Sorting
Name: Rosa Rivera Soto
Date: 11/23/23
WorstCaseQuickSelect.hpp defines the WorstCaseQuickSelect method
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iterator>

// Function to generate a vector representing the worst-case scenario for QuickSelect.
std::vector<int> worstCaseQuickSelect() {
    // Create an empty vector to store the worst-case sequence.
    std::vector<int> nums;

    // Populate the vector with integers in descending order from 20000 to 1.
    for (int i = 20000; i >= 1; i--) {
        nums.push_back(i);
    }

    // Return the generated worst-case sequence.
    return nums;
}
