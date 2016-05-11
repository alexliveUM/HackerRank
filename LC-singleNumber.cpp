//
//  Created by Alexander Li on 5/11/16.
//  Copyright © 2016 Alexander L. Li (alexlive). All rights reserved.
//

//	Valid solution for LeetCode's '136. Single Number' problem
//	Array of elements, all of which appear TWICE except for one. Return that single element
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int i = 0;
        for (auto it = nums.begin(); it != nums.end(); it++){
            i = i ^ *it;
        }
        return i;
    }
};