/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    var strlen, ret = 0;
    if (!s) return ret;
    strlen = s.length;
    for (var i = strlen-1; i >= 0; i--) {
        if (s[i] === ' ') {
            if (ret === 0) continue;
            return ret;
        }
        ret++;
    }
    return ret;
};



module.exports = lengthOfLastWord;
