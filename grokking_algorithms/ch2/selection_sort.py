array = [4, 9, 11, 5320, 2, 1, 3, 0]

def selection_sort(array, order):
    sorted = []
    def find_max(array):
        max_n = array[0]
        index = 0
        for i in range(len(array)): 
            item = array[i]
            if item >= max_n:
                max_n = item
                index = i
        return index

    def find_min(array):
        min_n = array[0]
        index = 0
        for i in range(len(array)): 
            item = array[i]
            if item <= min_n:
                min_n = item
                index = i
        return index

    if order == 'asc':
        get_next_item = find_min
    elif order == 'desc':
        get_next_item = find_max

    for n in range(len(array)):
        next_item_index = get_next_item(array)
        sorted.append(array[next_item_index])
        del array[next_item_index]

    print(sorted)
    

selection_sort(array, 'desc')

array = [4, 9, 11, 5320, 2, 1, 3, 0]
selection_sort(array, 'asc')


