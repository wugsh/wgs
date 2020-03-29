import yaml
import os
import json


def get_yaml_data(yaml_file):
    # 打开yaml文件
    print("***获取yaml文件数据***")
    file = open(yaml_file, 'r', encoding="utf-8")
    file_data = file.read()
    file.close()
    #print(file_data)
    print("类型：", type(file_data))
    # 将字符串转化为字典或列表
    print("***转化yaml数据为字典或列表***")
    data = yaml.load(file_data)
    #print(data)
    print(json.dumps(data))
    print("类型：", type(data))
    return data


# yaml文件中含有多个文档时，分别获取文档中数据
def get_yaml_load_all(yaml_file):
    # 打开yaml文件
    file = open(yaml_file, 'r', encoding="utf-8")
    file_data = file.read()
    file.close()
    all_data = yaml.load_all(file_data)
    for data in all_data:
        print(data)


#ruamel模块生成yaml文档
def generate_yaml_doc_ruamel(yaml_file):
    from ruamel import yaml
    py_object = {'school': 'zhang',
                 'students': ['a', 'b']}
    file = open(yaml_file, 'w', encoding='utf-8')
    yaml.dump(py_object, file, Dumper=yaml.RoundTripDumper)
    file.close()


# 通过from ruamel import yaml读取yaml文件
def get_yaml_data_ruamel(yaml_file):
    from ruamel import yaml
    file = open(yaml_file, 'r', encoding='utf-8')
    data = yaml.load(file.read(), Loader=yaml.Loader)
    file.close()
    print(data)


current_path = os.path.abspath("/home/wgs/Git/fabric/orderer/common/server/testdata")
yaml_path = os.path.join(current_path, "orderer.yaml")
get_yaml_data(yaml_path)

