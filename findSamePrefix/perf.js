var list = ["list_aa1", "list_bb1", "list_bb3", "kk_aaa_b", "kk_aaac", "n1", "n2"];

var lib = require("./algorithm");
var smartPerf = require("smart-perf");

//console.log(getPrefix("abcd", "abgesg"));
var res;

smartPerf.start("test 1");

for (var i = 0 ; i < 20000; i++) {
    list = ["list_aa1", "list_bb1", "list_bb3", "kk_aaa_b", "kk_aaac", "n1", "n2"];
    res = lib.findSamePrefix(list);
}

//console.log(res);
smartPerf.end(true);

smartPerf.start("test 2");

for (var i = 0 ; i < 20000; i++) {
    list = ["list_aa1", "list_bb1", "list_bb3", "kk_aaa_b", "kk_aaac", "list_zaa1", "list_gaa1"];
    res = lib.findSamePrefix(list);
}

//console.log(res);
smartPerf.end(true);

console.log("\n");
smartPerf.print();
