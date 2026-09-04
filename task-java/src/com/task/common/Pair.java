package com.task.common;

public class Pair<T,U> {
    private T first;
    private U second;
    public Pair(T first, U second) {
        this.first = first;
        this.second = second;
    }
    public T getKey() {
        return first;
    }
    public U getValue() {
        return second;
    }
    @Override
    public String toString() {
        return "(" + first + ", " + second + ")";
    }
}
