package com.task.leetcode;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class _76 {
    //76. 最小覆盖子串
    public String minWindow(String s, String t) {
        if (s == null || t == null || s.length() < t.length()) return "";
        int minPos = -1;
        int minLen = Integer.MAX_VALUE;
        int tail = 0;
        int require = t.length();//核心：还需匹配的字符总数
        Map<Character, Integer> need = new HashMap<>();
        for (Character c : t.toCharArray()) need.put(c,need.getOrDefault(c,0)+1);
        for (int i=0;i<s.length();i++){
            if (need.containsKey(s.charAt(i))){
                if (need.get(s.charAt(i))>0) require--;
                need.put(s.charAt(i),need.get(s.charAt(i))-1);
            }
            while (tail<=i&&require==0){
                if (i-tail+1<minLen) {
                    minPos = tail;
                    minLen = i-tail+1;
                }
                if (need.containsKey(s.charAt(tail))){
                    need.put(s.charAt(tail),need.get(s.charAt(tail))+1);
                    if (need.get(s.charAt(tail))>0) require++;
                }
                tail++;
            }
        }
        return minPos == -1 ? "" : s.substring(minPos, minPos + minLen);
    }
}
