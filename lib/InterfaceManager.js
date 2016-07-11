const Herbivore = require('../bin/Herbivore')
let helper = require('../lib/herb-helper')
// const _ = require('underscore')

class InterfaceManager {

  constructor () {
    this.utils = new Herbivore.Interface()
  }

  get up () {
    return helper.parseSVec(this.utils.get_interfaces(true))
  }

  get down () {
    return helper.parseSVec(this.utils.get_interfaces(false))
  }

  get localhost () {
    return helper.parseSVec(this.utils.get_localhosts())
  }

}

module.exports = InterfaceManager

