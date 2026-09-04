package com.task.algo.sort;

import com.task.common.PrintUtil;

public class Main {
    public static void main(String[] args) {
        int[] array = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
        Sort sort = new QuickSort();
        sort.sort(array);
        PrintUtil.printArray(array);
    }
}
