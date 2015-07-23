//var _ = require("underscore");

exports.findSamePrefix = function (list) {
    var ret = [], subList = [], prefix = "", newPrefix;
    var i, n;
    var getPrefix = function(str1, str2) {
        var prefix = "", n1, n2, i;
        n1 = str1.length;
        n2 = str2.length;

        for (i = 0; i < n1 && i < n2; i++) {
            if (str1[i] == str2[i]) {
                prefix += str1[i];
            }
        }

        return prefix;
    };

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


