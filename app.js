'use strict';
const fs = require('fs');
// Create socket to listen to Sniffer messages.
// TODO: Add callbacks to implement this. Don't want to deal with V8 rn
const dgram = require('dgram')
const sniffReceiver = dgram.createSocket('udp4')
const child_process = require('child_process');
const sniffRunner = child_process.fork("./lib/sniffer.js");
const sniffConfig = {iface:'en0',is_promisc:true,is_monitor:false};

function ab2str (buf) { return String.fromCharCode.apply(null, new Uint16Array(buf)) }

sniffRunner.send({ config: sniffConfig, start:true });

sniffReceiver.on('error', (err) => { console.log('server error:\n' + err.stack); sniffReceiver.close();})

sniffReceiver.on('message', (msg, rinfo) => {console.log(JSON.parse(ab2str(msg)))});

sniffReceiver.on('listening', () => { console.log(`server listening ${sniffReceiver.address().address} : ${sniffReceiver.address().port}` );});

sniffReceiver.bind(8080)