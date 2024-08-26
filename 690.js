/**
 * Definition for Employee.
 * function Employee(id, importance, subordinates) {
 *     this.id = id;
 *     this.importance = importance;
 *     this.subordinates = subordinates;
 * }
 */
/**
 * @typedef {Object} Employee
 * @prop {number}  id
 * @prop {number} importance
 * @prop {number[]} subordinates
 */
/**
 * @param {Employee[]} employees
 * @param {number} id
 * @return {number}
 */
var GetImportance = function(employees, id) {
    const g = {};
    for (const employee of employees){
        g[employee.id] = {
            children: employee.subordinates,
            instance: employee
        }
    };
    let ans = 0
    /**
     * 
     * @param {number} start 
     */
    const dfs = (start) => {
        ans += g[start].instance.importance;
        for (const child of g[start].children){
            dfs(child);
        }
        return ans;
    }
    dfs(id);
    return ans;
};