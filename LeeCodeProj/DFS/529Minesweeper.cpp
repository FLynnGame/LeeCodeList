
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution529 {
public:
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		// 几种情况
		// 1. 选中的是雷(M) 直接修改board返回
		// 2. 选中的是空白(E)
		// 2.1 空白附近八个位置没有地雷->递归四个方向持续翻开
		// 2.2 空白附近八个位置有地雷->当前位置修改为地雷的数量，返回
		int x = click[0];
		int y = click[1];

		
		if (board[x][y] == 'M') {
			board[x][y] = 'X';
			return board;
		}

		if (board[x][y] == 'E')
		{
			int nMine = adjacentMineNum(x,y,board);
			
			if (nMine != 0) {
				board[x][y] = '0' + nMine;
				return board;
			}
			else {
				// 递归展开
				dfs(x, y, board);
			}
		}

		return board;
	}

	void dfs(int x, int y, vector<vector<char>>& board) {
		int nMine = adjacentMineNum(x, y, board);
		if (nMine != 0) {
			board[x][y] = '0' + nMine;
		}
		else {
			board[x][y] = 'B';
		}

		int xNew = 0, yNew = 0;
		int height = board.size(), width = board[0].size();
		for (size_t i = 0; i < 8; i++)
		{
			xNew = x + nDir8[i][0];
			yNew = y + nDir8[i][1];

			if (xNew < 0 || xNew >= height || 
				yNew < 0 || yNew >= width)
			{
				continue;
			}

			nMine = adjacentMineNum(xNew, yNew, board);
			if (board[xNew][yNew] == 'M' || board[xNew][yNew] == 'B')
			{
				continue;
			}

			if (nMine > 0)
			{
				board[xNew][yNew] = '0' + nMine;
				continue;
			}

			dfs(xNew, yNew, board);
		}
	}

	int adjacentMineNum(int x, int y, vector<vector<char>>& board) {
		int xNew = 0;
		int yNew = 0;
		int nMine = 0;
		int height = board.size(), width = board[0].size();
		for (size_t i = 0; i < 8; i++)
		{
			xNew = x + nDir8[i][0];
			yNew = y + nDir8[i][1];
			if (xNew < 0 || xNew >= height ||
				yNew < 0 || yNew >= width)
			{
				continue;
			}
			if (board[xNew][yNew] == 'M')
			{
				nMine++;
			}
		}
		return nMine;
	}


private:
	int nDir8[8][2] = { -1,1, 0,1, 1,1, -1,0, 1,0, -1,-1, 0,-1, 1,-1 };
	int nDir4[4][2] = { 0,1, 0,-1, -1,0, 1,0 };
};

int main()
{
	Solution529 s;
	vector<vector<char>> board(4, vector<char>(5));
	board[0] = { 'E', 'E', 'E', 'E', 'E' };
	board[1] = { 'E', 'E', 'M', 'E', 'E' };
	board[2] = { 'E', 'E', 'E', 'E', 'E' };
	board[3] = { 'E', 'E', 'E', 'E', 'E' };
	vector<int> click = {3,0};
	s.updateBoard(board, click);

	vector<vector<char>> board1(4, vector<char>(5));
	board1[0] = { 'B', '1', 'E', '1', 'B' };
	board1[1] = { 'B', '1', 'M', '1', 'B' };
	board1[2] = { 'B', '1', '1', '1', 'B' };
	board1[3] = { 'B', 'B', 'B', 'B', 'B' };
	vector<int> click1 = { 1,2 };
	s.updateBoard(board1, click1);

	vector<vector<char>> board2(8, vector<char>(8));
	board2[0] = { 'E','E','E','E','E','E','E','E' };
	board2[1] = { 'E','E','E','E','E','E','E','M' };
	board2[2] = { 'E','E','M','E','E','E','E','E' };
	board2[3] = { 'M','E','E','E','E','E','E','E' };
	board2[4] = { 'E','E','E','E','E','E','E','E' };
	board2[5] = { 'E','E','E','E','E','E','E','E' };
	board2[6] = { 'E','E','E','E','E','E','E','E' };
	board2[7] = { 'E','E','M','M','E','E','E','E' };
	vector<int> click2 = { 0,0 };
	s.updateBoard(board2, click2);

	return 0;
}