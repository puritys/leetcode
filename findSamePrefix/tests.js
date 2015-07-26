
var lib = require("./algorithm");
var assert = require('assert');

describe("Test findSamePrefix", function () {

    it("normal", function () {
        var list = ["list_aa1", "list_bb1", "list_bb3", "kk_aaa_b", "kk_aaac", "n1", "n2"];
        var res = lib.findSamePrefix(list);
        assert.equal("list_", res[0].prefix);
        assert.equal(2, res[0].weight);
        assert.equal("kk_aaa", res[1].prefix);
        assert.equal(1, res[1].weight);
    });
});

