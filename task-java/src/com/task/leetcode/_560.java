package com.task.leetcode;

import java.util.Arrays;

public class _560 {
    //和为k的子数组
//    public int subarraySum(int[] nums, int k) {
//        //test();
//        int ans = 0;
//        //Arrays.sort(nums);
//        int n = nums.length;
//        for (int i=0;i<n;i++) nums[i] += 1001;
//        int []pre = new int[n];
//        if (n>0) pre[0] = nums[0];
//        for (int i=1;i<n;i++) pre[i] = pre[i-1] + nums[i];
//        //for (int i=0;i<n;i++) System.out.print(pre[i]+" ");
//        //System.out.println();
//        for (int i=0;i<n;i++){
//            int tar = (i>0 ? pre[i-1] : 0) + k;
//            //System.out.println("tar:"+tar);
//            int pos1 = lower_bound(pre,i,n-1,tar);
//            int pos2 = upper_bound(pre,i,n-1,tar);
//            //System.out.println("pos1,pos2="+pos1+","+pos2);
//            ans += pos2-pos1;
//        }
//        return ans;
//    }
//
//    private int lower_bound(int[] nums,int left,int right,int target){
//        int l = left-1;
//        int r = right+1;
//        while (l+1 < r){
//            int mid = (l+r) / 2;
//            int value = nums[mid];
//            if (value >= target) r = mid;
//            else l = mid;
//        }
//        return r;
//    }
//    private int upper_bound(int[] nums,int left,int right,int target){
//        int l = left-1;
//        int r = right+1;
//        while (l+1 < r){
//            int mid = (l+r) / 2;
//            int value = nums[mid];
//            if (value > target) r = mid;
//            else l = mid;
//        }
//        return r;
//    }
//
//    private void test(){
//        int []nums = new int[]{1,1,1,2,2,2,2,3,4,5};
//        int n = nums.length;
//        System.out.println(lower_bound(nums,0,n-1,2));
//        System.out.println(upper_bound(nums,0,n-1,2));
//    }
    public int subarraySum(int[] nums, int k){
        int n = nums.length;
        int []pre = new int[n];
        int ans = 0;
        if (n>0) pre[0] = nums[0];
        for (int i=1;i<n;i++) pre[i] = pre[i-1] + nums[i];
        for (int i=0;i<n;i++){
            for (int j=i;j<n;j++){
                if (pre[j] - pre[i] + nums[i] == k) ans++;
            }
        }
        return ans;
    }
}
