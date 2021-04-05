import sys

if __name__ == '__main__':
    n = int(sys.stdin.readline())
    length = len(str(n))

    data_list = [int(x) for x in str(n)]
    result_list = []
    if length % 2 == 0:
        four_num = 0
        seven_num = 0
        stop = 0
        for i in range(length):
            if data_list[i] < 4:
                four_num += 1
                result_list.append(4)
                stop = 1
                break
            elif data_list[i] == 4:
                four_num += 1
                result_list.append(4)
            elif data_list[i] > 4 and data_list[i] < 7:
                seven_num += 1
                result_list.append(7)
                stop = 1
                break
            elif data_list[i] == 7:
                seven_num += 1
                result_list.append(7)
            else:
                stop = 2
                break
        if stop == 1:
            count = length // 2
            for p in range(count - four_num):
                result_list.append(4)
            for q in range(count - seven_num):
                result_list.append(7)
        elif stop == 2:
            count = length // 2 + 1
            result_list = []
            for p in range(count):
                result_list.append(4)
            for q in range(count):
                result_list.append(7)
    else:
        count = (length + 1) // 2
        for p in range(count):
            result_list.append(4)
        for q in range(count):
            result_list.append(7)
    final_result = [str(y) for y in result_list]
    print(''.join(final_result))