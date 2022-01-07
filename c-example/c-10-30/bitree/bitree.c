#include <stdio.h>
#include <stdlib.h>

#define NAMESIZE 32
struct score {
	int id;
	char name[NAMESIZE];
	int math;
};

struct node_st{
	struct score data;
	struct node_st *l, *r;
};

struct node_st *tree = NULL;
static void print_s(void *record){
	struct score *r = record;
	printf("%d  %s  %d\n",r->id,  r->name, r->math);
}

static int id_cmp(const void *key, const void *record){
	const int *k = key;
	const struct score *r = record;
	return (*k - r->id);
}

int insert(struct node_st **root, struct score *data){
	struct node_st *node;
	if(*root == NULL){
		node = malloc(sizeof(*node));
		if (node == NULL){
			printf("malloc error\n");
		}
		node->data = *data;
		node->l = node->r = NULL;
		*root = node;
		return 0;
	}
	if(data->id <= (*root)->data.id){
		return insert(&(*root)->l, data);
	}
	return insert(&(*root)->r, data);
}

struct score *find(struct node_st *root, int id){
	if (root == NULL){
		return NULL;
	}
	if(id == root->data.id){
		return &root->data;
	}
	if(id < root->data.id){
		return find(root->l,id);
	}
	return find(root->r,id);
}

static void draw_(struct node_st *root, int level){
	int i;
	if (root == NULL)
		return;
	draw_(root->r, level+1);
	for (i= 0; i < level; i++){
		printf("    ");
	}
	print_s(&root->data);
	draw_(root->l, level+1);
}

void draw(struct node_st *root){
	draw_(root, 0);
	printf("\n\n\n");
	getchar();
}

static int get_num(struct node_st *root){
	if(root == NULL)
		return 0;
	return(get_num(root->l) + 1 + get_num(root->r));
}

static struct node_st *find_min(struct node_st *root){
	if(root->l == NULL)
		return root;
	return find_min(root->l);
}


static struct node_st *find_max(struct node_st *root){
	if(root->r == NULL)
		return root;
	return find_max(root->r);
}
// 先序遍历
void travel1(struct node_st *root){
	if(root == NULL)
		return;
	print_s(&root->data);
	travel1(root->l);
	travel1(root->r);
}
// 中序遍历
void travel2(struct node_st *root){
	if(root== NULL)
		return;
	travel2(root->l);
	print_s(&root->data);
	travel2(root->r);
}
// 按层遍历
//

int main(){
	int arr[] = {1,2,3,7,6,5,9,8,4};
	struct score tmp,*datap;
	int i;
	for (i = 0; i < sizeof(arr)/sizeof(*arr); i++){
		tmp.id = arr[i];
		tmp.math = 100 - arr[i];
		snprintf(tmp.name,NAMESIZE, "stu%d", arr[i]);
		insert(&tree, &tmp);
	}
	draw(tree);
	travel1(tree);
	travel2(tree);

	return 0;
}
