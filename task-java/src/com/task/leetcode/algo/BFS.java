package com.task.leetcode.algo;

import com.task.leetcode.common.Pair;

import java.util.ArrayDeque;
import java.util.Queue;

public class BFS {
    //0为障碍，1为可通行
    //标记访问vis数组，返回影响点数
    public static int bfs(int [][]num,int [][]vis,int n,int m,int x,int y){
        if (x<0||x>n||y<0||y>m||num[x][y]==0||vis[x][y]==1) return 0;
        int []dx = {-1,0,1,0};
        int []dy = {0,1,0,-1};
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
}
