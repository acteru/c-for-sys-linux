# Iteration pattern
solution for iteration pattern in python:

```python
list = [1,2,3]
iter = list.__iter__()
iter.__next__()
```

## List comprehension examples
## even numbers
```python
numbers = [1,2,3,4,5]
numbers_again = [n for n in numbers]
even_numbers = [n for n in numbers if n%2 == 0]
even_numbers
```

### squared odd numbers
```python
numbers = [1,2,3,4,5]
odd_squares = [n**2 for n in numbers if n%2 == 1]
```

### flatten a matrix
``` python
matrix = [[1,2,3], [4,5,6], [7,8,9]]
flat = [n for row in matrix for n in row]
flat
```
