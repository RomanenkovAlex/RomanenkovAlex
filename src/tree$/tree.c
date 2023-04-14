#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_item
{
    void *val;
    struct s_item *next;
} t_item;

typedef struct s_stack
{
    t_item *head;
    size_t size;
} t_stack;

t_item *create_item(void* val)
{
    t_item *item = calloc(1, sizeof(t_item));
    if (item)
        item->val = val;
    return item;
}

void stck_init(t_stack *stack)
{
    if (!stack)
        return;
    stack->head = NULL;
    stack->size = 0;
}

void stck_push(t_stack *stack, void *ptr)
{
    t_item *item = NULL;
    if (!stack || !(item = create_item(ptr)))
        return;
    item->next = stack->head;
    stack->head = item;
    ++stack->size;
}

void *stck_pop(t_stack *stack)
{
    void *ptr = NULL;
    t_item *next = NULL;

    if (!stack || !stack->size)
        return NULL;
    next = stack->head->next;
    ptr = stack->head->val;
    free(stack->head);
    stack->head = next;
    --stack->size;
    return ptr;
}

int stck_empty(t_stack *stack)
{
    if (!stack)
        return -1;
    return !stack->size;
}

struct s_tree
{
    int val;
    char height;
    struct s_tree *right;
    struct s_tree *left;
};

typedef struct s_tree t_tree;

t_tree *btree_new(int n)
{
    t_tree *item = calloc(1, sizeof(t_tree));
    if (item)
        item->val = n;
    return item;
}

void btree_clean(t_tree *elem /*, void (*cleanup)(void*) */ ) // функция очистки дерева
{
    if (elem->right)
        btree_clean(elem->right);
    if (elem->left)
        btree_clean(elem->left);
    // elem->val = NULL;
    // cleanup(elem->val);
    free(elem);
}

void btree_inorder_stack(t_tree *root)
{
    t_stack *s = calloc(1, sizeof(t_stack));

    stck_init(s);
    while (root || !stck_empty(s))
    {
        while (root)
        {
            stck_push(s, root);
            root = root->left;
        }
        root = stck_pop(s);
        printf("%d ", root->val);
        root = root->right;
    }
    free(s);
}

void btree_postorder_stack(t_tree *root)
{
    t_stack *s = calloc(1, sizeof(t_stack));

    stck_init(s);
    while (root || !stck_empty(s))
    {
        while (root)
        {
            stck_push(s, root);
            root = root->left;
        }
        root = stck_pop(s);
        root = root->right;
        printf("%d ", root->val);
    }
    free(s); 
}

void btree_preorder_iterative(t_tree* root)
{
    if (root == NULL)
        return;

    t_stack *s = calloc(1, sizeof(t_stack));

    stck_init(s);
    stck_push(s, root);
    
    while (!stck_empty(s))
    {
        t_tree* curr = stck_pop(s); // беру последний элемент из стэка
        printf("%d ", curr->val);
        if (curr->right)
        {
            stck_push(s, curr->right);
        }
        if (curr->left)
        {
            stck_push(s, curr->left);
        }
    }
}

void btree_insert(t_tree **root, int n)
{
    t_tree *walker;
    t_tree *prev;
    
    if (!root)
        return;

    if (!*root)
    {
        *root = btree_new(n);
        return ;
    }
    
    walker = *root;
    while (walker)
    {
        prev = walker;
        if (walker->val > n)
            walker = walker->left;
        else
            walker = walker->right;
    }
    if (prev->val > n)
        prev->left = btree_new(n);
    else
        prev->right = btree_new(n);
}

// preorder
// inorder
// postorder

t_tree *btree_search(t_tree *root, int n)
{
    while (root)
    {
        if (root->val == n)
            return root;

        if (root->val > n)
            root = root->left;
        else
            root = root->right;
    }
}

void btree_preorder(t_tree *root)
{
    if (root == NULL)
        return;
        
    printf("%d ", root->val);
    btree_preorder(root->left);
    btree_preorder(root->right);
}

void btree_inorder(t_tree *root)
{
    if (root == NULL)
        return;

    btree_inorder(root->left);
    printf("%d ", root->val);
    btree_inorder(root->right);
}

void btree_postorder(t_tree *root)
{
    if (root == NULL)
        return;

    btree_postorder(root->left);
    btree_postorder(root->right);
    printf("%d ", root->val);
}

void remove_node(t_tree *root, int n)
{
    t_tree *parent = root;

    while (root && root->val != n)
    {
        parent = root;
        if (n > root->val)
            root = root->right;
        else
            root = root->left;
    }

    if (!root)
        return ;
    
    if (!root->left)
    {
        if (parent->left == root)
            parent->left = root->right;
        else if (parent->right == root)
            parent->right = root->right;
    }
    else if (root->right)
    {}

    // root->right ... ->left
}

unsigned char height(t_tree *root) // вычисление коэффициента сбалансированности дерева
{
	return root?root->height:0;
}

