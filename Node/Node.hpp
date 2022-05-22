#pragma once
#include <vector>
#include <string>

class Node
{
public:
    Node(const std::vector<std::string>& coords);
    ~Node() = default;
    std::vector<std::string> getCoords() const;
    std::string at(int index) const;
    std::size_t size() const;

private:
    std::vector<std::string> _variables;
};