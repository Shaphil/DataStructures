# Arrays

Array is a Data Structure where data elements reside in a contiguous block of memory. That memory chunk is divided into several pieces of smaller chunks of the same size. For example in the C programming language, `char` arrays are divided into 1 byte elements. Whereas elements of an `int` array are of 4 bytes in size. Almost all the programming languages has a built in Array data structure. I said almost because there are languages that doesn't have that structure built-in, like Assembly for example or even Python. Python makes that up by providing a far more powerful built in called `list` which can do all the things that makes an structure an array and more.

> More discussion with some code examples

# HackerRank

This section is for the Array problems in HackerRank.


## 01. Array - DS

The first problem is reversing an array. This can be done in many ways.

For `C/C++` based languages it could be as simple as printing the array from the opposite direction. For languages like Python there are built-in methods for reversing the array (or list which we will treat like an array).

**Arrays - DS** - [https://www.hackerrank.com/challenges/arrays-ds/problem](https://www.hackerrank.com/challenges/arrays-ds/problem)

### C Solution
```c
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i; 
    scanf("%d",&n);
    int *arr = malloc(sizeof(int) * n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       scanf("%d",&arr[arr_i]);
    }
    
    for(i = n - 1; i >= 0; i--)
        printf("%d ", arr[i]);
    
    return 0;
}
```

### Python Solution - 01
```python
#!/bin/python3

n = int(input())
a = list(input().split())
rev = ' '.join(list(reversed(a)))
print(rev)
```

The HackerRank editor provides some boilerplate code for you, so that you can focus on the problem without being worried about handling I/O. The boilerplate is provided below, you are just expected to complete the function `reverseArray`.

### Python Boilerplate
```python
#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the reverseArray function below.
def reverseArray(a):
    pass

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr_count = int(input())

    arr = list(map(int, input().rstrip().split()))

    res = reverseArray(arr)

    fptr.write(' '.join(map(str, res)))
    fptr.write('\n')

    fptr.close()
```

### Python Solution - 02
```python
def reverseArray(a):
    return a[::-1]
```

### Python Solution - 03
```python
def reverseArray(a):
    a.reverse()
    return a
```

### Python Solution - 03
```python
def reverseArray(a):
    return list(reversed(a))
```
