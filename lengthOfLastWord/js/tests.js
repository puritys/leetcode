
//var fuc = require('./algorithm.js');
var fuc = require('./algorithmSplit.js');
var assert = require('assert');

describe("Test lengthOfLastWord", function () {

    it("Normal", function () {
        var s = fuc("Hello World");
        assert.equal(5, s);
    });

    it("Undefined", function () {
        var s = fuc();
        assert.equal(0, s);
    });

    it("Empty", function () {
        var s = fuc("");
        assert.equal(0, s);
    });

    it("Empty string", function () {
        var s = fuc(" ");
        assert.equal(0, s);
    });


    it("Three world", function () {
        var s = fuc("This is good");
        assert.equal(4, s);
    });


    it("Last letter is empty", function () {
        var s = fuc("This is good  ");
        assert.equal(4, s);
    });




});

