/*
CSCI335 Fall 2023
Assignment 2 – Sorting
Name: Rosa Rivera Soto
Date: 11/23/23
HalfSelectionSort.hpp defines the HalfSelectionSort method
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iterator>
#include <cmath>

// Function to perform HalfSelectionSort on a vector of integers and measure the duration.
int halfSelectionSort(std::vector<int>& nums, int& duration) {
    // Check if the input size is too large for selection sort to be efficient.
    if (nums.size() > 50000) {
        std::cout << "Input was too big for selection sort." << std::endl;
        return -1;
    }
    
    // Record the start time of the sorting process.
    auto comenzar = std::chrono::steady_clock::now();
    
    // Calculate the center index of the vector.
    int centro = std::ceil(nums.size() / 2.0);

    // Iterate through the first half of the vector and perform selection sort.
    for (auto iterator = nums.begin(); iterator != nums.begin() + centro; ++iterator) {
        // Find the minimum element in the remaining unsorted part of the vector.
        auto min_i = std::min_element(iterator, nums.end());

        // Swap the current element with the minimum element.
        std::iter_swap(iterator, min_i);
    }

    // Determine the iterator pointing to the last element of the sorted first half.
    std::vector<int>::iterator solution = nums.begin() + centro - 1;

    // Record the end time of the sorting process.
    auto end = std::chrono::steady_clock::now();

    // Calculate the duration of the sorting process in microseconds.
    duration = (end - comenzar).count();

    // Return the element at the center of the sorted first half.
    return *solution;
}
