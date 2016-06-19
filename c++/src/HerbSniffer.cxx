#include "HerbSniffer.h"

bool HerbSniffer::doo(Tins::PDU &pdu) {
            Tins::IP *ip = pdu.find_pdu<Tins::IP>();
            Tins::TCP *tcp = pdu.find_pdu<Tins::TCP>();
            if(ip == NULL || tcp == NULL){
                return true;
            }
            uint16_t srcPort = tcp->sport();
            std::string  srcIp = ip->src_addr().to_string();
            std::string  dstIp = ip->dst_addr().to_string();
            uint16_t dstPort = tcp->dport();
            std::stringstream ss;
            ss<<srcIp<< " - "<<srcPort<<" -- "<<dstIp<<" - "<<dstPort<<std::endl;
            send_packet(ss.str());
    return true;
}

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


void HerbSniffer::run() {
    config.set_promisc_mode(is_promisc);
    config.set_rfmon(is_monitor);
    Tins::Sniffer sniffer(iface, config);
    sniffer.sniff_loop(doo);
}

// void HerbSniffer::run(){
//     Tins::Sniffer * sniffer = new Tins::Sniffer(iface,config);
//     while(Tins::Packet pkt = sniffer->next_packet()) {

//         try{
//             Tins::PDU& pdu = *pkt.pdu();
//             Tins::IP *ip = pdu.find_pdu<Tins::IP>();
//             Tins::TCP *tcp = pdu.find_pdu<Tins::TCP>();
//             if(ip == NULL || tcp == NULL){
//                 continue;
//             }
//             uint16_t srcPort = tcp->sport();
//             std::string  srcIp = ip->src_addr().to_string();
//             std::string  dstIp = ip->dst_addr().to_string();
//             uint16_t dstPort = tcp->dport();
//             std::stringstream ss;
//             ss<<srcIp<< " - "<<srcPort<<" -- "<<dstIp<<" - "<<dstPort<<std::endl;
//             send_packet(ss.str());

//         }
//         catch(...){

//         }
//     }
// }
