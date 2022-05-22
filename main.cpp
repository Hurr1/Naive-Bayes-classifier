#include <bits/stdc++.h>
#include "Algorithm/Algorithm.hpp"
#include "CSVRow/CSVRow.hpp"
#include <random>


int main(int argc, char *argv[])
{

    if (argc - 1 != 2)
    {
        std::cout << "You provide incorrect number of arguments for this application" << '\n';
        return 1;
    }
    std::ifstream trainSet("Resources/" + static_cast<std::string>(argv[1])),
                  testSet("Resources/" + static_cast<std::string>(argv[2]));
    
    if(!(trainSet && testSet))
    {
        trainSet ? std::cout<<"There no file with name: "<<argv[2]<<'\n' : std::cout<<"There no file with name: " << argv[1]<<'\n';
        return EXIT_FAILURE;
    }


    std::vector<Node>dataBase;
    std::vector<Node>testDataBase;

    dataBase = algs::createDataBase(trainSet);
    testDataBase = algs::createDataBase(testSet);

    double yes_count = algs::count_decision_parameter(dataBase,"tak");
    double no_count = algs::count_decision_parameter(dataBase,"nie");

    for(const auto& record : dataBase)
    {
        algs::determine_the_result(record,dataBase,yes_count,no_count);
    }   
}