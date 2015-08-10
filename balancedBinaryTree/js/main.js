//https://leetcode.com/problems/balanced-binary-tree/
var fuc = require("./algorithm.js");
function TreeNode(val) {
    this.val = val;
    this.left = this.right = null;
}

var root = new TreeNode(0);
root.left = new TreeNode(1);
root.right = new TreeNode(2);

var s = fuc(root);
console.log(s);
