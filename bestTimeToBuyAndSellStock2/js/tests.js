var assert = require('assert');
var fuc = require('./algorithm.js');

describe("Test bestTimeToBuyAndSellStock", function () {

    it("Empty", function () {
        assert.equal(0, fuc());
    });

    it("Normal", function () {
        assert.equal(40, fuc([10,20,30,40,50]));
    });

    it("Normal2", function () {
        assert.equal(45, fuc([10,5,30,40,50]));
    });

    it("Normal3", function () {
        assert.equal(63, fuc([10,5,40,2,30]));
    });

    it("Normal4", function () {
        assert.equal(173, fuc([10,5,100,2,80]));
    });

    it("Normal5", function () {
        assert.equal(100, fuc([10,30,0,20,80,40]));
    });

    it("Normal6", function () {
        assert.equal(164, fuc([10,30,0,20,80,40, 30,50, 35,60,38, 57]));
    });

});
