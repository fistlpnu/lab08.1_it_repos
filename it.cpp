#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

// Функція для підрахунку кількості груп "OGO" або "AGA"
int Count(const char* str) {
    if (strlen(str) < 3) return 0;
    int count = 0;
    for (int i = 0; str[i + 2] != '\0'; i++) {
        if ((str[i] == 'O' && str[i + 1] == 'G' && str[i + 2] == 'O') ||
            (str[i] == 'A' && str[i + 1] == 'G' && str[i + 2] == 'A')) {
            count++;
        }
    }
    return count;
}

// Функція для заміни "OGO" та "AGA" на "***"
char* Change(char* str) {
    size_t len = strlen(str);
    if (len < 3) return str;

    // Виділяємо динамічну пам'ять для нового рядка
    char* tmp = new char[len * 2 + 1]; // Виділяємо з запасом
    char* t = tmp;
    tmp[0] = '\0';
    size_t i = 0;

    while (i < len && str[i + 2] != '\0') {
        if ((str[i] == 'O' && str[i + 1] == 'G' && str[i + 2] == 'O') ||
            (str[i] == 'A' && str[i + 1] == 'G' && str[i + 2] == 'A')) {
            strcat_s(t, len * 2 + 1, "***");
            t += 3;
            i += 3;
        }
        else {
            *t++ = str[i++];
            *t = '\0';
        }
    }

    // Копіюємо залишок рядка
    while (i < len) {
        *t++ = str[i++];
    }
    *t = '\0';

    // Копіюємо результат у початковий рядок
    strcpy_s(str, len + 1, tmp);
    delete[] tmp; // Звільняємо пам'ять
    return str;
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contained " << Count(str) << " groups of \"OGO\" or \"AGA\"." << endl;

    char* modifiedStr = Change(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << modifiedStr << endl;

    return 0;
}
