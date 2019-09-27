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

## 02. 2D Array - DS

This is rather a simulation problem. You are given the problem and told what to do. You just have to translate that into code.

Read the problem statement here - [https://www.hackerrank.com/challenges/2d-array/problem](https://www.hackerrank.com/challenges/2d-array/problem)

I made two submissions. Both are practically the same except for one is in C and the other is in Python. I would have done the Python solution exactly the same way as the C solution. But in the editorial I saw this Python solution which uses List slicing. The code looks better. Look at the first three lines of the second `for` loop of both the code solutions and you'll see the difference. Also having separate variables for storing the `top`, `mid` and the `bottom` sum of the hourglass instead of doing a `+=` directly to the `_sum` variable allows you to not have to worry about setting `_sum = 0` at the end of the loop, which I had to do in the C code. I often forget doing that.

### C Solution

```c
#include <stdio.h>

int main()
{
	// freopen("2d_array.txt", "r", stdin);

	int a[6][6];
	int i, j;
	int sum, highest;

	sum = 0;
	highest = -2147483648;

	for(i = 0; i < 6; i++)
		for(j = 0; j < 6; j++)
			scanf("%d", &a[i][j]);



	for(i = 0; i < 4; i++) {
		for(j = 0; j < 4; j++) {
			sum += ( a[i][j] + a[i][j + 1] + a[i][j + 2] ) ;
			sum += a[i + 1][j + 1];
			sum += ( a[i + 2][j] + a[i + 2][j + 1] + a[i + 2][j + 2] );

			if(sum > highest)
				highest = sum;

			sum = 0;
		}
	}

	printf("%d\n", highest);

	return 0;
}
```

### Python Solution

The solution is in the `hourglassSum` function. Don't be bothered by the other parts of the code, they're there just to handle the IO.

```python
#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the hourglassSum function below.
def hourglassSum(arr):
    _sum = 0
    highest = -2147483647

    for i in range(4):
        for j in range(4):
            top = sum(arr[i][j : j + 3])
            mid = arr[i + 1][j + 1]
            bottom = sum(arr[i + 2][j : j + 3])

            _sum = top + mid + bottom

            if _sum > highest:
                highest = _sum

    return highest

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr = []

    for _ in range(6):
        arr.append(list(map(int, input().rstrip().split())))

    result = hourglassSum(arr)

    fptr.write(str(result) + '\n')
```
