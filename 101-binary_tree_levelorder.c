#include "binary_trees.h"

Queue *init_queue(void);
void free_queue(Queue *queue);
void enqueue(Queue *queue, const binary_tree_t *tree_node);
const binary_tree_t *dequeue(Queue *queue);
int queue_is_empty(Queue *queue);

/**
 * init_queue - Initializes a new queue.
 *
 * Return: A pointer to the newly created queue, or NULL on failure.
 */
Queue *init_queue()
{
	Queue *new_queue = malloc(sizeof(Queue));

	if (!new_queue)
		return (NULL);

	new_queue->front = NULL;
	new_queue->rear = NULL;

	return (new_queue);
}

/**
 * free_queue - Frees a queue and all its nodes.
 *
 * @queue: A pointer to the queue to free.
 */
void free_queue(Queue *queue)
{
	while (!queue_is_empty(queue))
		dequeue(queue);
	free(queue);
}

/**
 * enqueue - Adds a tree node to the queue.
 *
 * @queue: A pointer to the queue.
 * @tree_node: A pointer to the tree node to enqueue.
 */
void enqueue(Queue *queue, const binary_tree_t *tree_node)
{
	QueueNode *new_node = malloc(sizeof(QueueNode));

	if (!new_node)
		return;

	new_node->tree_node = tree_node;
	new_node->next = NULL;

	if (queue->rear)
		queue->rear->next = new_node;
	queue->rear = new_node;

	if (!queue->front)
		queue->front = new_node;
}

/**
 * dequeue - Removes and retrieves the front node from the queue.
 *
 * @queue: A pointer to the queue.
 *
 * Return: A pointer to the dequeued tree node, or NULL if the queue is empty.
 */
const binary_tree_t *dequeue(Queue *queue)
{
	const binary_tree_t *tree_node;
	QueueNode *tmp = queue->front;

	if (!queue)
		return (NULL);

	queue->front = queue->front->next;

	if (!queue->front)
		queue->rear = NULL;

	tree_node = tmp->tree_node;
	free(tmp);

	return (tree_node);
}

/**
 * queue_is_empty - Checks if a queue is empty.
 *
 * @queue: A pointer to the queue.
 *
 * Return: 1 if the queue is empty, 0 otherwise.
 */
int queue_is_empty(Queue *queue)
{
	return (queue->front == NULL);
}

/**
 * binary_tree_levelorder - Goes through a bin-tree by level-order traversal.
 *
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *tmp;
	Queue *queue;

	if (!tree || !func)
		return;
	queue = init_queue();
	if (!queue)
		return;

	enqueue(queue, tree);

	while (!queue_is_empty(queue))
	{
		tmp = dequeue(queue);
		func(tmp->n);

		if (tmp->left)
			enqueue(queue, tmp->left);
		if (tmp->right)
			enqueue(queue, tmp->right);
	}
	free_queue(queue);
}
