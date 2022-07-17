---
title: Java进阶-03-常用类
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

[^版权说明]: // 版权说明:以下笔记总结归纳自 *动力节点* 相关课程，没有经过作者同意，禁止转载

# Java 常用类



## 1. Object

Object 类是所有 Java 类的根基类，如果在类的声明中未使用 extends 关键字指明其基类，则默认基类为 Object 类



#### ==与 equals 方法

java中的数据类型，可分为两类：

1. **基本数据类型**，也称原始数据类型。byte,short,char,int,long,float,double,boolean
    他们之间的比较，应用双等号（==）,比较的是他们的值。
2. **复合数据类型**(类)
    当他们用（==）进行比较的时候，比较的是他们在内存中的存放地址，所以，除非是同一个new出来的对象，他们的比较后的结果为true，否则比较后结果为false。 JAVA当中所有的类都是继承于Object这个基类的，在Object中的基类中定义了一个equals的方法，这个方法的初始行为是比较对象的内存地 址，但在一些类库当中这个方法被覆盖掉了，如String,Integer,Date在这些类当中equals有其自身的实现，而不再是比较类在堆内存中的存放地址了。
3. 对于复合数据类型之间进行equals比较，在没有覆写equals方法的情况下，他们之间的比较还是基于他们在内存中的存放位置的地址值的，因为Object的equals方法也是用双等号（==）进行比较的，所以比较后的结果跟双等号（==）的结果相同。



#### toString

返回该对象的字符串表示。通常 toString 方法会返回一个“以文本方式表示”此对象的字 符串，Object 类的 toString 方法返回一个字符串，该字符串由类名加标记@和此对象哈希码 的无符号十六进制表示组成，

```java
// Object 类 toString 源代码如下：

getClass().getName() + '@' + Integer.toHexString(hashCode())
```





#### finalize

当垃圾收集器将要收集某个垃圾对象时将会调用 finalize，

垃圾回收器（Garbage Collection），也叫 GC，垃圾回收器主要有以下特点：

1. GC 主要针对堆内存
2. 当对象不再被程序使用时，垃圾回收器将会将其回收
3. 垃圾回收是在后台运行的，我们无法命令垃圾回收器马上回收资源，但是我们可以告 诉他，尽快回收资源（System.gc 和 Runtime.getRuntime().gc() ）



## 2. String

String 类是不可变类，也就是说 String 对象声明后，将不可修改，如果对字 符串修改，那么将会创建新的对象

1. 注意：只要采用双引号赋值字符串，那么在编译期将会放到方法区中的字符串的常量池里,如果是运行时对字符串相加或相减 会放到堆中（放之前会先验证方法区中是否含有相同的字符串常量，如果存在，把地址返回，如果不存在，先将字符串常量放到池中，然后再返回该对象的地址）
2. 如果是采用双引号引起来的字符串常量，首先会到常量池中去查找，如果存在就不再分配， 如果不存在就分配，常量池中的数据是在编译期赋值的，也就是生成 class 文件时就把它 放到常量池里了，所以 s1 和 s2 都指向常量池中的同一个字符串“abc” 
3. 关于 s3，s3 采用的是 new 的方式，在 new 的时候存在双引号，所以他会到常量区中查找 “abc”，而常量区中存在“abc”，所以常量区中将不再放置字符串，而 new 关键子会在 堆中分配内存，所以在堆中会创建一个对象 abc，s3 会指向 abc 
4. 如果比较 s2 和 s3 的值必须采用 equals，String 已经对 eqauls 方法进行了覆盖

```java
String s1 = "abc";

String s2 = "abc";

String s3 = new String("abc");
```

