def get_words():
    """
        reads words.txt and returns a list of strings containing them
    """
    with open('../words.txt', 'r') as reader:
        lines = reader.readlines()
    return lines 

