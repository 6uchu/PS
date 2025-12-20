#include<bits/stdc++.h>
using namespace std;
int n, flag1 = 1, flag2 = 1, bigeven, bigodd, prevv;
vector<int> vec;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int a; cin >> a;

        vec.push_back(a);
    }
    //짝 짝 짝
    bigodd = NULL;
    bigeven = NULL;
    for(int i = 0; i < n; i++){
        if(bigodd != 0 && vec[i] < bigodd){
            //홀 + 홀 -> 짝
            if((vec[i] + bigodd) % 2 == 0){
                flag1 = 0;
            //짝 + 홀 -> 홀
            }else{
                flag2 = 0;
            }

            if((vec[i] & 1) && vec[i] > bigodd)
                bigodd = vec[i];
        }else if(vec[i] & 1) bigodd = vec[i];
        
        if(bigeven != 0 && vec[i] < bigeven){
            //짝 + 짝 -> 짝
            
            if((vec[i] + bigeven) % 2 == 0){
                flag1 = 0;
            //홀 + 짝 -> 홀
            }else{
                flag2 = 0;
            }

            if((vec[i] & 1) && vec[i] > bigeven)
                bigeven = vec[i];
        }else if(!(vec[i] & 1)) bigeven = vec[i];
    }
 
    cout << (flag1 ? "So Lucky\n" : "Unlucky\n");
    cout << (flag2 ? "So Lucky\n" : "Unlucky\n");
}