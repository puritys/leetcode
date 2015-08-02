
/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
    var reg;
    reg = new RegExp("^"+p+"$");
    if (s.match(reg)) return true;
    return false;
};


module.exports.isMatch = isMatch;
