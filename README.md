# Ternary search tree(TST)
## Introduction
`三元树`(Ternary tree)本质上是一种类似`BST`的三叉树，搜索性能与`BST`接近，同时由于单个节点仅保存单个字符，相比`Trie`树占用空间也更少。从各个方面来说，`TST`是提供`前缀查找`(prefix searching)的一个不错的数据结构。

该数据结构是我意图为CLI程序提供自动补全而编写的。

由于只有一个头文件和源文件，因此引入项目十分轻便。

## Tree structure
`TST`的结点结构：
```c
typedef struct _TernaryNode {
  char c;                       /* character */
  bool store;                   /* store the string in the mid */
  struct _TernaryNode *left;    /* lower than the c */
  struct _TernaryNode *mid;     /* equal to the c */
  struct _TernaryNode *right;   /* higher than the c */
} TernaryNode;
```

## Add a string
根据比较结果得到一个**空槽(empty slot)**，以该槽为根节点构筑以`mid`为直线的树，`left`和`right`对于该字符串而言仅起引导作用。

比较特别地，在最后一个结点的`mid`中存储字符串本身，避免拼接的开销，简化查询操作。

为了支持这一点，包括插入的字符串是已存在字符串的前缀部分也能够实现该特性，最后一个结点并不是字符串的最后一个字符，而是单独的一个特殊结点(sentinel)，从而有多余的`mid`供存储。

而该存储方式有两种：存储在结点内部，存储在结点外部。
```c
ternary_add(&root, "xxxxxx", false);
ternary_add(&root, argv[0], false);

char *arr = { "xxxxxx" };
ternary_add(&root, arr[0], true);
```
不过是否存储在结点内部还是得根据实际场景。

```
Add: stradd, strget, strset, str
                        s
                        |
                        t
                        |
                        r
                      / |
                     0  a 
                     |  |    \
                   str  d     g
                        |     |    \
                        d     e     s
                        |     |     |
                        0     t     e
                        |     |     |
                      stradd strget t
                                    |
                                  strset
```

## Search prefix
`TST`是一种适合于`前缀查找`的数据结构，也提供了对应的API：
```c
/* 对匹配的字符串调用callback
 * e.g. print, store to another place
 */
ternary_search_prefix(root, prefix-str, callback);

/* num指定了处理的匹配字符串最大数目
 * 如果匹配数 >= num，只会调用num
 * 匹配数 < num，调用的仅是匹配数
 */
ternary_search_prefix(root, prefix-str, callback, num);
```
