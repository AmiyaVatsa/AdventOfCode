import pathlib
import sys

def parse(puzzle_input):
	puzzle_input += '\n'
	#print(puzzle_input)
	list1 = []
	list2 = []
	num = ""
	for i in puzzle_input:
		if i != ' ' and i != '\n':
			num += i
		elif i == ' ' and num.isnumeric():
			list1.append(int(num))
			num = ""
		elif i == '\n' and num.isnumeric():
			list2.append(int(num))
			num = ""
	#print(list1)
	#print(list2)
	return list1, list2

def part_1_solution(data):
	list1, list2 = data
	list1.sort()
	list2.sort()
	ans = 0
	for i in range(len(list1)):
		ans += abs(list1[i] - list2[i])
	return ans

def part_2_solution(data):
	list1, list2 = data
	dict_list_2 = {}
	ans = 0
	for i in list2:
		if i in dict_list_2:
			dict_list_2[i] += 1
		else:
			dict_list_2[i] = 1
	for i in list1:
		if (i not in dict_list_2):
			continue
		ans += (i * dict_list_2[i])
	return ans

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

