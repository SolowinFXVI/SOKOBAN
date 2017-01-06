struct Node  {
	SOKOBAN data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head; // global variable - pointer to head node.
struct Node* tail;

struct Node* GetNewNode(SOKOBAN x);

void InsertAtHead(SOKOBAN x);

void InsertAtTail(SOKOBAN x);

SOKOBAN send_head();

SOKOBAN send_tail();
