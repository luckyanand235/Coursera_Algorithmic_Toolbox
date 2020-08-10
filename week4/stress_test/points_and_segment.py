# Uses python3
import sys
from numpy import random
from itertools import chain

def fast_count_segments(starts, ends, points):
    cnt = [0] * len(points)
    start_points = zip(starts, ['l'] * len(starts), range(len(starts)))
    end_points = zip(ends, ['r'] * len(ends), range(len(ends)))
    point_points = zip(points, ['p'] * len(points), range(len(points)))

    sort_list = chain(start_points, end_points, point_points)
    sort_list = sorted(sort_list, key=lambda a: (a[0], a[1]))
    segment_count = 0
    for num, letter, index in sort_list:
        if letter == 'l':
            segment_count += 1
        elif letter == 'r':
            segment_count -= 1
        else:
            cnt[index] = segment_count
    return cnt

def naive_count_segments(starts, ends, points):
    cnt = [0] * len(points)
    for i in range(len(points)):
        for j in range(len(starts)):
            if starts[j] <= points[i] <= ends[j]:
                cnt[i] += 1
    return cnt

if __name__ == '__main__':
    while True:
        data = [random.randint(1, 10), random.randint(1, 10)]
        n = data[0]
        m = data[1]
        starts = []
        ends = []
        for i in range(n):
            starts.append(random.randint(1, 10))
            ends.append(random.randint(1, 10))
        points = []
        for i in range(m):
            points.append(random.randint(1, 10))
        

        flag = False
        #use fast_count_segments
        cnt_fast = fast_count_segments(starts, ends, points)
        cnt_naive = naive_count_segments(starts, ends, points)
        for i in range(len(cnt_naive)):
            if cnt_naive[i] != cnt_fast[i]:
                flag = True
                break
            else:
                print("OK")
                
        print(n, " ", m)
        for i in range(n):
            print(starts[i], " ", ends[i])
        print('Points : ',points)
        print("Fast Algorithm : ", cnt_fast)
        print("Naive Algorithm : ",cnt_naive)
                
            
        if flag == True:
            break
