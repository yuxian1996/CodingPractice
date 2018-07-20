#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
	int numCourses = 3;
	vector<pair<int, int>> prerequisites{ {1,0},{1,2},{0,1} };

	unordered_map<int, vector<int>> maps;

	for (int i = 0; i < prerequisites.size(); ++i)
	{
		if (maps.find(prerequisites[i].first) == maps.end())
			maps[prerequisites[i].first] = vector<int>(1, prerequisites[i].second);
		else
			maps[prerequisites[i].first].push_back(prerequisites[i].first);
	}

	for (int i = 0; i < numCourses; ++i)
	{
		int firstCoutse = i;
		int course = i;
		while (true)
		{
			if (maps.find(course) == maps.end())
			{
				continue;
			}

			auto& vectors = maps[course];
			auto it = find(vectors.begin(), vectors.end(), course);
			if (it != vectors.end())
			{

			}

			int newCourse = maps[course];
			if (maps.find(newCourse) == maps.end())
				break;

			course = newCourse;
			if (firstCoutse == course)
				return false;
		}
	}

	return true;

}