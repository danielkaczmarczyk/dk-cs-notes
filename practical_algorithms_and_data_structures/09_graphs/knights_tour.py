from collections import defaultdict


def add_edge(graph, vertex_a, vertex_b):
    graph[vertex_a].add(vertex_b)
    graph[vertex_b].add(vertex_a)


def build_graph(board_size):
    graph = defaultdict(set)
    for row in range(board_size):
        for col in range(board_size):
            for to_row, to_col in legal_moves_from(row, col, board_size):
                add_edge(graph, (row, col), (to_row, to_col))
    return graph

def legal_moves_from(row, col, board_size):
    for row_offset, col_offset in MOVE_OFFSETS:
        move_row, move_col = row + row_offset, col + col_offset
        if 0 <= move_row < board_size and 0 <= move_col < board_size:
            yield move_row, move_col

def first_true(sequence):
    for item in sequence:
        if item:
            return item

    return None

def find_solution_for(board_size, heuristic=lambda graph: None):
    graph = build_graph(board_size)
    total_squares = board_size * board_size

def traverse(path, current_vertex):
    if len(path) + 1 == total_squares:
        return path + [current_vertex]

    yet_to_visit = graph[current_vertex] - set(path)
    if not yet_to_visit:
        return False

    next_vertices = sorted(yet_to_visit, heuristic(graph))
    return first_true(traverse(path + [current_vertex], vertex) for vertex in next_vertices)

    return first_true(traverse([], starting_vertex) for starting vertex in graph)
