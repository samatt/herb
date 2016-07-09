#include "HerbSniffer.h"



HerbSniffer::HerbSniffer(){
    iface = "en0";
    is_promisc = false;
    is_monitor = false;
}

HerbSniffer::HerbSniffer(std::string _iface, bool _is_promisc, bool _is_monitor){
    config;
    iface = _iface;
    is_promisc = _is_promisc;
    is_monitor = _is_monitor;
}

Tins::RawPDU::payload_type HerbSniffer::get_raw_payload(Tins::PDU &pdu){
    Tins::RawPDU *raw =  pdu.find_pdu<Tins::RawPDU>();
    Tins::RawPDU::payload_type& payload = raw->payload();
    return payload;
}

void HerbSniffer::run() {
    config.set_promisc_mode(is_promisc);
    config.set_rfmon(is_monitor);
    Tins::Sniffer sniffer(iface, config);
    sniffer.sniff_loop(doo);
}

bool HerbSniffer::doo(Tins::PDU &pdu) {
    try{
        HerbParser parser = HerbParser();
        Tins::IP *ip = pdu.find_pdu<Tins::IP>();
        Tins::TCP *tcp = pdu.find_pdu<Tins::TCP>();
        if(ip == NULL || tcp == NULL){
            return true;
        }

        uint16_t srcPort = tcp->sport();
        uint16_t dstPort = tcp->dport();
        std::string  srcIp = ip->src_addr().to_string();
        std::string  dstIp = ip->dst_addr().to_string();

        std::map <string, string> p_info;
        p_info["s_ip"] = srcIp;
        p_info["d_ip"] = dstIp;
        p_info["s_prt"] = std::to_string(srcPort);
        p_info["d_prt"] = std::to_string(dstPort);
        cout<<p_info["s_ip"]<<","<<p_info["d_ip"]<<","<<p_info["s_prt"]<<","<<p_info["d_prt"]<<endl;
            // cout<<dstPort<<endl;
            // if(dstPort == 80 ){

            //     // Tins::RawPDU::payload_type payload = get_raw_payload(pdu);
            //     std::cout<<"HERE"<<std::endl;
            //     // p_info["payload"] = parser.parse_http(payload);

            // }
        // send_packet(to_json(p_info));
        return true;
    }
    catch(...){
        std::cout<<"SOME ERROR"<<std::endl;
        return false;
    }

}