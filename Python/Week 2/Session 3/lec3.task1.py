def get_bit_mode(bit_Number):
    while True:
        mode=input(f"Enter bit {bit_Number} mode (in or out) ").strip().lower()
        if mode == 'in':
            return mode
        elif mode == 'out':
            return mode
        else:
            print("Wrong option , Please choose (In or Out)")

def generate_gpio_init():
    bit_modes = (get_bit_mode(bit) for bit in range(8))
    
    DDRX_value = 0
    for bit, mode in enumerate(bit_modes):
        if mode == 'out':
            DDRX_value |= (1 << bit)
    
    init_function = f"""\void GPIO_Init() {{// Set DDRx register DDRx = 0x{DDRX_value:02X};  // 0b{DDRX_value:08b}}}"""
    return init_function

if __name__ == "__main__":
    init_code = generate_gpio_init()
    print("Generated GPIO Initialization Function:\n")
    print(init_code)