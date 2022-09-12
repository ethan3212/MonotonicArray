#include <iostream>
#include <vector>
using namespace std;

// O(n) time | O(1) space
bool isMonotonicBoolean(vector<int> array) {
    bool ascending = true;// O(1) space
    bool descending = true;// O(1) space
    for(int i = 1; i < array.size(); i++) {// O(n) time
        if(array[i] < array[i - 1]) {// O(1) time
            ascending = false;// O(1) time | O(1) space
        }
        if(array[i] > array[i - 1]) {// O(1) time
            descending = false;// O(1) time | O(1) space
        }
    }
    return ascending || descending;// O(1) time
}

// O(1) time | O(1) space
bool breaksDirection(int direction, int currentElement, int previousElement) {
    int difference = currentElement - previousElement;// O(1) time | O(1) space
    if(direction > 0) {// O(1) time
        return difference < 0;// O(1) time
    }
    return difference > 0;// O(1) time
}

// O(n) time | O(1) space
bool isMonotonicMultiMethod(vector<int> array) {
    if(array.size() <= 2) {// O(1) time
        return true;// O(1) time
    }
    int direction = array[1] - array[0];// O(1) time | O(1) space
    for(int i = 2; i < array.size(); i++) {// O(n) time
        if(direction == 0) {// O(1) time
            direction = array[i] - array[i - 1];// O(1) time | O(1) space
            continue;
        }
        if(breaksDirection(direction, array[i], array[i - 1])) {// O(1) time | O(1) space
            return false;// O(1) time
        }
    }
    return true;// O(1) time
}

int main() {
    vector<int> input = {-1, -5, -10, -1100, -1100, -1101, -1102, -9001};
    cout << isMonotonicBoolean(input) << endl;
    cout << isMonotonicMultiMethod(input) << endl;
    return 0;
}
