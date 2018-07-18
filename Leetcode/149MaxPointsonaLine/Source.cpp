#include <vector>
#include <unordered_set>
#include <numeric>
#include <string>
using namespace std;
struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
	
};
int main()
{
	vector<Point> points;

	if (points.size() == 0)
		return 0;
	if (points.size() == 1)
		return 1;
	if (points.size() == 2)
		return 2;

	unordered_set<string> sets;
	int max = 2;

	for (int i = 0; i < points.size(); ++i)
	{
		for (int j = i + 1; j < points.size(); ++j)
		{
			int number = 2;

			if (points[i].x == points[j].x)
			{
				string name = string("x=") + to_string(points[i].x);
				if(sets.find(name) == sets.end())
				{
					for (int k = 0; k < points.size(); ++k)
					{
						if (k != i && k != j)
						{
							if(points[k].x == points[i].x)
								++number;
						}
					}
					if (number > max)
						max = number;
					sets.insert(name);
				}
			}
			else
			{
				long long m = (points[i].y - points[j].y);
				long long n = (points[i].x - points[j].x);
				long long nb = n * points[i].y - m * points[i].x;
				string name = to_string(n) + "*y-" + to_string(m) + "*x-" + to_string(nb);
				if (sets.find(name) == sets.end())
				{
					for (int k = 0; k < points.size(); ++k)
					{
						if (k != i && k != j)
						{
							if (n*points[k].y - m * points[k].x - nb == 0)
							{
								++number;
							}
						}
					}
					if (number > max)
						max = number;
					sets.insert(name);
				}
			}
		}
	}
	
	return max;
}