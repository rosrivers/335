/*
CSCI335 Fall 2023
Assignment 2 – Sorting
Name: Rosa Rivera Soto
Date: 11/23/23
MergeSort.hpp defines the MergeSort method
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cmath>

// Helper function for merge sort.
void mergeSortHelper(std::vector<int>& nums, int comenzar, int terminar) {
    // Base case: if the range has more than one element, continue sorting.
    if (comenzar < terminar) {
        // Calculate the middle index to divide the range into two halves.
        int centro = comenzar + (terminar - comenzar) / 2;

        // Recursively sort the two halves.
        mergeSortHelper(nums, comenzar, centro);
        mergeSortHelper(nums, centro + 1, terminar);

        // Create a temporary vector to store the merged result.
        std::vector<int> temp(terminar - comenzar + 1);

        // Merge the two sorted halves into the temporary vector.
        std::merge(nums.begin() + comenzar, nums.begin() + centro + 1, nums.begin() + centro + 1, nums.begin() + terminar + 1, temp.begin());

        // Copy the merged result back to the original vector.
        std::copy(temp.begin(), temp.end(), nums.begin() + comenzar);
    }
}

// Function to perform merge sort on a vector of integers and measure the duration.
int mergeSort(std::vector<int>& nums, int& duration) {
    // Record the start time of the sorting process.
    auto s = std::chrono::steady_clock::now();
    
    // Call the helper function to perform merge sort on the entire vector.
    mergeSortHelper(nums, 0, nums.size() - 1);

    // Record the end time of the sorting process.
    auto e = std::chrono::steady_clock::now();

    // Calculate the duration of the sorting process in milliseconds.
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(e - s).count();

    // Return the median element of the sorted vector.
    if (nums.size() % 2 == 0) {
        return std::min(nums[nums.size() / 2 - 1], nums[nums.size() / 2]);
    } else {
        return nums[nums.size() / 2];
    }
}
