#include "binary_trees.h"

Queue *init_queue(void);
void free_queue(Queue *queue);
void enqueue(Queue *queue, const binary_tree_t *tree_node);
const binary_tree_t *dequeue(Queue *queue);
int queue_is_empty(Queue *queue);


/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 0 if `tree` is NULL or the tree is not complete, 1 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	const binary_tree_t *tmp;
	Queue *queue;
	int isNullNodeEnc = 0;

	if (!tree)
		return (0);

	queue = init_queue();
	if (!queue)
		return (0);
	enqueue(queue, tree);

	while (!queue_is_empty(queue))
	{
		tmp = dequeue(queue);
		if (!tmp)
			isNullNodeEnc = 1;
		else
		{
			if (isNullNodeEnc)
				return (0);
			enqueue(queue, tmp->left);
			enqueue(queue, tmp->right);
		}
	}
	free_queue(queue);
	return (1);
}

/**
 * init_queue - Initializes a new queue.
 *
 * Return: A pointer to the newly created queue, or NULL on failure.
 */
Queue *init_queue(void)
{
	Queue *new_queue = malloc(sizeof(Queue));

	if (!new_queue)
		return (NULL);

	new_queue->front = NULL;
	new_queue->rear = NULL;

	return (new_queue);
}

/**
 * enqueue - Adds a tree node to the queue.
 *
 * @queue: A pointer to the queue.
 * @tree_node: A pointer to the tree node to enqueue.
 */
void enqueue(Queue *queue, const binary_tree_t *tree_node)
{
	QueueNode *new_node;

	if (!queue)
		return;

	new_node = malloc(sizeof(QueueNode));
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
	QueueNode *tmp = queue->front;
	const binary_tree_t *tree_node;

	if (!queue || !queue->front)
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
 * free_queue - Frees a queue.
 *
 * @queue: A pointer to the queue to free.
 */
void free_queue(Queue *queue)
{
	free(queue);
}
