/*
CSCI335 Fall 2023
Assignment 2 – Sorting
Name: Rosa Rivera Soto
Date: 11/23/23
InPlaceMergeSort.hpp defines the InPlaceMergeSort method
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iterator>
#include <cmath>

// Helper function for in-place merge sort.
void inPlaceMergeSortHelper(std::vector<int>::iterator comenzar, std::vector<int>::iterator terminar) {
    // Base case: if the range has only one element, it is already sorted.
    if (std::next(comenzar) == terminar) {
        return;
    }
    
    // Calculate the middle iterator to divide the range into two halves.
    auto centro = comenzar + std::distance(comenzar, terminar) / 2;

    // Recursively sort the two halves.
    inPlaceMergeSortHelper(comenzar, centro);
    inPlaceMergeSortHelper(centro, terminar);

    // Merge the two sorted halves in-place.
    std::inplace_merge(comenzar, centro, terminar);
}

// Function to perform in-place merge sort on a vector of integers and measure the duration.
int inPlaceMergeSort(std::vector<int>& nums, int& duration) {
    // Record the start time of the sorting process.
    auto comenzar = std::chrono::steady_clock::now();
    
    // Call the helper function to perform in-place merge sort on the entire vector.
    inPlaceMergeSortHelper(nums.begin(), nums.end());

    // Determine the iterator pointing to the last element of the sorted first half.
    int centro = std::ceil(nums.size() / 2.0) - 1;
    std::vector<int>::iterator solution = nums.begin() + centro;

    // Record the end time of the sorting process.
    auto terminar = std::chrono::steady_clock::now();

    // Calculate the duration of the sorting process in microseconds.
    duration = (terminar - comenzar).count();

    // Return the element at the center of the sorted first half.
    return *solution;
}
