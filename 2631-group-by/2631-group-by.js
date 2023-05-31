Array.prototype.groupBy = function(fn) {
    const ans = {};
   for (let ele of this) {
        const temp = fn(ele);
        ans[temp]?ans[temp].push(ele): ans[temp] = [ele];
    }
    return ans;
};