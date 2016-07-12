const arp = require('node-arp')
const Promise = require('promise')

function getMacFromIP (ip, enc) {
  return new Promise(function (resolve, reject) {
    arp.getMAC(ip, function (err, mac) {
      if (err) reject(err)
      else resolve({ ip: ip, mac: mac })
    })
  })
}

module.exports.getMacFromIPs = function getMacFromIPs (ips) {
  return Promise.all(ips.map(getMacFromIP))
}

module.exports.arp = arp
