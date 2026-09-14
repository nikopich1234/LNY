l = input().split(".")
res = 0
int_part = l[0]

if len(l) > 1:
    float_part = l[1]

else:
    float_part = ""

n1 = len(int_part)
n2 = len(float_part)

#int part
for i in range(n1):
    if int_part[i] == "1":
        res+= 2**(n1-i-1)

# float part
for i in range(n2):
    if float_part[i] == "1":
        res += 2**(-(i+1))
print("decimal: ",res)

float_part = res%1
int_part = res-float_part

#------------------------------------------------------#

res = ""

#quaternary int part
temp_int = int(int_part)
if temp_int == 0:
    res = "0"
else:
    while temp_int > 0:
        res+=str(temp_int % 4)
        temp_int //= 4
    res = res[::-1]

temp_float = float_part

#quaternary float part till 10-th number
if temp_float > 0:
    res+="."
    for _ in range(10):
        if temp_float == 0:
            break
        else:
            temp_float *= 4
            temp = int(temp_float)
            res += str(temp)
            temp_float -= temp

print("quaternary: ", res)

#------------------------------------------------------#

quat_num = res.split(".")
res = 0

int_part = quat_num[0]
if len(quat_num) > 1:
    float_part = quat_num[1]
else:
    float_part = ""

for i in range(len(int_part)):
    res += int(int_part[i]) * 4**(len(int_part)-i-1)

for i in range(len(float_part)):
    res += int(float_part[i]) / 4 **(i+1)

print("decimal from quaternary:", res)

#------------------------------------------------------#

temp = str(res).split(".")
res = ""

int_part = int(temp[0])

if len(temp) > 1:
    float_part = temp[1]
else:
    float_part = ""

if int_part == 0:
    res = "0"
else:
    while int_part > 0:
        res+= str(int_part % 2)
        int_part //= 2
    res = res[::-1]

if float_part:
    res+=   "."
    float_part = float("0." + float_part)
    for _ in range(10):
        if float_part == 0:
            break
        float_part *= 2
        temp = int(float_part)
        res+=str(temp)
        float_part -= temp
print("binary from decimal", res)