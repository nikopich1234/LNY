# binary to any

uni = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

number = input("input a decimal number \n")


def convert(number, base):
    if base > len(uni) or base < 2:
        raise ValueError("Unsupported convertation base")
    
    else:
        if base == 10:
            return number
        elif "." in str(number):
            parts = str(number).split(".")
            result = 0
        else:
            raise ValueError("Unsupported number type")


result = convert(number, int(input("input convertation base")))
print(result)