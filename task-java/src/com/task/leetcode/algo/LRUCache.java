package com.task.leetcode.algo;

import com.task.leetcode.common.DoublyListNode;
import com.task.leetcode.common.Pair;

import java.util.HashMap;
import java.util.Map;

public class LRUCache {
    private final DoublyListNode head;
    private final DoublyListNode tail;
    private final Map<Integer, DoublyListNode> cacheMap;
    private final int capacity;

    public LRUCache(int capacity) {
        if (capacity <= 0) throw new IllegalArgumentException("Capacity must be greater than 0");
        this.capacity = capacity;
        head = new DoublyListNode();
        tail = new DoublyListNode();
        head.next = tail;
        tail.prev = head;
        cacheMap = new HashMap<>();
    }

    public int get(int key) {
        if (!cacheMap.containsKey(key)) return -1;
        DoublyListNode node = cacheMap.get(key);
        delete(key);
        int value = ((Pair<Integer, Integer>) node.val).getValue();
        add(key, value);
        return value;
    }

    public void put(int key, int value) {
        if (cacheMap.containsKey(key)) delete(key);
        if (cacheMap.size() >= capacity){
            Integer lastKey = ((Pair<Integer,Integer>) tail.prev.val).getKey();
            delete(lastKey);
        }
        add(key,value);
    }

    public void delete(int key) {
        if (!cacheMap.containsKey(key)) return;
        DoublyListNode node = cacheMap.get(key);
        node.prev.next = node.next;
        node.next.prev = node.prev;
        cacheMap.remove(key);
    }
    public void add(int key, int value){
        if (cacheMap.containsKey(key)) return;
        DoublyListNode node = new DoublyListNode(new Pair<>(key, value));
        node.next = head.next;
        node.prev = head;
        head.next.prev = node;
        head.next = node;
        cacheMap.put(key, node);
    }
}
