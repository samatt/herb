let expect = require('chai').expect
let InterfaceManager = require('../lib/InterfaceManager')
let TransportSniffer = require('../lib/TransportSniffer')
let Arp = require('../lib/Arp')

describe('interface', () => {
  let ifconfig = new InterfaceManager()
  it('up', () => {
    expect(ifconfig.up).to.have.length.above(0)
  })

  it('down', () => {
    expect(ifconfig.down).to.have.length.above(0)
  })

  it('has properties', () => {
    let info = ifconfig.up[0]
    expect(info).to.have.property('name')
    expect(info).to.have.property('status')
    expect(info).to.have.property('mac')
    expect(info).to.have.property('ip')
    expect(info).to.have.property('netmask')
    expect(info).to.have.property('broadcast')
  })

  it('has active interface', () => {
    let active = ifconfig.up
    for (const a in active) {
      let info = active[a]
      expect(info.status).equals('up')
      expect(info.ip).to.not.equal('127.0.0.1')
      expect(info.ip).to.not.equal('0.0.0.0')
    }
  })

  it('has localhost', () => {
    let local = ifconfig.localhost
    for (const a in local) {
      const iface = local[a]
      expect(iface.status).equals('up')
      expect(iface.ip).to.oneOf(['127.0.0.1', '0.0.0.0'])
    }
  })
})

describe('sniffer', () => {
  const sniffer = new TransportSniffer(1)
  it('correct packet size', () => {
    sniffer.on('packet', (d) => {
      expect(Object.keys(d).length).equals(4)
    })
  })
})

describe('arp', () => {
  Arp.getMacFromIPs(['192.168.0.1', '192.168.0.2', '192.168.0.100']).done(function (results) {
    it('correct packet size', () => {
      expect(Object.keys(results).length).equals(3)
    })
    console.log(results)
  }, function (err) {
    if (err) console.log(err)
  })
})
