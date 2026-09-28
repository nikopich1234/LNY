num = int(input())
nums = [int(item) for item in str(num)]
if len(nums) % 2 != 0:
    nums.insert(0,0)


def packed_format() -> list:
    packed_nums = []
    for i in range(len(nums)):
        convert_number = nums[i]
        temp = ""
        for j in range(4):
            if convert_number >= 2**(3-j):
                temp+="1"
                convert_number -= 2**(3-j)
            else:
                temp+="0"
        packed_nums.append(temp)
    return packed_nums

def not_packed_format() -> list:
    packed_nums = packed_format()
    not_packed_nums = []
    for i in range(len(packed_nums)):
        not_packed_nums.append("0011")
        not_packed_nums.append(packed_nums[i])
    return not_packed_nums
    
num = input()
nums = [item for item in num]

print("packed format:")
print(*packed_format())
print("not packed format:")
print(*not_packed_format())