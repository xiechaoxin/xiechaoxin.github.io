/* 1. 作用域 解构 箭头函数 */

// 闭包
// 闭包方便外部访问函数内部的变量
function Out() {
    let aOut = 1

    function In() {
        aOut = 3
    }

    return In
}

/* 2. 构造函数 常用函数 */
function pig(name, age, gender) {
    this.name = name
    this.gender = gender
}

const Peppa = new Pig('佩奇', 6, '女')
const fs = require('fs')
fs.write()
/* 3. 面相对象 */
/* 4. 高阶技巧 */
