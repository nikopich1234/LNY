user_input = input()

if "." not in user_input:
    user_input+=".0"
nums = user_input.split(".")

def bin_float(nums: list, accurancy: int = 0) -> str:
    int_res = ""
    if "-" in nums[0]:
        int_res+="1"
    else:
        int_res+="0"
    int_part = abs(int(nums[0]))
    while int_part > 0:
        int_res+=f"{int_part%2}"
        int_part//=2
    int_res = int_res[0]+int_res[1:][::-1]

    float_part = float(f"0.{nums[1]}")
    float_res = ""
    for _ in range(accurancy):
        if float_part == 0:
            break
        float_part *= 2
        float_res+=f"{int(float_part)}"
        float_part -= int(float_part)

    bias = (2**8)-1+len(int_res)-2
    bias_res = ""
    while bias > 0:
        bias_res += f"{bias%2}"
        bias//=2
    bias_res = bias_res[::-1]

    zeros = "0" * (80-len(bias_res)-len(int_res)-len(float_res))

    return f"{int_res[0]} {bias_res} {int_res[1:]} {float_res} {zeros}"

def packed_format(nums: list) -> str:
    int_part = abs(int(nums[0]))
    float_part = float(f"0.{nums[1]}")

    int_res = ""
    float_res = ""

    while int_part > 0:
        int_res += f"{int_part%2}"
        int_part//=2
    int_res = int_res[::-1]
    for i in range(4):
        float_part*=2
        float_res+=f"{int(float_part)}"
        float_part-= int(float_part)

    return f"{int_res} , {float_res}"

def not_packed_format(nums: list) -> str:
    int_part = abs(int(nums[0]))
    float_part = float(f"0.{nums[1]}")

    int_res = ""
    float_res = ""

    while int_part > 0:
        int_res+=f"{int_part%2}"
        int_part//=2
    int_res = int_res[::-1]
    for i in range(4):
        float_part*=2
        float_res+=f"{int(float_part)}"
        float_part -= int(float_part)

    return f"0011 {int_res},0011 {float_res}"

def forward_format(nums: list) -> str:
    int_part = abs(int(nums[0]))
    float_part = float(f"0.{nums[1]}")

    res = ""

    if(int(nums[0]) < 0):
        res+="1 "
    else:
        res+="0 "

    while int_part > 0:
        res+=f"{int_part%2}"
        int_part//=2
    res = res[0:2]+res[2:][::-1]
    res+=","
    for i in range(4):
        float_part*=2
        res+=f"{int(float_part)}"
        float_part -= int(float_part)

    return res

def reversed_format(nums: list) -> str:
    fwd = forward_format(nums)
    res = ""
    if fwd[0] == "1":
        for i in range(len(fwd)):
            if fwd[i] == "0":
                res+="1"
            elif fwd[i] == "1":
                res+="0"
            elif fwd[i] == ",":
                res+=","
            else:
                res+=" "
        return res
    return fwd

def additional_format(nums: list) -> str:
    fwd = reversed_format(nums)
    res = ""
    if fwd[0] == "1":
        res = fwd[:(len(fwd)-1)] + "1"
        return res
    return fwd

def modified_forward_format(nums: list) -> str:
    fwd = forward_format(nums)
    return fwd[0] + fwd

def modified_reversed_format(nums: list) -> str:
    fwd = reversed_format(nums)
    return fwd[0] + fwd

def modified_additional_format(nums: list) -> str:
    fwd = additional_format(nums)
    return fwd[0] + fwd


print(bin_float(nums, 3))
print(packed_format(nums))
print(not_packed_format(nums))
print(forward_format(nums))
print(reversed_format(nums))
print(additional_format(nums))
print(modified_forward_format(nums))
print(modified_reversed_format(nums))
print(modified_additional_format(nums))