#include <iostream>
堆 + BFS 参考出处

动态规划 参考出处

class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {
        /**
        基于最短路径Dijkstra算法, 加上了k中转的约束, 利用一个优先队列按费用最低保存到达不同目标站
        所需的中间站数和费用, 每次从优先队列中poll出一个当前最小花费的站, 如果该站为dst则直接返回
        对应的费用(优先队列保证花费最低). 为了便于更新, 利用一个map保存不同的始发站可以到达的不同
        下一站的和费用
        
        Map<Integer, Map<Integer, Integer>> map = new HashMap<>();
        for(int[] flight : flights) {
            if(!map.containsKey(flight[0]))
                map.put(flight[0], new HashMap<>(0));
            map.get(flight[0]).put(flight[1], flight[2]);
        }
        
        // 数组内元素依次为: 到达站的最低费用(fee)、到达站(tar)和经过中转的站数(k)
        PriorityQueue<int[]> pq = new PriorityQueue<>(
            (a, b) -> (a[0]-b[0])
        );
        pq.offer(new int[]{0, src, 0});
        
        while(!pq.isEmpty()) {
            int[] temp = pq.poll();
            int fee = temp[0];
            int tar = temp[1];
            int k = temp[2];
            if(tar == dst) return fee;
            if(k <= K) {
                // 防止下一站城市不在map中
                Map<Integer, Integer> nextHops = map.getOrDefault(tar, new HashMap<>());
                for(Map.E***y<Integer, Integer> e***y : nextHops.e***ySet()) 
                    pq.offer(new int[]{fee + e***y.getValue(), e***y.getKey(), k+1});
            }
        }
        
        return -1;
        **/
        
        /**
        动态规划解法, dp[i][k]表示经过k个中转站后到达站i的最低费用
        初始除了dp[src][0]~dp[src][k]之外所有的元素置为无穷大inf
        则状态方程为: 对于所有目标地位i的航班(flight[1] = i)
        只要dp[flight[0]][k-1] != inf就更新dp[i][k]
        dp[i][k] = Math.min(dp[i][k], dp[flight[0]][k-1])
        **/
        
        int[][] dp = new int[n][K+2];
        for(int i = 0; i < n; ++i) Arrays.fill(dp[i], Integer.MAX_VALUE);
        for(int k = 0; k <= K+1; ++k) dp[src][k] = 0;
        for(int k = 1; k <= K+1; ++k) {
            for(int[] flight : flights) {
                if(dp[flight[0]][k-1] != Integer.MAX_VALUE)
                    dp[flight[1]][k] = Math.min(dp[flight[1]][k], dp[flight[0]][k-1] + flight[2]);
            }
        }
        return dp[dst][K+1] == Integer.MAX_VALUE ? -1 : dp[dst][K+1];
    }
}
评论(11)
guo-guo-2果果
12 天前
动态规划，dp[i][k]表示经过k次中转到达i的最低费用

class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {
        int[][] dp = new int[n][K+1];
        for(int i=0; i<n; i++){
            Arrays.fill(dp[i], Integer.MAX_VALUE);
        }
        Arrays.fill(dp[src], 0);

        for(int[] flight : flights){
            int s = flight[0];
            int d = flight[1];
            int p = flight[2];
            if(s == src){
                dp[d][0] = p;
            }
        }

        for(int i=1; i<K+1; i++){
            for(int[] flight : flights){
                int s = flight[0];
                int d = flight[1];
                int p = flight[2];
                if(dp[s][i-1] != Integer.MAX_VALUE) {
                    dp[d][i] = Math.min(dp[d][i], dp[s][i - 1] + p);
                }
            }
        }
        return dp[dst][K] == Integer.MAX_VALUE  ? -1 : dp[dst][K];
    }
}

