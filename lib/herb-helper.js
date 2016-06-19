module.exports = {
    parseSVec :function(vec){
        arr = [];
        for (var i = 0; i < vec.size(); i++) {
            arr.push(vec.get(i))
        }
        return arr;
    }
}