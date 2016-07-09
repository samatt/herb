const Bin = require('./bin.js')
const _ = require('underscore')

class TransportSniffer extends Bin {

  constructor () {
    super('sniffer', (data) => {
      let k = ['s_ip', 'd_ip', 's_prt', 'd_prt']
      let d = data.toString().split('\n')
      let c = _.filter(d, (line) => { return (line.split(',').length === 4) })
      c.forEach((e, i, a) => { this.emit('packet', _.object(k, c[i].split(','))) })
    })
  }
}

module.exports = TransportSniffer

