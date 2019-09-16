
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

class Node:
    def __init__(self, val, idx):
        self._idx = idx
        
        self._val = 0
        self._possible_values = self.set_possible_values()
        self.set_val(val)
        self._row = self.get_row()
        self._col = self.get_col()
        # self._square = self.get_square()

    def set_val(self, val):
        # if self.is_possible(val):
            self._val = val
        # else:
            # raise ValueError(f'{val} cannot be set in node with index={self._idx}')

    def is_possible(self, val):
        return val in self._possible_values

    def set_possible_values(self):
        possible_values = {}

        for i in range(1, 10):
            if i != self._val:
                possible_values[i] = 1
        return possible_values

    def remove_possible_value(self, val):
        self._possible_values.pop(val)

    def get_row(self):
        return self._idx // 9

    def get_col(self):
        return self._idx % 9

    # def get_square(self):
    #     pass


class Solver:
    input = []

    def __init__(self, input):
        self._input = input
        self._board = [Node(0, 1)] * 81

        self.validate_input()

        self.initialize_board()

        self.populate_board()

    def initialize_board(self):
        for idx in range(81):
            self._board[idx] = Node(0, idx)

    def populate_board(self):
        for idx, val in enumerate(self._input):
            self._board[idx].set_val(val)
            self.validate_board(idx)
            self.remove_val_from_row(val, idx)
            self.remove_val_from_col(val, idx)

    def validate_input(self):
        if len(self._input) != 81:
            raise ValueError('input is not valid')

    def validate_board(self, idx):
        target_space = self._board[idx]
        for i in range(81):
            # NOTE: Could be faster without checking rows/columns/squares that don't match idx
            # Think about creating a map: idx -> [indexes to check]
            curr_space = self._board[i]
            if i != idx:
                # TODO: check square also
                if curr_space._row == target_space._row or curr_space._col == target_space._col:
                    if curr_space._val == target_space._val:
                        return False
                        # raise ValueError(f'spaces {i} and {idx} have the same value of {curr_space._val}')
        return True

    def remove_val_from_row(self, val, idx):
        target_space = self._board[idx]
        for i in range(81):
            curr_space = self._board[i]
            if i != idx:
                if curr_space._row == target_space._row:
                    curr_space.remove_possible_value(target_space._val)
        return True

    def remove_val_from_col(self, val, idx):
        target_space = self._board[idx]
        for i in range(81):
            curr_space = self._board[i]
            if i != idx:
                if curr_space._col == target_space._col:
                    curr_space.remove_possible_value(target_space._val)
        return True

    def remove_val_from_square(self, val, idx):
        pass

    def dump(self, arr=None):
        if arr is None:
            arr = self._input

        for r in range(9):
            x = r * 9
                
            if r > 0 and r % 3 == 0:
                s = ''
                for _ in range(28):
                    s += '-'
                print(s)

            a = '  '.join([str(z) for z in arr[x:x+3]])
            b = '  '.join([str(z) for z in arr[x+3:x+6]])
            c = '  '.join([str(z) for z in arr[x+6:x+9]])
            print(a + ' | ' + b + ' | ' + c)


    def solve(self):
        self.dump(input)
        


# solver = Solver(input)
# solver.solve()
