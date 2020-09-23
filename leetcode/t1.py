'''
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。
'''

def check_string(string):
    string_clean = ''
    for s in string:
        if s == '(' or s == ')' or s == '{' or s == '}' or s == '[' or s == ']':
            string_clean += s
    print(string_clean)

    # 判断是否为空字符串
    if string_clean.strip() == '':
        print(string, "字符串有效")

    # 判断是否为奇数
    if len(string_clean.strip()) > 0:
        if len(string_clean) % 2 == 1:
            print(string, '字符串中括号数量为奇数')
        # 循环遍历字符串，存在()[]{}的剔除
        if len(string_clean) % 2 == 0:
            for n in range(int(len(string_clean))):
                print(string_clean)
                for i in range(len(string_clean)-2):
                    left_right1 = string_clean[i] == '(' and string_clean[i+1] == ')'
                    left_right2 = string_clean[i] == '[' and string_clean[i+1] == ']'
                    left_right3 = string_clean[i] == '{' and string_clean[i+1] == '}'
                    if left_right1 or left_right2 or left_right3:
                        string_clean = string_clean[:i]+string_clean[i+2:]  # 字符串拼接
                        break
            if len(string_clean) > 2:
                print(string, '字符串中括号无效')
            if len(string_clean) == 2:
                d = ['()', '[]', '{}']
                if string_clean not in d:
                    print(string, '字符串中括号无效')
                else:
                    print(string, '字符串中括号有效')
        

if __name__ == '__main__':
     string = input("请输入一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串:")
     check_string(string)

