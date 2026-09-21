from typing import List


def reverse_list(arr: List[int]) -> List[int]:
    stack = []
    for i in arr:
        stack.append(i)
    
    l = []
    while len(stack) > 0:
        l.append(stack.pop())
    
    return l


# do not modify below this line
print(reverse_list([1, 2, 3]))
print(reverse_list([3, 2, 1, 4, 6, 2]))
print(reverse_list([1, 9, 7, 3, 2, 1, 4, 6, 2]))
