#include <iostream>
#include <vector>

using namespace std;

int cal_cross_largest(vector<int>& A, int left, int right) {
    int mid = (left + right) / 2;
    int i = mid, j = mid + 1;
    int min_value = min(A[i], A[j]);
    int largest_area = min_value * (j - i + 1);
    while (i > left || j < right) {
        while (i - 1 >= left && A[i - 1] >= min_value) {
            i--;
            largest_area = max(largest_area, min_value * (j - i + 1));
        }
        while (j + 1 <= right && A[j + 1] >= min_value) {
            j++;
            largest_area = max(largest_area, min_value * (j - i + 1));
        }

        if (i - 1 >= left && A[i - 1] < min_value) {
            i--;
            min_value = A[i];
            largest_area = max(largest_area, min_value * (j - i + 1));
            continue;
        }

        if (j + 1 <= right && A[j + 1] < min_value) {
            j++;
            min_value = A[j];
            largest_area = max(largest_area, min_value * (j - i + 1));
            continue;
        }
    }
    return largest_area;
}

int largest_rectangle(vector<int>& A, int left, int right) {
    if (A.size() == 0) return 0;
    if (right - left == 1) {
        return min(A[left], A[right]) * (right - left + 1);
    }
    if (left == right) {
         return A[left];
    }
    int n = A.size();
    int mid = (left + right) / 2;
    int left_largest = largest_rectangle(A, left, mid);
    int right_largest = largest_rectangle(A, mid + 1, right);
    int cross_largest = cal_cross_largest(A, left, right);
    return max(max(left_largest, right_largest), cross_largest);

}

int main() {
    vector<int> input;
    input.push_back(1);
    input.push_back(3);
    input.push_back(2);
    input.push_back(5);
    input.push_back(3);
    input.push_back(4);
    input.push_back(1);
    cout << largest_rectangle(input, 0, input.size() - 1) << endl;

}
