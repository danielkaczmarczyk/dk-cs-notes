def rearrange(array):
    negatives = []
    positives = []

    for item in array:
        if item < 0:
            negatives.append(item)
        else:
            positives.append(item)

    return negatives + positives
