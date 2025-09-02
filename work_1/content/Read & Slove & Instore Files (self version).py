<<<<<<< HEAD
import math
def data_read(filename):
    with open(filename,'r',encoding='utf-8') as file:
        return [float(line.strip() )for line in file if line.strip()]
def calculate_data(data):
    mean=sum(data)/len(data)
    fangcha=sum((x-mean) ** 2 for x in data )/len(data)
    return mean,fangcha
def write_results(filename,statistics):
    with open(filename,'w',encoding='utf-8') as file:
        file.write(
        f"输出结果：\n"
        f"数据数量：{len(data)}\n"
        f"均值：{statistics[0]:.4f}\n"
        f"方差：{statistics[1]:.4f}\n"
    )
if __name__ == "__main__":
    input_file="input.txt"
    output_file="output.txt"
    try:
        data=data_read(input_file)
        if not data:
            raise FileNotFoundError(f"文件{input_file}不存在")
        statistics=calculate_data(data)
        write_results(output_file,statistics)
        print(f"数据处理成功，结果已成功保存到{output_file}")
    except ValueError as e:
=======
import math
def data_read(filename):
    with open(filename,'r',encoding='utf-8') as file:
        return [float(line.strip() )for line in file if line.strip()]
def calculate_data(data):
    mean=sum(data)/len(data)
    fangcha=sum((x-mean) ** 2 for x in data )/len(data)
    return mean,fangcha
def write_results(filename,statistics):
    with open(filename,'w',encoding='utf-8') as file:
        file.write(
        f"输出结果：\n"
        f"数据数量：{len(data)}\n"
        f"均值：{statistics[0]:.4f}\n"
        f"方差：{statistics[1]:.4f}\n"
    )
if __name__ == "__main__":
    input_file="20250629.txt"
    output_file="Answer.txt"
    try:
        data=data_read(input_file)
        if not data:
            raise FileNotFoundError(f"文件{input_file}不存在")
        statistics=calculate_data(data)
        write_results(output_file,statistics)
        print(f"数据处理成功，结果已成功保存到{output_file}")
    except ValueError as e:
>>>>>>> a191e88c568cf9e2e2333f9de660d0447dd7f9b2
        print(f"数据错误：{e}")