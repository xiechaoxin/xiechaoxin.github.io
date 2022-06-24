---
title: mybatis_plus笔记
category: 
  - Java
  - frame_work
  - mybatis_plus
tags:
  - Java
  - frame_work
  - mybatis_plus
date: 2022-06-17 17:59:13
---

# MyBatisPlus

[toc]

官网:https://baomidou.com/，简化 MyBatis !



## 1. 特性

* **无侵入**:只做增强不做改变，引入它不会对现有工程产生影响，如丝般顺滑
* **损耗小**:启动即会自动注入基本 CURD，性能基本无损耗，直接面向对象操作， BaseMapper 
* **强大的** **CRUD** **操作**:内置通用 Mapper、通用 Service，仅仅通过少量配置即可实现单表大部分 CRUD 操作，更有强大的条件构造器，满足各类使用需求, 以后简单的CRUD操作，它不用自己编写 了!
* **支持** **Lambda** **形式调用**:通过 Lambda 表达式，方便的编写各类查询条件，无需再担心字段写错
* **支持主键自动生成**:支持多达 4 种主键策略(内含分布式唯一 ID 生成器 - Sequence)，可自由配 置，完美解决主键问题
* **支持** **ActiveRecord** **模式**:支持 ActiveRecord 形式调用，实体类只需继承 Model 类即可进行强大 的 CRUD 操作
* **支持自定义全局通用操作**:支持全局通用方法注入( Write once, use anywhere )
* **内置代码生成器**:采用代码或者 Maven 插件可快速生成 Mapper 、 Model 、 Service 、 Controller 层代码，支持模板引擎，更有超多自定义配置等您来使用(自动帮你生成代码)
* **内置分页插件**:基于 MyBatis 物理分页，开发者无需关心具体操作，配置好插件之后，写分页等同 于普通 List 查询
* **分页插件支持多种数据库**:支持 MySQL、MariaDB、Oracle、DB2、H2、HSQL、SQLite、 Postgre、SQLServer 等多种数据库
* **内置性能分析插件**:可输出 Sql 语句以及其执行时间，建议开发测试时启用该功能，能快速揪出慢 查询
* **内置全局拦截插件**:提供全表 delete 、 update 操作智能分析阻断，也可自定义拦截规则，预防误 操作



## 2. **快速入门**

地址:https://mp.baomidou.com/guide/quick-start.html

说明:尽量不要同时导入 mybatis 和 mybatis- plus!版本的差异!



## 3. **CRUD**扩展

#### **自动填充**

创建时间、修改时间!这些个操作一遍都是自动化完成的，我们不希望手动更新!

阿里巴巴开发手册:所有的数据库表:gmt_create、gmt_modified几乎所有的表都要配置上!而且需要自动化!



#### **乐观锁**&**悲观锁**

**乐观锁** : 故名思意十分乐观，它总是认为不会出现问题，无论干什么不去上锁!如果出现了问题， 再次更新值测试,一般是添加version字段,然后提交事务时,检查是否字段值相同

**悲观锁**:故名思意十分悲观，它总是认为总是出现问题，无论干什么都会上锁!再去操作!





#### **分页查询**

原始limit

常用pageHelper

MP 其实内置了分页插件

**MP如何进行数据分页**

(1) 配置拦截器组件

```java
// 分页插件
@Bean
public PaginationInterceptor paginationInterceptor() {
    return  new PaginationInterceptor();
}
```

(2) 直接使用Page对象

```java
// 测试分页查询
@Test
public void testPage() {
    // 参数一:当前页
    // 参数二:页面大小
    // 使用了分页插件之后，所有的分页操作也变得简单的! Page<User> page = new Page<>(2,5); userMapper.selectPage(page,null);
    page.getRecords().forEach(System.out::println);
    System.out.println(page.getTotal());
}
```



#### 通过map删除

```java
// 通过map删除
@Test
public void testDeleteMap() {
    HashMap<String, Object> map = new HashMap<>();
    map.put("name", "张三");
    userMapper.deleteByMap(map);
}
```

#### **逻辑删除**

1、在数据表中增加一个 deleted 字段

2、实体类中增加属性

```java
 @TableLogic //逻辑删除 
 private Integer deleted;
```

3、配置

```java
// 逻辑删除组件!
@Bean
public ISqlInjector sqlInjector() {
    return new LogicSqlInjector();
}
```

```yaml
   # 配置逻辑删除 
    mybatis-plus.global-config.db-config.logic-delete-value=1
    mybatis-plus.global-config.db-config.logic-not-delete-value=0
```

测试结果发现,实际是更新操作,而不是删除操作



## 4. 条件构造器

我们写一些复杂的sql就可以使用它来替代

[条件构造器 | MyBatis-Plus (baomidou.com)](https://baomidou.com/pages/10c804/#alleq)



## 5. 代码自动生成器

dao、pojo、service、controller 自己写,其实有其它工具可以生成,比如人人开源gitee

AutoGenerator 是 MyBatis-Plus 的代码生成器，通过 AutoGenerator 可以快速生成 Entity、Mapper、Mapper XML、Service、Controller 等各个模块的代码，极大的提升了开发效率



[代码生成器（新） | MyBatis-Plus (baomidou.com)](https://baomidou.com/pages/779a6e/)

适用版本：mybatis-plus-generator 3.5.1 及其以上版本，对历史版本不兼容！



```java
FastAutoGenerator.create("url", "username", "password")
        .globalConfig(builder -> {
            builder.author("baomidou") // 设置作者
                    .enableSwagger() // 开启 swagger 模式
                    .fileOverride() // 覆盖已生成文件
                    .outputDir("D://"); // 指定输出目录
        })
        .packageConfig(builder -> {
            builder.parent("com.baomidou.mybatisplus.samples.generator") // 设置父包名
                    .moduleName("system") // 设置父包模块名
                    .pathInfo(Collections.singletonMap(OutputFile.mapperXml, "D://")); // 设置mapperXml生成路径
        })
        .strategyConfig(builder -> {
            builder.addInclude("t_simple") // 设置需要生成的表名
                    .addTablePrefix("t_", "c_"); // 设置过滤表前缀
        })
        .templateEngine(new FreemarkerTemplateEngine()) // 使用Freemarker引擎模板，默认的是Velocity引擎模板
        .execute();
```
