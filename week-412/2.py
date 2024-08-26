def countAlmostEqualPairs(nums):
    def equal(x, y):
        if x == y:
            return True
        
        x_str, y_str = str(x), str(y)
        
        # 处理前导零的情况
        if len(x_str) < len(y_str):
            x_str = '0' * (len(y_str) - len(x_str)) + x_str
        elif len(y_str) < len(x_str):
            y_str = '0' * (len(x_str) - len(y_str)) + y_str
        
        return check(x_str, y_str) or check(y_str, x_str)

    def check(source, target):
        if len(source) != len(target):
            return False
        
        diff = []
        for i in range(len(source)):
            if source[i] != target[i]:
                diff.append(i)
        
        if len(diff) != 2:
            return False
        
        i, j = diff
        return source[i] == target[j] and source[j] == target[i]

    count = 0
    n = len(nums)
    
    for i in range(n):
        for j in range(i + 1, n):
            if equal(nums[i], nums[j]):
                count += 1
    
    return count
print(countAlmostEqualPairs([3, 12, 30, 17, 21]))
print(countAlmostEqualPairs([1, 1, 1, 1, 1]))
print(countAlmostEqualPairs([123, 231]))
print(countAlmostEqualPairs([456,654]))