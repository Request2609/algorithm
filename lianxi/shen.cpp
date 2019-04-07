/*
 给定一个 m x n 的非负整数矩阵来表示一片大陆上各个单元格的高度。
 “太平洋”处于大陆的左边界和上边界，而“大西洋”处于大陆的右边界和下边界。
规定水流只能按照上、下、左、右四个方向流动，且只能从高到低或者在同等高度上流动。
请找出那些水流既可以流动到“太平洋”，又能流动到“大西洋”的陆地单元的坐标。
提示：
    输出坐标的顺序不重要
    m 和 n 都小于150
示例：
给定下面的 5x5 矩阵:

  太平洋 ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * 大西洋

返回:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (上图中带括号的单元). 
 */
#include <iostream>
#include<vector>
using namespace std ;
class Solution {
public:
void dfs(vector<vector<bool>> &visit, vector<vector<int>>& matrix, int r, int c) {
	visit[r][c] = true;
	if ((r - 1) >= 0 && !visit[r-1][c] && matrix[r - 1][c] >= matrix[r][c]) dfs(visit, matrix, r - 1, c);
	if ((r + 1) < (int)matrix.size() && !visit[r + 1][c] && matrix[r + 1][c] >= matrix[r][c]) dfs(visit, matrix, r + 1, c);
	if ((c - 1) >= 0 && !visit[r][c-1] && matrix[r][c - 1] >= matrix[r][c]) dfs(visit, matrix, r, c - 1);
	if ((c + 1) < (int)matrix[0].size() && !visit[r][c+1] && matrix[r][c + 1] >= matrix[r][c]) dfs(visit, matrix, r, c + 1);
}

vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
	vector<pair<int, int>> res;
    //空的话，就退出
	if (matrix.empty()) return res;
    //计算数组的长宽
	int m = matrix.size(), n = matrix[0].size();
    
	vector<vector<bool>> visit_pacific(matrix.size(), vector<bool>(matrix[0].size(), false));
	vector<vector<bool>> visit_atlantic(matrix.size(), vector<bool>(matrix[0].size(), false));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || j == 0) visit_pacific[i][j] = true;
			if (i == (m - 1) || j == (n - 1)) visit_atlantic[i][j] = true;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || j == 0) dfs(visit_pacific, matrix, i, j);
			if (i == (m - 1) || j == (n - 1)) dfs(visit_atlantic, matrix, i, j);
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visit_atlantic[i][j] && visit_pacific[i][j]) res.push_back(make_pair(i, j));
		}
	}
	return res;
}
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

