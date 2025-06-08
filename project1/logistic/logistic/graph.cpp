#include "graph.h"
void Graph::addRoute(const std::string& city1, const std::string& city2, int cost, int time)
{
	routes[city1].push_back({ cost,time,city2 });
	routes[city2].push_back({ cost,time,city1 });
}

void Graph::removeRoute(const std::string& city1, const std::string& city2)
{
	auto& vec1 = routes[city1];
	vec1.erase(std::remove_if(vec1.begin(), vec1.end(), [&](const Route& r) {return r.destination == city1; }), vec1.end());

	auto& vec2 = routes[city2];
	vec2.erase(std::remove_if(vec2.begin(), vec2.end(), [&](const Route& r) {return r.destination == city2; }), vec2.end());
}
void Graph::displayRoute()
{
	for (const auto& pair : routes)
	{
		std::cout << pair.first << "->";
		for (const auto& route : pair.second)
		{
			std::cout << "[" << route.destination << "," << route.cost << "$," << route.time << "h]\n";
		}
		std::cout << std::endl;
	}
}


std::unordered_map<std::string, std::vector<Route>> Graph::getRoute()
{
	return routes;
}