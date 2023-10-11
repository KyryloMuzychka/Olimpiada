
def same_elements(array):
    are_all_equal = all(x == array[0] for x in array)
    return True if are_all_equal else False


def xor(xor_group):
    if len(xor_group) == 1:
        return xor_group[0][0]
    else:
        res = xor_group[0][0]
        i = 1
        while i < len(xor_group):
            res ^= xor_group[i][0]
            i += 1
        return res


def print_indexes(xor_group):
    for pair in xor_group:
        print(pair[1])


def solve():
    n = int(input())
    user_input = list(map(int, input().split()))

    if same_elements(user_input):
        print("NO")
        return

    array = []
    for i in range(n):
        pair = [user_input[i], i+1]
        array.append(pair)

    sorted_pairs = sorted(array, key=lambda x: x[0])

    xor_group = []

    for i in range(n-1):
        xor_group.append(sorted_pairs[len(sorted_pairs)-1])
        sorted_pairs.pop()
        if xor(xor_group) > sorted_pairs[0][0]:
            print("YES")
            print(len(xor_group))
            print_indexes(xor_group)
            return

    print("NO")


def main():
    t = int(input())
    while t:
        solve()
        t -= 1


main()

