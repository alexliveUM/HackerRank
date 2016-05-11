#include <cmath>
#include <vector>
#include <iostream>

//
//  Created by Alexander Li on 5/11/16.
//  Copyright © 2016 Alexander L. Li (alexlive). All rights reserved.
//

//	Valid solution for LeetCode's '338. Counting Bits' problem
//	Calculates, for every number i in range [0, num], the number of 
//	'1's in their binary representation.
//	num = 5, return [0, 1, 1, 2, 1, 2]

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> solution(num + 1, 0);
        if(num == 0) return solution;
        solution[1] = 1;
        if (num == 1) return solution;
        bool add = false, set = false;
        int pwr = 0, count = 0;
        for (int i = 2; i <= num; i++){
            if (isPowerTwo(i)){
                pwr = log2(i) - 1;
                set = true;
                count = 0;
            }
           if (set == false){
                solution[i] = solution[i - pow(2, pwr)] + 1;
            }
            if (set == true){     
                solution[i] = solution[i - pow(2, pwr)];
                count++;  
                if (count >= pow(2, pwr)) set = false;
            }
        }
        return solution;
    }
    private:
        bool isPowerTwo(int num){
            while ((num % 2) == 0 && num > 1) num /= 2;
            return (num == 1);
        }
};