void fixheight(t_tree *root) // – корректирование значения height, затронутое в процессе балансировки.
{
	unsigned char hl = height(root->left);
	unsigned char hr = height(root->right);
	root->height = (hl>hr ? hl:hr) + 1;
}

t_tree *rotate_L(t_tree *root)
{

}

t_tree *rotate_R(t_tree *root)
{

}

t_tree *rotate_l(t_tree *root)
{
    t_tree *root1 = root->right;
	root->right = root1->left;
	root1->left = root;
	fixheight(root);
	fixheight(root1);
	return root1;
}

t_tree *rotate_r(t_tree *root)
{
    t_tree *root1 = root->left;
	root->left = root1->right;
	root1->right = root;
	fixheight(root);
	fixheight(root1);
	return root1;
}

int wide_euklid(int a, int b, int *x, int *y) // ax + by = nod(a, b)
{
    int x1, y1 = 0;
    int nod = 0;

    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
    nod = wide_euklid(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;

    return nod;
}

int rec(int a, int b)
{
    if (b == 0)
        return a;
    return rec(b, a % b);
}

int low_bites(int n)
{
    return n & 15;
}

void dvoich(int n)
{ 
    if (n >= 2)
    {
        dvoich(n / 2);
    }
    printf("%d", n % 2);
}

int unit_count(int n)
{
    int count = 0;
    for (int i = 0; i < 32; ++i)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int hemming_distance(int a, int b)
{
    int count = 0;
    for (int i = 0; i < 32; ++i)
    {
        count += (a ^ b) & 1;
        // if ((a & 1) != (b & 1))
        //    count++;
        a >>= 1;
        b >>= 1;
    }
    return count;
}
int power(unsigned int n)
{
    return unit_count(n) == 1;
}

int* countBits(int n, int* returnSize)
{
    int count = 0;
    int *array = (int*)malloc((n + 1) * sizeof(int));
    *returnSize = n + 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 32; ++j)
        {
            count += i & 1;
            i >>= 1;
        }
        array[i] = count;
        count = 0;
    }
    return array;
}

int bits_out(int n)
{
    int bin = 0;
    int k = 1;

    while (n)
    {
        bin += (n % 2) * k;
        k *= 10;
        n /= 2;
    }
    return bin;
}

void bits_out2(int n)
{
    for (int i = 0; i < sizeof(int) * 8; )
    {
        printf("%d", (n >> (31 - i)) & 1);
        ++i;
        if (i % 4 == 0)
            putc(' ');
    }
}

char *get_filename(char *filepath)
{
    int length_path = strlen(filepath);
    int kol = 0;
    int k = 0;
    int j = 0;
    int n = 0;
    int m = 0;
    int i = length_path;
    int final_length = 0;
    //printf("%d\n", length_path);

    for (i; (filepath[i] != '\\') && (filepath[i] != '/') && i >= 0; --i);

    char *filename = (char*)malloc((length_path - i - 1) * sizeof(char));

    while (filepath[++i] != '\0')
    {
        filename[k] = filepath[i];
        ++k;
    }

    final_length = strlen(filename);
    for (n = final_length; filename[n] != '.' && n >= 0; --n);
    char *file_format = (char*)malloc((final_length - n + 1) * sizeof(char));
    k = 0;
    while(filename[n - 1] != '\0')
    {
        file_format[k] = filename[n];
        ++k;
        ++n;
    }
    char *filename_noformat = (char*)malloc((n + 1) * sizeof(char));

    while (filename[m] != '\0' && m < n)
    {
        filename_noformat[j] = filename[m];
        ++j;
        ++m;
    }
    free();
    return filename_noformat;
}

char *get_file_ext_pos(char *filename)
{
    char *ext = 0;

// "\0" - const char * - 0x560ce602100d
// '\0' - char - 0

    if (!filename)
        return NULL;
    ext = strrchr(filename, '.');
    if (ext)
        ++ext;
    return ext;
}

size_t number_length(long long num)
{
    size_t length = (num <= 0);

    while (num != 0)
    {
        num /= 10;
        length++;
    }
    return length;
}

char *file_add_num(const char *filename, int num)
{
    size_t filename_len = strlen(filename);
    size_t num_len = number_length(num);
    int len = filename_len + num_len + 2;
    char *result = malloc(len * sizeof(char));
    char *ext = get_file_ext_pos(filename);

    if (!result)
        return NULL;
    
    if (ext)
        *(ext - 1) = '\0';
    snprintf(result, len, "%s_%d.%s", filename, num, ext);
    if (ext)
        *(ext - 1) = '.';
    return result;
}
    /*
    int n = 0;
    int k = 0;
    int j = 0;
    char *file_format = (char*)malloc((length - n + 1) * sizeof(char));
    while(filename[n] != '\0')
    {
       file_format[k] = filename[n];
       ++k;
       ++n;
    }

    char *filename_noformat = (char*)malloc((n + 1) * sizeof(char));
    k = 0;
    while (filename[k] != '\0' && k < n)
    {
        filename_noformat[j] = filename[k];
        ++j;
        ++k;
    }
    int len = j + 1;
    char *final = (char*)malloc((len + 2 + number_length(num)) * sizeof(char));  // length(num) поменять на длину числа
    sprintf(final, "%s_%d.%s", filename_noformat, num, file_format);
    free(); 
    return final;
    */
