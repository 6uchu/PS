#include<bits/stdc++.h>
using namespace std;
char plane[54][54];
int fcnt[54][54];
int sum[54];
int n;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char c; cin >> c;
            plane[i][j] = c;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(plane[i][j] == 'Y' && plane[i][j] == plane[j][i]){
                fcnt[i][j] = 1;
                fcnt[j][i] = 1;    
            }
        }
        for(int j = i + 1; j < n; j++){
            for(int l = 0; l < n; l++){
                if(plane[i][l] == 'Y' && plane[j][l] == 'Y'){
                    fcnt[i][j] = 1;
                    fcnt[j][i] = 1; 
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        int tmp = 0;
        for(int j = 0; j < n; j++){
            tmp += fcnt[i][j];
        }
        sum[i] = tmp;
    }

    cout << *max_element(sum, sum + n);
}