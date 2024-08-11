//indices stored in the res vector should reflect the original indices of the activities from the input lists.
#include <bits/stdc++.h>
using namespace std;

vector<int> ActivitySelect(vector<int>& start, vector<int>& finish, int n) {
    vector<int> res;
    vector<pair<pair<int, int>, int>> activities(n);

    for (int i = 0; i < n; i++) {
        activities[i] = {{finish[i], start[i]}, i};
    }

    // Sort activities based on their finish time
    sort(activities.begin(), activities.end());

    // The first activity is always selected
    res.push_back(activities[0].second);
    int last_finish_time = activities[0].first.first;

    for (int i = 1; i < n; i++) {
        if (activities[i].first.second >= last_finish_time) {
            res.push_back(activities[i].second);
            last_finish_time = activities[i].first.first;
        }
    }
    return res;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> start(n);
    vector<int> finish(n);

    cout << "Enter start time and finish time of the activities: ";
    for (int i = 0; i < n; i++) {
        cin >> start[i] >> finish[i];
    }

    vector<int> res = ActivitySelect(start, finish, n);

    cout << "Activities selected, their indices are: ";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}
