#include <bits/stdc++.h>
using namespace std;
vector<vector<string> > answer;
void print_board()
{
	for (auto& str : answer[1]) {
		for (auto& letter : str)
			cout << letter << " ";
		cout << endl;
	}
	return;
}

int safe(int row, int col, vector<string>& board)
{
	for (int i = 0; i < board.size(); i++) {
		if (board[i][col] == 'Q')
			return false;
	}
	int i = row, j = col;
	while (i >= 0 && j >= 0)
		if (board[i--][j--] == 'Q')
			return false;
	i = row, j = col;
	while (i >= 0 && j < board.size())
		if (board[i--][j++] == 'Q')
			return false;
	return true;
}

void rec(vector<string> board, int row)
{
	if (row == board.size()) {
		answer.push_back(board);
		return;
	}
	for (int i = 0; i < board.size(); i++) {
		if (safe(row, i, board)) {
			board[row][i] = 'Q';
			rec(board, row + 1);
			board[row][i] = '.';
		}
	}
	return;
}
vector<vector<string> > solveNQueens(int n)
{
	string s;
	for (int i = 0; i < n; i++)
		s += '.';

	vector<string> board(n, s);
	rec(board, 0);
	return answer;
}
int main()
{
	clock_t start, end;
	start = clock();
	cout << solveNQueens(4).size() << endl;
	end = clock();
	double time_taken
		= double(end - start) / double(CLOCKS_PER_SEC);
	cout << time_taken << " time was taken(in miliseconds)"
		<< endl;
	cout << "Out of " << answer.size()
		<< " solutions one is following" << endl;
	print_board();
}
