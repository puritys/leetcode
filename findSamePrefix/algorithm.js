//var _ = require("underscore");

exports.findSamePrefix = function (list) {
    var ret = [], subList = [], prefix = "", newPrefix, weight;
    var i, n, tmp;
    // Get the same prefix from two string.
    var getPrefix = function(str1, str2) {
        var prefix = "", n1, n2, i;
        n1 = str1.length;
        n2 = str2.length;
        for (i = 0; i < n1 && i < n2; i++) {
            if (str1[i] == str2[i]) {
                prefix += str1[i];
            } else {
                break;
            }
        }
        return prefix;
    };

    while(list && list[0]) {
        prefix = list[0];
        n = list.length;
        subList = [];
        weight = 0;
        for (i = 1; i < n ; i++) {
            newPrefix = getPrefix(prefix, list[i]);
            if (newPrefix) { 
                prefix = newPrefix;
                weight++;
            } else {
                subList.push(list[i]);
            }
        }
        if (!prefix || prefix == "") {
            ret.push({prefix: list[0], weight: 0});
        } else {
            ret.push({prefix: prefix, weight: weight});
        }
        list = [];
        for (var k in subList) { // clone
            list.push(subList[k]);
        }
    }
    //Sort by weight
    n = ret.length;
    for (i = 0; i< n; i++) {
        for (j = i+1; j < n; j++) {
            if (ret[i].weight < ret[j].weight) {
                tmp = ret[j] ;
                ret[j] = ret[i];
                ret[i] = tmp;
            }
        }
    }
    return ret;
}


