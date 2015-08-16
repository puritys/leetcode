/**
 * @param {number[]} prices
 * @return {number}
 */

var maxProfit = function(prices) {
    var i ,n, maxInt, profit, buy, p;
    if (!prices) return 0;
    maxInt = -Math.pow(2, 53) + 1;
    profit = [0, 0],buy = [maxInt, maxInt];
    n = prices.length;
    for (i = 0; i < n; i++) {
        p = prices[i];
        profit[1] = Math.max(profit[1], p + buy[1]);
        buy[1] = Math.max(buy[1], profit[0] - p);
        profit[0] = Math.max(profit[0], p + buy[0]);
        buy[0] = Math.max(buy[0], -p);
    }
    return profit[1];
};


module.exports = maxProfit;
