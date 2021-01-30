#852. Peak Index in a Mountain Array

###Let's call an array arr a mountain if the following properties hold:

```
:small_blue_diamond: arr.length >= 3

:small_blue_diamond: There exists some i with 0 < i < arr.length - 1 such that:

        :small_orange_diamond: arr[0] < arr[1] < ... arr[i-1] < arr[i]

        :small_orange_diamond: arr[i] > arr[i+1] > ... > arr[arr.length - 1]

```

Given an integer array arr that is guaranteed to be a mountain, return any i such that:
```
arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].
```