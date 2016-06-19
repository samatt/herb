#ifndef HERBSNIFFER_H
#define HERBSNIFFER_H
using namespace std;
#include "tins/tins.h"
#include "HerbParser.h"
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
    bool is_promisc;
    bool is_monitor;

    static bool doo(Tins::PDU &some_pdu);
    static Tins::RawPDU::payload_type get_raw_payload(Tins::PDU &pdu);
};

#endif