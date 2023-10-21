/* 1. let / const */
const arr = [1, 2, 3, 4]
arr.push(5)
const obj = {
  age: 10,
  classNo: 2,
  name: "jerry"
}

/* 2. change html */
const div = document.querySelector('div')
console.log(div);

// id use #id
// class use .class
const lis = document.querySelectorAll('ul li')
const lis2 = document.querySelectorAll('.nav li')
console.log(lis);
console.log(lis2);
for (let i = 0; i < lis.length; i++) {
  const item = lis[i];
  item.innerHTML
  item.innerText
}

// const docById = document.getElementById('id')
// const docByTag = document.getElementsByTagName('div')
// const docByClassName = document.getElementsByClassName('nav')

const personArr = [
  'jay chao',
  'liu dehua',
  'xingchi zhou'
]

const random = Math.floor(Math.random() * personArr.length)
const one = document.querySelector('#one')
one.innerHTML = personArr[random]
personArr.splice(random, 1)

const random2 = Math.floor(Math.random() * personArr.length)
const two = document.querySelector('#two')
two.innerHTML = personArr[random2]
personArr.splice(random2, 1)

const random3 = Math.floor(Math.random() * personArr.length)
const three = document.querySelector('#three')
three.innerHTML = personArr[random3]
personArr.splice(random3, 1)

/* 3. Change CSS */
const imgSrc = document.querySelector('img')
imgSrc.src = 'https://www.desicomments.com/wallpapers/wp-content/uploads/2014/12/Mountains.jpg'

const divBox = document.querySelector('.box')
console.log(divBox);
// divBox.style.width = '500px'
// divBox.style.backgroundColor = 'blue'

// 这个更常用
divBox.className = 'boxNew' // 替换掉 class
divBox.classList.add('boxNew') // 追加 class
divBox.classList.remove('box')
divBox.classList.toggle('active')  // 切换 class, 有就删掉, 没有就切换

const oneDiv = document.querySelector('.div1')
console.log('---------------------');
console.log(oneDiv.dataset)

/* 4. 间歇函数 */
let interval = setInterval(() => {
  console.log("hello");
}, 1000); // 每隔1000ms打印
clearInterval(interval)

const btn = document.querySelector('.btn')
let i = 5
let in2 = setInterval(() => {
  i--
  // document.write(i, '\r\n')
  btn.innerHTML = `${i}`
  if (i === 0) {
    clearInterval(in2)
    btn.innerHTML = '同意'
    btn.disabled = false
  }
}, 1000);

btn.addEventListener('click', (e) => {
  console.log('btn on click');
})

/* 5. 事件对象 */
btn.addEventListener('click', (e) => {
  console.log(e);
  console.log(e.type)
  if (e.key === 'Enter') {
    console.log('我按下了 enter');
  }
})

/* 6. 环境对象this */
// 是哪个对象调用我的, this 指向谁
// 普通函数的调用是 windows
// 事件监听的函数, 指向调用者

/* 7. 回调函数 */
// 如果将函数 A 做为参数传递给函数B时，我们称函数 A 为回调函数
let recallFn = () => {

}
setInterval(recallFn, 10);

/* 8. 事件流, 事件捕获, 事件解绑, 事件冒泡 */
// 事件捕捉就是从 document 开始捕捉事件
// 事件冒泡就是从绑定事件的子元素向上冒泡响应处理
// 事件委托就是将事件响应函数绑定到父元素上


/* 9. BOM */
window.document.querySelector()

/* 10. location */
// 这个用的多
localStorage.setItem('key', 'value')
localStorage.getItem('key')
// localStorage.setItem('key', JSON.stringify(obj))
// JSON.parse(localStorage.getItem('key'))

sessionStorage.setItem('key', 'value')
sessionStorage.getItem('key')

/* 11. regex */

const re = /xonst/
let trueORfalse = re.test('string')
let arrResult = re.exec('string')

// 元字符 [a-z]
//   - 边界符 $ ^
//   - 量词 
//      - 量词用来设定某个模式出现的次数
//        *      重复零次或更多次
//        +      重复一次或更多次
//        ？     重复零次或一次
//        {n}    重复n次
//        {n, }  重复n次或更多次
//        {n, m} 重复n到m次
//      - 字符类
//         [abc]   出现只选一个 abc 中的字符
//       正则表达式中的字符类用于匹配特定类型的字符。以下是你提到的以及其他常用字符类的解释：
//       1. **\d**：匹配任意数字。等同于 `[0-9]`。
//         - 例如：`\d` 可以匹配字符串 "abc123" 中的 '1'、'2' 或 '3'。
//       2. **\D**：匹配任意非数字字符。等同于 `[^0-9]`。
//         - 例如：`\D` 可以匹配字符串 "abc123" 中的 'a'、'b' 或 'c'。
//       3. **\s**：匹配任意空白字符，包括空格、制表符、换页符等。
//         - 例如：`\s` 可以匹配字符串 "a b" 中的空格。
//       4. **\S**：匹配任意非空白字符。
//         - 例如：`\S` 可以匹配字符串 "a b" 中的 'a' 或 'b'。
//       5. **\w**：匹配任意单词字符，包括字母、数字和下划线。等同于 `[a-zA-Z0-9_]`。
//         - 例如：`\w` 可以匹配字符串 "abc_123" 中的任何字符。
//       6. **\W**：匹配任意非单词字符。等同于 `[^a-zA-Z0-9_]`。
//         - 例如：在字符串 "!abc_123?" 中，`\W` 可以匹配 '!' 或 '?'。
//       7. **\b**：匹配单词边界。这不匹配任何字符，而是表示一个位置，例如单词的开头或结尾。
//         - 例如：正则表达式 `\bword\b` 可以匹配字符串 "a word here" 中的 "word"，但不会匹配字符串 "a wordhere" 中的 "word"。
//       8. **\B**：匹配非单词边界。
//       以上只是正则表达式中的一部分字符类。正则表达式是一个非常强大的工具，有很多高级功能和特殊字符供你探索。
//  - 修饰符
//      i     ignore case
//      g     global
