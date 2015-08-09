var smartPerf = require("smart-perf");
var v1 = require("./algorithmV1.js");
var v2 = require("./algorithm.js");
var split = require("./algorithmSplit.js");


var string = "This is a good ddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddday";
var max = 99000;

// Test the performace of V1 algorithm
smartPerf.start("Test V1");
for (var i = 0; i < max; i++) {
    v1(string);
}
smartPerf.end();

// test the performace of v2 algorithm
smartPerf.start("test v2");
for (var i = 0; i < max; i++) {
    v2(string);
}
smartPerf.end();

// test the performace of split algorithm
smartPerf.start("test split");
for (var i = 0; i < max; i++) {
    split(string);
}
smartPerf.end();




smartPerf.print();

