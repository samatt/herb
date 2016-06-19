#include "HerbParser.h"


HerbParser::HerbParser(){
    // TODO: Make this json that is parsed
    http_headers.push_back("Host:");
    http_headers.push_back("GET");
    http_headers.push_back("POST");
    http_headers.push_back("Referer:");
    http_headers.push_back("User-Agent:");
    http_headers.push_back("Cookie:");
    http_headers.push_back("Content-Type:");

}


std::string HerbParser::payload_to_str(Tins::RawPDU::payload_type payload){
    std::string str;
    for (int i = 0; i < payload.size(); ++i)
    {
        str += (char) payload[i];
    }
    return str;
}

std::string HerbParser::parse_http(Tins::RawPDU::payload_type payload){

    std::vector<std::string> packet = split(payload_to_str(payload),'\r');
    std::map <std::string, std::string> p_info;
    for(string line : packet )
    {
        for (std::string h : http_headers)
        {
            size_t f_idx = line.find(h);
            if(f_idx != std::string::npos){
                std::string s = line.substr (f_idx + h.size());
                p_info[h] = s;
            }
        }
    }

    if(!p_info.empty()){

        // std::stringstream ss;
        // ss<<"{"<<endl;
        // for(auto kv : p_info ){
        //     ss<<" \" " << kv.first<<" \" " <<" : "<<" \" " <<kv.second<<" \" ," <<std::endl  ;
        // }
        // std::cout<<ss.str()<<std::endl;
        return to_json(p_info);
    }

    return "";

}