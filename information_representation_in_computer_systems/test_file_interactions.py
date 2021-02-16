data = input('What do you want to put in a file?\n>>> ')

def write_data(data):
    with open('data.txt', 'w') as f:
        f.write(data + "\n")

write_data(data)

def read_data():
    with open('data.txt', 'r') as f:
        data = f.read()
        print("Retrieved data from the text file:", data)

read_data()
