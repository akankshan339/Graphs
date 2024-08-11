#include<bits/stdc++.h>
#define INF INT_MAX;
using namespace std;


int main()
{
    int n;
    cout<<"Enter size of matrix : ";
    cin>>n;
    vector<vector<int>> matrix(n, vector<int>(n, 1e9));
    cout<<"Enter matrix element: ";
    for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
                string val;
                cin>>val;
                if(val == "INF")
				matrix[i][j] = 1e9;
                else
                matrix[i][j] = stoi(val);
            }
    }


 for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][k] != 1e9 && matrix[k][j] != 1e9)
                {
                    matrix[i][j] = min(matrix[i][j] , matrix[i][k] + matrix[k][j]);
                }
            }
    }
 }
for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if(matrix[i][j] == 1e9)
                cout<<"INF"<<" ";
                else
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
    }


    return 0;
}