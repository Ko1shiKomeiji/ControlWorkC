#define N 40

struct Data {
    double f;
    char s[N];
};

typedef struct Node {
    struct Data data;
    struct Node *next;
    struct Node *prev;
} node;

int llength(node *head);
void lprint(node *head);
node *add_head(node *head, struct Data *data);
int checker(node *L1, node *L2);