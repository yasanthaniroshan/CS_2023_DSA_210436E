
#include <iostream>
#include <limits.h>
#include <chrono>
#include <iomanip>
#include <cstdlib>
#include <vector>

using namespace std;

//
double median(vector<int> array, int n) {
    double median = 0;
    if (n % 2 == 0) {
        median = (array[n/2] + array[n/2 - 1]) / 2.0;
    } else {
        median = array[n/2];
    }
    return median;
}

vector<int> sort(vector<int> array, int size) {
    int i = 0;
    while (i < size) {
        int j = i + 1;
        while (j < size) {
            if (array[i] > array[j]) {
                int temp_value = array[i];
                array[i] = array[j];
                array[j] = temp_value;
            }
            j++;
        }
        i++;
    }
    return array;
}

void printing_array(vector<int> array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}


int main() {
    vector<int> new_median_array;
    vector<int> number_array = {7,3,5,2};
    int size = number_array.size();

    for(int i = 0; i < size; i++) {
        new_median_array.push_back(number_array[i]);
        vector<int> sorted = sort(new_median_array, i+1);
        printing_array(sorted, i+1);
        cout <<std::fixed << std::setprecision(1)<< median(sorted, i+1) << endl;
    }

    return 0;
}
