/**
 * @param {number} n
 * @param {number[][]} trust
 * @return {number}
 */
var findJudge = function(n, trust) {
    const i = new Array(n+1).fill(0);
    const o = new Array(n+1).fill(0);
    for (const [from, to] of trust) {
        i[to] += 1;
        o[from] += 1;
    }
    for (let j=1;j<=n;j++){
        if (i[j] === n-1 && o[j] === 0){
            return j;
        }
    }
    return -1
};