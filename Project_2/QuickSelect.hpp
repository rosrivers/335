/*
CSCI335 Fall 2023
Assignment 2 – Sorting
Name: Rosa Rivera Soto
Date: 11/23/23
QuickSelect.hpp defines the QuickSelect method
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iterator>
#include <cmath>

// Function to determine the median of three values and return the iterator pointing to it.
std::vector<int>::iterator medianOfThree(std::vector<int>::iterator& izquerda, std::vector<int>::iterator& derecha) {
    auto centro = izquerda + std::distance(izquerda, derecha) / 2;

    // Arrange the values at izquerda, centro, and derecha to ensure centro holds the median.
    if ((*izquerda < *centro && *centro < *derecha) || (*derecha < *centro && *centro < *izquerda)) {
        std::swap(*centro, *derecha);
    } else if ((*centro < *izquerda && *izquerda < *derecha) || (*derecha < *izquerda && *izquerda < *centro)) {
        std::swap(*izquerda, *derecha);
    }

    return derecha;
}

// Function implementing the Hoare partition scheme for QuickSelect.
std::vector<int>::iterator hoarePartition(std::vector<int>& nums, std::vector<int>::iterator izquerda, std::vector<int>::iterator derecha) {
    // Choose the pivot using the median of three strategy.
    auto pivot = medianOfThree(izquerda, derecha);
    int pivotVal = *pivot;

    // Move the pivot to the end for partitioning.
    std::iter_swap(pivot, derecha);

    auto abajo = izquerda;
    auto arriba = derecha;

    // Partition the array around the pivot value.
    while (true) {
        while (abajo < arriba && *abajo < pivotVal) {
            abajo++;
        }
        while (arriba > abajo && *arriba >= pivotVal) {
            arriba--;
        }

        if (abajo >= arriba) {
            break;
        }

        std::swap(*abajo, *arriba);
    }

    // Move the pivot to its final sorted position.
    std::swap(*abajo, *derecha);

    return abajo;
}

// Recursive helper function for QuickSelect.
int quickSelectHelper(std::vector<int>& nums, std::vector<int>::iterator izquerda, std::vector<int>::iterator derecha, int median) {
    // Base case: if the range is small, use sorting to find the median.
    if (derecha - izquerda < 1e1) {
        std::sort(izquerda, derecha + 1);
        return *(izquerda + median);
    }

    // Perform Hoare partition and determine the distance of the pivot from izquerda.
    auto parting = hoarePartition(nums, izquerda, derecha);
    int distance = std::distance(izquerda, parting);

    // If the distance is equal to the desired median, return the pivot value.
    if (distance == median) {
        return *parting;
    } else if (distance > median) {
        // If the desired median is to the left, recurse on the left subarray.
        return quickSelectHelper(nums, izquerda, parting - 1, median);
    } else {
        // If the desired median is to the right, recurse on the right subarray.
        return quickSelectHelper(nums, parting + 1, derecha, median - distance - 1);
    }
}

// Function to perform QuickSelect on a vector of integers and measure the duration.
int quickSelect(std::vector<int>& nums, int& duration) {
    // Record the start time of the sorting process.
    auto start = std::chrono::steady_clock::now();

    // Determine the index of the median element.
    int centro = (nums.size() - 1) / 2;

    // Call the helper function to perform QuickSelect on the entire vector.
    quickSelectHelper(nums, nums.begin(), nums.end() - 1, centro);

    // Record the end time of the sorting process.
    auto end = std::chrono::steady_clock::now();

    // Calculate the duration of the sorting process in milliseconds.
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    // Return the element at the center of the sorted vector.
    return nums[centro];
}
