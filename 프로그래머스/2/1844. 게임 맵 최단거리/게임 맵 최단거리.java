import java.util.ArrayDeque;

class Solution {
    private static final int[] rx = {0, 0, 1, -1};
    private static final int[] ry = {1, -1, 0, 0};
    
    private static class Node {
        int r, c;
        public Node(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }
    
    public int solution(int[][] maps) {
        int N = maps.length;
        int M = maps[0].length;
        
        int[][] dist = new int[N][M];
        
        ArrayDeque<Node> q = new ArrayDeque<>();
        
        q.add(new Node(0, 0));
        dist[0][0]=1;
        
        while (!q.isEmpty()) {
            Node now = q.poll();
            
            for (int i=0; i< 4; i++) {
                int mr = now.r + rx[i];
                int mc = now.c + ry[i];
                
                if (mr<0 || mc<0 || mr>=N || mc>=M)
                    continue;
                
                if (maps[mr][mc]==0)
                    continue;
                
                if (dist[mr][mc]==0){
                    q.add(new Node(mr, mc));
                    dist[mr][mc]=dist[now.r][now.c]+1;
                }
            }
        }
        
        return dist[N-1][M-1] == 0 ? -1 : dist[N-1][M-1];
    }
}