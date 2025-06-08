#pragma once
#include "graph.h"
#include <queue>
#include <limits>
std::vector <std::string> findShortestPath(Graph& graph, const std::string& start,
	const std::string& end, bool isOptimizedByCost);
/*
	Киев -- 800 грн -- Луцк
	Киев -- 700 грн -- Чернигов
	Луцк -- 900 грн -- Львов
	Чернигов -- 1200 грн -- ЛЬвов
	Львов -- 1000 грн -- Житомир
	Луцк -- 1500 грн -- Житомир

	Киев(0) 
			Луцк (800) - Житомир(1500)  = 2300
			Чернигов (700) - Львов (1200) - Житомир (1000) = 2900

*/
