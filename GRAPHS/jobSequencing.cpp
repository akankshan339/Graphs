#include <bits/stdc++.h>
using namespace std;
bool comparator(const vector<int> &a, const vector<int> &b)
{
    return a[2] > b[2]; //sorting deadlines in decending order 
}
int main()
{
    int n, total_profit =0;
    cout<<"Enter n: ";
    cin>>n;
    vector<int> id(n), deadline(n), profit(n), selected_job;
    cout<<"Enter job ids : ";
    for(int i=0; i<n; i++)
    {
        cin>>id[i];
    }
    cout<<"Enter deadlines of ids : ";
    for(int i=0; i<n; i++)
    {
        cin>>deadline[i];
    }
    cout<<"Enter profit from each id : ";
    for(int i=0; i<n; i++)
    {
        cin>>profit[i];
    }
    vector<vector<int>> job;
    for(int i=0; i<n; i++)
    {
       job.push_back({id[i], deadline[i], profit[i]});
        
    }
    sort(job.begin(), job.end(), comparator);

   // sort(deadline.rbegin(), deadline.rend());
    int max_deadline = deadline[0];
    vector<int>slot(max_deadline +1, -1);

    for(int i=0; i<n; i++)
    {
        for(int j =job[i][1]; j> 0 ;j--)
        {
            if(slot[j] == -1)
            {
                slot[j] = job[i][0];
                // slot[j] = i;
                total_profit += job[i][2];
                selected_job.push_back(job[i][0]);
                break;
            }
        }
    }
    cout << "Total profit: " << total_profit << endl;
    cout << "Selected jobs: ";
    for (int i = 0; i < selected_job.size(); i++)
    {
        cout << selected_job[i] << " ";
    }
     





    return 0;
}