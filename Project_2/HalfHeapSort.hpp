/*
CSCI335 Fall 2023
Assignment 2 – Sorting
Name: Rosa Rivera Soto
Date: 11/23/23
HalfHeapSort.hpp defines the HalfHeapSort method
*/

#ifndef HALFHEAPSORT_HPP
#define HALFHEAPSORT_HPP

#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

// Function to compute the left child index of a given index in a heap.
inline int leftChild(int i) {
    return 2 * i;
}

// Function to perform the percolate-down operation on a heap.
void percDown(std::vector<int>& heap, std::vector<int>::size_type hole) {
    int child;
    int temp = heap[0];

    // Loop until the hole has no more children or the heap property is restored.
    for (; leftChild(hole) < heap.size(); hole = child) {
        child = leftChild(hole);

        // If the right child exists and is smaller, choose it.
        if (child < heap.size() - 1 && heap[child] > heap[child + 1])
            ++child;

        // If the child is smaller than the temporary value, move it up.
        if (temp > heap[child])
            heap[hole] = heap[child];
        else
            break;
    }

    // Place the temporary value in its correct position.
    heap[hole] = temp;
}

// Function to build a heap from the elements of a vector.
void buildHeap(std::vector<int>& heap) {
    // Start from the last non-leaf node and perform percolate-down on each.
    for (int i = (heap.size() - 1 / 2); i > 0; i--) {
        heap[0] = heap[i];
        percDown(heap, i);
    }
}

// Function to perform HalfHeapSort on a vector of integers and measure the duration.
int halfHeapSort(std::vector<int>& nums, int& duration) {
    auto start = std::chrono::steady_clock::now();

    // Duplicate the first element and build a heap from the entire vector.
    nums.push_back(nums[0]);
    buildHeap(nums);

    // Determine the center index of the vector.
    int center = ((nums.end() - nums.begin()) - 2) / 2;

    // Perform percolate-down operation for the first half of the vector.
    for (int i = 0; i < center; i++) {
        nums[0] = nums[nums.size() - 1];
        nums.pop_back();
        percDown(nums, 1);
    }

    // Measure the duration of the sorting process.
    auto end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    // Return the second smallest element in the sorted vector.
    return nums[1];
}

#endif
