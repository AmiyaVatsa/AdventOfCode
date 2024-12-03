import pathlib
import sys
import re

def parse(puzzle_input):
	mul_list = []
	mul_list2 = []
	temp = ""
	flag = False
	flag2 = False
	flag3 = True
	temp2 = ""
	mul_regex = re.compile(r'mul\((\d+),(\d+)\)')
	# 'do()'
	# 'don\'t()'
	for i in puzzle_input:
		if i == 'm':
			temp = ""
			flag = True
		if i == 'd':
			temp2 = ""
			flag2 = True
		if i == ')' and flag == True:
			# print(temp)
			flag = False
			temp += i
			if re.match(mul_regex, temp):
				com = mul_regex.search(temp)
				a, b = com.groups()
				mul_list.append(int(a) * int(b))
				if (flag3):
					mul_list2.append(int(a) * int(b))
			temp = ""
		if i == ')' and flag2 == True:
			 temp2 += i
			 flag2 = False
			 if (temp2 == "do()"):
			 	flag3 = True
			 if (temp2 == "don\'t()"):
			 	flag3 = False
			 temp2 = ""
		if flag == True:
			temp += i
		if flag2 == True:
			temp2 += i
	print(mul_list, mul_list2)
	return mul_list, mul_list2
def part_1_solution(data):
	data, _ = data
	ans = 0
	for i in data:
		ans += i
	return ans

def part_2_solution(data):
 	_, data = data
 	ans = 0
 	for i in data:
 		ans += i
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

