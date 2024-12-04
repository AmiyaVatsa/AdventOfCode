import pathlib
import sys

XMAS = ['X', 'M', 'A', 'S']
dx = [-1, -1, -1, 0, +1, +1, +1, 0]
dy = [-1, 0, +1, +1, +1, 0, -1, -1]
def parse(puzzle_input):
	return puzzle_input

'''
  1 2 3
  * * *
8 * X * 4
  * * *
  7 6 5


 * * *
 * A *
 * * *
'''
def isOK(i, j, maze):
	n = len(maze)
	m = len(maze[0])
	if i < 0 or j < 0 or i >= n or j >= m:
		return False
	return True

def gfs(i, j, maze):
	if isOK(i - 1, j - 1, maze) and isOK(i + 1, j + 1, maze) and isOK(i + 1, j - 1, maze) and isOK(i - 1, j + 1, maze):
		if ((maze[i - 1][j - 1] == 'M' and maze[i + 1][j + 1] == 'S') or (maze[i - 1][j - 1] == 'S' and maze[i + 1][j + 1] == 'M')) and ((maze[i + 1][j - 1] == 'M' and maze[i - 1][j + 1] == 'S') or (maze[i + 1][j - 1] == 'S' and maze[i - 1][j + 1] == 'M')):
			return 1
	return 0

def dfs(i, j, maze, depth, mode, s):
	if not isOK(i, j, maze):
		return 0
	s += maze[i][j]
	if depth == 4:
		if s == 'XMAS':
			return 1
		return 0
	return dfs(i + dx[mode - 1], j + dy[mode - 1], maze, depth + 1, mode, s)

def f(i, j, maze):
	ans = 0
	ans += dfs(i - 1, j - 1, maze, 2, 1, 'X')
	ans += dfs(i - 1, j, maze, 2, 2, s = 'X')
	ans += dfs(i - 1, j + 1, maze, 2, 3, 'X')
	ans += dfs(i, j + 1, maze, 2, 4, 'X')
	ans += dfs(i + 1, j + 1, maze, 2, 5, 'X')
	ans += dfs(i + 1, j, maze, 2, 6, 'X')
	ans += dfs(i + 1, j - 1, maze, 2, 7, 'X')
	ans += dfs(i, j - 1, maze, 2, 8, 'X')
	return ans

def g(i, j, maze):
	ans = 0
	ans += gfs(i,j,maze)
	return ans

def part_1_solution(data):
	data = data.split('\n')
	# print(data, len(data))
	ans = 0
	for i in range(0, len(data)):
		for j in range(0, len(data[0])):
			if (data[i][j] == 'X'):
				ans += f(i, j, data)
	return ans

def part_2_solution(data):
	data = data.split('\n')
	ans = 0
	for i in range(0, len(data)):
		for j in range(0, len(data[0])):
			if data[i][j] == 'A':
				ans += g(i, j, data)
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

