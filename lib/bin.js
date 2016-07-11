const spawn = require('child_process').spawn
const config = require('./config')
const events = require('events')

class Bin extends events.EventEmitter {
  constructor (name, parser) {
    super()
    this.name = name
    this.bin = spawn(`${config.binPath}/herb_commands`,[name])
    this.count = 0
    this.bin.stdout.on('data', (d) => { this.emit('data', parser(d)) })
    // this.bin.stderr.on('error', (d) => { console.error(d); this.emit('error', d) })
    this.bin.stderr.on('error', (d) => { this.emit('error', new Error(d)) })
    this.bin.on('close', (code) => { this.emit('close') })
    process.on('SIGINT', (code) => { this.emit('kill'); this.bin.kill() })
  }

  kill () {
    this.bin.kill('SIGTERM')
  }
}

module.exports = Bin

