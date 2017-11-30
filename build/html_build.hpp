//
// Created by Administrator on 2017/11/23.
//

#ifndef __CPPHTML_HTML_BUILD_HPP_
#define __CPPHTML_HTML_BUILD_HPP_

#include <map>
#include <set>
#include <ostream>

#include <iostream>

class html_build
{
public:

    explicit html_build();


    struct __html_attr
    {
        std::set<std::string> node;
        std::set<std::string> attr;
    } html_attr;

    void
    print_node(std::ostream &out)
    {
        for (auto &iter : html_attr.node)
        {
            out << "NODE_REG(" << iter << ")" << std::endl;
        }

    }

    void
    print_attr(std::ostream &out)
    {
        for (auto &iter : html_attr.attr)
        {
            out << "ATTR_REG(" << iter << ")" << std::endl;
        }
    }


};


#define ADD_NODE(X) html_attr.node.insert(#X);
#define ADD_ATTR(X) html_attr.attr.insert(#X);


#endif//__CPPHTML_HTML_BUILD_HPP_
