#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000];
map<pair<int, int>, pair<int, int>> nextRow, nextCol;

void updateRowCol(vector<vector<int>> &a)
{
  for (int i = 0; i < a.size(); i++)
  {
    vector<pair<int, pair<int, int>>> temp;
    for (int j = 0; j < a.size(); j++)
    {
      temp.push_back({a[i][j], {i, j}});
    }
    sort(temp.begin(), temp.end(), greater<pair<int, pair<int, int>>>());
    for (int j = 0; j < a.size() - 1; j++)
    {
      auto x = temp[j].second;
      auto y = temp[j + 1].second;
      nextRow[x] = y;
    }
  }
  for (int j = 0; j < a.size(); j++)
  {
    vector<pair<int, pair<int, int>>> temp;
    for (int i = 0; i < a.size(); i++)
    {
      temp.push_back({a[i][j], {i, j}});
    }
    sort(temp.begin(), temp.end(), greater<pair<int, pair<int, int>>>());
    for (int j = 0; j < a.size() - 1; j++)
    {
      auto x = temp[j].second;
      auto y = temp[j + 1].second;
      nextCol[x] = y;
    }
  }
}

int dfs(int x, int y)
{
  if (dp[x][y] != -1)
  {
    return dp[x][y];
  }
  int ans = 1;
  if (nextRow.find({x, y}) != nextRow.end())
  {
    auto next = nextRow[{x, y}];
    ans = max(ans, 1 + dfs(next.first, next.second));
  }
  if (nextCol.find({x, y}) != nextCol.end())
  {
    auto next = nextCol[{x, y}];
    ans = max(ans, 1 + dfs(next.first, next.second));
  }
  return dp[x][y] = ans;
}

int solve(vector<vector<int>> &a)
{
  assert(1 <= a.size() && a.size() <= 1e3);
  memset(dp, -1, sizeof(dp));
  nextRow.clear();
  nextCol.clear();
  updateRowCol(a);
  set<int> s;
  int ans = 0;
  for (int i = 0; i < a.size(); i++)
  {
    // assert(a.size() == a[i].size());
    for (int j = 0; j < a.size(); j++)
    {
      s.insert(a[i][j]);
      ans = max(ans, dfs(i, j));
    }
  }
  // assert(s.size() == a.size() * a.size());
  return ans;
}

int main()
{
  int testcase;
  cin >> testcase;

  while (testcase--)
  {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
        cin >> a[i][j];
    }
    cout << solve(a) << endl;
  }
}