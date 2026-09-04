package com.task.leetcode;

import com.task.algo.graph.BFS;
import com.task.common.Pair;

import java.util.ArrayDeque;
import java.util.Queue;

public class _994 {
    public int orangesRotting(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int [][]num = new int[n+1][m+1];
        int [][]vis = new int [n+1][m+1];
        Queue<Pair<Integer,Integer>> queue = new ArrayDeque<>();
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                if (grid[i-1][j-1]==2){
                    vis[i][j] = 1;
                    num[i][j] = 0;
                    queue.add(new Pair<>(i,j));
                }else if (grid[i-1][j-1]==1){
                    num[i][j] = 1;
                }else{
                    num[i][j] = 0;
                }
            }
        }
        return BFS.bfs(num,vis,n,m,queue);
    }
}
