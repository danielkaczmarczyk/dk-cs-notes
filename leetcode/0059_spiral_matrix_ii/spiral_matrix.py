def generate_matrix(n):
    matrix = []
    first_row = []
    number = 1
    location = [1, n-1]
    direction = 'D'

    turn = {
            'R': 'D',
            'D': 'L',
            'L': 'U',
            'U': 'R'
            }

    for _ in range(n):
        first_row.append(number)
        number += 1
    matrix.append(first_row)

    # places n next numbers twice, then calls itself with n-1
    def place(n):
        j = 0
        while j < n:
            matrix[location[0]][location[1]] = number
            # place the number at current index
            # advance the location pointer (depending on direction)
            # j++ 
        # change direction by turning right
        # advance the location pointer
        pass 


    return matrix


print(generate_matrix(4))
