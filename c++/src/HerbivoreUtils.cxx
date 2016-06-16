#include "HerbivoreUtils.h"

std::string to_json(std::map <std::string, std::string> data){
    std::stringstream ss;
    ss<<"{";
    for(const auto kv : data ){
        ss<<"\"" << kv.first<<"\"" <<" : "<<"\"" <<kv.second<<"\"," ;
    }
    ss<<"\"" << "dummy"<<"\"" <<" : "<<"\"" <<"value"<<"\""  ;
    ss<<"}"<<std::endl;
    return ss.str();
}
