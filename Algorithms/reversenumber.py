def reverse(n):
    n = str(n)
    return int(n[::-1])

n = input('Enter integer: ')
while not n.isdigit():
    n = input('Enter a valid integer: ')
    continue
print(reverse(n))
