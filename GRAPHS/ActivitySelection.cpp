/* In Activity selection activities are selected based on their start and finish times such that maximum number of non-overlapping activities are selected. 
(i) sort activities acc to finish time in acending order
0 th idx i.e 1st activity is always selected
select new activity whoes start time >= finish time of previous activity    */

#include<bits/stdc++.h>
using namespace std;

vector<int> ActivitySelect(vector<int>&start, vector<int>&finish, int  n)
{
    vector<int> res;
    //vector<pair<pair<int, int>,  int>>activities;
vector<pair<int, int>>activities;

    for(int i=0; i<n; i++)
    {
       // activities[i] = {{finish[i], start[i]}, i};
       activities[i] = {finish[i], start[i]};
    }
    sort(activities.begin(), activities.end()); //it will sort acc to finish time

    for(int i=0; i<n; i++){//to use start[i] >= finish[prv_selected], again store, sorted activities to start & finish array
        start[i] = activities[i].second;
        finish[i] = activities[i].first;
     }

    //res.push_back(0);   //activity 1 always selected so push idx 0
    res.push_back(0);
    int prv_selected = 0;
    for(int i=1; i<n; i++)
    {
       // if(start[i] >= finish[prv_selected])  
       if(activities[i].second >= activities[prv_selected].first)    
        {
            res.push_back(i);
            prv_selected = activities[i].first;
          //  prv_selected = i;
        }
    }
return res;
}

int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int>start(n);
    vector<int>finish(n);
    vector<int>res;
    cout<<"Enter start time and finish time of the activities: ";
    for(int i =0; i<n; i++)
    {
        cin>>start[i];
        cin>>finish[i];
    }
    res=ActivitySelect(start, finish, n);
    cout<<"Activity Selected their index are: ";
    for(int i =0; i<res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}