package com.task.algo.sort;

import com.task.common.CommonUtil;

public class QuickSort implements Sort {

    @Override
    public void sort(int[] array) {
        quickSort(array,0,array.length-1);
    }
    public void quickSort(int[]array,int low,int high){
        if (low>=high) return;
        int pi = partition(array,low,high);
        quickSort(array,low,pi-1);
        quickSort(array,pi+1,high);
    }
    public int partition(int[]array,int low,int high){
        int pivot = array[high];
        int tail = low;
        for (int now=tail;now<high;now++){
            if (array[now]<=pivot){
                CommonUtil.swap(array,tail,now);
                tail++;
            }
        }
        CommonUtil.swap(array,tail,high);
        return tail;
    }
}
