
#include <bits/stdc++.h>
#define NUMS 9
#define LEN 3
using namespace std;

class Solution {
private:
	vector<vector<int>> arr;
	map<int, set<int>> row_map;
	map<int, set<int>> col_map;
	map<int, set<int>> board_map;
public:
	void solve(vector<vector<int>>& board)
	{
		arr = board;
		if (!isValidSudoku())
			cout << "ERROR: NOT VALID SUDO!" << endl;
		dfs(0, 0);
	}

	bool isValidSudoku() {
		for (int i = 0; i < 9; i++)
		{
			row_map[i] = {};
			col_map[i] = {};
			board_map[i] = {};
		}
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				if (!is_valid(i, j, arr[i][j]))
					return false;
		return true;
	}

	bool is_valid(int i, int j, int num)
	{
		int index = i / 3 * 3 + j / 3;
		if (row_map[i].find(num) == row_map[i].end() && col_map[j].find(num) == col_map[j].end() && board_map[index].find(num) == board_map[index].end())
		{
			if (num != 0)
			{
				row_map[i].insert(num);
				col_map[j].insert(num);
				board_map[index].insert(num);
			}
			return true;
		}
		else
			return false;
	}

	bool dfs(int i, int j)
	{	
		if (j == 9)
			return dfs(i + 1, 0);
		if (i == 9)
		{
			print_arr();
			return true;
		}
		if (arr[i][j] != 0)
			return dfs(i, j + 1);
		int index = i / 3 * 3 + j / 3;
		for (int k = 1; k <= 9; k++)
		{
			if (is_valid(i, j, k))					//若i,j,k合法，则set已经插入，否则不会插入
			{
				//cout << i << " " << j << " " << k << endl;
				arr[i][j] = k;
				dfs(i, j + 1);
				arr[i][j] = 0;
				row_map[i].erase(k);
				col_map[j].erase(k);
				board_map[index].erase(k);
			}
		}
		return false;
	}

	void print_arr()
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				cout << arr[i][j] << " ";
			cout << endl;
		}
		cout << endl;
		cout << endl;
	}
};

int main()
{
	Solution soooo;
	vector<vector<int>> arr = {
	 		{0, 0, 0, 0, 0, 0, 0, 0, 0},
	 		{0, 0, 0, 0, 1, 0, 0, 5, 0},
	 		{0, 0, 0, 0, 0, 0, 0, 0, 0},
	 		{0, 0, 0, 0, 0, 0, 0, 0, 0},
	 		{0, 0, 0, 0, 0, 0, 0, 0, 8},
	 		{2, 0, 0, 0, 0, 0, 0, 0, 0},
	 		{0, 0, 0, 0, 0, 0, 0, 0, 0},
	 		{0, 0, 0, 0, 0, 0, 0, 0, 0},
	 		{0, 0, 0, 0, 6, 0, 0, 0, 0}
	 };
	//vector<vector<int>> arr = {
	//		{5, 0, 4, 0, 7, 8, 0, 1, 2},
	//		{6, 0, 2, 1, 0, 5, 0, 4, 0},
	//		{0, 9, 8, 3, 0, 2, 5, 6, 0},
	//		{0, 5, 9, 0, 6, 1, 0, 0, 3},
	//		{4, 0, 6, 0, 0, 3, 7, 9, 1},
	//		{7, 0, 0, 0, 2, 0, 0, 0, 6},
	//		{9, 6, 1, 5, 3, 0, 2, 8, 0},
	//		{2, 0, 0, 0, 1, 0, 6, 0, 5},
	//		{0, 4, 0, 2, 0, 6, 0, 7, 9}
	//};
	soooo.solve(arr);
	return 0;
}
