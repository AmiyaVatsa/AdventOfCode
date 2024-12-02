import pathlib
import sys

def parse(puzzle_input):
	puzzle_input += '\n'
	#print(puzzle_input)
	levels = []
	temp = []
	nums = ""
	for i in puzzle_input:
		if i == ' ':
			temp.append(int(nums))
			nums = ""
		elif i == '\n':
			temp.append(int(nums))
			levels.append(temp)
			temp = []
			nums = ""
		else:
			nums += i
	#print(levels)
	return levels

def part_1_solution(data):
	#print(data)
	safe = 0
	for i in data:
		flag = False
		for j in range(1, len(i) - 1):
			if (i[j] <= i[j - 1] and i[j] <= i[j + 1]) or (i[j] >= i[j - 1] and i[j] >= i[j + 1]):
				flag = True
				break
		for j in range(len(i) - 1):
			if (abs(i[j] - i[j + 1]) >= 1 and abs(i[j] - i[j + 1]) <= 3):
				continue
			else:
				flag = True
				break
		if (not flag):
			safe += 1
	return safe

def part_2_solution(data):
	safe = 0
	for i in data:
		damp = False
		flag = False
		for j in range(1, len(i) - 1):
			if (i[j] <= i[j - 1] and i[j] <= i[j + 1]) or (i[j] >= i[j - 1] and i[j] >= i[j + 1]):
				if (not damp):
					damp = True
					#print(i)
					continue
				flag = True
				break
		for j in range(len(i) - 1):
			if (abs(i[j] - i[j + 1]) >= 1 and abs(i[j] - i[j + 1]) <= 3):
				continue
			else:
				if not damp:
					damp = True
					#print(i)
					continue
				flag = True
				break
		if (not flag):
			safe += 1
	return safe

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

