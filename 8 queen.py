import random

def random_board():
    return random.sample(range(8), 8)

def attack_pairs(board):
    pairs = 0
    for i in range(8):
        for j in range(i+1, 8):
            if board[i] == board[j] or abs(board[i] - board[j]) == abs(i - j):
                pairs += 1
    return pairs

def hill_climb(board):
    current_attacks = attack_pairs(board)
    while current_attacks > 0:
        next_board = list(board)
        min_attacks = current_attacks

        for col in range(8):
            for row in range(8):
                if board[col] != row:
                    next_board[col] = row
                    new_attacks = attack_pairs(next_board)
                    if new_attacks < min_attacks:
                        min_attacks = new_attacks
                        board[col] = row

        if min_attacks >= current_attacks:
            return board
        current_attacks = min_attacks

    return board

def solve_eight_queens():
    attempts = 100000
    curr = 0
    while(curr<attempts):
        board = random_board()
        solution = hill_climb(board)
        if attack_pairs(solution) == 0:
            return solution
        curr+=1

    return None

def print_board(board):
    for row in range(8):
        row_str = ""
        for col in range(8):
            if board[col] == row:
                row_str += "1 "
            else:
                row_str += ". "
        print(row_str)

if __name__ == "__main__":
    solution = solve_eight_queens()
    if solution:
        print("Solution found:")
        print_board(solution)
    else:
        print("No solution found after random restarts.")
