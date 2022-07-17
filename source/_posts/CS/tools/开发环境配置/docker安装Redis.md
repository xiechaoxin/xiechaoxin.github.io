---
title: docker安装Redis
category: 
  - tools
  - 开发环境配置
tags:
  - tools
date: 2022-07-16 02:51:55
---





## docker安装Redis

~~~shell
docker create --name redis-server -p 6399:6379 --restart=always -v redis-server-data:/data redis:5.0.2 --appendonly yes

docker start redis-server

#进入容器进行测试
docker exec -it redis-server /bin/bash

#测试
root@0bd11c170b43:/data# redis-cli 
127.0.0.1:6379> set abc 123
OK
127.0.0.1:6379> get abc
"123"
127.0.0.1:6379> del abc
~~~

