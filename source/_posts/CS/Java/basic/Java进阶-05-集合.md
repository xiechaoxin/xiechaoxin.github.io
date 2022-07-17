---
title: Java进阶-05-集合
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

# 集合



## 1. 主要集合概述

### 集合继承结构图-Collection 

![image-20211030085503664](https://gitee.com/xcxhalo/picgo/raw/master/Img/image-20211030085503664.png)

### 集合继承结构图-Map

![image-20211030085549337](https://gitee.com/xcxhalo/picgo/raw/master/Img/image-20211030085549337.png)

### java 集合主要有三种重要的类型：

1. List：是一个**有序**集合，可以放**重复**的数据
2. Set：是一个**无序**集合，**不允许放重复的数据**
3. Map：是一个无序集合，集合中包含键值对，键对象不允许重复，值可以重复



### 遍历集合中的元素

```java
int[] arr = {432,4,65,46,54,76,54};

for(int data : arr) {
  // data就是数组中的元素（数组中的每一个元素。）
  System.out.println(data);
}
```

```java
// 创建List集合
List<String> strList = new ArrayList<>();

// 添加元素
strList.add("hello");
strList.add("world!");
strList.add("kitty!");

// 遍历，使用迭代器方式
Iterator<String> it = strList.iterator();
while(it.hasNext()){
  String s = it.next();
  System.out.println(s);
}

// 使用下标方式（只针对于有下标的集合）
for(int i = 0; i < strList.size(); i++){
  System.out.println(strList.get(i));
}

// 使用foreach
for(String s : strList){ // 因为泛型使用的是String类型，所以是：String s
  System.out.println(s);
}

List<Integer> list = new ArrayList<>();
list.add(100);
list.add(200);
list.add(300);
for(Integer i : list){ // i代表集合中的元素
  System.out.println(i);
}
```





## 2. collection & Iterator

### Collection 是 List 和 Set 的父接口，在 Collection 中定义了一些主要方法

| 返回类型    | 内容                                                         |
| ----------- | ------------------------------------------------------------ |
| boolean     | add (E o)确保此 collection 包含指定的元素（可选操作）。      |
| boolean     | addAll(Collection<? extends E>c)将指定 collection 中的所有元素都添加到此collection 中（可选操作）。 |
| void        | clear()移除此 collection 中的所有元素（可选操作）。          |
| boolean     | contains(Object o)如果此 collection 包含指定的元素，则返回 true 。 |
| boolean     | containsAll(Collection<?>c)如果此 collection 包含指定 collection 中的所有元素，则返回 true 。 |
| boolean     | equals(Object o)比较此 collection 与指定对象是否相等。       |
| int         | hashCode()返回此 collection 的哈希码值。                     |
| boolean     | isEmpty ()如果此 collection 不包含元素，则返回 true 。       |
| Iterator<E> | iterator()返回在此 collection 的元素上进行迭代的迭代器。     |
| boolean     | remove(Object o)从此 collection 中移除指定元素的单个实例，如果存在的话（可选操作）。 |
| boolean     | removeAll (Collection<?> c)移除此 collection 中那些也包含在指定 collection中的所有元素（可选操作）。 |
| boolean     | retainAll (Collection<?> c)仅保留此 collection 中那些也包含在指定collection 的元素（可选操作）。 |
| int         | size ()返回此 collection 中的元素数。                        |
| Object []   | toArray ()返回包含此 collection 中所有元素的数组。           |
| <T> T[]     | toArray (T[] a)返回包含此 collection 中所有元素的数组；返回数组的运行时类型与指定数组的运行时类型相同。 |



### Collection中能存放什么元素

没有使用“泛型”之前，Collection中可以存储Object的所有子类型。
使用了“泛型”之后，Collection中只能存储某个具体的类型。
集合后期我们会学习“泛型”语法。目前先不用管。Collection中什么都能存，
只要是Object的子类型就行。（集合中不能直接存储基本数据类型，也不能存
java对象，只是存储java对象的内存地址。）



### Iterator 接口说明

Iterator 称为迭代接口，通过此接口可以遍历集合中的数据，此接口主 要方法为：

| 返回值类型 | 内容                                           |
| ---------- | ---------------------------------------------- |
| boolean    | hasNext ()如果仍有元素可以迭代，则返回 true 。 |
| E          | next ()返回迭代的下一个元素。                  |





## 3. List

### 概述

**List 接口**下面主要有两个实现 **ArrayList** 和 **LinkedList**，他们都是有顺序的，也就是放进去 是什么顺序，取出来还是什么顺序，也就是基于线性存储，可以看作是一个**可变数组**

- ArrayList：查询数据比较快，添加和删除数据比较慢(基于可变数组)
- LinkedList：查询数据比较慢，添加和删除数据比较快（基于链表数据结构）
- （不用）Vector:Vector 已经不建议使用，Vector 中的方法都是同步的，效率慢，已经被 ArrayList 取代 
- （不用）Stack 是继承 Vector 实现了一个栈，栈结构是后进先出，目前已经被 LinkedList 取代



#### 3.1 - ArrayList

1. 默认初始化容量10（底层先创建了一个长度为0的数组，当添加第一个元素的时候，初始化容量10。）
2. 集合底层是一个Object[]数组。
3. 构造方法：
    new ArrayList();
    new ArrayList(20);
4. ArrayList集合的扩容：
    增长到原容量的1.5倍。
    ArrayList集合底层是数组，怎么优化？
        尽可能少的扩容。因为数组扩容效率比较低，建议在使用ArrayList集合
        的时候预估计元素的个数，给定一个初始化容量。
5. 数组优点：
    检索效率比较高。（每个元素占用空间大小相同，内存地址是连续的，知道首元素内存地址，
    然后知道下标，通过数学表达式计算出元素的内存地址，所以检索效率最高。）
6. 数组缺点：
    随机增删元素效率比较低。
    另外数组无法存储大数据量。（很难找到一块非常巨大的连续的内存空间。）
7. 向数组末尾添加元素，效率很高，不受影响。
8. 面试官经常问的一个问题？
    这么多的集合中，你用哪个集合最多？
        答：ArrayList集合。
        因为往数组末尾添加元素，效率不受影响。
        另外，我们检索/查找某个元素的操作比较多。

9. ArrayList集合是非线程安全的。（不是线程安全的集合。）

```java
// hashset 转换成 list
Collection c = new HashSet();

// 通过这个构造方法就可以将HashSet集合转换成List集合。
List myList3 = new ArrayList(c);
for(int i = 0; i < myList3.size(); i++){
  System.out.println(myList3.get(i));
}
```



#### 3.2 - LinkedList

同 ArrayList



## 4. Set

#### 1. 哈希表

哈希表是一种数据结构，哈希表能够提供快速存取操作。哈希表是基于数组的，所以也存 在缺点，数组一旦创建将不能扩展。

正常的数组，如果需要查询某个值，需要对数组进行遍历，只是一种线性查找，查找的速 度比较慢。如果数组中的元素值和下标能够存在明确的对应关系，那么通过数组元素的值就可 以换算出数据元素的下标，通过下标就可以快数定位数组元素，这样的数组就是哈希表。

#### 2. HashSet

HashSet 中的数据是无序的不可重复的。HashSet 按照哈希算法存取数据的，具有非常好性能， 它的工作原理是这样的，当向 HashSet 中插入数据的时候，他会调用对象的 hashCode 得到该 对象的哈希码，然后根据哈希码计算出该对象插入到集合中的位置。

```java
// 覆盖 HashCode
hashCode public int hashCode() { return (name==null)?0:name.hashCode(); }

// 覆盖 equal
equals public boolean equals(Object obj) {

  if (this == obj) { return true; } if (obj instanceof Person) {
    Person p = (Person)obj;
    return this.name.equals(p.name); } return false;
}
```

因为覆盖了 equals 和 hashCode ，当 hashCode 相同，它会调用 equals 进 行比较，如果 equals 比较相等将不加把此元素加入到 Set 中，但 equals 比较不相等会重新根据 hashCode 换算位置仍然会将该元素加入进去的。

**再次强调**：特别是向 HashSet 或 HashMap 中加入数据时必须同时覆盖 equals 和 hashCode 方 法， 应该养成一种习惯覆盖 equals 的同时最好同时覆盖 hashCode



java 要求：

1. 两个对象 equals 相等，那么它的 hashcode 相等
2. 两个对象 equals 不相等，那么它的 hashcode 并不要求它不相等，但一般建议不相等 hashcode 相等不代表两个对象相等（采用 equals 比较）

#### 3. TreeSet

TreeSet 可以对 Set 集合进行排序，默认自然排序（即升序），但也可以做客户化的排序

实现 Comparable 接口完成排序

#### Comparator 和 Comparable 的区别？

一个类实现了 Camparable 接口则表明这个类的对象之间是可以相互比较的，这个类对象组成 的集合就可以直接使用 sort 方法排序。

Comparator 可以看成一种算法的实现，将算法和数据分离，Comparator 也可以在下面两种环境 下使用：

1. 类的没有考虑到比较问题而没有实现 Comparable ，可以通过 Comparator 来实现排序而不必 改变对象本身
2. 可以使用多种排序标准，比如升序、降序等

```java
//Comparable 是默认的比较接口，Comparable 和需要比较的对象紧密结合到一起了 
//Comparator 可以分离比较规则，所以它更具灵活性
```





## 5. Map

Map 中可以放置**键值对**，也就是每一个元素都包含**键对象和值对象**，Map 实现较常用的为 HashMap，HashMap 对键对象的存取和 HashSet 一样，仍然采用的是**哈希算法**，所以**如果使用 自定类作为 Map 的键对象，必须复写 equals 和 hashCode 方法。**

### 1. HashMap

```java
// new 对象 
Map map = new HashMap();
// 新增
map.put("1001", "张三");
//采用 entrySet 遍历 Map
Set entrySet = map.entrySet();
for (Iterator iter=entrySet.iterator(); iter.hasNext();) {
  Map.Entry entry = (Map.Entry)iter.next();
  System.out.println(entry.getKey() + ", " + entry.getValue());
}
// 查询
Object v = map.get("1003");
```



### 2. HashMap 自定义类作为 key



### 3. HashMap，覆盖 IDcard 和 equals 方法



```java
public boolean equals(Object obj){

        if(obj==this){
        return true;
        }
        if(obj instanceof IdCard){

        IdCard idCard=(IdCard)obj;

        if(this.cardNo==idCard.cardNo){

        return true;

        }
        }return false;

        }
public int hashCode(){return new Long(cardNo).hashCode();}

```



### 4. TreeMap

treeMap 可以对 Map 中的 key 进行排序，如果 map 中的 key 采用的是自定类那么需要实现 Comaprable 或 Comparator 接口完成排序





## 6. Collections 工具类

Collections 位于 java.util 包中，提供了一系列实用的方法，如：对集合排序，对集合中的内容 查找等



## 7. Comparable 与 Comparator



## 8. 泛型

1. 什么是泛型：List<Animal> myList = new ArrayList<Animal>();

2. 泛型这种语法机制，只在程序编译阶段起作用，只是给编译器参考的。（运行阶段泛型没用！）

3. 泛型的好处

   1. 储存元素的类型统一了
   2. 集合中的元素取出不用做大量的 *向下转型* ，如果集合中的元素调用子类的方法还是需要向下转型的

4. 泛型的缺点

   1. 导致集合中存储的元素缺乏多样性！
   2. 大多数业务中，集合中元素的类型还是统一的。所以这种泛型特性被大家所认可。

5. 自定义泛型


```java
   自定义泛型可以吗？可以
       自定义泛型的时候，<> 尖括号中的是一个标识符，随便写。
       java源代码中经常出现的是：
           <E>和<T>
       E是Element单词首字母。
       T是Type单词首字母。
```



#### 自动类型推断机制。（又称为钻石表达式）

```java
List<String> strList = new ArrayList<>();// 类型不匹配。
strList.add(new Cat());
// 类型匹配
strList.add("http://www.126.com");

// 类型不匹配。
//strList.add(123);
```



## 9. 遗留类对比表（不建议使用）

| 遗留类      | 缺点                                    | 取代类                  |
| ----------- | --------------------------------------- | ----------------------- |
| Vector      | 方法都是同步的影响性 能                 | ArrayList 和 LinkedList |
| Hashtable   | 方法都是同步的影响性 能                 | HashMap                 |
| Stack       | 因为 Stack 继承了 Vector， 同样影响性能 | LinkedList              |
| Enumeration | 只能与历史集合使用                      | Iterator                |
