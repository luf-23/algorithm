package com.task.algo.graph;

import com.task.common.Pair;

import java.util.ArrayDeque;
import java.util.Queue;

public class BFS {
    private static final int []dx = {-1,0,1,0};
    private static final int []dy = {0,1,0,-1};
    //0为障碍，1为可通行
    //标记访问vis数组，返回影响点数
    //leetcode-200
    public static int bfs(int [][]num,int [][]vis,int n,int m,int x,int y){
        if (x<0||x>n||y<0||y>m||num[x][y]==0||vis[x][y]==1) return 0;
        Queue<Pair<Integer,Integer>> queue = new ArrayDeque<>();
        int ans = 1;
        vis[x][y] = 1;
        queue.add(new Pair<>(x,y));
        while (!queue.isEmpty()){
            Pair<Integer,Integer> now = queue.poll();
            ans++;
            for (int i=0;i<4;i++){
                int nx = now.getKey() + dx[i];
                int ny = now.getValue() + dy[i];
                if (nx<0||nx>n||ny<0||ny>m||num[nx][ny]==0||vis[nx][ny]==1) continue;
                vis[nx][ny] = 1;
                queue.add(new Pair<>(nx,ny));
            }
        }
        return ans;
    }
    //leetcode-994
    public static int bfs(int [][]num,int [][]vis,int n,int m,Queue<Pair<Integer,Integer>> queue){
        int ans = 0;
        Queue<Pair<Integer,Integer>> nextQueue = new ArrayDeque<>();
        while (!queue.isEmpty()){
            while (!queue.isEmpty()){
                Pair<Integer,Integer> now = queue.poll();
                for (int i=0;i<4;i++){
                    int nx = now.getKey() + dx[i];
                    int ny = now.getValue() + dy[i];
                    if (nx<0||nx>n||ny<0||ny>m||num[nx][ny]==0||vis[nx][ny]==1) continue;
                    vis[nx][ny] = 1;
                    nextQueue.add(new Pair<>(nx,ny));
                }
            }
            if (!nextQueue.isEmpty()) ans++;
            queue = nextQueue;
            nextQueue = new ArrayDeque<>();
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                if (num[i][j]==1&&vis[i][j]==0) return -1;
            }
        }
        return ans;
    }
}
