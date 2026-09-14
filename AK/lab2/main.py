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

temp_int = int(int_part)
if temp_int == 0:
    res = "0"
else:
    while temp_int > 0:
        res+=str(temp_int % 4)
        temp_int //= 4
    res = res[::-1]

res+="."

temp_float = float_part

for _ in range(10):
    if temp_float == 0:
        break
    else:
        temp_float *= 4
        temp = int(temp_float)
        res += str(temp)
        temp_float -= temp

print("quaternary: ", res)