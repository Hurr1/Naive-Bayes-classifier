#include "Algorithm.hpp"
#include <iostream>
#include <algorithm>
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
        attributes.clear();
    }
    return data;
}


double algs::count_decision_parameter(std::vector<Node>& records, std::string des_par)
{
        double count = 0;
        for(const auto& record : records)
            if(record.at(record.size()-1)==des_par) count++;
        return count;
}


void algs::determine_the_result(const Node& record,std::vector<Node>& dataBase,double yes_count, double no_count)
{
    double yes_result = algs::count_given_parameter(dataBase,{record.at(0),0},{"tak",yes_count});
    double no_result = algs::count_given_parameter(dataBase,{record.at(0),0},{"nie",no_count});
    for(int i = 1;i<record.size()-1;i++)
    {
        yes_result *= algs::count_given_parameter(dataBase,{record.at(i),i},{"tak",yes_count});
    }
    for(int i = 1;i<record.size()-1;i++)
    {
        no_result *= algs::count_given_parameter(dataBase,{record.at(i),i},{"nie",no_count});
    }
    yes_result *= yes_count/dataBase.size();
    no_result *=no_count/dataBase.size();
    std::cout<<"Result for record <";
    for(int i = 0;i<record.size();i++)
    {
        std::cout<<'['<<record.at(i)<<"] ";
    }
    std::string res = yes_result > no_result ? "YES" : "NO";
    std::cout<<"> is " << res <<'\n';
}


double algs::count_given_parameter(std::vector<Node>& records,std::pair<std::string,int>attr_n_index ,std::pair<std::string,int>dec_pair)
{
    double numerator = 0;
    for(const auto& record : records)
    {
        if((record.at(attr_n_index.second) == attr_n_index.first) && (record.at(record.size()-1) == dec_pair.first))
            numerator++;
    }
    if(numerator!=0) return numerator/dec_pair.second;
    std::set<std::string>unique_str;
    for(const auto& record : records)
    {
        unique_str.insert(record.at(attr_n_index.second));
    }
    return (numerator+1)/(dec_pair.second + unique_str.size());
}
