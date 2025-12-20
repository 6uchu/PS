n = int(input())
nums = list(map(int, input().split(' ')))
x = int(input())

cnt = 0
nodu = set(nums)

for num in nums:
    if x - num in nodu:
        cnt += 1
        
if x % 2 == 0 and x / 2 in nodu:
    cnt -= 1

cnt /= 2

print(int(cnt))