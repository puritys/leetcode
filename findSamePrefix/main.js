var list = ["list_aa1", "list_bb1", "list_bb3", "kk_aaa_b", "kk_aaac", "n1", "n2"];

var _ = require("underscore");

//console.log(getPrefix("abcd", "abgesg"));
var res = findSamePrefix(list);
console.log(res);

function findSamePrefix(list) {
    var ret = [], subList = [], prefix = "", newPrefix;
    var i, n;
    while(list && list[0]) {
        prefix = list[0];
        n = list.length;
        subList = [];
        for (i = 0; i < n ; i++) {
            newPrefix = getPrefix(prefix, list[i]);
            if (newPrefix) {
                prefix = newPrefix;
            } else {
                subList.push(list[i]);
            }
        }
        ret.push(prefix);
        list = [];
        for (var k in subList) { // clone
            list.push(subList[k]);
        }
    }
    return ret;
}

function getPrefix(str1, str2) {
    var prefix = "", n1, n2, i;
    n1 = str1.length;
    n2 = str2.length;

    for (i = 0; i < n1 && i < n2; i++) {
        if (str1[i] == str2[i]) {
            prefix += str1[i];
        }
    }

    return prefix;
}
