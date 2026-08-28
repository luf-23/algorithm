package com.task.leetcode;

import java.util.HashMap;
import java.util.Map;

public class _128 {
    //最长连续序列0(n)
    public int longestConsecutive(int[] nums) {
        int n = nums.length;
        int []dp = new int[n];
        int []vis = new int[n];
        int []next = new int[n];
        int []pre = new int[n];
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i=0;i<n;i++){
            dp[i] = 1;
            next[i] = -1;
            pre[i] = -1;
            vis[i] = 0;
            mp.put(nums[i], i);
        }
        for (int i=0;i<n;i++){
            if (mp.containsKey(nums[i]+1)) next[i] = mp.get(nums[i]+1);
            if (mp.containsKey(nums[i]-1)) pre[i] = mp.get(nums[i]-1);
        }
        for (int i=0;i<n;i++){
            System.out.print(pre[i]+ " ");
        }
        System.out.println();
        for (int i=0;i<n;i++){
            if (vis[i]==1 || pre[i] != -1) continue;
            int j = i;
            while (next[j] != -1){
                dp[next[j]] = dp[j] + 1;
                vis[j] = 1;
                j = next[j];
            }
        }
        int ans = 0;
        for (int i=0;i<n;i++){
            ans = Math.max(ans, dp[i]);
        }
        return ans;
    }
}
