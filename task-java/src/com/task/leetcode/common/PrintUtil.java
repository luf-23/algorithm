package com.task.leetcode.common;

public class PrintUtil {
    public static void printArray(Object[] array) {
        for (Object o : array) {
            System.out.print(o.toString() + " ");
        }
        System.out.println();
    }
    public static void printArray(Object [][]array){
        for (Object[] objects : array) {
            printArray(objects);
        }
    }

    public static void printArray(int[] array) {
        if (array == null) {
            System.out.println("null");
            return;
        }
        for (int i : array) {
            System.out.print(i + " ");
        }
        System.out.println();
    }

    public static void printArray(int[][] array) {
        if (array == null) {
            System.out.println("null");
            return;
        }
        for (int[] row : array) {
            printArray(row);
        }
    }

    public static void printArray(float[] array) {
        if (array == null) {
            System.out.println("null");
            return;
        }
        for (float f : array) {
            System.out.print(f + " ");
        }
        System.out.println();
    }

    public static void printArray(float[][] array) {
        if (array == null) {
            System.out.println("null");
            return;
        }
        for (float[] row : array) {
            printArray(row);
        }
    }
}
