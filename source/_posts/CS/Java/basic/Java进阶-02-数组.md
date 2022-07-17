---
title: Java进阶-02-数组
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

# 数组

## 1. 数组概要

1. 数组是一种引用数据类型
2. 数组中的元素可以是基本数据类型,或者引用数据类型,但同一个数组必须是同一种类型
3. length 属性,长度在数组对象创建后就无法再更改

## 一维数组

### 数组声明

```java
int[] a;
Student[] stu;
```

### 数组的创建和赋值

1. 使用 new 操作符来创建数组，格式为：new 数组元素的数据类型[数组元素的个数]

```java
基本数据类型数组
int[] a = new int[5]
a[0] = 1;
a[1] = 2;

引用数据类型
Student[] student = new student[5];
student[0].id = 1001;
student[1].name = '张三';
注意这里可能出现空指针异常
```

2. 使用数组的初始化语句，格式为：数组元素的类型[] 变量名称 = {数组元素 1， 数组元素 2,......数组元素 n}或数组元素的类型 变量名称[] = {数组元素 1，数组元素 2,...... 数组元素 n}

```java
基本数据类型
int[] a = {
  1,
  2,
  2,
  2,
  2,
};
// 这里还需要掌握 for 和 while 循环

引用数据类型
Student[] student = {
  'zhangsan','lisi'
}
```



### 内存结构

![image-20211025210844899](https://gitee.com/xcxhalo/picgo/raw/master/Img/image-20211025210844899.png)

## 2. 二维数组

### 声明

```java
// 当数组元素的类型是数组时就成了多维数组
1. 数组元素的数据类型[][] 变量名；
2. 数组元素的数据类型 变量名[][]；
```

### 数组的创建和赋值

```java
1.采用 new 关键字直接创建
基本数据类型
int[][] data = new int[2][3];
data[0][0] = 1;

2.从高维开始逐维创建
  //从高维开始逐维创建 
  int[][] data = new int[2][];
	data[0] = new int[2];
	data[1] = new int[4];

3.采用初始化语句块创建数组对象
  int[][] data = {{1,2},{1,2,3,4}};

//这里还要掌握 for 和 while 嵌套遍历数组
```

### 内存结构

![image-20211025214221358](https://gitee.com/xcxhalo/picgo/raw/master/Img/image-20211025214221358.png)



## 3. 数组的排序

1. 冒泡排序
2. 选择排序



## 4. 数组的搜索

1. 二分法(折半法)
   - 查找数组中的元素我们可以遍历数组中的所有元素，这种方式称为线性查找。
2. 慢慢再补充一些数据结构和算法的知识



## 5. Arrays 工具类

了解 jdk 中的 Array 工具类的使用

1. sort

   ```java
   Arrays.sort(data);
   ```

   

2. fill

3. binarySearch

4. ```java
   int index = Arrays.binarySearch(data, 3);
   ```



// 版权说明:以下笔记出自*动力节点*

day23课堂笔记

## 1、数组

### 1.1、数组的优点和缺点，并且要理解为什么。

第一：空间存储上，内存地址是连续的。

第二：每个元素占用的空间大小相同。

第三：知道首元素的内存地址。

第四：通过下标可以计算出偏移量。

通过一个数学表达式，就可以快速计算出某个下标位置上元素的内存地址，

直接通过内存地址定位，效率非常高。

优点：检索效率高。

缺点：随机增删效率较低，数组无法存储大数据量。

注意：数组最后一个元素的增删效率不受影响。

### 1.2、一维数组的静态初始化和动态初始化

静态初始化：

```java
int[] arr = {1,2,3,4};

Object[] objs = {new Object(), new Object(), new Object()};
```

动态初始化：

```java
int[] arr = new int[4]; // 4个长度，每个元素默认值0

Object[] objs = new Object[4]; // 4个长度，每个元素默认值null
```



### 1.3、一维数组的遍历

```java
for(int i = 0; i < arr.length; i++){

System.out.println(arr[i]);

}
```

### 1.4、二维数组的静态初始化和动态初始化

静态初始化：

```java
int[][] arr = {

{1,2,34},

{54,4,34,3},

{2,34,4,5}

};

Object[][] arr = {

{new Object(),new Object()},

{new Object(),new Object()},

{new Object(),new Object(),new Object()}

};


```

动态初始化：

```java
int[][] arr = new int[3][4];

Object[][] arr = new Object[4][4];

Animal[][] arr = new Animal[3][4];

// Person类型数组，里面可以存储Person类型对象，以及Person类型的子类型都可以。

Person[][] arr = new Person[2][2];

....
```

### 1.5、二维数组的遍历

```java
for(int i = 0; i < arr.length; i++){ // 外层for循环负责遍历外面的一维数组。

// 里面这个for循环负责遍历二维数组里面的一维数组。

for(int j = 0; j < arr[i].length; j++){

System.out.print(arr[i][j]);

}

// 换行。

System.out.println();

}
```

### 1.6、main方法上“String[] args”参数的使用（非重点，了解一下，以后一般都是有界面的，用户可以在界面上输入用户名和密码等参数信息。）

### 1.7、数组的拷贝：System.arraycopy()方法的使用

数组有一个特点：长度一旦确定，不可变。

所以数组长度不够的时候，需要扩容，扩容的机制是：新建一个大数组，

将小数组中的数据拷贝到大数组，然后小数组对象被垃圾回收。

### 1.8、对数组中存储引用数据类型的情况，要会画它的内存结构图。













