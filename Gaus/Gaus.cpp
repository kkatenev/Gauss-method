#include <iostream>
#define N 10
using namespace std;

void vivod(float a[N][N], int n, int m)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}
int main()
{
	setlocale(0, "Russian");
	int n, m,savei,savej,null=0; 
	float max = 0, glav;
	float a[N][N];
	int b[N][N];
	cout << "Введите размер матрицы NxM" << endl;
	cin >> n >> m;
	cout << "Введите матрицу NxM" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
		if (a[i][0] > max)
		{
			swap(a[i], a[0]);
			max = a[0][0];
		}
	}
	glav = a[1][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = m-1; j >=0; j--)
			a[i][j] = a[i][j] / a[i][0];
		for (int k = i+1; k < n; k++)
			a[k][0] = 0;
		break;
	}
	for (int i = 1; i < n; i++)
		for (int j = i; j < m; j++)
		{
			if (j == i)
			{
				savei = i;
				savej = j;
				glav = a[i][j];
			}
			else
				for(int l=i;l<n;l++)
					for(int p=j;p<m;p++)
						a[l][p] -= a[savei][p] * a[l][savej];
			a[i][j] /= glav;
			for (int l = j;null<m;null++)
			{
				if (j == m - 1)
					break;
				cout << endl << "nice" << endl;
				if (null == savei)
					continue;
				else
					a[null][l] = 0;
			}
			null = 0;
		}
	vivod(a, n, m);
	return 0;
}

