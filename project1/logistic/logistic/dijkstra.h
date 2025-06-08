#pragma once
#include "graph.h"
#include <queue>
#include <limits>
std::vector <std::string> findShortestPath(Graph& graph, const std::string& start,
	const std::string& end, bool isOptimizedByCost);
/*
	���� -- 800 ��� -- ����
	���� -- 700 ��� -- ��������
	���� -- 900 ��� -- �����
	�������� -- 1200 ��� -- �����
	����� -- 1000 ��� -- �������
	���� -- 1500 ��� -- �������

	����(0) 
			���� (800) - �������(1500)  = 2300
			�������� (700) - ����� (1200) - ������� (1000) = 2900

*/
