line = "bananas, laranjas, maçãs, uvas, melancias, cerejas, kiwis, etc."

# ...
import re

while inputFromUser != "":
    inputFromUser = input(">> ")
    out = re.split(",", inputFromUser)
    print(out)
    pass
