struct ListNode {
    int val;
    struct ListNode *next;
};

void print(struct ListNode* node);
void insert(struct ListNode* node, int num);

struct ListNode* merge(struct ListNode* left, struct ListNode* right);

struct ListNode* sortList(struct ListNode* head);
struct ListNode* merge(struct ListNode* left, struct ListNode* right);

struct ListNode* sortListPartitionV1(struct ListNode* head);
bool sortPartListV1(struct ListNode* left, struct ListNode* right);
