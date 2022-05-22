#include <vector>
#include "../Node/Node.hpp"

namespace algs
{
    std::vector<Node> createDataBase(std::ifstream &stream);

    double count_decision_parameter(std::vector<Node>& records, std::string des_par);

    double count_given_parameter(std::vector<Node>& records,std::pair<std::string,int>attr_n_index ,std::pair<std::string,int>dec_pair);

    void determine_the_result(const Node& record,std::vector<Node>& dataBase,double yes_count, double no_count);

    void count_parameter(std::string attr,int index, std::string dec_attr, std::vector<Node>&);
}