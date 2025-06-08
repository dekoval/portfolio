#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

struct Route
{
	int cost;
	int time;
	std::string destination;
};

class Graph
{
private:
	std::unordered_map<std::string, std::vector<Route>> routes;
public:
	void addRoute(const std::string& city1, const std::string& city2, int cost, int time);
	void removeRoute(const std::string& city1, const std::string& city2);
	void displayRoute();
	std::unordered_map<std::string, std::vector<Route>> getRoute();
	
};