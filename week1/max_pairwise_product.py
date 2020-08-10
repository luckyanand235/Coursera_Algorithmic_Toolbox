def max_pairwise_product(arr):
    p1 = max(arr)
    arr.remove(p1)
    p2 = max(arr)
    return p1*p2

if __name__ == '__main__':
    input_n = int(input())
    input_numbers = [int(x) for x in input().split()]
    print(max_pairwise_product(input_numbers))