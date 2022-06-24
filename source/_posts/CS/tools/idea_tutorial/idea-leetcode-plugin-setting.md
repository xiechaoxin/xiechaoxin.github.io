---
title: idea-leetcode-plugin-setting
category: 
  - tools
  - idea_tutorial
tags:
  - tools
  - idea_tutorial
date: 2022-06-17 17:59:12
---

在idea 中使用leetcode插件刷题

## 效果图

![image-20220529124915505](idea-leetcode-plugin-setting/image-20220529124915505.png)



## 设置

![image-20220529124952581](idea-leetcode-plugin-setting/image-20220529124952581.png)



codeName:

```
P${question.frontendQuestionId}_$!velocityTool.camelCaseName(${question.titleSlug})
```

codeTemplate:

```
${question.content}

package leetcode.editor.cn;
/**
 * NO.${question.frontendQuestionId}
 * Title: ${question.titleSlug}(${question.title})
 * create time: $!velocityTool.date()
 * update time: $!velocityTool.date()
 */
public class P${question.frontendQuestionId}_$!velocityTool.camelCaseName(${question.titleSlug}) {
    public static void main(String[] args) {
        // test case

        Solution solution = new P${question.frontendQuestionId}_$!velocityTool.camelCaseName(${question.titleSlug})().new Solution();
        // solution.$!velocityTool.smallCamelCaseName(${question.titleSlug})();
        // TO TEST
    }
${question.code}
}
```

