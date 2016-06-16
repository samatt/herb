#ifndef INTERFACE_H
#define INTERFACE_H

using namespace std;
#include "tins/tins.h"
#include "HerbivoreUtils.h"
#include <string>
#include <map>
class Interface
{
public:
    Interface();
    bool is_active(Tins::NetworkInterface iface);
    vector<std::string> get_interfaces(bool onlyActive);
    vector<std::string> get_localhosts();
    std::string parse_interface(Tins::NetworkInterface iface);
    vector<Tins::NetworkInterface> active;
    vector<Tins::NetworkInterface> all;
};

#endif