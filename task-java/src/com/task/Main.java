package com.task;

import com.task.leetcode._128;
import com.task.leetcode._283;
import com.task.leetcode._49;

public class Main {
    public static void main(String[] args) {
//        String []str = {"eat", "tea", "tan", "ate", "nat", "bat"};
//        _49 solution = new _49();
//        System.out.println(solution.groupAnagrams(str));
//        _128 solution = new _128();
//        System.out.println(solution.longestConsecutive(new int[]{100,4,200,1,3,2}));;
        _283 solution = new _283();
        int []nums = new int[]{0,1,0,3,12};
        solution.moveZeroes(nums);
        for (int i:nums) System.out.print(i+" ");

    }
}
