from urllib.request import urlopen

shakespeare = urlopen('http://composingprograms.com/shakespeare.txt')
words = set(shakespeare.read().decode().split())
print({w for w in words if len(w) == 6 and w[::-1] in words})

