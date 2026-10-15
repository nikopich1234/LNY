user_input = input()

if "." not in user_input:
  user_input += ".0"
nums = user_input.split(".")


def bin_float(nums: list, accuracy: int = 0) -> str:
  int_part = int(nums[0])

  if int_part >= 0:
    int_res = "0."
  else:
    int_res = "1."
    int_part = abs(int_part)

  if int_part == 0:
    int_res += "0"
  else:
    temp_int = ""
    while int_part > 0:
      temp_int += str(int_part % 2)
      int_part //= 2
    int_res += temp_int[::-1]

  float_res = ""
  if len(nums) < 2 or nums[1] == "" or int(nums[1]) == 0:
    float_part = 0.0
  else:
    float_part = float(f"0.{nums[1]}")

  for _ in range(accuracy):
    float_part *= 2
    bit = int(float_part)
    float_res += str(bit)
    float_part -= bit

  # Видаляємо крапку для розрахунку біасу
  pure_int_bits = int_res.replace(".", "")
  bits = max(0, len(pure_int_bits) - 2)
  bias = (2**8) - 1 + bits
  print(f"\nBias: {bias}")

  bin_bias = ""
  temp_bias = bias
  while temp_bias > 0:
    bin_bias += str(temp_bias % 2)
    temp_bias //= 2
  bin_bias = bin_bias[::-1]
  while len(bin_bias) < 8:
    bin_bias = "0" + bin_bias

  # Формат: знак, крапка, біас, ціла частина, дробова частина
  res = f"{int_res[0]}.{bin_bias} {int_res[2:]}{float_res}"

  if len(res.replace(" ", "").replace(".", "")) < 80:
    res += "0" * (80 - len(res.replace(" ", "").replace(".", "")))
  else:
    # Залишаємо приблизний ліміт з урахуванням нових символів
    res = res[:85]

  return res


print(bin_float(nums, 9))
print("-" * 40)

bcd_clean = user_input.replace(".", "").replace("-", "")
bcd_nums = [int(item) for item in bcd_clean]
if len(bcd_nums) % 2 != 0:
  bcd_nums.insert(0, 0)


def packed_format() -> list:
  packed_nums = []
  for i in range(len(bcd_nums)):
    convert_number = bcd_nums[i]
    temp = ""
    for j in range(4):
      if convert_number >= 2 ** (3 - j):
        temp += "1"
        convert_number -= 2 ** (3 - j)
      else:
        temp += "0"
    while len(temp) < 4:
      temp = "0" + temp
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
print("-" * 40)


def forward_format() -> str:
  res = ""
  if user_input[0] == "-":
    res += "1."
    number = int(float(user_input[1:]))
  else:
    res += "0."
    number = int(float(user_input))

  if number == 0:
    return res + "0000000"
  else:
    for i in range(7):
      power = 6 - i
      if number >= 2**power:
        res += "1"
        number -= 2**power
      else:
        res += "0"
  return res


def reversed_format() -> str:
  forward = forward_format()
  if float(user_input) >= 0:
    return forward
  else:
    rev_res = forward[:2]
    for i in range(2, len(forward)):
      if forward[i] == "1":
        rev_res += "0"
      else:
        rev_res += "1"
    return rev_res


def additional_format() -> str:
  rev = reversed_format()
  if float(user_input) >= 0:
    return rev
  else:
    bits_part = list(rev[2:])
    carry = 1
    for i in range(len(bits_part) - 1, -1, -1):
      if carry == 0:
        break
      if bits_part[i] == "1":
        bits_part[i] = "0"
        carry = 1
      else:
        bits_part[i] = "1"
        carry = 0
    return rev[:2] + "".join(bits_part)


def modified_forward_format() -> str:
  fwd = forward_format()
  sign_bit = fwd[0]
  return sign_bit + fwd


def modified_reversed_format() -> str:
  rev = reversed_format()
  sign_bit = rev[0]
  return sign_bit + rev


def modified_additional_format() -> str:
  add_fmt = additional_format()
  sign_bit = add_fmt[0]
  return sign_bit + add_fmt


print("forward format:")
print(forward_format())
print("reversed format:")
print(reversed_format())
print("additional format:")
print(additional_format())
print("modified forward format:")
print(modified_forward_format())
print("modified reversed format:")
print(modified_reversed_format())
print("modified additional format:")
print(modified_additional_format())