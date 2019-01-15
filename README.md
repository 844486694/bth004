## BTH004

#### Dijkstra最短路径

```c++
//邻接矩阵
int n, e[maxv][maxv];
int dis[maxv], pre[maxv];// pre用来标注当前结点的前一个结点
fill(dis, dis + maxv, inf);
bool vis[maxv] = {false};
void Dijkstra(int s) {
  dis[s] = 0;
  for(int i = 0; i < n; i++) pre[i] = i; //初始状态设每个点的前驱为自身
  for(int i = 0; i < n; i++) {
    int u = -1, minn = inf;
    for(int j = 0; j < n; j++) {
      if(visit[j] == false && dis[j] < minn) {
        u = j;
        minn = dis[j];
      }
    }
    if(u == -1) return;
    visit[u] = true;
    for(int v = 0; v < n; v++) {
      if(visit[v] == false && e[u][v] != inf && dis[u] + e[u][v] < dis[v]) {
        dis[v] = dis[u] + e[u][v];
        pre[v] = u; // pre用来标注当前结点的前一个结点
      }
    }
  }
}
//邻接表
struct node {
  int v, dis;
}
vector<node> e[maxv];
int n;
int dis[maxv], pre[maxv];// pre用来标注当前结点的前一个结点
bool vis[maxv] = {false};
for(int i = 0; i < n; i++) pre[i] = i; //初始状态设每个点的前驱为自身
void Dijkstra(int s) {
  fill(dis, dis + maxv, inf);
  dis[s] = 0;
  for(int i = 0; i < n; i++) {
    int u = -1, minn = inf;
    for(int j = 0; j < n; j++) {
      if(visit[j] == false && dis[j] < minn) {
        u = j;
        minn = dis[j];
      }
    }
    if(u == -1) return ;
    visit[u] = true;
    for(int j = 0; j < e[u].size(); j++) {
      int v = e[u][j].v;
      if(visit[v] == false && dis[u] + e[u][j].dis < dis[v]) {
        dis[v] = dis[u] + e[u][j].dis;
        pre[v] = u;
      }
    }
  }
}

void dfs(int s, int v) {
  if(v == s) {
    printf("%d\n", s);
    return ;
  }
  dfs(s, pre[v]);
  printf("%d\n", v);
}
• 三种附加考法：第一标尺是距离，如果距离相等的时候，新增第二标尺
• 新增边权（第二标尺），要求在最短路径有多条时要求路径上的花费之和最小
for(int v = 0; v < n; v++) { //重写v的for循环
  if(visit[v] == false && e[u][v] != inf) {
    if(dis[u] + e[u][v] < dis[v]) {
      dis[v] = dis[u] + e[u][v];
      c[v] = c[u] + cost[u][v];
    }else if(dis[u] + e[u][v] == dis[v] && c[u] + cost[u][v] < c[v]) {
      c[v] = c[u] + cost[u][v];
    }
  }
}
• 给定每个点的点权（第二标尺），要求在最短路径上有多条时要求路径上的点权之和最大
for(int v = 0; v < n; v++) {
  if(visit[v] == false && e[u][v] != inf) {
    if(dis[u] + e[u][v] < dis[v]) {
      dis[v] = dis[u] + e[u][v];
      w[v] = w[u] + weight[v];
    }else if(dis[u] + e[u][v] == dis[v] && w[u] + weight[v] > w[v]) {
      w[v] = w[u] + weight[v];
    }
  }
}
• 直接问有多少条最短路径
增加一个数组num[]，num[s] = 1，其余num[u] = 0，表示从起点s到达顶点u的最短路径的条数为num[u]
for(int v = 0; v < n; v++) {
  if(visit[v] == false && e[u][v] != inf) {
    if(dis[u] + e[u][v] < dis[v]) {
      dis[v] = dis[u] + e[u][v];
      num[v] = num[u];
    }else if(dis[u] + e[u][v] == dis[v]) {
      num[v] = num[v] + num[u];
    }
  }
}
```

#### 动态规划

- ##### 动态规划：

- - 将一个复杂的问题分解成若干个子问题，通过综合子问题的最优解来得到原问题的最优解
  - 动态规划会将每个求解过的子问题的解记录下来，这样下一次碰到同样的子问题时，就可以直接使用之前记录的结果，而不是重复计算
  - 可以用递归或者递推的写法实现，递归的写法又叫记忆化搜索
  - 重叠子问题：如果一个问题可以被分解成若干个子问题，且这些子问题会重复出现，就称这个问题拥有重叠子问题。       一个问题必须拥有重叠子问题，才能用动态规划去解决。
  - 最优子结构：如果一个问题的最优解可以由其子问题的最优解有效地构造出来，那么称为这个问题拥有的最有子结构。最优子结构保证了动态规划中的原问题的最优解可以由子问题的最优解推导而来
  - 动态规划与分治的区别：都是分解为子问题然后合并子问题得到解，但是分治分解出的子问题是不重叠的
  - 动态规划与贪心的区别：都有最优子结构，但是贪心直接选择一个子问题去求解，会抛弃一些子问题，这种选择的正确性需要用归纳法证明，而动态规划会考虑所有的子问题



- //不 使用动态规划

- ```c++
  int F(int n) {
  
    if(n == 0 || n == 1) return 1;
  
    else  return F(n - 1) + F(n - 2);
  
  }
  ```

- // 此时F(5) = F(4) + F(3), F(4) = F(3) + F(2),3会被计算两次

-  

- // 采用动态规划的方法(记忆化搜索)

