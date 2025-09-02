<<<<<<< HEAD
#define _CRT_SECURE_NO_WARNINGS//后面的fopen，fscanf会报错，需要改成fopen_s和fscanf_s,但是改完之后又说后面不能连接两个参数，所以自然而然我们就直接使用#define CRT_SECURE_NO_WARNINGS,就可以直接预防后面出现的所有情况了
//确定头文件（完成数据读取-stdlib，运用数学公式处理-math，输出到新的文件中-stdlib）
#include <stdio.h>//文本的读取和写入（也就是我们在下面敲的任何代码），没有它，压根运行不了
#include <stdlib.h>//提供动态内存分配的作用，没有它，就无法读取、处理我们要用的文本文件，也无法存储新处理出来的数据，也就无法输出到新的文件中
#include<math.h>//文本的数学处理，比如说方差，求和等等

//定义一个结构体——利用指针来确定data的位置和读取data数量
typedef struct {
    double* data;    //指向double（双精度浮点类型）的指针，后面的data指的是数据的内存地址
    size_t size;     //size_t，指的是数据的一个数量，标准数据库就是这么规定的，后面不管再加什么都会报错
} DataArray;//首先两个大写代表的是它是结构体类型的名称，其次为什么要用DataArray的本质原因在于具有可读性啊，一下子就可以明白这行代码是什么意思，不香嘛，省的我们去读这几行代码啦，还要慢慢了解整个的一个东西，比如我们要通过那个double*去读懂他是一个双精度浮点型的指针类型，然后慢慢读，知道它的作用，最后原来它是读取数据位置从而定义的一个结构体呀。这不啰嗦嘛，我们直接看结尾部分就知道：哦哦哦，这个是那个数据指针，用来读取数据用的，这个一目了然

