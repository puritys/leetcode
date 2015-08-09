/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    if (!s) return 0;
    s = s.trim();
    var strs = s.split(" "); 
    return strs[strs.length - 1].length;
};



module.exports = lengthOfLastWord;
