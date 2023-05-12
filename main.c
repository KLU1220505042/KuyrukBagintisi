#include <stdio.h>
#include <stdlib.h>

// Kuyruk yapýsý için düðüm tanýmý
struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

// Yeni düðüm oluþturma fonksiyonu
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Kuyruk sonuna eleman ekleme fonksiyonu
void enqueue(int data) {
    struct Node* temp = newNode(data);
    if (rear == NULL) {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

// Kuyruk baþýndan eleman silme fonksiyonu
void dequeue() {
    if (front == NULL) {
        printf("Kuyruk bos\n");
        return;
    }
    struct Node* temp = front;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
}

// Kuyruktaki tüm elemanlarý yazdýrma fonksiyonu
void display() {
    if (front == NULL) {
        printf("Kuyruk bos\n");
        return;
    }
    struct Node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("1. Eleman Ekle\n");
        printf("2. Eleman Sil\n");
        printf("3. Kuyruktaki Elemanlari Goster\n");
        printf("4. Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Eklenecek elemani girin: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Gecersiz secim\n");
        }
    }
    return 0;
}

