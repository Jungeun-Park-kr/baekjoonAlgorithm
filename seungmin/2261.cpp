#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>
#include <cmath>


using namespace std;

double distance(pair<int,int> a,pair<int,int> b)
{
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main(void)
{
	int* arr;
	int x, y;
	int inputAmt;
	
	cin >> inputAmt;
	vector<pair<int, int>> point(inputAmt);
	//point[100001], point(100001) ����??

	set<pair<int, int>> s;

	for (int i = 0; i < inputAmt; i++)
		scanf("%d %d", &point[i].first, &point[i].second);
	
	sort(point.begin(), point.end()); //vector ������ ������ ũ������� ����
	//ũ����� ���� ũ����ΰ���
	
	s.insert(pair<int, int>(point[0].second, point[0].first));
	s.insert(pair<int, int>(point[1].second, point[1].first));

	double min = distance(point[0], point[1]);

	int last = 0;
	for (int i = 2; i < inputAmt; i++)
	{
		int d = point[i].first - point[last].first;
		if (d * d <= min) break;
		else s.erase(pair<int, int>(point[last].first, point[last].second));//Y�˻��� �ʿ� ����
		
		last++;
	}
	//Y �˻�κк��� ���ذ� �ȵ�.. �̤�
	double limit = sqrt(min);

}