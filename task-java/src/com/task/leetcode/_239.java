package com.task.leetcode;

import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class _239 {
    // 239. 滑动窗口最大值
    public int[] maxSlidingWindow(int[] nums, int k) {
        Map<Integer, Integer> mp = new HashMap<>();
        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b)->b-a);
        int n = nums.length;
        for (int i=0;i<k;i++){
            mp.put(nums[i],mp.getOrDefault(nums[i],0)+1);
            if (mp.get(nums[i])==1) pq.add(nums[i]);
        }
        int[] ans = new int[n-k+1];
        ans[0] = pq.peek();
        for (Integer key : mp.keySet()){
            //System.out.println("key:"+key+" "+mp.get(key));
        }
        //System.out.println("初始pq:"+pq.peek());
        for (int i=k;i<n;i++){
            //System.out.println("i:"+i+" nums[i],nums[i-k]="+nums[i]+","+nums[i-k]);
            mp.put(nums[i-k],mp.getOrDefault(nums[i-k],0)-1);
            while (!pq.isEmpty()&&mp.get(pq.peek())==0){
                //System.out.println("要丢掉的："+nums[pq.peek()]);
                pq.poll();
            }
            //System.out.println("---------------------");
            mp.put(nums[i],mp.getOrDefault(nums[i],0)+1);
            if (mp.get(nums[i])==1) pq.add(nums[i]);
            ans[i-k+1] = pq.peek();
        }
        return ans;
    }
}