![image-20211026224034887](https://gitee.com/xcxhalo/picgo/raw/master/Img/image-20211026224034887.png)

#### string 常用方法

1. endsWith：判断字符串是否以指定的后缀结束
2. startsWith，判断字符串是否以指定的前缀开始
3. equals，字符串相等比较，不忽略大小写
4. equalsIgnoreCase，字符串相等比较，忽略大小写
5. **indexOf**，取得指定字符在字符串的位置
6. lastIndexOf，返回最后一次字符串出现的位置
7. length，取得字符串的长度
8. **replaceAll**，替换字符串中指定的内容
9. split，根据指定的表达式拆分字符串
10. **substring**，截子串
11. **trim**,去前尾空格
12. valueOf，将其他类型转换成字符串



#### 注意：

#### 因为 String 是不可变对象，如果多个字符串进行拼接，将会形成多个对象，这样可能会造成内 存溢出，会给垃圾回收带来工作量



#### 正则表达式

```java
// 正则表达式（独立的学科），主要可以用来做字符串处理，可以描述特定的字符模式，如：”a{2}” 表示由两个字符“a”构成的字符串，等同于普通字符串“aa”，如”\d”代表任意一个数字 0~9， \D 代表所有的非数字，\w 代表所有的英文字母，\W 代表所有的非英文字母。
```



## 3. StringBuffer & StringBuilder

#### StringBuffer

StringBuffer 称为字符串缓冲区，它的工作原理是：预先申请一块内存，存放字符序列，如果 字符序列满了，会重新改变缓存区的大小，以容纳更多的字符序列。**StringBuffer 是可变对象， 这个是 String 最大的不同**

```java
StringBuffer sbStr = new StringBuffer();
//sbStr.append(i); 
//sbStr.append(",");
```



#### StringBuilder

用法同 StringBuffer，StringBuilder 和 StringBuffer 的区别是 StringBuffer 中所有的方法都是同 步的，是线程安全的，但速度慢，StringBuilder 的速度快，但不是线程安全的



## 基本类型对应的包装类

#### 包装类概述

基本类型的包装类主要提供了更多的实用操作，这样更容易处理基本类型。所有的包装类都是 final 的，所以不能创建其子类，包装类都是不可变对象

| 基本类型 | 包装类    |
| -------- | --------- |
| byte     | Byte      |
| short    | Short     |
| char     | Character |
| int      | Integer   |
| long     | Long      |
| float    | Float     |
| double   | Double    |
| boolean  | Boolean   |

```java
//除了 boolean 和 Character 外，其它的包装类都有 valueOf()和 parseXXX 方法，并且还具有 byteVaue(),shortVaue(),intValue(),longValue(),floatValue() 和 doubleValue()方法，这些方法是最 常用的方法
int i1 = 100; 
Integer i2 = new Integer(i1);
double i3 = i2.doubleValue();
String s = "123";
int i4 = Integer.parseInt(s);
Integer i5 = new Integer(s);
Integer i6 = Integer.valueOf(s);
```



#### 类层次结构

![image-20211028213734785](https://gitee.com/xcxhalo/picgo/raw/master/Img/image-20211028213734785.png)

#### 自动装箱和拆箱

jdk 5 之后支持自动拆箱和装箱

```java
//自动装箱 
Integer i2 = 100;
//自动拆箱 
int i3 = i2;
```





## 4. 日期类

#### java.util.Date

#### java.text.SimpleDateFormat

#### java.util.Calendar

```java
new Date()；
SimpleDate sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");

//格式化日期 
SimpleDateFormat sdf = SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
System.out.println(sdf.format(today));
Calendar c = Calendar.getInstance(); System.out.println(c.get(Calendar.DAY_OF_MONTH));
                 
//取得 2000-10-01 为星期几
Date d = new SimpleDateFormat("yyyy-MM-dd").parse("2000-10-01"); c.setTime(d); System.out.println(c.get(Calendar.DAY_OF_WEEK));
```



## 5. 数字类

#### java.text.DecimalFormat

#### java.math.BigDecimal

```java
// 加入千分位，保留两位小数 
DecimalFormat df = new DecimalFormat("###,###.##"); 
System.out.println(df.format(1234.23452));

// 加入千分位保留 4 位小数，不够补零 
System.out.println(new DecimalFormat("###,###.0000").format(12345.12));

// BigDecimal 可以精确计算，特别是财务数据
```

#### Random

```java
Random r = new Random();
```



## 6. Enum

为什么使用枚举

