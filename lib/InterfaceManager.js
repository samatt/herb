const Herbivore = require('../bin/Herbivore')
let herbUtils = require('../lib/HerbUtils')
// const _ = require('underscore')

class InterfaceManager {

  constructor () {
    this.utils = new Herbivore.Interface()
  }

  get up () {
    return herbUtils.parseSVec(this.utils.get_interfaces(true))
  }

  get down () {
    return herbUtils.parseSVec(this.utils.get_interfaces(false))
  }

  get localhost () {
    return herbUtils.parseSVec(this.utils.get_localhosts())
  }

}

module.exports = InterfaceManager

