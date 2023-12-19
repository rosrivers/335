/*
CSCI335 Fall 2023
Assignment 2 – Sorting
Name: Rosa Rivera Soto
Date: 11/23/23
StandardSort.hpp defines the StandardSort method
*/

#ifndef STANDARDSORT_HPP
#define STANDARDSORT_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iterator>

// Function to perform standard sorting using C++ STL's std::sort and measure the duration.
int standardSort(std::vector<int>& nums, int& duration) {
    // Record the start time of the sorting process.
    auto comienza = std::chrono::steady_clock::now();
    
    // Use std::sort to perform standard sorting on the entire vector.
    std::sort(nums.begin(), nums.end());

    // Record the end time of the sorting process.
    auto termina = std::chrono::steady_clock::now();

    // Calculate the duration of the sorting process in milliseconds.
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(termina - comienza).count();

    // Determine the index of the median element in the sorted vector.
    int centro;
    if (nums.size() % 2 == 0) {
        centro = nums.size() / 2 - 1;
    } else {
        centro = nums.size() / 2;
    }

    // Return the element at the center of the sorted vector.
    return nums[centro];
}

#endif
