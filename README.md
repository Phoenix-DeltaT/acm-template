# ACM Template

> ACM-ICPC 竞赛常用可复用 C++ 代码模板库

## 目录结构

```
.
├── include/
│   ├── math/          # 数学：数论、组合数学
│   ├── ds/            # 数据结构：线段树、树状数组、并查集
│   ├── graph/         # 图论：最短路、最小生成树
│   ├── string/        # 字符串：KMP、Trie
│   └── utils/         # 工具：快速 IO、调试
└── README.md
```

## 使用方式

直接 `#include` 对应头文件即可，所有模板均为模板类/函数，无需额外编译。

```cpp
#include "include/ds/segment_tree.hpp"

int main() {
    SegmentTree<int> st(n);
    // ...
}
```

## 约定

- 所有模板默认使用 `long long` 作为数值类型，避免溢出
- 下标从 1 开始（符合竞赛习惯）
- 每个类/方法均有完整注释说明时间复杂度与适用场景
