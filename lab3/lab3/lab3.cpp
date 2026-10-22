#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct node
{
    char inf[50];
    int priority;
    struct node* next;
};

struct node* priorityHead = NULL;
struct node* queueHead = NULL;
struct node* queueLast = NULL;
struct node* stackHead = NULL;


void priorityAdd()
{
    struct node* p;
    struct node* temp;

    p = (struct node*)malloc(sizeof(struct node));
    if (p == NULL)
    {
        printf("Ошибка выделения памяти\n");
        return;
    }

    printf("Введите название: ");
    scanf("%49s", p->inf);

    printf("Введите приоритет: ");
    scanf("%d", &p->priority);

    p->next = NULL;

    if (priorityHead == NULL)
    {
        priorityHead = p;
        return;
    }

    if (p->priority > priorityHead->priority)
    {
        p->next = priorityHead;
        priorityHead = p;
        return;
    }

    temp = priorityHead;

    while (temp->next != NULL &&
        temp->next->priority >= p->priority)
    {
        temp = temp->next;
    }

    p->next = temp->next;
    temp->next = p;
}

void priorityReview()
{
    struct node* temp = priorityHead;

    if (priorityHead == NULL)
    {
        printf("Очередь пуста\n");
        return;
    }

    while (temp != NULL)
    {
        printf("Название: %s, приоритет: %d\n",
            temp->inf, temp->priority);
        temp = temp->next;
    }
}

void priorityFind()
{
    char name[50];
    struct node* temp = priorityHead;

    printf("Введите название для поиска: ");
    scanf("%49s", name);

    while (temp != NULL)
    {
        if (strcmp(temp->inf, name) == 0)
        {
            printf("Элемент найден: %s, приоритет: %d\n",
                temp->inf, temp->priority);
            return;
        }

        temp = temp->next;
    }

    printf("Элемент не найден\n");
}

void priorityDelete()
{
    struct node* temp;

    if (priorityHead == NULL)
    {
        printf("Очередь пуста\n");
        return;
    }

    temp = priorityHead;
    priorityHead = priorityHead->next;

    printf("Удален элемент: %s\n", temp->inf);
    free(temp);
}

void priorityChange()
{
    char name[50];
    int newPriority;
    struct node* temp = priorityHead;
    struct node* prev = NULL;
    struct node* p;

    printf("Введите название: ");
    scanf("%49s", name);
    printf("Введите новый приоритет: ");
    scanf("%d", &newPriority);

    // Просто идем по списку ОДИН РАЗ от начала до конца
    while (temp != NULL)
    {
        if (strcmp(temp->inf, name) == 0)
        {
            struct node* nextNode = temp->next; // Запоминаем, кто идет дальше

            // Твое отсоединение элемента
            if (prev == NULL)
                priorityHead = temp->next;
            else
                prev->next = temp->next;

            temp->priority = newPriority;

            // Твоя вставка элемента на новое место
            if (priorityHead == NULL || newPriority > priorityHead->priority)
            {
                temp->next = priorityHead;
                priorityHead = temp;
            }
            else
            {
                p = priorityHead;
                while (p->next != NULL && p->next->priority >= newPriority)
                {
                    p = p->next;
                }
                temp->next = p->next;
                p->next = temp;
            }

            // Переходим к следующему элементу
            // Так как мы изменили порядок, prev для следующего элемента нужно обновить
            if (priorityHead == nextNode) {
                prev = NULL;
            }
            else {
                p = priorityHead;
                while (p != NULL && p->next != nextNode) {
                    p = p->next;
                }
                prev = p;
            }
            temp = nextNode;
        }
        else
        {
            // Если имя не совпало, просто шагаем вперед как обычно
            prev = temp;
            temp = temp->next;
        }
    }
}

void queueAdd()
{
    struct node* p;

    p = (struct node*)malloc(sizeof(struct node));
    if (p == NULL)
    {
        printf("Ошибка выделения памяти\n");
        return;
    }

    printf("Введите название: ");
    scanf("%49s", p->inf);

    p->next = NULL;

    if (queueHead == NULL)
    {
        queueHead = p;
        queueLast = p;
    }
    else
    {
        queueLast->next = p;
        queueLast = p;
    }
}

void queueReview()
{
    struct node* temp = queueHead;

    if (queueHead == NULL)
    {
        printf("Очередь пуста\n");
        return;
    }

    while (temp != NULL)
    {
        printf("Название: %s\n", temp->inf);
        temp = temp->next;
    }
}

void queueFind()
{
    char name[50];
    struct node* temp = queueHead;

    printf("Введите название для поиска: ");
    scanf("%49s", name);

    while (temp != NULL)
    {
        if (strcmp(temp->inf, name) == 0)
        {
            printf("Элемент найден: %s\n", temp->inf);
            return;
        }

        temp = temp->next;
    }

    printf("Элемент не найден\n");
}