int main() {//表示C语言程序的一个入口函数，用来表示进入
    const char* input_file = "input.txt";  // const即constant表示这是一个常量，无法进行修改，char代表这字符类型，是特定的字符串类型，*代表指针，指向input_file,然后将右边的确切的文件名称赋值给input_file
    const char* output_file = "output.txt"; // 同上

    // 1. 读取文件数据

    FILE* file = fopen(input_file, "r"); //定义一个文件（FILE）类型的指针，fopen即file open打开函数，包括该文件名(20250629.txt)和打开方式-只读（r），目的是为了防止意外修改
    if (file == NULL) {  // 如果文件为空，if后面必须是括号，而括号内放置判断条件
        printf("无法打开文件 %s\n", input_file);//%s是占位符，s的全称是string，用来放后面的input_file,而input_file又通过指针，直接溯源到上面的"20250629.txt",然后就变成了无法打开文件20250629.txt，确实跟python有点区别，因为python是直接写成print(f"无法打开文件{input_file}")的
        return 1;//通常非0表示错误，0表示运行正确
    }

    // 计算数据行数
    size_t count = 0;//表示从0开始计数
    double temp;//double是代表双精度浮点型，而temp代表的是一个名称，相当于是给后面的提供一个地址吧，因为temp翻译出来就是缓存的意思，所以这个的目的大概就是先将它存储到一个缓存里面，方便后期去调用
    while (fscanf(file, "%lf", &temp) == 1) {//while代表的是当……时，循环进行括号里面的东西，（）里面是循环条件，{}这个里面是循环体，也就是不停循环里面的东西，文件扫描函数主要就是三个部分，首先是扫描哪个文件，接着是扫描完了之后格式化，也就是"%If",最后就是存储该扫描完之后的文件，所以是&temp，也不枉费我再前面定义了这个东西呀，那个fscanf代表的是文件扫描函数，是C语言程序里面自带的，所以是必须写上去的；括号里面是它要扫描的文件，也就是file，是一个文件指针，指向已经打开的文件；"%If"是格式说明符，%代表格式化的开始，I是long,f代表浮点数，必须都是要格式化的嘛，就像python里面的一样，它的格式化就是直接一个f""，果然每种语言还是有点差别的；&代表的是取地址符，表示里面的这个东西要存储到temp里面去
        count++;//表示count=count+1
    }

    if (count == 0) {//（）这个里面的是判断条件
        fclose(file);//不用多说，就是关闭该文件的意思
        printf("错误：文件 %s 中没有有效数据\n", input_file);
        return 1;
    }

    // 分配内存
    double* data = (double*)malloc(count * sizeof(double));//首先第一个=代表的是赋值，然后后面就使用了这个内存分配函数malloc,全称memory allocation,然后前面括号里面的就是将原来的malloc返回通用类型的指针的转化为double类型的指针，然后malloc后面括号里面的一大坨东西就代表着一共所需要占用的内存数量，count就是我们前面已经计算出来的需要多少个，*代表着就是乘法，后面就是double类型，也就是双精度浮点型的字节数，一般是8，所以是sizeof（double）,所以总的就是double*data=(double*)malloc(count*sizeof(double))
    if (data == NULL) {
        fclose(file);
        printf("内存分配失败\n");
        return 1;
    }

    // 重新读取数据
    rewind(file);//意思是倒带，将文件指针重新一会文件开头，重新进行文件读取
    for (size_t i = 0; i < count; i++) {//size_t i=0,意思就是创建计数器i，并将其初始化为0，后面就是当i<count时，就进行+1
        if (fscanf(file, "%lf", &data[i]) != 1) {//判断条件，就是当前不是进行了文件扫描嘛，也就是fscanf（file，"%lf",&temp）==1时嘛，然后不是进行了count++;这里的意思就是说当fscanf(file,"%lf",&data[i])!=1时，就会进行报错，就是跟这个fscanf（file，"%lf",&temp）==1时一个意思
            free(data);//这边就是释放数据
            fclose(file);//关闭文件
            printf("数据读取错误\n");//打印进行报错
            return 1;
        }
    }
    fclose(file);//倒带完了之后，要再将函数关闭，可以看见这边的fclose（file）;和rewind(file);是处于同一个等级的，所以倒带完了之后还要进行关闭

    // 2. 计算统计量
    double sum = 0;
    for (size_t i = 0; i < count; i++) {//()里面是判断条件；{}里面是循环体，用来循环进行；size_t i=0,意思就是创建计数器i，并将其初始化为0
        sum = sum + data[i];//就是把数组中的每个数都加到sum里面
    }
    double mean = sum / count;

    double fangcha = 0;
    for (size_t i = 0; i < count; i++) {//size_t i=0,意思就是创建计数器i，并将其初始化为0；接着是循环条件；然后是循环操作
        fangcha = (data[i] - mean) * (data[i] - mean);
    }
    fangcha = fangcha / count;

    // 3. 写入结果
    file = fopen(output_file, "w");
    if (file == NULL) {
        free(data);
        printf("无法创建文件 %s\n", output_file);
        return 1;
    }

    fprintf(file, "统计结果:\n");//fprintf 文件格式化输出函数
    fprintf(file, "数据个数: %zu\n", count);//%zu - 格式说明符(z表示size_t类型，u表示无符号)
    fprintf(file, "平均值: %.4f\n", mean);//%.4f - 格式说明符，表示保留4位小数
    fprintf(file, "方差: %.4f\n", fangcha);
    fclose(file);

    // 4. 清理内存
    free(data);
    printf("处理完成，结果已保存到 %s\n", output_file);
    return 0;
=======
#define _CRT_SECURE_NO_WARNINGS//后面的fopen，fscanf会报错，需要改成fopen_s和fscanf_s,但是改完之后又说后面不能连接两个参数，所以自然而然我们就直接使用#define CRT_SECURE_NO_WARNINGS,就可以直接预防后面出现的所有情况了
//确定头文件（完成数据读取-stdlib，运用数学公式处理-math，输出到新的文件中-stdlib）
#include <stdio.h>//文本的读取和写入（也就是我们在下面敲的任何代码），没有它，压根运行不了
#include <stdlib.h>//提供动态内存分配的作用，没有它，就无法读取、处理我们要用的文本文件，也无法存储新处理出来的数据，也就无法输出到新的文件中
#include<math.h>//文本的数学处理，比如说方差，求和等等

//定义一个结构体——利用指针来确定data的位置和读取data数量
typedef struct {
    double* data;    //指向double（双精度浮点类型）的指针，后面的data指的是数据的内存地址
    size_t size;     //size_t，指的是数据的一个数量，标准数据库就是这么规定的，后面不管再加什么都会报错
} DataArray;//首先两个大写代表的是它是结构体类型的名称，其次为什么要用DataArray的本质原因在于具有可读性啊，一下子就可以明白这行代码是什么意思，不香嘛，省的我们去读这几行代码啦，还要慢慢了解整个的一个东西，比如我们要通过那个double*去读懂他是一个双精度浮点型的指针类型，然后慢慢读，知道它的作用，最后原来它是读取数据位置从而定义的一个结构体呀。这不啰嗦嘛，我们直接看结尾部分就知道：哦哦哦，这个是那个数据指针，用来读取数据用的，这个一目了然

int main() {//表示C语言程序的一个入口函数，用来表示进入
    const char* input_file = "20250629.txt";  // const即constant表示这是一个常量，无法进行修改，char代表这字符类型，是特定的字符串类型，*代表指针，指向input_file,然后将右边的确切的文件名称赋值给input_file
    const char* output_file = "Answer.txt"; // 同上

    // 1. 读取文件数据

    FILE* file = fopen(input_file, "r"); //定义一个文件（FILE）类型的指针，fopen即file open打开函数，包括该文件名(20250629.txt)和打开方式-只读（r），目的是为了防止意外修改
    if (file == NULL) {  // 如果文件为空，if后面必须是括号，而括号内放置判断条件
        printf("无法打开文件 %s\n", input_file);//%s是占位符，s的全称是string，用来放后面的input_file,而input_file又通过指针，直接溯源到上面的"20250629.txt",然后就变成了无法打开文件20250629.txt，确实跟python有点区别，因为python是直接写成print(f"无法打开文件{input_file}")的
        return 1;//通常非0表示错误，0表示运行正确
    }

    // 计算数据行数
    size_t count = 0;//表示从0开始计数
    double temp;//double是代表双精度浮点型，而temp代表的是一个名称，相当于是给后面的提供一个地址吧，因为temp翻译出来就是缓存的意思，所以这个的目的大概就是先将它存储到一个缓存里面，方便后期去调用
    while (fscanf(file, "%lf", &temp) == 1) {//while代表的是当……时，循环进行括号里面的东西，（）里面是循环条件，{}这个里面是循环体，也就是不停循环里面的东西，文件扫描函数主要就是三个部分，首先是扫描哪个文件，接着是扫描完了之后格式化，也就是"%If",最后就是存储该扫描完之后的文件，所以是&temp，也不枉费我再前面定义了这个东西呀，那个fscanf代表的是文件扫描函数，是C语言程序里面自带的，所以是必须写上去的；括号里面是它要扫描的文件，也就是file，是一个文件指针，指向已经打开的文件；"%If"是格式说明符，%代表格式化的开始，I是long,f代表浮点数，必须都是要格式化的嘛，就像python里面的一样，它的格式化就是直接一个f""，果然每种语言还是有点差别的；&代表的是取地址符，表示里面的这个东西要存储到temp里面去
        count++;//表示count=count+1
    }

    if (count == 0) {//（）这个里面的是判断条件
        fclose(file);//不用多说，就是关闭该文件的意思
        printf("错误：文件 %s 中没有有效数据\n", input_file);
        return 1;
    }

    // 分配内存
    double* data = (double*)malloc(count * sizeof(double));//首先第一个=代表的是赋值，然后后面就使用了这个内存分配函数malloc,全称memory allocation,然后前面括号里面的就是将原来的malloc返回通用类型的指针的转化为double类型的指针，然后malloc后面括号里面的一大坨东西就代表着一共所需要占用的内存数量，count就是我们前面已经计算出来的需要多少个，*代表着就是乘法，后面就是double类型，也就是双精度浮点型的字节数，一般是8，所以是sizeof（double）,所以总的就是double*data=(double*)malloc(count*sizeof(double))
    if (data == NULL) {
        fclose(file);
        printf("内存分配失败\n");
        return 1;
    }

    // 重新读取数据
    rewind(file);//意思是倒带，将文件指针重新一会文件开头，重新进行文件读取
    for (size_t i = 0; i < count; i++) {//size_t i=0,意思就是创建计数器i，并将其初始化为0，后面就是当i<count时，就进行+1
        if (fscanf(file, "%lf", &data[i]) != 1) {//判断条件，就是当前不是进行了文件扫描嘛，也就是fscanf（file，"%lf",&temp）==1时嘛，然后不是进行了count++;这里的意思就是说当fscanf(file,"%lf",&data[i])!=1时，就会进行报错，就是跟这个fscanf（file，"%lf",&temp）==1时一个意思
            free(data);//这边就是释放数据
            fclose(file);//关闭文件
            printf("数据读取错误\n");//打印进行报错
            return 1;
        }
    }
    fclose(file);//倒带完了之后，要再将函数关闭，可以看见这边的fclose（file）;和rewind(file);是处于同一个等级的，所以倒带完了之后还要进行关闭

    // 2. 计算统计量
    double sum = 0;
    for (size_t i = 0; i < count; i++) {//()里面是判断条件；{}里面是循环体，用来循环进行；size_t i=0,意思就是创建计数器i，并将其初始化为0
        sum = sum + data[i];//就是把数组中的每个数都加到sum里面
    }
    double mean = sum / count;

    double fangcha = 0;
    for (size_t i = 0; i < count; i++) {//size_t i=0,意思就是创建计数器i，并将其初始化为0；接着是循环条件；然后是循环操作
        fangcha = (data[i] - mean) * (data[i] - mean);
    }
    fangcha = fangcha / count;

    // 3. 写入结果
    file = fopen(output_file, "w");
    if (file == NULL) {
        free(data);
        printf("无法创建文件 %s\n", output_file);
        return 1;
    }

    fprintf(file, "统计结果:\n");//fprintf 文件格式化输出函数
    fprintf(file, "数据个数: %zu\n", count);//%zu - 格式说明符(z表示size_t类型，u表示无符号)
    fprintf(file, "平均值: %.4f\n", mean);//%.4f - 格式说明符，表示保留4位小数
    fprintf(file, "方差: %.4f\n", fangcha);
    fclose(file);

    // 4. 清理内存
    free(data);
    printf("处理完成，结果已保存到 %s\n", output_file);
    return 0;
>>>>>>> a191e88c568cf9e2e2333f9de660d0447dd7f9b2
}