s = "bleach whine smash conscious silver spot amusement itch thought clumsy play welcome telephone butter uneven gather pets bridge minor frequent communicate godly piquant double greasy scorch identify weather clip spicy end run love puncture evanescent bell memory angle"

def lastLetter(word):
    return word[-1]

reverses = lambda x: sorted(x.split(" "), key=lastLetter)

print(reverses(s))
