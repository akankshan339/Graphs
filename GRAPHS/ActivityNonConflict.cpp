#include <bits/stdc++.h>
using namespace std;

// Activity_Select(int n, vector<int> &start, vector<int> &end)
// {

// }
//sort in acending order of finish time
bool comparator(const pair<int, int> &a, const pair<int, int>&b)
{
    return a.second < b.second;
}
int main()
{
    int n;
    cout<<"Enter no of activities : ";
    cin>>n;
    vector<int> start(n), end(n), res;
    cout<<"Enter the start time : ";
    for(int i =0; i<n; i++)
    {
        cin>>start[i];
    }
    
    cout<<"Enter the end time : ";
     for(int i =0; i<n; i++)
    {
        cin>>end[i];
    }
    // Activity_Select(n, start, end);
    vector<pair<int, int>> activities;
    for(int i =0; i<n; i++)
    {
        activities.push_back({start[i], end[i]});
    }
    sort(activities.begin(), activities.end(), comparator);
    res.push_back(1);       //1st activity always selected 
    int prv = activities[0].second;
    int count =1;
    for(int i =1; i<n; i++)
    {
        if(activities[i].first >= prv)
        {
        res.push_back(i+1);
        count++;
         prv = activities[i].second;
        }
    }
    cout<<"No of Activity Selected :"<<count;
    cout<<"List of Activity Selected are : ";
    for(int i =0; i<res.size(); i++)
    {
        cout<<res[i]<<" ";
    }



}



