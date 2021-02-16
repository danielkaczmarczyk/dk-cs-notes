def merge_lists(list_1, list_2):
    result = []
    p, q = 0, 0

    p_in = True
    q_in = True

    while p_in or q_in:
        if p_in and q_in:
            smaller_value = min(list_1[p], list_2[q])
            result.append(smaller_value)
            if smaller_value == list_1[p]:
                p += 1
            else:
                q += 1

        if not q_in:
            result.append(list_1[p])
            p += 1

        if not p_in:
            result.append(list_2[q])
            q += 1

        if p == len(list_1):
            p_in = False
        if q == len(list_2):
            q_in = False

    return result

if __name__ == '__main__':
    list_1 = [1,3,4,5]  
    list_2 = [2,6,7,8]
    expected = [1,2,3,4,5,6,7,8]
    result =  merge_lists(list_1, list_2)
    assert expected == result, "Lists not merged successfully"
