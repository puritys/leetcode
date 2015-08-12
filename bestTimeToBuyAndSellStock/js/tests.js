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
        assert.equal(35, fuc([10,5,40,2,30]));
    });

    it("Normal4", function () {
        assert.equal(95, fuc([10,5,100,2,80]));
    });

});
