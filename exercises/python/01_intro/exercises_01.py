
def is_palindrome(string_var):     
    '''
    returns True if string_var is palindrome, False otherwise
    '''
    ret = None
    ########################
    ret = string_var==string_var[::-1]
    ########################
    return ret 

def histogram_letters(string_var):     
    '''
    count how many times a letter is present in the string_var
    and returns a dict

    '''
    ret = None
    ########################
    ret = dict((char,0) for char in string_var)
    for char in string_var:
        ret[char]+=1
    ########################
    return ret 

def get_most_frequent(list_var):
    '''
    returns a tuple with the most frequent object in the list with the 
    corresponing number
    '''
    ret = None
    ########################
    most_frequent = max(list_var, key=list_var.count)
    ret = (most_frequent, list_var.count(most_frequent))
    ########################
    return ret

def which_duplicates(list_var):
    '''
    return a dict with containing the repeted object and the number of repetitions
    '''
    ret = None
    ########################
    ret = {}
    for item in list_var:
        if list_var.count(item) > 1:
            ret[item] = list_var.count(item)
            list_var.remove(item)
    ###########NOTE: IMPLEMENT FOR LIST OF LISTS TOO#############
    return ret


def compute_factorial(int_val):
    '''
    returns factorial of a number
    '''
    ret = None
    ########################
    if int_val == 1 or int_val == 0:
        ret = 1
    else:
        ret = compute_factorial(int_val-1)*int_val
    ########################
    return ret


def is_prime(int_val):
    '''
    returns True if int_val is prime, False otherwise
    '''
    ret = None
    ########################

    ########################
    return ret




print("'ciao' is palindrome: ", is_palindrome("ciao"))
print("'hannah' is palindrome: ", is_palindrome("hannah"))

print("'letter' histogram: ", histogram_letters("letter"))

list1=["ciao",1,1,2,"ciao","ciao"]
print(get_most_frequent(list1))
list2=["ciao",1,1,2,"ciao","ciao",[1,2],[1,2],[1,2],[1,2]]
print(get_most_frequent(list2))

print(which_duplicates(list1))

print(compute_factorial(6))
