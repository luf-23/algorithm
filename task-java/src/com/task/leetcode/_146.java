package com.task.leetcode;

import com.task.algo.LRUCache;

public class _146 {
    // 146.LRU
    public void test(){
        LRUCache lruCache = new LRUCache(5);
        lruCache.put(1, 1);
        lruCache.put(2, 2);
        lruCache.put(3, 3);
        lruCache.put(4, 4);
        lruCache.put(5, 5);
        lruCache.put(6, 6);
        System.out.println(lruCache.get(4));
    }
}
