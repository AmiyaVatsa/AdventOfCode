import pathlib
import sys

def parse(puzzle_input):
	return puzzle_input

def part_1_solution(data):
	return ""

def part_2_solution(data):
    return ""

def solve(input):
	data = parse(puzzle_input)
	solution_1 = part_1_solution(data)
	solution_2 = part_2_solution(data)

	return solution_1, solution_2

if __name__ == '__main__':
	for path in sys.argv[1:]:
		print(f"{path}:")
		puzzle_input = pathlib.Path(path).read_text().strip()
		solutions = solve(puzzle_input)
		print("\n".join(str(solution) for solution in solutions))

