t = int(input())
for _ in range(t):
    s = input()
    ans = set()
    for i in range(1, 6):
        ind = 0
        current = int(s[:i])
        digit_length = i
        flag = True # True if the entire string is valid
        impossible = False
        potential_add = None
        while ind < len(s):
            # print(s[ind:ind + digit_length], current, digit_length)
            if (len(str(current))) == digit_length + 1:
                # print("good")
                digit_length += 1

            if int(s[ind:ind + digit_length]) == current:
                # print('good')
                current += 1
                ind += digit_length
                
                
            elif flag:
                flag = False
                
                potential_add = current
                # print(potential_add)
                current += 1
            else:
                impossible = True
                break
        if impossible:
            continue
        if flag:
            if (int(s[:i]) - 1) > 0:
                ans.add(int(s[:i]) - 1)
            if (int(s[-digit_length:]) + 1) <= 99999:
                ans.add(int(s[-digit_length:]) + 1)
        else:
            ans.add(potential_add)
    li = sorted(list(ans))
    print(len(li))
    
    for num in li:
        print(num)