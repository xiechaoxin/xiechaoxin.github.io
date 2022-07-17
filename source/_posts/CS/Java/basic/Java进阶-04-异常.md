---
title: Java进阶-04-异常
category: 
  - Java
  - basic
  - 进阶
tags:
  - Java
  - basic
  - 进阶
date: 2022-07-17 11:06:53
---

[^版权说明]: 以下笔记总结归纳自 *动力节点* 相关课程，没有经过作者同意，禁止转载

[toc]


# 异常

## 1. 异常的基本概念
在程序运行过程中出现的错误，称为异常；java 异常都是 类，在异常类中会携带一些信息给我们，我们可以通过这个类把信息取出来

## 2. 异常的分类

### 异常的层次结构

![image-20211029093104824](https://gitee.com/xcxhalo/picgo/raw/master/Img/image-20211029093104824.png)



### 异常的分类

异常主要分为：错误、一般性异常（受控异常）、运行期异常（非受控异常）

积累：那些是受控异常，那些是非受控异常

1. 错误：出现 error，无法恢复，只能重启应用程序，最典型的Error 的异常是：OutOfMemoryError
2. 受控异常：出现了这种异常必须显示的处理，不显示处理 java 程序将无法编译通过
3. 非受控异常：此种异常可以不用显示的处理，例如被 0 除异常，java 没有要求我们一定要处理



## 3. 异常的捕获和处理

#### try、 catch 和 finally

异常的捕获和处理需要采用 try 和 catch 来处理

注意：不出现异常的代码最好不要放到 try 作用

```java
try{
  // try 中包含了可能产生异常的代码
}catch(oneException){
  // try 后面是 catch，catch 可以有一个或多个，catch 中是需要捕获的异常
}catch(twoException){
  // 当 try 中的代码出现异常时，出现异常下面的代码不会执行，马上会跳转到相应的 catch 语 句块中，如果没有异常不会跳转到 catch 中
}finally{
  // 不管是出现异常，还是没有出现异常，finally 里的代码都执行，finally 和 catch 可以分开使用，但 finally 必须和 try 一块使用
}
```



#### getMessage 和 printStackTrace()

取得异常描述信息：getMessage()

取得异常的堆栈信息(比较适合于程序调试阶段)：printStackTrace();

```java
}catch(ArithmeticException ae) { 
	//ae 是一个引用，它指向了堆中的 ArithmeticException 
  //通过 getMessage 可以得到异常的描述
  System.out.println(ae.getMessage());
  //通过 getMessage 可以得到异常的描述
	System.out.println(ae.printStackTrace());
}
```

注意：受控异常，必须处理，例如：

```java
catch(FileNotFoundException ffe) { //此异常为受控异常，必须处理 ffe.printStackTrace(); }
```



### final

finally 在任何情况下都会执行，通常在 finally 里关闭资源

```java

```



#### 声明异常

关键字：throws

在方法定义处采用 throws 声明异常，**如果声明的异常为受控异常，那么调用方法必须处理此异常**

main 方法不建议抛出异常，因为这样是交个 jvm 处理了

非受控异常可以不声明，但是也可以使用try catch

```java

// throws Exception
public class ExceptionTest14 {

  public static void main(String[] args) {

    //不需要使用 try...catch..，因为声明的是非受控异常 //method1();

    //也可以拦截非受控异常 try {

    method1(); 
  }catch(ArithmeticException e) {

    e.printStackTrace();
  }

}

//可以声明非受控异常 
private static void method1() throws ArithmeticException {
  int i1 = 100; int i2 = 0; 
  // try { int i3 = i1/i2; System.out.println(i3);

/*

}catch(ArithmeticException ae) { ae.printStackTrace(); }

*/ 
}
}
```



#### 如何手动抛出异常

关键字：throw

```java
if (value2 == 0) {
  // 手动抛出异常 
  throw new IllegalArgumentException("除数为 0"); } 
if (!(value1 >0 && value1<=100)) { 
  //手动抛出异常 
  throw new IllegalArgumentException("被除数必须为 1~100 之间的数据");

}

try {
  int ret = method1(1000, 10);
  System.out.println(ret); 
}catch(IllegalArgumentException iae) {
  //ide 为指向堆中的 IllegalArgumentException 对象的地址

  System.out.println(iae.getMessage()); 
}
```



#### throws 和 throw 的区别？

thorws 是声明异常，throw 是抛出异常

可以简单理解，如果语句编译出错，throw 相当于 return 语句，但是 throw 执行后还是可以执行 final



#### 异常捕获顺序

异常的捕获顺序应该是：从小到大

```java
try { 
  FileInputStream fis = new FileInputStream("test.txt"); 
  fis.close(); 
}catch(IOException e) {
  e.printStackTrace(); 
}catch(FileNotFoundException e) {
  e.printStackTrace(); 
}
//将 IOException 放到前面，会出现编译问题
//因为 IOException 是 FileNotFoundException 的父类， 
//所以截获了 IOException 异常后，IOException 的子异常 
//都不会执行到，所以再次截获 FileNotFoundException 没有任何意义 
//异常的截获一般按照由小到大的顺序，也就是先截获子异常，再截获父异常
```



## 4. 自定义异常

#### 如何自定义异常

自定义异常通常继承于 Exception 或 RuntimeException，到底继承那个应该看具体情况来定， 关于异常再以后的项目中再继续讨论

```java
// 1. 自定义受控异常
class MyException extends Exception {
  public MyException() { 
    //调用父类的默认构造函数
    super();
  }

  public MyException(String message) {
    //手动调用父类的构造方法
    super(message); 
  }
}

//如果是受控异常必须声明
private static void method1(int value1, int value2) throws MyException { }


//必须拦截,拦截后必须给出处理，如果不给出处理，就属于吃掉了该异常
try { method1(10, 0); }catch(MyException e) {}


// 2. 定义非受控异常
class MyException extends RuntimeException {

  public MyException() { //调用父类的默认构造函数 super(); 
  }

  private static void method1(int value1, int value2) //throws MyException {

    if (value2 == 0) { //抛出非受控异常，方法可以不适用 throws 进行声明 //但也也可以显示的声明
      throw new MyException("除数为 0");
    }
```



## 5. 方法覆盖与异常

方法覆盖的条件

子类方法不能抛出比父类方法更多的异常，但可以抛出父类方法异常的子异常



## 6. 总结

a) 异常的分类

b) 受控异常和非受控异常的区别

c) 异常的 5 个关键字 try、catch、finally、throws、throw

d) 异常的捕获顺序，先捕获小的，再捕获大的

e) 方法覆盖和异常的关系
