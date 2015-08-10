/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isBalanced = function(root) {
    if (!root) return true;
    if (Math.abs(getHeight(root.left) - getHeight(root.right)) > 1) return false;
    return isBalanced(root.left) && isBalanced(root.right);
};

function getHeight(root) {
    if (!root) return 0;
    var stack = [], deep = 1, tmp;
    root.val = deep;
    stack.push(root);
    while (stack.length > 0) {
        tmp = stack.pop();
        if (tmp.left) {
            tmp.left.val = tmp.val + 1;
            stack.push(tmp.left);
            deep = Math.max(tmp.left.val, deep);
        }
        if (tmp.right) {
            tmp.right.val = tmp.val + 1;
            stack.push(tmp.right);
            deep = Math.max(deep, tmp.right.val);
        }
    }
    return deep;
}

function TreeNode(val) {
    this.val = val;
    this.left = this.right = null;
}


module.exports = isBalanced;
