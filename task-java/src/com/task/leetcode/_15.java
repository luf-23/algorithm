package com.task.leetcode;

import java.util.*;

public class _15 {
    //三数之和
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        Set<List<Integer>> ans = new HashSet<>();
        for (int i = 0; i < nums.length; i++) {
            int sum = 0 - nums[i];
            Set<Integer> container = new HashSet<>();
            for (int j = i + 1; j < nums.length; j++) {
                if (!container.contains(sum-nums[j])) container.add(nums[j]);
                else {
                    ans.add(Arrays.asList(nums[j], sum-nums[j], -sum));
                }
            }
        }
        return new ArrayList<>(ans);
    }
}
