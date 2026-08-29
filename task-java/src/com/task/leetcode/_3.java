package com.task.leetcode;

import java.util.Map;

public class _3 {
    //最长不重复子序列
    public int lengthOfLongestSubstring(String s) {
        int ans = 0;
        int []num = new int [5000];
        int tail = 0;
        for (int i=0;i<s.length();i++){
            num[s.charAt(i)-'a'+1000]++;
            while (tail<i && num[s.charAt(i)-'a'+1000]>1){
                num[s.charAt(tail)-'a'+1000]--;
                tail++;
            }
            ans = Math.max(ans,i-tail+1);
        }
        return ans;
    }
}
