#include <bits/stdc++.h>

using namespace std;

int main () {
    deque <int> dq;
    vector <int> vec;
    int windowSize;
    int input;

    cout << "Enter windowSize " ;
    cin >> windowSize;

    while (cin >> input) {
        vec.push_back(input);
    }

    vector<int>:: iterator it;
    int ans = INT_MAX;

    if (windowSize == 1) {
        ans = *min_element (vec.begin(), vec.end());
    }
    else {
        for (int i = 0; i < vec.size(); i++) {

            // Remove all indices from back that are for elements less than vec[i]
            while (dq.size() && vec[dq.back()] < vec[i])
                dq.pop_back();

            // Push this index
            dq.push_back (i);

            // Remove all indices from front that are outside the window
            while (dq.size() && dq.front() <= i - windowSize) 
                dq.pop_front();

            // front of dq contains the maximum element in the current window
            // Update ans by checking the front of the dq
            if (i >= windowSize - 1) 
                ans = min (ans, vec[dq.front()]);
        }
    }

    cout << "Answer is " << ans << endl;
}
