'use strict';
const fs = require('fs');
const child_process = require('child_process');
const dgram = require('dgram')
const udp = dgram.createSocket('udp4')
const sniffRunner = child_process.fork("./lib/sniffer.js");
const sniffConfig = {iface:'en0',is_promisc:true,is_monitor:false};

function ab2str (buf) { return String.fromCharCode.apply(null, new Uint16Array(buf)) }

sniffRunner.send({ config: sniffConfig, start:true });

udp.on('error', (err) => { console.log('server error:\n' + err.stack); udp.close();})

udp.on('message', (msg, rinfo) => {console.log(JSON.parse(ab2str(msg)))});

udp.on('listening', () => { console.log(`server listening ${udp.address().address} : ${udp.address().port}` );});

udp.bind(8080)