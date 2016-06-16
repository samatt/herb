#include "Interface.h"


Interface::Interface(){
    all = Tins::NetworkInterface::all();
    for (const Tins::NetworkInterface& iface: Tins::NetworkInterface::all()){

    }
}

vector<std::string> Interface::get_interfaces(bool onlyActive){
    std::vector<string> active;
    std::vector<string> all;
    for(const Tins::NetworkInterface& iface : Tins::NetworkInterface::all()){
        if(is_active(iface)){
            active.push_back(parse_interface(iface));
        }
        all.push_back(parse_interface(iface));
    }
    return (onlyActive ? active : all);
}

vector<std::string> Interface::get_localhosts(){
    std::vector<string> localhosts;
    for(const Tins::NetworkInterface& iface : Tins::NetworkInterface::all()){
        Tins::NetworkInterface::Info info = iface.info();
        bool is_localhost = (info.ip_addr == "127.0.0.1");
        if ( iface.is_up() && is_localhost){
            localhosts.push_back(parse_interface(iface));
        }
    }
    return localhosts;
}

bool Interface::is_active(Tins::NetworkInterface iface){
    Tins::NetworkInterface::Info info = iface.info();
    bool is_localhost = (info.ip_addr == "0.0.0.0" || info.ip_addr == "127.0.0.1");
    return (iface.is_up() && !is_localhost);
}

std::string Interface::parse_interface(Tins::NetworkInterface iface){
    std::map <string, string> p_info;

    std::string name = iface.name();
    p_info["name"] = name;
    std::string status = iface.is_up() ? "up" : "down";
    p_info["status"] = status;
    Tins::NetworkInterface::Info info = iface.info();
    p_info["mac"] = info.hw_addr.to_string();
    p_info["ip"] = info.ip_addr.to_string();
    p_info["netmask"] = info.netmask.to_string();
    p_info["broadcast"] = info.bcast_addr.to_string();
    return to_json(p_info);
}
