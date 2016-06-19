let expect = require('chai').expect
let herbivore = require('../build/Release/herbivore')
let helper = require('../lib/herb-helper')

describe('interface',() => {

    let Interface = herbivore.Interface
    var interface = new Interface()
    let ifaces = helper.parseSVec(interface.get_interfaces(false))
    it('exists', () => {
        expect(ifaces).to.have.length.above(0);
    })

    it('has properties', () => {
        let iface = JSON.parse(ifaces[0])
        expect(iface).to.have.property('name')
        expect(iface).to.have.property('status')
        expect(iface).to.have.property('mac')
        expect(iface).to.have.property('ip')
        expect(iface).to.have.property('netmask')
        expect(iface).to.have.property('broadcast')
    })

    it('has active interface', () => {
        let active = helper.parseSVec(interface.get_interfaces(true))
        for(a in active){
            iface = JSON.parse(active[a])
            expect(iface.status).equals('up')
            expect(iface.ip).to.not.equal('127.0.0.1')
            expect(iface.ip).to.not.equal('0.0.0.0')
        }
    })

    it('has localhost', () => {
        let local = helper.parseSVec(interface.get_localhosts())
        for(a in local){
            iface = JSON.parse(local[a])
            expect(iface.status).equals('up')
            expect(iface.ip).to.oneOf(['127.0.0.1','0.0.0.0'])
        }
    })
})

describe('sniffer',() => {

    let HerbSniffer = herbivore.HerbSniffer
    const sniffer = new HerbSniffer()
    const sniffConfig = {iface:'en0',is_promisc:true,is_monitor:false};
    sniffer.iface = sniffConfig.iface
    sniffer.is_promisc = sniffConfig.is_promisc
    sniffer.is_monitor = sniffConfig.is_monitor

    it('can run', () => {
        sniffer.run();
    })

})