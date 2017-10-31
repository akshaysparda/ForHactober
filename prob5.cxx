#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int input, sum = 0;
    queue <int> moduloZeroQ;
    queue <int> moduloOneQ;
    queue <int> moduloTwoQ;
    vector <int> inputArray;
    
    cout << "Enter the digits ";

    while (cin >> input) {
        if (input < 0 || input > 9) {
            cout << "Out of range, only positive digits allowed " << endl;
            exit (0);
        }

        inputArray.push_back (input);
    }

    sort (inputArray.begin(), inputArray.end());

    for (int i = 0; i < inputArray.size(); i++) {
        sum += inputArray[i];
        int remainderByThree = inputArray[i] % 3;

        // Push the element to the appropriate queue
        if (remainderByThree == 0) 
            moduloZeroQ.push (inputArray[i]);
        else if (remainderByThree == 1)
            moduloOneQ.push (inputArray[i]);
        else // remainder is 2
            moduloTwoQ.push (inputArray[i]);
    }

    // Check the sum of elements and take necessary action
    vector <int> resultArray;
    int remOfSum = sum % 3;

    // Can include all elements when remOfSum is 0, happens outside the conditional
    if (remOfSum == 1) {
        // Pop one element from moduloOneQ if non-empty, else pop 2 elements from moduloTwoQ
        if (!moduloOneQ.empty()) { // pop one element from moduloOneQ
            moduloOneQ.pop();
        }
        else if (moduloTwoQ.size() >= 2) { // pop 2 elements from moduleTwoQ
            moduloTwoQ.pop();
            moduloTwoQ.pop();
        }
        else { // A number divisible by 3 cannot be formed
            cout << "No multiple of 3 can be formed ";
            exit (0);
        }
    }
    else if (remOfSum == 2) {
        // Pop one element from moduloTwoQ if non-empty, else pop 2 elements from moduloOneQ
        if (!moduloTwoQ.empty()) { // pop one element from moduloTwoQ
            moduloTwoQ.pop();
        }
        else if (moduloOneQ.size() >= 2) { // pop 2 elements from moduleOneQ
            moduloOneQ.pop();
            moduloOneQ.pop();
        }
        else { // A number divisible by 3 cannot be formed
            cout << "No multiple of 3 can be formed ";
            exit (0);
        }
    }

    // Empty the queues into a result vector
    while (!moduloZeroQ.empty()) {
        resultArray.push_back (moduloZeroQ.front());
        moduloZeroQ.pop();
    }
    while (!moduloOneQ.empty()) {
        resultArray.push_back (moduloOneQ.front());
        moduloOneQ.pop();
    }
    while (!moduloTwoQ.empty()) {
        resultArray.push_back (moduloTwoQ.front());
        moduloTwoQ.pop();
    }

    // Result Array is ready, sort in decreasing order -- usual sort is in increasing order
    sort (resultArray.begin(), resultArray.end(), greater<int>());

    if (resultArray.size() != 0) {
        cout << "The greatest multiple of 3 is ";
        for (int i = 0; i < resultArray.size(); i++)
            cout << resultArray[i];
    }
    else {
            cout << "No multiple of 3 can be formed ";
    }
    cout << endl;
}
