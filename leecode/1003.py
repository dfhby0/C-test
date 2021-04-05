import sys
if __name__ == '__main__':
    n = int(sys.stdin.readline())
    line = sys.stdin.readline()
    value_list = list(map(int, line.split()))
    if n < 3:
        print("-1")
    else:
        if n % 2 == 0:
            print("-1")
        else:
            i_max = (n - 1) // 2
            run_round = 0
            while(sum(value_list[1:]) != 0):
                for i in range(1, i_max + 1):
                    if 2 * i > i_max:
                        max_value = max(value_list[2 * i - 1], value_list[2 * i])
                        value_list[i - 1] = max(value_list[i - 1] - max_value, 0)
                        value_list[2 * i - 1] = 0
                        value_list[2 * i] = 0
                        run_round += max_value
                    else:
                        if 2 * i + 1 > i_max:
                            max_value = value_list[2 * i]
                            value_list[i - 1] = max(value_list[i - 1] - max_value, 0)
                            value_list[2 * i - 1] = max(value_list[2 * i - 1] - max_value, 0)
                            value_list[2 * i] = 0
                            run_round += max_value
                i_max = i_max // 2
            if value_list[0] == 0:
                print(run_round)
            else:
                print(run_round + value_list[0])