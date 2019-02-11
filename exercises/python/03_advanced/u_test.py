class MyRange():
    """ Acts like `range` """
    def __init__(self, start, stop, step = 1):
        self.myrng = range(start, stop, step)


def myrange(*args): # treats arguments as a tuple
    """ Acts like `range` """
    n_arguments = len(args)
    if n_arguments not in [1,2,3]:
        raise TypeError("myrange only accepts 1 to 3 arguments")
    if n_arguments == 1:
        return MyRange(0,args[0]).myrng
    if n_arguments == 2:
        return MyRange(args[0], args[1]).myrng
    if n_arguments == 3:
        return MyRange(args[0], args[1], args[2]).myrng



import unittest

class TestMyRangeClass(unittest.TestCase):
    def test_size(self):
        self.assertEqual(len([i for i in myrange(1,10,2)]), len([i for i in range(1,10,2)]))

    def test_wrong_number_of_args(self):
        with self.assertRaises(TypeError):
            myrange()
            myrange(1,2,3,4)
    
    def test_last_element(self):
        self.assertEqual(max([i for i in myrange(12)]),max([i for i in range(12)]))
        self.assertEqual(max([i for i in myrange(12,104,3)]),max([i for i in range(12,104,3)]))
        self.assertEqual(max([i for i in myrange(12,1,-1)]),max([i for i in range(12,1,-1)]))


if __name__ == '__main__':
    unittest.main()
