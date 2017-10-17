#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


void arr() {
    printf("-------------数组-------------\n");
    /**
    * 数组:特殊的指针
    */
    int ar[10]; //他是一个特殊的指针
    //ar不做初始化,默认的值全是机器垃圾值
    for (int k = 0; k < 10; ++k) {
        printf("%d ", ar[k]);
    }
    printf("\n");
    int *ap = ar; //他本是是一个地址,所以可以直接赋给一个指针
    int *a1 = &ar[0]; //ar[0]是一个变量值,所以需要通过取地址赋给指针变量
    printf("ap=%d,a1=%d\n", ap, a1); //ap=a1
    //[]可以对数组和指针做
    int ap0 = ap[2];
    int ar0 = ar[2];
    printf("ap0=%d\n", ap0);
    printf("ar0=%d\n", ar0); //两个也是一样的
    //*可以对数组做
    *ar = 11; //对第一个元素赋值
    *(ar + 1) = 12; //对第二个元素赋值:ar+1指向数组下一个元素,*加一个指针表示取地址里面的值
    printf("ar[0]=%d,ar[1]=%d\n", ar[0], ar[1]);
    //数组变量是一个const指针,所以不能呢个再次赋值,只能初始化
//    int b[] = ar; //错误
    int ar1[10] = {1}; //初始化第一个元素,网上有说这种方式是初始化所有元素,不过这里试了并不是这样,还是初始化第一个元素,看运行结果就知道了
    int ar2[10] = {1, 2}; //初始化前两个元素
    for (int j = 0; j < 10; ++j) {
        printf("%d ", ar1[j]);
    }
    printf("\n");
    for (int j = 0; j < 10; ++j) {
        printf("%d ", ar2[j]);
    }
    printf("\n");

    //二维数组
    int aa[3][4]; //int类型二维数组
    int (*p)[4]; //定义一个数组指针,他的值也是一个大小为4的数组.
    p = aa; //将二维数组首地址赋给p,也就是a[0]或者&a[0][0]
    p++; //p指向了a[1][]
    aa[1][0] = 2;
    printf("p[0]=%d\n", *p[0]); //*p是取值,因为他的值是一个数组,所以可以直接[0]拿到第一个元素


}

