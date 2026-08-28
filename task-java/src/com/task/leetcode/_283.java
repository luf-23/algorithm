package com.task.leetcode;


public class _283 {
    public void moveZeroes(int[] nums) {
        //原地移动0到末尾O(n)
        int []pre = new int[nums.length];
        pre[0] = nums[0] == 0 ? 1 : 0;
        for (int i=1;i<nums.length;i++) pre[i] = pre[i-1] + (nums[i] == 0 ? 1 : 0);
        for (int i=0;i<nums.length;i++){
            int cnt = i>0 ? pre[i-1] : 0;
            int j = i;
            while (cnt>0){
                swap(nums,j,j-1);
                j--;
                cnt--;
            }
        }
    }
    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
