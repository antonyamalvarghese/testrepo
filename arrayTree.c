#include <stdio.h>
#define MAX 100

char tree[MAX];
int end = -1;

void clearTree() {
    for (int i = 0; i < MAX; i++) {
        tree[i] = '-';   // '-' means empty
    }
    end = -1;
}

void insertRoot(char root) {
    if (tree[0] == '-') {
        tree[0] = root;
        end = 0;
    } else {
        printf("Root already exists!\n");
    }
}

void insertChild(char parent, char child, char pos) {
    int i = 0;
    while (i <= end && tree[i] != parent) {
        i++;
    }
    if (i > end) {
        printf("Parent not found!\n");
        return;
    }
    if (pos == 'L' || pos == 'l') {
        int left = 2 * i + 1;
        if (left < MAX && tree[left] == '-') {
            tree[left] = child;
            if (end < left) end = left;
        } else {
            printf("Left position occupied or out of bound!\n");
        }
    } else if (pos == 'R' || pos == 'r') {
        int right = 2 * i + 2;
        if (right < MAX && tree[right] == '-') {
            tree[right] = child;
            if (end < right) end = right;
        } else {
            printf("Right position occupied or out of bound!\n");
        }
    }
}

void displayTree() {
    if (end == -1) {
        printf("Tree is empty!\n");
        return;
    }
    printf("Tree (Array Representation):\n");
    for (int i = 0; i <= end; i++) {
        printf("%c ", tree[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    char root, parent, child, pos;
    clearTree();
     printf("\n========== MENU ==========\n");
        printf("1. Insert Root\n");
        printf("2. Insert Child\n");
        printf("3. Display Tree\n");
        printf("4. Clear Tree\n");
        printf("5. Exit\n");
    while (1) {
       
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter root element: ");
                scanf(" %c", &root);
                insertRoot(root);
                break;
            case 2:
                printf("Enter parent, child, position(L/R): ");
                scanf(" %c %c %c", &parent, &child, &pos);
                insertChild(parent, child, pos);
                break;
            case 3:
                displayTree();
                break;
            case 4:
                clearTree();
                printf("Tree cleared!\n");
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
