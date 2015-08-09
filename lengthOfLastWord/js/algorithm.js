/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    var strlen, ret = 0;
    if (!s) return ret;
    strlen = s.length;
    for (var i = strlen-1; i >= 0; i--) if (s[i] !== ' ') break;

    for (i; i >= 0; i--) {
        if (s[i] === ' ') {
            return ret;
        }
        ret++;
    }
    return ret;
};



module.exports = lengthOfLastWord;