void queueDelete()
{
    struct node* temp;

    if (queueHead == NULL)
    {
        printf("Очередь пуста\n");
        return;
    }

    temp = queueHead;
    queueHead = queueHead->next;

    if (queueHead == NULL)
        queueLast = NULL;

    printf("Удален элемент: %s\n", temp->inf);
    free(temp);
}

void stackAdd()
{
    struct node* p;

    p = (struct node*)malloc(sizeof(struct node));
    if (p == NULL)
    {
        printf("Ошибка выделения памяти\n");
        return;
    }

    printf("Введите название: ");
    scanf("%49s", p->inf);

    p->next = stackHead;
    stackHead = p;
}

void stackReview()
{
    struct node* temp = stackHead;

    if (stackHead == NULL)
    {
        printf("Стек пуст\n");
        return;
    }

    while (temp != NULL)
    {
        printf("Название: %s\n", temp->inf);
        temp = temp->next;
    }
}

void stackFind()
{
    char name[50];
    struct node* temp = stackHead;

    printf("Введите название для поиска: ");
    scanf("%49s", name);

    while (temp != NULL)
    {
        if (strcmp(temp->inf, name) == 0)
        {
            printf("Элемент найден: %s\n", temp->inf);
            return;
        }

        temp = temp->next;
    }

    printf("Элемент не найден\n");
}

void stackDelete()
{
    struct node* temp;

    if (stackHead == NULL)
    {
        printf("Стек пуст\n");
        return;
    }

    temp = stackHead;
    stackHead = stackHead->next;

    printf("Удален элемент: %s\n", temp->inf);
    free(temp);
}


void clearAll()
{
    struct node* temp;

    while (priorityHead != NULL)
    {
        temp = priorityHead;
        priorityHead = priorityHead->next;
        free(temp);
    }

    while (queueHead != NULL)
    {
        temp = queueHead;
        queueHead = queueHead->next;
        free(temp);
    }
    queueLast = NULL;

    while (stackHead != NULL)
    {
        temp = stackHead;
        stackHead = stackHead->next;
        free(temp);
    }
}


int main()
{
    setlocale(LC_ALL, "Russian");

    int choice;
    int operation;

    do
    {
        printf("\n===== ЛАБОРАТОРНАЯ РАБОТА №3 =====\n");
        printf("1 - Приоритетная очередь\n");
        printf("2 - Очередь\n");
        printf("3 - Стек\n");
        printf("0 - Выход\n");
        printf("Выберите структуру: ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            do
            {
                printf("\n--- ПРИОРИТЕТНАЯ ОЧЕРЕДЬ ---\n");
                printf("1 - Добавить\n");
                printf("2 - Показать\n");
                printf("3 - Найти\n");
                printf("4 - Удалить первый по приоритету\n");
                printf("5 - Изменить приоритет по названию\n");
                printf("0 - Назад\n");
                printf("Выберите действие: ");

                scanf("%d", &operation);

                switch (operation)
                {
                case 1:
                    priorityAdd();
                    break;
                case 2:
                    priorityReview();
                    break;
                case 3:
                    priorityFind();
                    break;
                case 4:
                    priorityDelete();
                    break;
                case 5:
                    priorityChange();
                    break;
                case 0:
                    break;
                default:
                    printf("Неверный выбор\n");
                }
            } while (operation != 0);
            break;

        case 2:
            do
            {
                printf("\n--- ОБЫЧНАЯ ОЧЕРЕДЬ ---\n");
                printf("1 - Добавить\n");
                printf("2 - Показать\n");
                printf("3 - Найти\n");
                printf("4 - Удалить первый\n");
                printf("0 - Назад\n");
                printf("Выберите действие: ");

                scanf("%d", &operation);

                switch (operation)
                {
                case 1:
                    queueAdd();
                    break;
                case 2:
                    queueReview();
                    break;
                case 3:
                    queueFind();
                    break;
                case 4:
                    queueDelete();
                    break;
                case 0:
                    break;
                default:
                    printf("Неверный выбор\n");
                }
            } while (operation != 0);
            break;

        case 3:
            do
            {
                printf("\n--- СТЕК ---\n");
                printf("1 - Добавить\n");
                printf("2 - Показать\n");
                printf("3 - Найти\n");
                printf("4 - Удалить верхний\n");
                printf("0 - Назад\n");
                printf("Выберите действие: ");

                scanf("%d", &operation);

                switch (operation)
                {
                case 1:
                    stackAdd();
                    break;
                case 2:
                    stackReview();
                    break;
                case 3:
                    stackFind();
                    break;
                case 4:
                    stackDelete();
                    break;
                case 0:
                    break;
                default:
                    printf("Неверный выбор\n");
                }
            } while (operation != 0);
            break;

        case 0:
            break;

        default:
            printf("Неверный выбор\n");
        }

    } while (choice != 0);

    clearAll();
    return 0;
}