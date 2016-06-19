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

void send_packet(std::string s){
    Tins::NetworkInterface::Info info =Tins::NetworkInterface::default_interface().info();
    // std::cout<<Tins::NetworkInterface::default_interface().name()<<std::endl;
    Tins::PacketSender sender;
    Tins::IP pkt = Tins::IP("127.0.0.1") / Tins::UDP(8080,5127) / Tins::RawPDU(s);
    std::cout<<"Sending "<<":"<<s<<std::endl;
    sender.send(pkt,"lo0");
}