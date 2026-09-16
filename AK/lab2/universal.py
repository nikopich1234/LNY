# any to any

uni = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

number = input("input a uni number \n")
base =  int(input("input number base \n"))

for i in range(len(number)):
    if number[i] not in uni and number[i] != ".":
        raise ValueError("Unsupported symbol in number")

def check_con_ability(base):
    if base > len(uni) or base < 2:
        raise ValueError("Unsupported convertation base")
    else:
        return True

def check_split_ability(number):
    if "." in number:
        return True
    return False

def uni_to_dec(number, base_uni, accurancy = 0):
    base_uni_len = len(base_uni)
    if check_split_ability(number):
        number_parts = number.split(".") # [0] - int, [1] - float
        number_int_part = number_parts[0]
        number_float_part = number_parts[1]

        int_part_result = 0
        for i in range(len(number_int_part)):
            if number_int_part[i] != "0":
                int_part_result += base_uni.find(number_int_part[i]) * len(base_uni) ** ((len(number_int_part)) - i - 1)

        temp_float_part_result = 0
        for i in range(len(number_float_part)):
            if number_float_part[i] != "0":
                temp_float_part_result += base_uni.find(number_float_part[i]) * len(base_uni) ** (len(number_float_part) - i - 1)

        float_part_result = temp_float_part_result / len(base_uni) ** len(number_float_part)

        return int_part_result + float_part_result
    else:
        uni_to_dec_result = 0
        for i in range(len(number)):
            if number[i] != "0":
                uni_to_dec_result += base_uni.find(number[i]) * len(base_uni) ** (len(number)-i-1) 
        return uni_to_dec_result

def dec_to_uni(number, base_uni, accurancy = 0):
    if "." in str(number):
        number_parts = str(number).split(".")
        number_int_part = int(number_parts[0])
        number_float_part = int(number_parts[1])

        dec_to_uni_result = ""
        while number_int_part > 0:
            dec_to_uni_result += base_uni[number_int_part % len(base_uni)]
            number_int_part //= len(base_uni)

        dec_to_uni_result = dec_to_uni_result[::-1]

        if number_float_part != 0:
            dec_to_uni_result += (".")

            for i in range(accurancy):
                if number_float_part != 0:
                    number_float_part *= base
                    dec_to_uni_result += base_uni[number_float_part // 10**len(number_parts[1])]
                    number_float_part %= 10**len(number_parts[1])
                else:
                    break            


    else:
        dec_to_uni_result = ""
        while number > 0:
            dec_to_uni_result += base_uni[number % len(base_uni)]
            number //= len(base_uni)
        dec_to_uni_result = dec_to_uni_result[::-1]

    return dec_to_uni_result
        

if check_con_ability(base):
    base_uni = uni[:base]
    if check_split_ability(number):
        accurancy = int(input("input accurancy \n"))
        dec_number = uni_to_dec(number, base_uni, accurancy)
        uni_number = dec_to_uni(dec_number, base_uni, accurancy)
    else:
        dec_number = uni_to_dec(number, base_uni)
        uni_number = dec_to_uni(dec_number, base_uni)

print(f"{base}-base to decimal number: ", dec_number)
print(f"decimal to {base}-base number: ", uni_number)