- ```c++
  int dp[10000];
  
  memeset(dp, -1, sizeof(dp));
  
  int F(int n) {
  
    if(n == 0 || n == 1) return 1;
  
    if(dp[n] != -1) return dp[n];
  
    else {
  
      dp[n] = F(n-1) + F(n - 2);
  
      return  dp[n];
  
    }
  
  }
  ```

-  

- ##### 最大连续子序列和

- - 给定序列，求连续的子序列要求和最大，求最大的和为多少
  - dp[i]表示以a[i]作为末尾的连续序列的最大和（a[i]必须是末尾被选的数啊啊），dp数组中所有的数据的最大值就是所求
  - 因为a[i]一定是所选序列的末尾，所以分为两种情况：
  - a[i]开始，a[i]结束
  - 某数开始，到a[i]结束（最大和是dp[i-1] + a[i]）
  - 所以递推方程为dp[i] = max(a[i], dp[i-1]+a[i])

-  

- // a数组从下标0开始

- ```c++
  dp[0] = a[0];
  
  for(int i = 1; i < n; i++)
  
    dp[i] = max(a[i], dp[i-1]+a[i]);
  
   
  
  int maxn = dp[0];
  
  for(int i = 1; i < n; i++)
  
    maxn = max(dp[i], maxn);
  
   
  
  printf("%d", maxn);
  ```

- ##### 最长不下降子序列（LIS）

- - 求一个序列的最长的子序列（可以不连续），使得这个子序列是不下降的
  - dp[i]表示必须以a[i]结尾的最长不下降子序列的长度
  - dp[i] = max{1, dp[j] + 1}; // j从1 ~ i-1 且必须满足a[j] <= a[i]

- -  

- ```c++
  int ans = 0;
  
  for(int i = 0; i < n; i++) {
  
    for(int j = 1; j < i; j++) {
  
      if(a[i] >= a[j])
  
        dp[i] = max(1, dp[j] + 1);
  
    }
  
    ans = max(dp[i], ans);
  
  }
  
   
  
  printf("%d", ans);
  ```

- ##### 

- ##### 最长回文子串

- - 给出一个字符串s，求s的最长回文字串的长度
  - dp[i][j]表示s[i]到s[j]所表示的字串是否是回文字串。只有0和1
  - 递推方程：
  - 当s[i] == s[j] : dp[i][j] = dp[i+1][j-1]
  - 当s[i] != s[j] : dp[i][j] =0
  - 边界：dp[i][j] = 1, dp[i][i+1] = (s[i] == s[i+1]) ? 1 : 0
  - 因为i、j如果从小到大的顺序来枚举的话，无法保证更新dp[i][j]的时候dp[i+1][j-1]已经被计算过。因此不妨考虑按照字串的长度和子串的初试位置进行枚举，即第一遍将长度为3的子串的dp的值全部求出，第二遍通过第一遍结果计算出长度为4的子串的dp的值…这样就可以避免状态无法转移的问题

-  

- ```c++
  int len = s.length();
  
  //先把1和2长度的都初始化了
  
  int ans = 1;
  
  for(int i = 0; i < len; i++) {
  
    dp[i][i] = 1;
  
    if(i < len - 1 && s[i] == s[i+1]) {
  
      dp[i][i+1] = 1;
  
      ans  = 2;
  
    }
  
  }
  
  //状态转移方程
  
  for(int L = 3; L <= len; L++) {
  
    for(int i = 0; i + L - 1 < len; i++) {
  
      int  j = i + L - 1;
  
      if(s[i] == s[j] && dp[i+1][j-1] == 1) {
  
        dp[i][j] = 1;
  
        ans = L;
  
      }
  
    }
  
  }
  
  printf("%d", ans);
  ```

- DAG最长路

- 背包问题

- - 多阶段动态规划问题：有一类动态规划可解的问题，它可以描述成若干个有序的阶段，且每个阶段的状态有关，一般把这类问题称为多阶段动态规划问题

- 01背包问题

- - 有n件物品，每件物品的重量为w[i]，价值为c[i]。现有一个重量为V的背包，问如何选取物品放入背包，使得背包内物品的总价值最大。其中每种物品只有1件
  - dp[i][j]表示前i件物品恰好装入容量为j的背包所能获得的最大价值
  - 不放第i件物品，则dp[i][j] = dp[i-1][j]
  - 放第i件物品，那么问题转化为前i – 1件物品恰好装入容量j – w[i]的背包中所能获得的最大价值dp[i-1][j-w[i]]       + c[i]
  - 递推方程dp[i][j] = max{ dp[i-1][j], dp[i-1][j-w[i]]+c[i] }

- -  

- ```c++
  for(int i = 1; i <= n; i++) {
  
    for(int j = 1, j <= v; j++)
  
      if(j < w[i]) 
  
        dp[i][j] = dp[i-1][j];
  
     else 
  
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + c[i]);
  
  }
  
  - 一维：
  
  -  
  
  for(int i = 1; i <= n; i++) {
  
    for(int j = v; j >= w[i]; j--)
  
      dp[v] = max(dp[v], dp[v[w[i]]] + c[i]);
  
  }
  ```

- 完全背包问题

- - 有n种物品，每种物品的单件重量为w[i]，价值为c[i]。现有一个容量为v的背包，问如何选取物品放入背包，使得背包内物品的总价值最大。其中每种物品有无穷件
  - 递推方程：dp[i][j] = max(dp[i-1][v], dp[i][j-w[i]] + c[i])
  - 和01背包不同，这里的j的枚举顺序为正向枚举,而且是dp[i][j-w[i]]

- -  

- ```c++
  for(int i =1; i <= n; i++) {
  
    for(int j = w[i]; j <= v; j++)
  
     dp[j] = max(dp[i], dp[j-w[j]]+ c[i]);
  
  }
  ```

- 
