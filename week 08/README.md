## Динамично заделяне на памет

### Свойства
- статична срещу динамична памет
- динамично деклариране на променлива
- деклариране на масив с размерност стойност на променлива
- изчистване на заделената памет

### Примери
- деклариране на променлива
```c++
int* n = new int(5);

// изчистване на паметта
delete n;
```

- деклариране на масив с произволен размер
```c++
size_t size;
std::cin >> size;
int* array = new int[size];

// изчистване на паметта
delete[] array;
```

- деклариране на матрица
```c++
size_t n, m;
std::cin >> n >> m;
char** matrix = new int*[n];

for (size_t i = 0; i < n; ++i) {
    matrix[i] = new int[m];
}

// изчистване на паметта
for (size_t i = 0; i < n; ++i) {
    delete[] matrix[i];
}
delete[] matrix;
```

### Tips & Tricks:
| <div style="width:100px" />           |  <div style="width:175px" /> Грешно     |  <div style="width:250px" />  Правилно | Защо?       |
| --------- | ----------- | --------- | ----------- |
| delete / delete[]                     | int* arr = new int[7]; <br> delete arr; <br> int *n = new int; <br> delete[] n; | int* arr = new int[7]; <br> delete[] arr; <br> int *n = new int; <br> delete n; | При изтриване на масив, операторът е delete[]. Ако обектът, който трябва да се изтрие, е единична променлива, се използва delete.  


