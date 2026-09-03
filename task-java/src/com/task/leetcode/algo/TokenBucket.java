package com.task.leetcode.algo;

import java.util.concurrent.locks.ReentrantLock;

public class TokenBucket {
    private final long capacity;
    private final long refillRate;//毫秒/个
    private long tokens;
    private long lastRefillTime;
    private final ReentrantLock lock = new ReentrantLock();
    public TokenBucket(long capacity, long refillRate) {
        this.capacity = capacity;
        this.refillRate = refillRate;
        this.tokens = capacity;
        this.lastRefillTime = System.currentTimeMillis();
    }
    public boolean tryAcquire(long permitCount) {
        lock.lock();
        try {
            refill();
            if (tokens >= permitCount) {
                tokens -= permitCount;
                return true;
            }
            return false;
        } finally {
            lock.unlock();
        }
    }
    public long getCurrentTokens() {
        lock.lock();
        try {
            long refillCount = (System.currentTimeMillis() - lastRefillTime) / refillRate;
            return Math.min(capacity, tokens + refillCount);
        } finally {
            lock.unlock();
        }
    }
    private void refill() {
        long now = System.currentTimeMillis();
        long period = now - lastRefillTime;
        long refillCount = period / refillRate;
        tokens = Math.min(capacity, tokens + refillCount);
        lastRefillTime = now;
    }
}
