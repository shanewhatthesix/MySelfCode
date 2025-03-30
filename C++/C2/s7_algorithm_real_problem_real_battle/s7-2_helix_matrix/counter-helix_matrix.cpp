/*
#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int main() {
	
	int n;
	cin>>n;

	for(int j=0; j<=n+1; ++j) a[0][j]=1;
	for(int i=0; i<=n+1; ++i) a[i][n+1]=1;
	for(int j=0; j<=n+1; ++j) a[n+1][j]=1;
	for(int i=0; i<=n+1; ++i) a[i][0]=1;

	int i=1,j=1,c=1;

	while(c<=n*n) {
		while(a[i][j]==0) {
			a[i][j]=c;
			c++;
			i++;
		}
		j--;
		i++;

		while(a[i][j]==0) {
			a[i][j]=c;
			c++;
			j++;
		}
		j--;
		i--;

		while(a[i][j]==0) {
			a[i][j]=c;
			c++;
			i--;
		}
		j--;
		i++;

		while(a[i][j]==0) {
			a[i][j]=c;
			c++;
			j--;
		}
		i--;
		j--;
	}

	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			cout<<a[i][j]<<" ";
			if(a[i][j]<10) {
				cout<<" ";
			}
		}
		cout<<endl;
	}
	
	cout<<i<<" "<<j<<" "<<c;

	return 0;
}
*/

#include <iostream>
using namespace std;

const int MAX_N = 100;
int a[MAX_N][MAX_N];

int main() {
    int n;
    cin >> n;

    // Initialize the matrix with 0s
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = 0;
        }
    }

    int i = 0, j = 0, c = 1;
    int direction = 0; // 0: down, 1: right, 2: up, 3: left

    while (c <= n * n) {
        a[i][j] = c;
        c++;

        // Determine next cell based on direction
        int ni = i, nj = j;
        switch (direction) {
            case 0: // down
                ni++;
                break;
            case 1: // right
                nj++;
                break;
            case 2: // up
                ni--;
                break;
            case 3: // left
                nj--;
                break;
        }

        // Check if next cell is out of bounds or already filled
        if (ni < 0 || ni >= n || nj < 0 || nj >= n || a[ni][nj] != 0) {
            direction = (direction + 1) % 4; // Change direction
            switch (direction) {
                case 0: // down
                    ni = i + 1;
                    nj = j;
                    break;
                case 1: // right
                    ni = i;
                    nj = j + 1;
                    break;
                case 2: // up
                    ni = i - 1;
                    nj = j;
                    break;
                case 3: // left
                    ni = i;
                    nj = j - 1;
                    break;
            }
        }

        i = ni;
        j = nj;
    }

    // Print the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

