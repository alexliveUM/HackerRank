#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

//
//  Created by Alexander Li on 5/10/16.
//  Copyright © 2016 Alexander L. Li (alexlive). All rights reserved.
//

//	Valid solution for Hacker Rank's '2D Array - DS' challenge by Shafeet
//	All Domains -> Data Structures > Arrays > 2D Array - DS

int sumHourglass(int i, int j, vector< vector<int> > a){
    int sum = a[i][j] + a[i][j+1] + a[i][j+2] + a[i+1][j+1] +a[i+2][j] + a[i+2][j+1] + a[i+2][j+2];  
    return sum;
}

int main(){
    vector< vector<int> > arr(6,vector<int>(6));
    for(int arr_i = 0;arr_i < 6;arr_i++){
       for(int arr_j = 0;arr_j < 6;arr_j++){
          cin >> arr[arr_i][arr_j];
       }
    }
    int max = numeric_limits<int>::min();
    //Starting code here
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            max = sumHourglass(i, j, arr) > max ? sumHourglass(i, j, arr) : max;
        }
    }
    cout << max;
    return 0;
}
