
input = [0] * 81

input = [
    1, 0, 0,  1, 0, 0,  0, 0, 0,
    0, 0, 0,  0, 0, 0,  0, 0, 0,
    0, 0, 0,  0, 0, 0,  0, 0, 0,

    0, 0, 0,  0, 0, 0,  0, 0, 0,
    0, 0, 0,  0, 0, 0,  0, 0, 0,
    0, 0, 0,  0, 0, 0,  0, 0, 0,

    0, 0, 0,  0, 0, 0,  0, 0, 0,
    0, 0, 0,  0, 0, 0,  0, 0, 0,
    0, 0, 0,  0, 0, 0,  0, 0, 0,
]

class Solver:

    def __init__(self, input):
        self._input = input

    def remove_val_from_row(self, val):
        pass

    def remove_val_from_col(self, val):
        pass

    def remove_val_from_square(self, val):
        pass

    def dump(self, arr=None):
        if arr is None:
            arr = self._input
            
        for r in range(9):
            x = r * 9
                
            if r > 0 and r % 3 == 0:
                s = ''
                for i in range(28):
                    s += '-'
                print(s)

            a = '  '.join([str(z) for z in arr[x:x+3]])
            b = '  '.join([str(z) for z in arr[x+3:x+6]])
            c = '  '.join([str(z) for z in arr[x+6:x+9]])
            print(a + ' | ' + b + ' | ' + c)


    def solve(self):
        self.dump(input)
        


solver = Solver(input)
solver.solve()
