#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

//
//  Created by Alexander Li on 5/11/16.
//  Copyright © 2016 Alexander L. Li (alexlive). All rights reserved.
//

//	Valid solution for Hacker Rank's 'Lower bound - STL' challenge
//	All Domains -> C++ -> STL -> Lower Bound - STL

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int size;
    cin >> size;
    map<int, int> search;
    int input, index;
    for(int i = 0; i < size; i++){
        cin >> input;
        if (search.find(input) == search.end()) search[input] = i + 1;
    }
    if (search.find(input) == search.end()){
        search[input] = size;
    } 
    cin >> size;
    for (int i = 0; i < size; i++){
        int query;
        cin >> query;
        auto it = search.find(query);
        if (it == search.end()){
            search[query] = -1;
            it = search.find(query);
            auto temp = it;
            cout << "No " << (++temp)->second << endl;
            search.erase(it);
        }
        else {
            cout << "Yes " << it->second << endl;
        }
    }
    return 0;
}
