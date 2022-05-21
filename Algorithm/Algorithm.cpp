#include "Algorithm.h"
#include "../CSVRow/CSVRow.h"
#include <random>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <set>


std::istream& operator>>(std::istream& str, CSVRow& data)
{
    data.readNextRow(str);
    return str;
}

std::vector<Node> algs::createDataBase(std::ifstream &stream)
{
    CSVRow row;
    std::vector<Node> data;
    std::vector<std::string>attributes;
    while(stream >> row)
    {
        for(int i = 0; i< row.size();i++)
            attributes.emplace_back(row[i]);
        data.emplace_back(Node(std::move(attributes)));
    }
    return data;
}


