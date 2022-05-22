#include "Node.hpp"
#include <iostream>

Node::Node(const std::vector<std::string>& coords)
{
    this->_variables =std::move(coords);
}

std::vector<std::string> Node::getCoords() const
{
    return this->_variables;
}


std::string Node::at(int index) const
{
    try{
        return this->_variables[index];
    }catch(std::exception&)
    {
        std::cout<<"One or more records you provide are incorrect"<<'\n';
        exit(1);
    }
}


std::size_t Node::size() const
{
    return this->_variables.size();
}
