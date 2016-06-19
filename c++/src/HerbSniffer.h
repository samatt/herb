#ifndef HERBSNIFFER_H
#define HERBSNIFFER_H
using namespace std;
#include "tins/tins.h"
#include "HerbivoreUtils.h"
#include <string>
#include <map>

class HerbSniffer
{
public:

    HerbSniffer();
    HerbSniffer(std::string iface, bool is_promisc, bool is_monitor);
    void run();

protected:
    Tins::SnifferConfiguration config;
    std::string iface;
    static bool doo(Tins::PDU &some_pdu);
    bool is_promisc;
    bool is_monitor;
};

#endif
