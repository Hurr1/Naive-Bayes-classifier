#include <iostream>
#include <sstream>
#include "Algorithm/Algorithm.hpp"

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

    for(const auto& record : testDataBase)
    {
        algs::determine_the_result(record,dataBase,yes_count,no_count);
    } 
    
    std::vector<std::string>attributes;
    std::string input_msg,splited;

    while(true)
    {
        std::getline(std::cin,input_msg);
        std::istringstream f(input_msg);  
        while (std::getline(f, splited, ' '))
            attributes.emplace_back(splited);
        if(attributes[0] == "STOP")
            return 0;
        if(attributes.size()!=dataBase[0].size()-1)
        {
            std::cerr<<"You provide incorrect number of attributes"<<'\n';
            attributes.clear();
        }
        else
        {
            algs::determine_the_result(Node(attributes),dataBase,yes_count,no_count);
            attributes.clear();
        }
    }  
}