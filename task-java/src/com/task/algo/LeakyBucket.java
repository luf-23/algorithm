package com.task.algo;

import java.util.concurrent.locks.ReentrantLock;

public class LeakyBucket {
    private final long capacity;
    private long currentWater;
    private long leakRate;//毫秒/滴
    private long lastLeakTime;
    private final ReentrantLock lock = new ReentrantLock();
    public LeakyBucket(long capacity,long leakRate){
        this.capacity = capacity;
        this.leakRate = leakRate;
        this.lastLeakTime = System.currentTimeMillis();
    }
    public boolean tryAcquire(int permitCount){
        if (permitCount < 0){
            throw new IllegalArgumentException("permitCount must be non-negative");
        }
        lock.lock();
        try{
            leak();
            if (currentWater+permitCount <= capacity){
                currentWater += permitCount;
                return true;
            }
            return false;
        }finally {
            lock.unlock();
        }
    }
    public long getCurrentWater(){
        lock.lock();
        try{
            long leaked = (System.currentTimeMillis()-lastLeakTime) / leakRate;
            return Math.max(0,currentWater-leaked);
        }finally {
            lock.unlock();
        }
    }
    private void leak(){
        //计算漏出的水
        long now = System.currentTimeMillis();
        long period = now - lastLeakTime;
        long leaked = period / leakRate;
        //更新当前水量和时间
        currentWater = Math.max(0,currentWater-leaked);
        lastLeakTime = now;
    }
}
