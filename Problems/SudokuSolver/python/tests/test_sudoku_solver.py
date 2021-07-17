from src.sudoku_solver import Solver, Node
import pytest
from unittest import mock


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
            0: 1,
            1: 1,
            2: 1,
            4: 1,
            5: 1,
            6: 1,
            7: 1,
            8: 1,
            9: 1
        }

    def test_set_val(self):
        node = Node(3, 1)
        assert node.set_val(1) == 1

        node._possible_values.pop(2)
        with pytest.raises(ValueError) as e:
            node.set_val(2)
        assert str(e.value) == '2 cannot be set in node with index=1'

    def test_set_val__zero(self):
        node = Node(0, 1)
        assert node.set_val(1) == 1

    def test_set_val__repeated(self):
        node = Node(0, 1)
        assert node.set_val(0) == 0
        assert node.set_val(0) == 0

    def test_remove_possible_value(self):
        node = Node(3, 1)
        assert 3 not in node._possible_values
        assert 1 in node._possible_values
        assert 8 in node._possible_values

class TestSudokuSolver:

    def create_empty_board(self):
        return [0] * 81

    def test_solver_setup(self):

        input = [
            1, 0, 0,  0, 0, 0,  0, 0, 0,
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
        
        assert isinstance(solver._board[0], Node)
        assert solver._board[0]._val == 1
        assert isinstance(solver._board[1], Node)
        assert solver._board[1]._val == 0
        assert isinstance(solver._board[80], Node)
        assert solver._board[80]._val == 0
        
    @mock.patch('src.sudoku_solver.Solver.propagate_changes')
    @mock.patch('src.sudoku_solver.Solver.validate_board')
    def test_solver__remove_val_from_row(self, mock_validate_board, mock_propagate_changes):

        input = [
            1, 0, 0,  0, 0, 0,  0, 0, 0,
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
        
        solver.remove_val_from_row(0, 1)

        for i in range(9):
            assert 1 not in list(solver._board[i]._possible_values.keys())

        assert 1 in list(solver._board[9]._possible_values.keys())

    @mock.patch('src.sudoku_solver.Solver.propagate_changes')
    @mock.patch('src.sudoku_solver.Solver.validate_board')
    def test_solver__remove_val_from_col(self, mock_validate_board, mock_propagate_changes):

        input = [
            1, 0, 0,  0, 0, 0,  0, 0, 0,
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
        
        solver.remove_val_from_col(0, 1)

        for i in range(9):
            assert 1 not in list(solver._board[i*9]._possible_values.keys())

        assert 1 in list(solver._board[1]._possible_values.keys())
        
    @mock.patch('src.sudoku_solver.Solver.validate_board')
    def test_solver__propagate_changes(self, mock_validate_board):

        input = [
            1, 0, 0,  0, 0, 0,  0, 0, 0,
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

        for i in range(9):
            assert 1 not in list(solver._board[i]._possible_values.keys())
            assert 1 not in list(solver._board[i*9]._possible_values.keys())

        assert 1 in list(solver._board[10]._possible_values.keys())
        assert 1 in list(solver._board[80]._possible_values.keys())
