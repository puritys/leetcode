
var rangeBitwiseAnd = function(m, n) {
    if (m === 0) return 0;
    var leftBit = 1;
    while (m != n) {
        m >>= 1;
        n >>= 1;
        leftBit <<= 1;
    }
    return m * leftBit;
};

module.exports = rangeBitwiseAnd;
