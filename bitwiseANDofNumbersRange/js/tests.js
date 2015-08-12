var assert = require('assert');
var fuc = require('./algorithm.js');



describe("Test rangeBitwiseAnd", function () {
    it("Normal", function () {
        assert.equal(4, fuc(4, 7));
    });

    it("empty", function () {
        assert.equal(0, fuc(0, 0));
    });
    it("empty2", function () {
        assert.equal(0, fuc(0, 2147483647));
    });
    it("large Number", function () {
        assert.equal(0, fuc(600000000, 2147483645));
    });

});
