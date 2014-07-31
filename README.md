合并排序的泛型实现
=========

合并排序算法，可以对任意类型的数据进行排序。通过使用宏来定义合并排序算法的函数体的方式，来满足使用者根据自己的需要排序的元素类型以及比较函数，来完成对数组元素的排序。


## 使用方式
使用者只需根据自己需要的元素的类型定义一个排序函数，并调用我们实现的宏即可， 例如：
```
int cmp_int(int a, int b) {
    if (a < b) {
        return -1;
    } else if (a == b) {
        return 0;
    } else {
        return 1;
    }
}
void sort_int_array(int *arr, int *aux_arr, uint32_t low, uint32_t high) {
    UT_SORT_FUNCTION_BODY(sort_int_array, arr, aux_arr, low, high, cmp_int);
}
```

## 注意：
1. 使用者必须自己实现比较函数，函数可以参考上面例子
2. 排序函数的low所所索引的值将会被函数排序，而high所索引的值将不会被排序
3. aux_arr和arr两个数组的空间大小必须一样
4. 排序是使用合并排序算法，算法的时间复杂度是O(logN)