void str() {
    printf("-------------string-------------\n");
    //字符串
    char c[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    printf("c=%s,len=%d\n", c, strlen(c)); //strlen()不包括\0
    char c2[6] = {'H', 'e', 'l', 'l', 'o'}; //这里长度设置为5时,字符串变成了"HelloHello"这个是为什么?
    printf("c2=%s,len=%d\n", c2, strlen(c2));
    char *str = "Hello World";
    printf("str=%s,len=%d\n", str, strlen(str));
    //字符串赋值
    char c3[12];
    strcpy(c3, "Hello World");
    printf("c3=%s,len=%d\n", c3, strlen(c3));

    printf("-------------string array-------------\n");
    char arr[][5] = {"Hello", "World"};
    char *arr2[] = {"Hello", "World"};

}

void number() {
    printf("-------------number-------------\n");
    int i = 012; //8进制
    int j = 0x12; //16进制
    printf("i=%d,j=%d\n", i, j); //%d是十进制
    printf("i=0%o,j=0x%x\n", i, j); //%o是八进制,%x是16进制
}

void sizes() {
    printf("-------------sizeof-------------\n");
    //取类型或者变量的长度
    printf("sizeof(int):%d\n", sizeof(int));
    int a = 0;
    printf("sizeof(a):%d\n", sizeof(a));
}

void unsigneds() {
    printf("-------------signed&unsigned-------------\n");
    char c = -1;
    printf("c=%d\n", c);
    char c2 = 255; //这里虽然是255,但是其实是-1,因为是补码,c2的二进制是11111111,对应的原码是10000001即-1. 默认char是signed 类型
    printf("c2=%d\n", c2);

    signed int si = -255; //默认是有符号
    unsigned int usi = -255;
    printf("si=%d,usi=%u\n", si, usi); //%u:无符号整型
}

void floats() {
    printf("-------------浮点型-------------\n");
    float f = 1.123f;
    float ff = 2.123f;
    float sum = f + ff; //浮点数不是精确的,所以要算钱这样的东西,可以改到最小单位如分,然后用整数计算.
    if (sum == 3.246f) {
        printf("相等\n");
    } else {
        printf("不相等\n:sum=%.10f,sum=%f\n", sum, sum);
    }
}

void point() {
    printf("-------------指针*和取地址符&-------------\n");

    /**
    * 指针,指针的值都是一个表示地址空间中某个存储器单元的整数
    * &取地址运算符
    */
    int i1 = 5;
    printf("i1=%d\n", i1);
    printf("i1的地址是%p\n", &i1); //%p是指针,一般输出一个十六进制正数,前面附加0x
    //指针变量
    int *p;
    p = &i1; //取i1的地址赋给指针变量p
    printf("*p的值是%d\n", *p); //指针变量前面有*时(*表达式),表示取这个指针变量锁存放的地址里面的数据


    printf("-------------\n");

    //定义一个数组和一个 存放 char 类型的指针
    char a[5] = "1235", *b;
    //可以直接将char数组 给 char*
    b = a;
    printf("b的值:%c\n", *b); //取值
    //将地址向后移动两位,移到了3的指针
    b += 2;
    //*b 代表取出地址 b 存放的元素值
    printf("b的值变成:%c\n", *b);    //结果:3
    printf("(b+1)的值:%c\n", *(b + 1));    //结果:5

    char *aa = &a; //取地址运算符,取出 a 数组的地址,也就是第一个元素的地址
    char **bb = &b;   //取出指针元素 b 的地址,指针的指针
    printf("bb=%p,bb最终指向的值:%c,,aa=%c\n", *bb, **bb, *aa); //**bb,先取*(*b)中存储的值,他是存储b的地址值(即*b),然后再一个*表示取出b的值

    printf("-------------\n");

    int iii = 3;
    double ddd = 3.141692;
    float fff = 3.1423;
    char ccc = 'B';
    int *ip = &iii;
    double *dp = &ddd;
    float *fp = &fff;
    char *cp = &ccc;
    printf("int 类型指针变量的长度为 %d\n", sizeof(ip));  // --> 4
    printf("double 类型指针变量的长度为 %d\n", sizeof(dp)); // --> 4
    printf("float 类型指针变量的长度为 %d\n", sizeof(fp)); // --> 4
    printf("char 类型指针变量的长度为 %d\n", sizeof(cp)); // --> 4


    char car[4] = {'a', 'b', 'c', 'd'}; //如果不初始化,拿到的也是机器乱码值
    char *pChar = &car[2]; //取数组第三个元素的地址
    printf("pChar的内存地址:%p,对应的值为:%c\n", pChar, *(pChar));
    printf("pChar+1的内存地址:%p,对应的值为:%c\n", pChar + 1, *(pChar + 1));

}


void sayHi(void (*p)(char const *str)) {
    p("hi2");
}

void print(char const *str) {
    printf("---%s----\n", str);
}

void malloctest() {
    printf("-------------malloc test-------------\n");
    int n = 10;
    //分配10个int大小的内存,失败返回0
    int *p = NULL;
    p = (int *) malloc(n * sizeof(int));
    if (NULL == p) {
        printf("cannot get memory!\n");
        return;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d\t", p[i]);
    }
    printf("\n");
    memset(p, 0, n * sizeof(int)); //将p指向的空间清0
    printf("malloc result:%d\n", *p); //输出分配的空间上的值
    *p = 10;
    printf("赋值结束:%d\n", *p);
    //回收p
    free(p);
}

void calloctest() {
    printf("-------------calloc test-------------\n");
    int *pData;
    int i = 4;
    pData = (int *) calloc(i, sizeof(int));
    if (pData == NULL) {
        printf("空间申请失败!\n");
        return;
    }
    for (int j = 0; j < 4; ++j) {
        printf("%d ", pData[j]);
    }
    printf("\n");
}

void realoctest() {
    printf("-------------realloc test-------------\n");
    char *p, *q;
    p = (char *) malloc(5 * sizeof(char));
    q = p;
    p = (char *) realloc(p, 10);
    //这里新内存空间比较小可能p和q就是一样的;如果是一个很大的值,如10000,就可能变化.
    printf("p=0x%x\n", p);
    printf("q=0x%x\n", q);
}


void enums() {
    printf("-------------enum-------------\n");
    enum Type {
        Open, Close
    };
    enum Type t = Open;
    printf("%d\n", t);
}

void structs() {
    printf("-------------结构体-------------\n");
    struct Position {
        int x;
        int y;
    };
    struct Position p = {1, 2}; //初始化
    struct Position q;
    q.x = 1;
    q.y = 2;
    printf("{%d,%d}\n", q.x, q.y);
    struct Position *r = &q; //结构体指针
    (*r).x = 1; //通过*取变量,然后给他的x赋值
    r->y = 2; //通过->给他的y赋值,->是指针取值的简写
    printf("r->y=%d\n", r->y);

    struct Position s = (struct Position) {4, 5}; //相当于s.x=4,s.y=5
    printf("after =:{%d,%d}\n", s.x, s.y);
    s = q;
    printf("after s=q: {%d,%d}\n", s.x, s.y);
}

void unions() {
    printf("-------------联合体-------------\n");
    union Value {
        int x;
        float y;
        char z;
        double q;
    };
    union Value v;
    v.x = 1;
    printf("%d, %f, %c, %f\n", v.x, v.y, v.z, v.q);
    v.z = 'A';
    printf("%d, %f, %c, %f\n", v.x, v.y, v.z, v.q);
    v.y = 0.1;
    printf("%d, %f, %c, %f\n", v.x, v.y, v.z, v.q);
    v.q = 0.2;
    printf("%d, %f, %c, %f\n", v.x, v.y, v.z, v.q);
    printf("%zu\n", sizeof(union Value));
    printf("sizeof(double):%d\n", sizeof(double));
    printf("sizeof(float):%d\n", sizeof(float));
    printf("sizeof(int):%d\n", sizeof(int));
    printf("sizeof(char):%d\n", sizeof(char));
}

void typedefs() {
    printf("-------------别名-------------\n");
    typedef int Age;
    typedef int *AgeP;
    struct Man {
        char *name;
    };
    typedef struct Man Student, *StudentP;

    Age a = 1;
    printf("a=%d\n", a);
    AgeP ap = &a;
    printf("ap=%d\n", *ap);
    Student student;
    student.name = "Jack";
    printf("student.name=%s\n", student.name);
    StudentP studentP = &student;
    printf("studentP=%s\n", studentP->name);
}

void defines() {
    printf("-------------宏定义-------------\n");
#define PI 3.14159
#define cube(x) ((x)*(x)*(x))
    printf("%d\n", cube(2)); //8
    double x = 2 * PI;
    printf("x=%f", x);
}


int main() {

    //hello world
    printf("Hello\n");
    //求类型或者变量的长度
    sizes();
    //数字和进制
    number();
    //符号和无符号
    unsigneds();
    //指针
    point();
    //函数指针
    sayHi(print);
//    //数组
    arr();
    //浮点型
    floats();
    //动态内存分配
    malloctest();
    calloctest();
    realoctest();
//    //字符串
    str();
    //枚举
    enums();
    //结构体
    structs();
    //联合体
    unions();
    //别名
    typedefs();
    //宏
    defines();


    return 0;
}


