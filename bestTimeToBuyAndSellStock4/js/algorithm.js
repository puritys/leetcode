"use strict";

/**
 * @param {number} k
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(k, prices) {
    var ki, i, j, n;
    var profitAfterSell, profitAfterBuy, buyPrices = [0], sellPrices = [0];
    var profit = [[0]], maxProfit = 0, minBuy = [];
    if (!prices) return 0;
    prices = getBounds(prices);
    if (!prices) return 0;
    n = prices.length;
    if (k >= n / 2) {
        for (i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1]) {
                maxProfit += prices[i] - prices[i - 1];
            }
        }
        return maxProfit;
    }

    // initialize the profit value to be zero.
    for (ki = 1; ki <= k; ki++) {
        profit[ki] = [0];
        minBuy[ki] = -prices[0];
        buyPrices[ki] = prices[0];
    }

    for (i = 1; i < n; i++) profit[0][i] = 0;

    for (i = 1; i < n; i++) {
        for (ki = 1; ki <= k; ki++) {
            profitAfterSell = minBuy[ki] + prices[i];
            if (profitAfterSell > profit[ki][i - 1]) {
                profit[ki][i] = profitAfterSell;
//                sellPrices[ki] = prices[i];
            } else {
                // transation profit of last day
                profit[ki][i] = profit[ki][i - 1];
            }

            profitAfterBuy = profit[ki - 1][i - 1] - prices[i];
            if (profitAfterBuy > minBuy[ki]) {
                minBuy[ki] = profitAfterBuy;
//                buyPrices[ki] = prices[i];
            } 
        }
    }
    if (!profit[k]) return 0;
    return profit[k][profit[k].length - 1];
};


function getBounds(prices) {
    var i, n, min, max, bounds = [], climbing = false, preClimbing = false, prePrices;
    if (!prices) return bounds;
    n = prices.length;
    prePrices = prices[0];
    for (i = 1; i < n ; i++) {
        if (prices[i] >= prePrices) {
            climbing = true;
        } else {
            climbing = false;
        }
        if (preClimbing != climbing) {
            bounds.push(prePrices);
        }
        preClimbing = climbing;
        prePrices = prices[i];
    }
    if (climbing === true) bounds.push(prices[n-1]);
    return bounds; 

}

module.exports = maxProfit;
