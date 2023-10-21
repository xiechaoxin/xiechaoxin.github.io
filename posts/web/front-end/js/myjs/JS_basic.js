/* 1. Write out */
document.write("<h1>我的输出中文</h1>")
alert("out js")
console.log("object")

/* 2. Input */
prompt("pls input you age:")

/* 3. let */
let age = prompt("pls input you age:")
console.log(age);
document.write("<h1>", age, "</h1>")

/* 4. var */
// - var 可以重复声明变量
// - 变量提升, 全局变量, 没有块级作用域
// - 建议统一使用 let

/* 5. array */
let arr = [0, 1, 2, 3, 4, 5]
console.log(arr[0]);
console.log(arr.length);

// add 
arr.push(6) // 向最后添加一个元素
arr.unshift(8) // 向最前面添加一个元素
// del
arr.pop() //  删除最后一个元素
arr.shift() // 删除第一个元素
arr.splice(/* 操作的下标, 删除的个数 */)
// modify
arr[0] = 8
// search
for (let i = 0; i < arr.length; i++) {
  const item = arr[i];
}


/* 6. const */
const FINAL = 123
console.log(FINAL);
// FINAL = 32 // Uncaught TypeError: Assignment to constant variable.

/* 7. Number type */
i = 1
f = 1.09
d = 1.80

/* 8. String */
s = "hello"
str = 'hello'
string = `hello`
strAdd = s + str + string
// 模版字符串
tempString = `my age is ${age}`

/* 9. NaN */
if (NaN === NaN) {
  console.log(object);
}

/* 10. bool */
let flag = true

/* 11. undefined */
let num
console.log(num);// undefined

/* 12. null */
let obj = null
// undefined 表示没有赋值, null 表示赋值了, 但是内容为空

/* 13. typeof() */
typeof (obj)

/* 14. Type convert */
// 隐式转换
let int2str = 'hello' + 1 // "hello1"
let str2int = '2' * 2 // 22
console.log(int2str);
console.log(str2int);

// 显式转换
string = "123"
let n = Number(string)
parseInt(string)
parseFloat(string)
let string = String(num)

/* 15. == === != !== */
// == 比较值, === 比较值和类型
// NaN 不能进行比较

/* 16. if else */
if (true/* condition */) {

} else {

}

// condition ? A : B

/* 17. switch */
// 比较使用===
// switch (/* key */) {
//   case /* value */:
//     /* do sth */
//     break;

//   default:
//     break;
// }

/* 18. while  */
while (false/* condition */) {
  console.log("object");
}
for (let i = 0; i < array.length; i++) {
  const element = array[i];
}

/* 19. function */
function name(params) {

}
// 函数表达式
let fn = function (params) {

}
fn(params);
// 立即执行函数, 可以避免全局变量之间的污染, 需要分号
(function () { })();

/* 20. Object */
let hellofn = function (i) {
  console.log(i);
  console.log("in hellofn");
}
let objB = {
  f1: 12,
  f2: "string",
  methodA: hellofn,
  methodB: function () {
  }
}

objB.methodA(2)
objB.methodB()

for (let key in objB) {
  console.log(key); // key: str = "f1"
  console.log(obj[key]);
  console.log(obj.key); // error
}

/* 21. Math */
Math.abs(x)
Math.random()// 0-1 随机 float
Math.ceil(x)// 向上取整
Math.floor(x)// 向下取整
Math.max()
Math.min()
Math.pow(x, y)// 幂运算
