#include <stdio.h>

int main() {
    // Массив из 3-х указателей на символы
    char *movies[] = {
        "Matrix",
        "Inception",
        "Interstellar"
    };

    int count = sizeof(movies) / sizeof(movies[0]);

    printf("🎬 Список фильмов:\n");
    for (int i = 0; i < count; i++) {
        // %s ожидает указатель на начало строки (char*)
        printf("%d. %s (Адрес в памяти: %p)\n", i + 1, movies[i], (void*)movies[i]);
    }

    // Изменение указателя: теперь второй элемент смотрит на другую строку
    movies[1] = "The Dark Knight";
    printf("\n🔄 Обновленный фильм №2: %s\n", movies[1]);

    return 0;
}
