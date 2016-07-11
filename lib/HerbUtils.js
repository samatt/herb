module.exports = {
  parseSVec: function (vec) {
    var arr = []
    for (var i = 0; i < vec.size(); i++) {
      arr.push(JSON.parse(vec.get(i)))
    }
    return arr
  }
}
