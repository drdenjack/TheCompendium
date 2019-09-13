from .sudoku_solver import Solver
import pytest


class TestSudokuSolver:

    def create_empty_board(self):
        return [0] * 81

    def test_remove_val_from_row(self):

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
        solver = Solver(input)
        solver.dump()
        assert False