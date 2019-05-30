#include <cmath>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

int maxSize;

int hashMe(int x, int y, int maxSize){
  return y*maxSize + x;
}

    /*
    index and total form a key for a map, since there are more than just total combinations. Every time you
    reduce the index by 1, you create the possibility of total more combinations, so you need to be able to 
    account for index*total possible recursive calls. Besides a map I think a vector of vectors would work too, 
    where you return vec[total][coins.size()-1], but the map worked.
    */
int cc(vector<int> coins, unordered_map<int, int> &combos, int total, int index){
    if (index < 0 || total < 0)
        return 0;
    if (total == 0)
        return 1;

    int key = hashMe(index, total, maxSize);
    
    if (combos.count(key) == 0){
        int combos_with = cc(coins, combos, total-coins[index], index);
        int combos_without = cc(coins, combos, total, index-1);
        combos[key] = combos_with + combos_without;
    }
    return combos[key]; 
}

int cc_m(vector<int> coins, int total){
    unordered_map<int, int> combos;
    maxSize = total*coins.size()-1;
    return cc(coins, combos, total, coins.size()-1);
}



int main() {
    int total;
    cin >> total;

    int n;
    cin >> n;

    vector<int> coins(n);
    for (int i = 0; i < n; i++){
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());
    cout << cc_m(coins, total);
}

