#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
	
};

bool SortInterval(const Interval& lhs, const Interval& rhs)
{
	return lhs.start < rhs.start;
}

int main()
{
	vector<Interval> intervals;

	if (intervals.size() == 0 || intervals.size() == 1)
		return intervals;
	
	vector<Interval> res;
	sort(intervals.begin(), intervals.end(), SortInterval);
	res.push_back(intervals[0]);

	for (int i = 1; i < intervals.size(); ++i)
	{
		if (intervals[i].start <= res[res.size() - 1].end)
			res[res.size() - 1].end = std::max(intervals[i].end, res[res.size()-1].end);
		else
			res.push_back(intervals[i]);
	}

	return res;
}