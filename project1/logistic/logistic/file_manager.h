#pragma once
#include "graph.h"
#include <fstream>

void loadRoutesFromFile(Graph& graph,const std::string& filename);
void saveRoutesToFile(Graph& graph, const std::string& filename);