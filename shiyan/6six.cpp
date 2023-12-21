#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<string.h>
 
using namespace std;
 
const int NNN = 9999999;
 
int road[300][300];
int dis[300];
int vis[300];
int N, M;
int d[300];
 
struct Node
{
	int num;
	char ch;
}node[6000];
 
void DIS(int x)
{
	int i;
	int j;
	int ans;
	int v;
	ans = NNN;
	dis[x] = 0;
	vis[x] = 1;
	for (i = 0; i < N; i++)
	{
		dis[i] = road[x][i];
	}
	for (j = 0; j < N+7; j++)
	{
		for (i = 0; i < N; i++)
		{
			if (dis[i] < ans && !vis[i])
			{
				ans = dis[i];
				v = i;
				
			}
 
		}
		vis[v] = 1;
		ans = NNN;
		for (i = 0; i < N; i++)
		{
			if (dis[v] + road[v][i] < dis[i])
			{
				dis[i] = dis[v] + road[v][i];
				d[i] = v;
			}
		}
	}
}
 
void print(int n)
{
	if (d[n] == n)
	{
		cout << node[n].ch;
		return;
	}
	print(d[n]);
	cout <<" "<< node[n].ch ;
	return;
}
 
int main()
{
	char ch1, ch2;
	int i, j;
	int a, b;
	int x, y;
	while (cin >> N)
	{
		a = b = x = y = 0;
		memset(dis, NNN, sizeof(dis));
		memset(vis, 0, sizeof(vis));
		for (i = 0; i < 250; i++)
			for (j = 0; j < 250; j++)
			{
				if (i != j)
					road[i][j] = NNN;
				else
					road[i][j] = 0;
			}
 
		cin >> M;
		if (N == 0 && M == 0)
			break;
		for (i = 0; i < N; i++)
		{
			cin >> node[i].ch;
			node[i].num = i;
		}
		for (i = 0; i < M; i++)
		{
 
			cin >> ch1 >> ch2;
			for (j = 0; j < N; j++)
			{
				if (node[j].ch == ch1)
					a = node[j].num;
				if (node[j].ch == ch2)
					b = node[j].num;
			}
			cin >> road[a][b];
			road[b][a] = road[a][b];
		}
 
		cin >> ch1 >> ch2;
		for (j = 0; j < N; j++)
		{
			if (node[j].ch == ch1)
				x = node[j].num;
			if (node[j].ch == ch2)
				y = node[j].num;
		}
		for (j = 0; j < N; j++)
		{
			d[j] = x;
		}
		DIS(x);
		if (dis[y] < NNN)
			cout << dis[y] << endl;
		else
			cout << "-1\n";
		print(y);
		cout << endl;
 
	}
 
 
	return 0;
}