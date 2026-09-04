package com.task.leetcode;

import com.task.algo.graph.BFS;

public class _200 {
    public int numIslands(char[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int ans = 0;
        int [][] num = new int[n+1][m+1];
        int [][] vis = new int[n+1][m+1];
        for (int i=0;i<=n;i++){
            for (int j=0;j<=m;j++){
                if (i==0||j==0) num[i][j] = 0;
                else{
                    if (grid[i-1][j-1]=='1') num[i][j] = 1;
                    else num[i][j] = 0;
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                if (num[i][j]==1&&vis[i][j]==0){
                    int count = BFS.bfs(num,vis,n,m,i,j);
                    //CommonUtil.printArray(vis);
                    if (count>0) ans++;
                }
            }
        }
        return ans;
    }
}
