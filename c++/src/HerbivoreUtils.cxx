#include "HerbivoreUtils.h"

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

std::string to_json(std::map <std::string, std::string> data){
    try{
        std::stringstream ss;
        ss<<"{";
        for(const auto kv : data ){
            ss<<"\"" << kv.first<<"\"" <<":"<<"\"" <<kv.second<<"\"," ;
        }
        ss<<"\"" << "dummy"<<"\"" <<":"<<"\"" <<"value"<<"\""  ;
        ss<<"}"<<std::endl;
        return ss.str();
    }
    catch(...){
        return "";
    }

}

void send_packet(std::string s){
    try{
        Tins::NetworkInterface::Info info =Tins::NetworkInterface::default_interface().info();
        // std::cout<<Tins::NetworkInterface::default_interface().name()<<std::endl;
        // Tins::PacketSender sender;
        // Tins::IP pkt = Tins::IP("127.0.0.1") / Tins::UDP(8080,5127) / Tins::RawPDU(s);
        std::cout<<s<<std::endl;
        // sender.send(pkt,"lo0");
    }
    catch(...){
        std::cout<<"Couldnt send it"<<std::endl;

    }
}


