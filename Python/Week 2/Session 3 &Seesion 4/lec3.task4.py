
def Ascii(value):
    return ord(value)

def main():
    result = input("Enter a character: ")

    # Ensure that only one character is entered
    if len(result) != 1:
        print("please try a single character.")
    else:
        ascii_value = Ascii(result)
        print(f"The ASCII value of '{result}' is {ascii_value}.")

if __name__ == "__main__":
    main()