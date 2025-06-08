#include <iostream>
#include "graph.h"
#include "dijkstra.h"
#include "file_manager.h"
void menu()
{
    Graph graph;
    std::string filename = "routes.txt";
    loadRoutesFromFile(graph, filename);
    while (true)
    {

        std::cout << "----Logistic centre ----\n";
        std::cout << "1. Show route\n";
        std::cout << "2. Find best route\n";
        std::cout << "3. Add new route\n";
        std::cout << "4. Delete route\n";
        std::cout << "5. CLose\n";
        std::cout << "Choose option:\n";

        size_t choice;
        std::cin >> choice;
        if(choice==1)
            graph.displayRoute();
        else if (choice == 2)
        {
            std::string start, end;
            int criterion;
            std::cout << "Type from where to start:\t";
            std::cin >> start;
            std::cout << "Type where to finish:\t";
            std::cin >> end;
            std::cout << "Optimaze by (1 - cost) (2 - time):\t";
            std::cin >> criterion;

            auto path = findShortestPath(graph, start, end, criterion);
            if (path.empty())
            {
                std::cout << "Route doesnt exist\n";
            }
            else
            {
                std::cout << "Optimazed route :\t";
                for (const auto& city : path)
                {
                    std::cout << city << "-->";
                }
                std::cout << std::endl;

            }
        }
        else if(choice==5)
        {
            break;
        }

    }
}

int main()
{
    menu();
}