// 1 2 3 4 5 6 7
// 1 2 3 5 6 7
// 1 2 3 3 5 6 7
/**
 * Note: The returned array must be malloced, assume caller calls free().
*/
/*
   1: 0001 ---- 1: 0001
   2: 0010 ---- 2: 0010
   3: 0011 ---- 3: 0011
   4: 0100 ---- 3: 0011
   5: 0101 ---- 5: 0101
   6: 0110 ---- 6: 0110
   7: 0111 ---- 7: 0111
*/

// выписать в двоичном виде в столбец числа прав массива и неправ массива и найти закономерность 

// int* findErrorNums(int* nums, int numsSize, int* returnSize)
// {
//     int *array_answer = (int*)malloc(2 * sizeof(int));
//     for (int i = 1; i < numsSize; ++i)
//     {
//         int val = abs(nums[i]);
//         array_answer[1] = array_answer[1] ^ (i + 1) ^ val;
//         if (nums[val - 1] < 0)
//             ans[0] = val;
//         else
//             nums[val - 1] = -nums[val - 1];
//     }
//     *returnSize = 2;
//     array_answer[1] ^= array_answer[0]
//     return array_answer;
// }

int* findErrorNums(int* nums, int numsSize, int* returnSize)
{
    int *array_answer = (int*)malloc(3 * sizeof(int));
    for (int i = 1; i < numsSize; ++i)
    {
        int val = abs(nums[i]);
        array_answer[1] = array_answer[1] ^ (i + 1) ^ val;
        if (nums[val - 1] < 0)
            array_answer[0] = val;
        else
            nums[val - 1] = -nums[val - 1];
    }
    *returnSize = 2 * sizeof(int);
    array_answer[1] ^= array_answer[0];

    // for (int i = 0; i < 2; i++)
    // {
        // printf("%d\t", array_answer[i]);
    // }
    // printf("\n");
    // printf("\n");
    // printf("\n");
    // printf("\n");
    // return array_answer;
}

int main()
{
    //printf("%d\n", bits_out(123));
    //printf("%s\n", get_filename("E:\\video\\100_Greatest_Discoveries\\09_fizika.avi"));
    printf("%s\n", file_add_num("09_fizika.avi", 1));
    /*
    int* arr = malloc(sizeof(int));   
    int* test = malloc(sizeof(int) * 10);
    int* farr = malloc(sizeof(int) * 4);
    farr[0] = 1;
    farr[1] = 2;
    farr[2] = 2;
    farr[3] = 4;
    test = findErrorNums(farr, 4, arr);
    for (int i = 0; i < 2; i++)
    {
        printf("%d\t", test[i]);
    }
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");

    // printf("%d\n",findErrorNums({1,2,2,4}, 4, arr));
    int n = 2;
    int m = 3;
    int a = 12435; // 0000 0000|0000 0000|0011 0000|1001 0011 = 147
                   // 0000 0000|0000 0000|0011 0000|1001 0011
                   // 0000 0000|0000 0000|0000 0000|0000 0000      
// Что будет, если выполнять сдвиг отрицательного числа? Почему?
    // & | ^ ~ >> <<

    printf("%d\n", a | (1 << n));       // установка 1 на место n-го бита
    printf("%d\n", a ^ (1 << n));       // обнуление n-го бита
    printf("%d\n", a ^ (a >> n));       // переключение n-го бита
// expected = 1011 0011  
//  1001 0011 >> 5 = 0000 0100  
// ~ = 1111 1011  
  
    printf("%d\n", a << 1);             // умножение на 2
    printf("%d\n", a >> 1);             // деление на 2
    printf("%d\n", a << m);             // умножение на 2**m
    printf("%d\n", a >> m);             // деление на 2**m
    printf("%d\n", a & 1);              // проверка четности числа
    printf("%d\n", 1 << n);             // вычисление 2**n
    printf("%d\n", (a >> (m - 1)) & 1); // Получение m-ого бита n (справа налево)
    printf("%d\n", a | (1 << (m - 1))); // Установка m-ого бита n (справа налево)
    printf("%d\n", hemming_distance(1, 4)); // расстояние хэмминга
    printf("------------MOVING NEGATIVE NUMBER------------\n");
    printf("%d\n", -n >> 1);
    printf("%d\n", -n << 1);
// Проверить, является ли число степенью 2 \/

// 2**0 = 1
// 2**1 = 10 
// 2**2 = 100
// 2**3 = 1000
// 2**4 = 10000
// 2**5 = 100000

// 0000 0000|0000 0000|0000 0000|0000 0001
// 0000 0000|0000 0000|0000 0000|0000 0010
// 0000 0000|0000 0000|0000 0000|0000 0100

    putchar('\n');
*/
    return 0;
}