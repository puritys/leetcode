var o = require('./algorithm.js');
var assert = require('assert');

describe("isMatch Test", function () {

    it("test a", function () {
        assert.equal(false, o.isMatch("aa", "a"));
    });

    it("test aa", function () {
        assert.equal(true, o.isMatch("aa","aa"));
    });

    it("test a*", function () {
        assert.equal(true, o.isMatch("aa", "a*"));
    });

    it("test aa .*", function () {
        assert.equal(true, o.isMatch("aa", ".*"));
    });

    it("test ab .*", function () {
        assert.equal(true, o.isMatch("ab", ".*"));
    });

    it("test c*a*b", function () {
        assert.equal(true, o.isMatch("aab", "c*a*b"));
    });



});

