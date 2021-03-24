# 856. Score of Parentheses

#### Given a balanced parentheses string `S`, compute the score of the string based on the following rule:

####    1: `()` has score 1

####    2: `AB` has score `A + B`, where `A` and `B` are balanced parentheses strings.

####    3: `(A)` has score `2 * A`, where `A` is a balanced parentheses string.

### Example 1:

```
Input: "()"
Output: 1
```

### Example 2:

```
Input: "(())"
Output: 2
```

### Example 3:

```
Input: "()()"
Output: 2
```

### Example 4:

```
Input: "(()(()))"
Output: 6
```

### Note:
```
S is a balanced parentheses string, containing only ( and ).
2 <= S.length <= 50
```
