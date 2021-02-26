# 682. Baseball Game

#### You are keeping score for a baseball game with strange rules. 

#### At the beginning of the game, you start with an empty record. 

#### You are given a list of strings ops, where `ops[i]` is the ith operation you must apply to the record and is one of the following:

#### 1. An integer `x` - Record a new score of x.

#### 2. `"+"` - Record a new score that is the sum of the previous two scores. It is guaranteed there will always be two previous scores.

#### 3. `"D"` - Record a new score that is double the previous score. It is guaranteed there will always be a previous score.

#### 4. `"C"` - Invalidate the previous score, removing it from the record. It is guaranteed there will always be a previous score.

### Example 1:

```
Input: target = [1,3], n = 3
Output: ["Push","Push","Pop","Push"]
Explanation: 
Read number 1 and automatically push in the array -> [1]
Read number 2 and automatically push in the array then Pop it -> [1]
Read number 3 and automatically push in the array -> [1,3]
```
### Example 2:

```
Input: target = [1,2,3], n = 3
Output: ["Push","Push","Push"]
```

### Example 3:

```
Input: target = [1,2], n = 4
Output: ["Push","Push"]
Explanation: You only need to read the first 2 numbers and stop.
```
### Example 4:

```
Input: target = [2,3,4], n = 4
Output: ["Push","Pop","Push","Push","Push"]
```

### Constraints:
```
1 <= target.length <= 100
1 <= target[i] <= n
1 <= n <= 100
target is strictly increasing.
```
