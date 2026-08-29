package com.task.leetcode;

import java.util.*;

public class _438 {
    //找到字符串中所有字母异位词
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> index = new ArrayList<>();
        int n = s.length();
        int m = p.length();
        if (m > n) return index;
        Map<Character,Integer> mp = new HashMap<>();
        for (int i=0;i<m;i++){
            mp.put(p.charAt(i),mp.getOrDefault(p.charAt(i),0)+1);
        }
        int cnt = mp.entrySet().size();
        for (int i=0;i<m;i++){
            mp.put(s.charAt(i),mp.getOrDefault(s.charAt(i),0)-1);
            if (mp.get(s.charAt(i))==0) cnt--;
        }
        if (cnt==0) index.add(0);
        for (int i=m;i<n;i++){
            mp.put(s.charAt(i),mp.getOrDefault(s.charAt(i),0)-1);
            if (mp.get(s.charAt(i))==0) cnt--;
            mp.put(s.charAt(i-m),mp.getOrDefault(s.charAt(i-m),0)+1);
            if (mp.get(s.charAt(i-m))==1) cnt++;
            if (cnt==0) index.add(i-m+1);
        }
        return index;
    }

}
