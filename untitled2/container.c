#include <stdlib.h>
#include "container.h"
#include "timer.h"

/// Инициализируем новый контейнер.
/// \param container контейнер.
void Initialize_cont(struct_cont *container) {
    container->count = 0;
}

/// Записывание в контейнер нового элемента.
/// \param container контейнер.
/// \param transport транспорт.
int Add_cont(struct_cont *container, struct_transport* transport) {
    int ans = 0;
    if (container->count >= 10000) {
        ans = -1;
    } else {
        container->count += 1;
        container->data[container->count - 1] = transport;
    }
    return ans;
}

/// Заполнений контейнера данными из файла.
/// \param container The container to be filled.
/// \param input_stream Input file stream.
void Fill_cont(struct_cont *container, FILE *input_stream) {
    struct_transport *transport;
    while((transport = To_Transport(input_stream)) != NULL) {
        Add_cont(container, transport);
    }
}

/// Заполняем контейнер случайными значениями.
/// \param container контейнер.
/// \param count счетчик объектов для генерации.
void Fill_cont_Rand(struct_cont *container, unsigned int count) {
    while(container->count < count) {
        Add_cont(container, ToRand_Transport());
    }
}

/// Очищение контейнера.
/// \param container контейнер.
void Clear_cont(struct_cont *container) {
    for (int i = 0; i < container->count; i++) {
        container->data[i] = NULL;
    }
    container->count = 0;
}

/// Выводим информацию о контейнере.
/// \param container контейнер.
/// \param output_stream выходной файл.
void Out_cont(struct_cont *container, FILE *output_stream) {
    FileCheck(output_stream, 1);
    fprintf(output_stream, "There are %d vehicles in the container.\n", container->count);
    printf("There are %d vehicles in the container.\n", container->count);
    for(int i = 0; i < container->count; i++) {
        fprintf(output_stream, "%d: ", i + 1);
        Out_Transport(container->data[i], output_stream);
    }
}
/// Метод для сортировки элементов контейнера слиянием (Merge Sort).
/// \param i индекс левой границы.
/// \param j индекс правой границы.
/// \param container контейнер.
/// \param help_container вспомогательный контейнер.
void Straight_Merge(int i, int j, struct_cont *container, struct_cont *help_container) {
    if (j == -1) {
        j = container->count-1;
    }
    if (j <= i) {
        return;
    }
    int mid = (i + j) / 2;
    // Отправляем на сортировку половинки контейнера.
    Straight_Merge(i, mid, container, help_container);
    Straight_Merge(mid + 1, j, container, help_container);
    int pointer_left = i;
    int pointer_right = mid + 1;
    int k;
    for (k = i; k <= j; k++) {
        if (pointer_left == mid + 1) {
            help_container->data[k] = container->data[pointer_right];
            pointer_right++;
        } else if (pointer_right == j + 1) {
            help_container->data[k] = container->data[pointer_left];
            pointer_left++;
        } else if (RoadTime(container->data[pointer_left]) > RoadTime(container->data[pointer_right])) {
            help_container->data[k] = container->data[pointer_left];
            pointer_left++;
        } else {
            help_container->data[k] = container->data[pointer_right];
            pointer_right++;
        }
    }
    for (k = i; k <= j; k++) {
        container->data[k] = help_container->data[k];
    }
}
