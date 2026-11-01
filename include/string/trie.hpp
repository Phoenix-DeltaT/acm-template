/**
 * @file trie.hpp
 * @brief Trie 字典树模板
 * @author Phoenix-DeltaT
 * @date 2026
 */
#ifndef ACM_STRING_TRIE_HPP
#define ACM_STRING_TRIE_HPP

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Trie 字典树（支持小写字母）
 *
 * 功能：
 *   - 插入字符串：insert(word)
 *   - 查询是否存在：search(word)
 *   - 查询前缀：starts_with(prefix)
 *
 * @note 时间复杂度 O(L) 每次操作，L 为字符串长度
 * @note 空间复杂度 O(total_length)
 *
 * 用法：
 *   Trie trie;
 *   trie.insert("hello");
 *   trie.search("hello");   // true
 */
class Trie {
private:
    struct Node {
        Node *child[26];
        bool is_end;
        Node() : is_end(false) { fill(child, child + 26, nullptr); }
    };
    Node *root;

public:
    Trie() : root(new Node()) {}

    ~Trie() { clear(root); }

    /**
     * @brief 插入字符串
     * @param word 待插入的单词（小写字母）
     */
    void insert(const string &word) {
        Node *p = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!p->child[idx]) p->child[idx] = new Node();
            p = p->child[idx];
        }
        p->is_end = true;
    }

    /**
     * @brief 查询单词是否存在
     * @param word 待查询的单词
     * @return true 表示存在完整单词
     */
    bool search(const string &word) const {
        Node *p = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!p->child[idx]) return false;
            p = p->child[idx];
        }
        return p->is_end;
    }

    /**
     * @brief 查询是否有以 prefix 为前缀的单词
     */
    bool starts_with(const string &prefix) const {
        Node *p = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!p->child[idx]) return false;
            p = p->child[idx];
        }
        return true;
    }

private:
    void clear(Node *node) {
        if (!node) return;
        for (int i = 0; i < 26; ++i)
            clear(node->child[i]);
        delete node;
    }
};

#endif // ACM_STRING_TRIE_HPP
