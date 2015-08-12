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
        if (prices[i] < min) {
            newProfit = max - min;
            if (newProfit > maxProfit) maxProfit = newProfit;
            max = min = prices[i];
        } else if (prices[i] > max) {
            max = prices[i];
        }
    }
    if (max > min) newProfit = max - min;
    if (newProfit > maxProfit) maxProfit = newProfit;
    return maxProfit; 
};


module.exports = maxProfit;
