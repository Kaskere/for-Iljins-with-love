def geoprog():
    a = None
    q = None
    n = None
    while True:     
        try:
            if a is None: a = int(input("Enter a: "))
            if q is None: q = int(input("Enter q: "))
            if n is None: n = int(input("Enter n: "))
            if n < 1: 
                print("Number n has to be above 0.")
                n = None
                raise Exception
            break
        except:
            print("Please enter a round number.")
        
    for i in range(n):
        #POW function is a math function that will work generically.
        num = a * pow(q,i)
        # empty dictionaries signed with {};
        #format() method formats the specified value(s) and insert them inside the string's placeholder.
        print("Number a{} is {}".format(i+1, num))

if __name__ == '__main__':
    while True:
        #geoprog for geometric progression
        geoprog()
        while True:
            moar = input("Would you like to calculate again? (y/n)\n")
            if moar == "y": break
            elif moar == "n": quit()
            else: print("Enter \"y\" to continue or \"n\" to end.")
