/* 
Borillo, Raphael Jedidiah R. | BCS32 | 202230704
Problem 2:
The logistics company wants to categorize routes by their efficiency. 
To do this, you need to analyze the time complexity of sorting algorithms. 
Implement and compare the runtime of Bubble Sort and Merge Sort for sorting a list of delivery times in ascending order.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> bubble_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return arr;
}

vector<int> merge_sort(vector<int>& arr) {
    if (arr.size() > 1) {
        int mid = arr.size() / 2;
        vector<int> left_half(arr.begin(), arr.begin() + mid);
        vector<int> right_half(arr.begin() + mid, arr.end());

        merge_sort(left_half);
        merge_sort(right_half);

        int i = 0, j = 0, k = 0;

        while (i < left_half.size() && j < right_half.size()) {
            if (left_half[i] < right_half[j]) {
                arr[k++] = left_half[i++];
            } else {
                arr[k++] = right_half[j++];
            }
        }

        while (i < left_half.size()) {
            arr[k++] = left_half[i++];
        }

        while (j < right_half.size()) {
            arr[k++] = right_half[j++];
        }
    }
    return arr;
}

int main() {
    int total_del;
    cout << "Enter the total number of delivery times: ";
    cin >> total_del;

    vector<int> del_in_mins;

    for (int i = 0; i < total_del; i++) {
        int mins;
        cout << "Enter delivery time " << i + 1 << " (in minutes, e.g., 60 for one hour, 120 for 2 hours, etc.): ";
        cin >> mins;
        del_in_mins.push_back(mins);
    }

    cout << "Delivery times: ";
    for (int i = 0; i < del_in_mins.size(); i++) {
        cout << del_in_mins[i] << " ";
    }
    cout << endl;

    vector<int> arr = {64, 34, 25, 12, 22, 11, 90, 20, 23};
    cout << "\nArray sorted using Bubble Sort: ";
    for (int i = 0; i < bubble_sort(del_in_mins).size(); i++) {
        cout << bubble_sort(del_in_mins)[i] << " ";
    }
    cout << "\nTime complexity: O (n^2)" << endl;

    cout << "\nArray sorted using Merge Sort: ";
    for (int i = 0; i < merge_sort(del_in_mins).size(); i++) {
        cout << merge_sort(del_in_mins)[i] << " ";
    }
    cout << "\nTime complexity: O (n log n)" << endl;

    return 0;
}
