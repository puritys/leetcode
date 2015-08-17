var assert = require('assert');
var fuc = require('./algorithm.js');

describe("Test bestTimeToBuyAndSellStock3", function () {

    it("Empty", function () {
        assert.equal(0, fuc());
    });
    it("Normal0", function () {
        assert.equal(10, fuc(1, [10,20]));
    });

    it("Normal", function () {
        assert.equal(40, fuc(1, [10,20,30,40,50]));
    });

    it("Normal2", function () {
        assert.equal(45, fuc(100, [10,5,30,40,50]));
    });

    it("Normal3", function () {
        assert.equal(35, fuc(1, [10,5,40,2,30]));
    });

    it("Normal4", function () {
        assert.equal(173, fuc(20, [10,5,100,2,80]));
    });

    it("Normal5", function () {
        assert.equal(100, fuc(50, [10,30,0,20,80,40]));
    });

    it("Normal6", function () {
        assert.equal(130, fuc(3, [10,30,0,20,80,40, 30,50, 35,60,38, 57]));
    });
    it("Normal7", function () {
        assert.equal(13, fuc(2, [1,2,4,2,5,7,2,4,9,0]));
    });

    it("Normal8", function () {
        assert.equal(0, fuc(1, [90,80,70,60]));
    });
    it("Normal9", function () {
        assert.equal(40, fuc(1, [10,20,30,40, 50]));
    });

    it("Normal10", function () {
        //890 + 780 + 20
        assert.equal(1690, fuc(3, [10,20,30,10,900,20,50,800,40, 50]));
    });

});
