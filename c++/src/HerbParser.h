#ifndef HERBPARSER_H
#define HERBPARSER_H
using namespace std;
#include "tins/tins.h"
#include "HerbivoreUtils.h"
#include <string>
#include <map>

class HerbParser
{
public:

    HerbParser();
    std::string payload_to_str(Tins::RawPDU::payload_type payload);
    std::string parse_http(Tins::RawPDU::payload_type payload);

protected:
    vector<std::string> http_headers;
};

#endif
