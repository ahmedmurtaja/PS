#include <bits/stdc++.h>

using namespace std;

int findFrequency(vector<int>& arr, int target) {
    // Find the lower bound of the target element <= trget 
    // lowerBound return vector<int>::iterator, we can use auto 
    vector<int>::iterator lowerBound = lower_bound(arr.begin(), arr.end(), target);

    // If the lower bound is not found or the element at the lower bound is not equal to the target,
    // then the target element is not present in the array
    if (lowerBound == arr.end() || *lowerBound != target) {
        return 0;
    }

    // Find the upper bound of the target element, ** > trget **
    vector<int>::iterator upperBound = upper_bound(arr.begin(), arr.end(), target);

    // Calculate the frequency by subtracting the lower bound iterator from the upper bound iterator
    int frequency = upperBound - lowerBound;

    return frequency;
}

int findFrequency2(vector<int>& arr, int target) {
    int lowerBound = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    int upperBound = upper_bound(arr.begin(), arr.end(), target) - arr.begin();

    if (lowerBound == upperBound) {
        return 0; // Element not found
    }

    return upperBound - lowerBound;
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5, 5};
    int target = 2;

    int frequency = findFrequency(arr, target);
    int frequency2 = findFrequency2(arr, target);

    cout << "Frequency of " << target << " in the array: " << frequency << endl;
    cout << "Frequency2 of " << target << " in the array: " << frequency2 << endl;

    return 0;
}