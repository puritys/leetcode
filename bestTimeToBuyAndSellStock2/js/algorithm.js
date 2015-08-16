/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    var i, n, min, max, maxProfit = 0, newProfit;
    if (!prices) return 0;
    n = prices.length;
    max = min = prices[0];
    for (i = 0; i < n ; i++) {
        if (prices[i] < max) {
            newProfit = max - min;
            if (newProfit >  0) maxProfit += newProfit;
            max = min = prices[i];
            continue;
        }

        if (prices[i] < min) {
            max = min = prices[i];
        } else if (prices[i] > max) {
            max = prices[i];
        }
    }
    if (max > min) maxProfit += max - min;
    return maxProfit; 
};


module.exports = maxProfit;
