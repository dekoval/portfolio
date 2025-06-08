#include "file_manager.h"

void loadRoutesFromFile(Graph& graph, const std::string& filename)
{
	std::ifstream file(filename); //открыть и записать из файла в file
	if (!file)
	{
		std::cerr << "Error can not open file:\t" << filename << "\n";
		return;
	}
	std::string city1, city2;
	int cost, time;
	while (file >> city1 >> city2 >> cost >> time)
	{
		graph.addRoute(city1 , city2 , cost , time);
	}
	file.close();
}

void saveRoutesToFile(Graph& graph, const std::string& filename)
{
	std::ofstream file(filename);
	if (!file)
	{
		std::cerr << "Error can not open file:\t" << filename << "\n";
		return;
	}
	auto routes = graph.getRoute();
	for (const auto &pair : routes)
	{
		for (const auto& route : pair.second)
		{
			file << pair.first << " " << route.cost <<" " << route.time << " " << route.destination << std::endl;
		}
	}
	file.close();

}
