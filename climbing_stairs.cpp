#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int stairs_h(vector<int> steps, vector<int> &mins, int index){
    if (mins[index] == -1){
        mins[index] = min(stairs_h(steps, mins, index-1), stairs_h(steps, mins, index-2))+steps[index];
    }
    return mins[index];
}

int stairs_m(vector<int> steps, int size){
    vector<int> mins (size, -1);
    mins[0] = steps[0];
    mins[1] = steps[1];
    int index = size-1;
    return stairs_h(steps, mins, index);
}


int main() {
    int n;
    cin >> n;
    vector<int> steps(n);
    for (int i = 0; i < n; i++){
        cin >> steps[i];
    }
    cout << stairs_m(steps, n);
    return 0;
}
