#include "dijkstra.h"

std::vector<std::string> findShortestPath(Graph& graph, const std::string& start, const std::string& end, bool isOptimizedByCost)
{
	auto routes = graph.getRoute();	// map<string , vector<Route>> routes
	std::unordered_map<std::string, int> distances;
	std::unordered_map<std::string, std::string> previous;

	std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, std::greater<>>pq;

	for (const auto& pair : routes) //pair - map
	{
		distances[pair.first] = std::numeric_limits<int>::max();
	}
	distances[start] = 0;
	pq.push({ 0,start });

	while (!pq.empty())
	{
		auto [currentDist, currentCity] = pq.top();
		pq.pop();
		if (currentCity == end)
		{
			break;
		}
		for (const auto& route : routes[currentCity])
		{
			int weight = isOptimizedByCost ? route.cost : route.time;
			int newDist = currentDist + weight;
			if (newDist < distances[route.destination])
			{
				distances[route.destination] = newDist;
				previous[route.destination] = currentCity;
				pq.push({ newDist,route.destination });
			}
		}
	}
	std::vector<std::string>path;
	for (std::string at = end; !at.empty(); at = previous[at])
	{
		path.push_back(at);
	}
	std::reverse(path.begin(), path.end());
	return (path.front() == start ? path : std::vector<std::string>{});
}