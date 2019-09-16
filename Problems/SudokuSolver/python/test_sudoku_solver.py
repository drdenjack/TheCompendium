from .sudoku_solver import Solver, Node
import pytest


class TestNode:

    def test_get_row(self):
        node = Node(2, 0)
        assert node.get_row() == 0
        node = Node(2, 1)
        assert node.get_row() == 0
        node = Node(2, 2)
        assert node.get_row() == 0
        node = Node(2, 8)
        assert node.get_row() == 0

        node = Node(1, 80)
        assert node.get_row() == 8
        node = Node(1, 72)
        assert node.get_row() == 8

        node = Node(1, 9)
        assert node.get_row() == 1
        node = Node(1, 17)
        assert node.get_row() == 1

    def test_get_col(self):
        node = Node(2, 0)
        assert node.get_col() == 0
        node = Node(2, 9)
        assert node.get_col() == 0
        node = Node(2, 18)
        assert node.get_col() == 0
        node = Node(2, 72)
        assert node.get_col() == 0

        node = Node(1, 3)
        assert node.get_col() == 3
        node = Node(1, 12)
        assert node.get_col() == 3

        node = Node(1, 8)
        assert node.get_col() == 8
        node = Node(1, 80)
        assert node.get_col() == 8

    def test_set_possible_values(self):
        node = Node(3, 1)
        assert node._possible_values == {
            1: 1,
            2: 1,
            4: 1,
            5: 1,
            6: 1,
            7: 1,
            8: 1,
            9: 1
        }


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