const HerbSniffer = require('../build/Release/herbivore').HerbSniffer
const sniffer = new HerbSniffer()

process.on('message', function(m) {

   if( m.config){
    sniffer.iface = m.config.iface
    sniffer.is_promisc = m.config.is_promisc
    sniffer.is_monitor = m.config.is_monitor
   }

   if( m.start){
    let {iface, is_promisc, is_monitor} = sniffer;
    console.log(`Sniffing on ${iface} \nPromisc : ${is_promisc} \nMonitor : ${is_monitor}`)
    sniffer.run()
   }

});



