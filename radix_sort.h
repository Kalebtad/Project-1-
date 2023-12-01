#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// A utility function to get the maximum value in an array
int getMax(int* a, int n) {
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

// Using counting sort to sort the elements based on significant places
void countingSort(int* a, int n, int exp) {
    const int base = 10;
    vector<int> output(n);
    vector<int> count(base, 0);

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(a[i] / exp) % base]++;

    // Change count[i] so that count[i] contains the actual
    // position of this digit in output[]
    for (int i = 1; i < base; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(a[i] / exp) % base] - 1] = a[i];
        count[(a[i] / exp) % base]--;
    }

    // Copy the output array to a[], so that a[] contains sorted numbers
    for (int i = 0; i < n; i++)
        a[i] = output[i];
}

// Main Radix Sort function
void radixSort(int* a, int n) {
    // Find the maximum number to know the number of digits
    int max = getMax(a, n);

    // Do counting sort for every digit
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(a, n, exp);
}

#endif // Radix_Sort//
// Created by admin on 30/11/2023.
//

#ifndef TELEGRAM_DESKTOP_RADIX_SORT_H
#define TELEGRAM_DESKTOP_RADIX_SORT_H

#endif //TELEGRAM_DESKTOP_RADIX_SORT_H
