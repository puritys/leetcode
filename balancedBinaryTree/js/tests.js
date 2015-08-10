function TreeNode(val) {
    this.val = val;
    this.left = this.right = null;
}
var fuc = require('./algorithm.js');
var assert = require('assert');

describe("Test balancedBinaryTree", function () {

    it("Normal", function () {
        var root = new TreeNode(0);
        root.left = new TreeNode(1);
        root.right = new TreeNode(2);
        var s = fuc(root);
        assert.equal(true, s);
    });

    it("Normal2", function () {
        var root = new TreeNode(2);
        root.left = new TreeNode(1);
        root.right = new TreeNode(3);
        var s = fuc(root);
        assert.equal(true, s);
    });
    it("Normal3", function () {
        var root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(2);
        root.left.left = new TreeNode(3);
        root.left.right = new TreeNode(3);
        root.right.left = new TreeNode(null);
        root.right.right = new TreeNode(null);
        root.left.left.left = new TreeNode(4);
        root.left.left.left = new TreeNode(4);
        var s = fuc(root);
        assert.equal(true, s);
    });


    it("Empty", function () {
        var s = fuc("");
        assert.equal(true, s);
    });
    it("Undefined", function () {
        var s = fuc("");
        assert.equal(true, s);
    });

    it("Without left", function () {
        var root = new TreeNode(0);
        root.left = new TreeNode(1);
        root.right = new TreeNode(2);
        root.left.right = new TreeNode(4);
        var s = fuc(root);
        assert.equal(true, s);
    });

    it("Without right", function () {
        var root = new TreeNode(0);
        root.left = new TreeNode(1);
        root.right = new TreeNode(2);
        root.left.left = new TreeNode(3);
        var s = fuc(root);
        assert.equal(true, s);
    });

    it("Wrong", function () {
        var root = new TreeNode(0);
        root.left = new TreeNode(1);
        root.right = new TreeNode(3);
        var s = fuc(root);
        assert.equal(true, s);
    });

    it("Wrong 2", function () {
        var root = new TreeNode(0);
        root.left = new TreeNode(1);
        root.left.left = new TreeNode(2);
        var s = fuc(root);
        assert.equal(false, s);
    });

    it("Wrong 3", function () {
        var root = new TreeNode(1);
        root.left = null;
        root.right = new TreeNode(2);
        root.right.left = null;
        root.right.right = new TreeNode(3);


        var s = fuc(root);
        assert.equal(false, s);
    });






});

