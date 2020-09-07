def read_txt_line(filename):
    with open(filename, mode='r', encoding='utf-8') as fp:
        txt_list = []
        for line in fp:
            line_list = []
            if line.split('\n')[0]:
                line_element = line.split('\n')[0].split(' ')
            else:
                continue
            for i in line_element:
                if i:
                    line_list.append(i)
                else:
                    continue
            #print(line_list)
            txt_list.append(line_list)
        print(txt_list)
    fp.close()
    return txt_list

if __name__ == '__main__':
    print(read_txt_line('a.txt'))
