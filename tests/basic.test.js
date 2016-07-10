let expect = require('chai').expect
let herbivore = require('../build/Release/herbivore')
let helper = require('../lib/herb-helper')
let TransportSniffer = require('../lib/sniffer')

describe('interface', () => {
  let Interface = herbivore.Interface
  var iface = new Interface()
  let ifaces = helper.parseSVec(iface.get_interfaces(false))
  it('exists', () => {
    expect(ifaces).to.have.length.above(0)
  })

  it('has properties', () => {
    let info = JSON.parse(ifaces[0])
    expect(info).to.have.property('name')
    expect(info).to.have.property('status')
    expect(info).to.have.property('mac')
    expect(info).to.have.property('ip')
    expect(info).to.have.property('netmask')
    expect(info).to.have.property('broadcast')
  })

  it('has active interface', () => {
    let active = helper.parseSVec(iface.get_interfaces(true))
    for (a in active) {
      let info = JSON.parse(active[a])
      expect(info.status).equals('up')
      expect(info.ip).to.not.equal('127.0.0.1')
      expect(info.ip).to.not.equal('0.0.0.0')
    }
  })

  it('has localhost', () => {
    let local = helper.parseSVec(iface.get_localhosts())
    for (a in local) {
      iface = JSON.parse(local[a])
      expect(iface.status).equals('up')
      expect(iface.ip).to.oneOf(['127.0.0.1', '0.0.0.0'])
    }
  })
})

describe('sniffer', () => {
  const sniffer = new TransportSniffer(10)
  it('correct packet size', () => {
    sniffer.on('packet', (d) => {
      expect(Object.keys(d).length).equals(4)
    })
  })
})
