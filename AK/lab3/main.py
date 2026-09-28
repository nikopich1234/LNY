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

print("packed format:")
print(*packed_format())
print("not packed format:")
print(*not_packed_format())

num = input()
nums = [item for item in num]

def forward_format() -> str:
    res = ""
    if num[0] == "-":
        res+="1."
        number = int(num[1:])
    else:
        res+="0."
        number = int(num)

    if number == 0:
        return res+"0000000"



    else:
        for i in range(7):
            power = 6-i
            if number >= 2**power:
                res+="1"
                number-=2**power
            else:
                res+="0"
    return res

def reversed_format() -> str:
    forward = forward_format()
    if int(num) >= 0:
        return forward
    else:
        reversed = forward[:2]
        for i in range(2,len(forward)):
            if forward[i] == "1":
                reversed += "0"
            else:
                reversed += "1"
    return reversed

def additional_format() -> str:
    reversed = reversed_format()
    if int(num) >= 0:
        return reversed
    else:
        additional = reversed[:8]
        additional+="1"
    return additional


print(forward_format())
print(reversed_format())
print(additional_format())