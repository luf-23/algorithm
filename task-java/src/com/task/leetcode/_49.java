package com.task.leetcode;

import java.util.*;

public class _49 {
    //字母异位词分组
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String,List<String>> mp = new HashMap<>();
        for (String s : strs){
            char []chars = s.toCharArray();
            Arrays.sort(chars);
            String now = new String(chars);
            if (!mp.containsKey(now)) mp.put(now,new ArrayList<>());
            mp.get(now).add(s);
        }
        List<List<String>> ans = new ArrayList<>();
        for (String key : mp.keySet()){
            ans.add(mp.get(key));
        }
        return ans;
    }
}
