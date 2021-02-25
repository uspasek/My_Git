#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <cmath>
#include <cassert>

#include <sys/resource.h>

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

struct Node
{
    int data;
    Node *next;
};

struct LinkedList
{
    Node *head;
};

struct Stack
{
    Node *top;
};

struct Queue
{
    Node *start;
    Node *end;
};

typedef int TreePathTaken;
enum
{
    PathTaken_Left,
    PathTaken_Right,
};

struct TreeNode
{
    int data;
    TreeNode *prev;
    TreeNode *left;
    TreeNode *right;
};

struct BSTree
{
    TreeNode *root;
};

typedef int RBNodeColor;
enum
{
    RBColor_Black,
    RBColor_Red,
};

struct RBNode
{
    int data;
    RBNodeColor color;
    RBNode *prev;
    RBNode *left;
    RBNode *right;
};

struct RBTree
{
    RBNode *root;
};

static void
node_print_until_null(Node *start)
{
    while(start)
    {
        const char *fmt_str = NULL;
        if(start->next) { fmt_str = "%d -> "; }
        else { fmt_str = "%d\n"; }
        
        printf(fmt_str, start->data);
        start = start->next;
    }
}

static void
llist_print(LinkedList *ll)
{
    node_print_until_null(ll->head);
}

static bool
llist_is_empty(LinkedList *ll)
{
    return ll->head == NULL;
}

static int
llist_size(LinkedList *ll)
{
    int node_cnt = 0;
    
    Node *last = ll->head;
    while(last)
    {
        last = last->next;
        node_cnt += 1;
    }
    
    return node_cnt;
}

static void
llist_push_back(LinkedList *ll, int data)
{
    Node *last = NULL;
    
    if(ll->head)
    {
        Node *one_before_last = ll->head;
        while(one_before_last->next)
        {
            one_before_last = one_before_last->next;
        }
        
        one_before_last->next = new Node;
        Node *n = one_before_last->next;
        n->data = data;
        n->next = NULL;
    }
    else
    {
        Node *n = ll->head = new Node;
        
        n->data = data;
        n->next = NULL;
    }
}

static void
llist_push_front(LinkedList *ll, int data)
{
    Node *node = new Node;
    node->data = data;
    
    node->next = ll->head;
    ll->head = node;
}

static Node *
llist_find_index(LinkedList *ll, int idx)
{
    Node *result = ll->head;
    
    for(int i = 0; result && (i < idx); i++)
    {
        result = result->next;
    }
    
    return result;
}

static Node *
llist_find_before_index(LinkedList *ll, int idx)
{
    Node *prev = NULL;
    Node *node = ll->head;
    
    for(int i = 0; node && (i < idx); i++)
    {
        prev = node;
        node= node->next;
    }
    
    return prev;
}

static void
llist_swap_first_last(LinkedList *ll)
{
    Node *first = ll->head;
    
    if(first)
    {
        Node *one_before_last = first->next;
        if(one_before_last)
        {
            if(one_before_last->next)
            {
                while(one_before_last->next->next)
                {
                    one_before_last = one_before_last->next;
                }
                
                Node *last = one_before_last->next;
                
                ll->head = last;
                one_before_last->next = first;
                last->next = first->next;
                first->next = NULL;
            }
            else
            {
                Node *last = one_before_last;
                
                ll->head = last;
                last->next = first;
                first->next = NULL;
            }
        }
    }
}

static void
llist_swap_found_next(LinkedList *ll, int data)
{
    if(ll->head->data == data && ll->head->next) {
        Node *p = ll->head;
        Node *n = ll->head->next;
        
        ll->head = n;
        p->next = n->next;
        n->next = p;
    } else {
        Node *one_before = ll->head;
        
        while(one_before->next && one_before->next->next) {
            if(one_before->next->data == data) {
                Node *p = one_before->next;
                Node *n = p->next;
                
                one_before->next = n;
                p->next = n->next;
                n->next = p;
                
                break;
            }
            
            one_before = one_before->next;
        }
    }
}

static void
llist_swap_every_second(LinkedList *ll)
{
    if(ll->head && ll->head->next)
    {
        Node *p = ll->head;
        Node *n = ll->head->next;
        
        ll->head = n;
        p->next = n->next;
        n->next = p;
        
        Node *one_before = p;
        while(one_before->next && one_before->next->next)
        {
            p = one_before->next;
            n = p->next;
            
            one_before->next = n;
            p->next = n->next;
            n->next = p;
            
            one_before = p;
        }
    }
}

static void
llist_swap(LinkedList *ll)
{
    // Swap Head with the next element
    if(ll->head)
    {
        Node *tmp = ll->head;
        ll->head = tmp->next;
        tmp->next = ll->head->next;
        ll->head->next = tmp;
    }
}

static void
llist_swap(LinkedList *ll, Node *ob)
{
    if(ll->head && ll->head->next)
    {
        if(!ob) { llist_swap(ll); }
        else
        {
            if(ob->next && ob->next->next)
            {
                Node *p = ob->next;
                ob->next = p->next;
                p->next = p->next->next;
                ob->next->next = p;
            }
        }
    }
}

static void
llist_swap_two_nodes(LinkedList *ll, Node *a0, Node *a1)
{
    if(a0 && a1)
    {
        Node *p0 = a0;
        Node *p1 = a1;
        Node *v0 = p0->next;
        Node *v1 = p1->next;
        
        if(v0 && v1 && p1 != v0 && p0 != v1)
        {
            Node *n0 = v0->next;
            Node *n1 = v1->next;
            
            p0->next = v1;
            v1->next = n0;
            
            p1->next = v0;
            v0->next = n1;
        }
        else if(v0 && v1 && (p1 == v0 || p0 == v1))
        {
            Node *sn = p1 == v0 ? p0 : p1;
            llist_swap(ll, sn);
        }
    }
    else if(a0 || a1)
    {
        Node *p0 = a0 ? a0 : a1;
        Node *v0 = p0->next;
        
        Node *v1 = ll->head;
        
        if(v0 && v1 && p0 != v1)
        {
            Node *n0 = v0->next;
            Node *n1 = v1->next;
            
            p0->next = v1;
            v1->next = n0;
            
            ll->head = v0;
            v0->next = n1;
        }
        else if(v0 && v1 && p0 == v1)
        {
            llist_swap(ll, NULL);
        }
    }
}

static LinkedList
llist_split_half_evenodd(LinkedList *ll)
{
    LinkedList second_list = {};
    Node *flast = NULL;
    Node *slast = NULL;
    
    Node *node = ll->head;
    
    if(node && node->next)
    {
        flast = node;
        ll->head = node;
        node = node->next;
        
        slast = node;
        second_list.head = node;
        node = node->next;
        
        while(node && node->next)
        {
            flast->next = node;
            flast = node;
            node = node->next;
            
            slast->next = node;
            slast = node;
            node = node->next;
        }
        
        if(node)
        {
            flast->next = node;
            flast = node;
        }
        
        flast->next = slast->next = NULL;
    }
    
    return second_list;
}

static LinkedList
llist_split_half(LinkedList *ll)
{
    //IACA_START;
    int half_len = llist_size(ll) / 2;
    
    Node *node = ll->head;
    Node *prev = NULL;
    
    for(int i = 0; i < half_len; i++)
    {
        prev = node;
        node = node->next;
    }
    
    prev->next = NULL;
    LinkedList result = {};
    result.head = node;
    
    //IACA_END;
    return result;
}

static LinkedList
llist_merge_sorted_lists(LinkedList *ll0, LinkedList *ll1)
{
    LinkedList result = {};
    Node *current = result.head;
    
    while(ll0->head && ll1->head)
    {
        Node *smallest = 0;
        if(ll0->head && (ll0->head->data < ll1->head->data))
        {
            smallest = ll0->head;
            ll0->head = ll0->head->next;
        }
        else
        {
            smallest = ll1->head;
            ll1->head = ll1->head->next;
        }
        
        if(result.head == 0)
        {
            result.head = current = smallest;
        }
        else
        {
            current->next = smallest;
            current = current->next;
        }
    }
    
    return result;
}

static LinkedList
llist_merge_sorted_lists_recursive(LinkedList *ll0, LinkedList *ll1)
{
    if(!ll0->head) {
        return *ll1;
    } else if(!ll1->head) {
        return *ll0;
    }
    
    LinkedList result = {};
    if(ll0->head->data < ll1->head->data)
    {
        result.head = ll0->head;
        
        ll0->head = ll0->head->next;
        LinkedList next = llist_merge_sorted_lists_recursive(ll0, ll1);
        result.head->next = next.head;
    }
    else
    {
        result.head = ll1->head;
        
        ll1->head = ll1->head->next;
        LinkedList next = llist_merge_sorted_lists_recursive(ll0, ll1);
        result.head->next = next.head;
        
    }
    
    return result;
}

static LinkedList
llist_merge_sort(LinkedList *ll)
{
    if(ll->head->next == NULL)
    {
        return *ll;
    }
    else
    {
        LinkedList second_half = llist_split_half(ll);
        *ll = llist_merge_sort(ll);
        second_half = llist_merge_sort(&second_half);
        LinkedList result = llist_merge_sorted_lists_recursive(ll, &second_half);
        return result;
    }
}

static LinkedList
llist_bubble_sort(LinkedList *ll, bool (* predicate)(Node *n0, Node *n1))
{
    Node *last_swap = NULL;
    
    for(int i = 0; i < 10; i++)
    {
        Node *one_before = NULL;
        Node *node = ll->head;
        
        Node *current_swap = last_swap;
        while(last_swap != node && node && node->next)
        {
            if(predicate(node, node->next))
            {
                llist_swap(ll, one_before);
                
                current_swap = node;
            }
            
            if(one_before)
            {
                one_before = one_before->next;
                node = one_before->next;
            }
            else
            {
                one_before = ll->head;
            }
        }
        
        last_swap = current_swap;
    }
    
    return *ll;
}

static LinkedList
llist_comb_sort(LinkedList *ll, bool (* predicate)(Node *n0, Node *n1))
{
    float shrink = 1.3f;
    int size = llist_size(ll);
    int gap = size / shrink;
    
    while(gap)
    {
        for(int i = 0; i < size - gap; i++)
        {
            Node *p0 = llist_find_before_index(ll, i);
            Node *p1 = llist_find_before_index(ll, i + gap);
            
            Node *n0 = p0 ? p0->next : ll->head;
            Node *n1 = p1 ? p1->next : ll->head;
            
            if(predicate(n0, n1))
            {
                assert(p0 != p1);
                llist_swap_two_nodes(ll, p0, p1);
            }
        }
        
        gap = gap / shrink;
    }
    
    return *ll;
}

static void
llist_validate_max_heap(LinkedList *ll, int lsize, int parent_idx,
                        bool (* predicate)(Node *n0, Node *n1))
{
    int lci = parent_idx * 2 + 1;
    int rci = parent_idx * 2 + 2;
    
    if(lci < lsize || rci < lsize)
    {
        int ci = 0;
        
        Node *p = NULL, *n = NULL;
        if(lci < lsize && rci < lsize)
        {
            Node *p0 = llist_find_before_index(ll, lci);
            Node *p1 = llist_find_before_index(ll, rci);
            Node *n0 = p0->next;
            Node *n1 = p1->next;
            assert(p0 && p1);
            
            n = predicate(n0, n1) ? n0 : n1;
            p = n == n0 ? p0 : p1;
            ci = n == n0 ? lci : rci;
        }
        else
        {
            ci = MIN(lci, rci);
            p = llist_find_before_index(ll, ci);
            n = p->next;
            assert(p);
        }
        
        Node *pp = llist_find_before_index(ll, parent_idx);
        Node *pn = pp ? pp->next : ll->head;
        if(!predicate(pn, n))
        {
            llist_swap_two_nodes(ll, pp, p);
            llist_validate_max_heap(ll, lsize, ci, predicate);
        }
    }
}

static LinkedList
llist_heap_sort(LinkedList *ll, bool (* predicate)(Node *n0, Node *n1))
{
    int ls = llist_size(ll);
    
    for(int i = ls / 2 - 1; i >= 0; i--)
    {
        llist_validate_max_heap(ll, ls, i, predicate);
    }
    
    for(int i = ls - 1; i > 0; i--)
    {
        Node *p = llist_find_before_index(ll, i);
        llist_swap_two_nodes(ll, NULL, p);
        
        ls -= 1;
        llist_validate_max_heap(ll, ls, 0, predicate);
    }
    
    return *ll;
}

static void
llist_remove_next(LinkedList *ll, Node *prev)
{
    if(prev)
    {
        Node *to_delete = prev->next;
        if(to_delete)
        {
            prev->next = to_delete->next;
            delete to_delete;
        }
    }
    else
    {
        Node *to_delete = ll->head;
        if(to_delete)
        {
            ll->head = to_delete->next;
            delete to_delete;
        }
    }
    
}

static void
llist_remove_every_second(LinkedList *ll)
{
    Node *one_before_delete = ll->head;
    while(one_before_delete && one_before_delete->next)
    {
        llist_remove_next(ll, one_before_delete);
        one_before_delete = one_before_delete->next;
    }
}

static bool
llist_predicate_is_even(Node *n)
{
    return n->data % 2 == 0;
}

static bool
llist_predicate_is_four(Node *n)
{
    return n->data == 4;
}

static bool
llist_sort_decreasing(Node *n0, Node *n1)
{
    return n0->data > n1->data;
}

static void
llist_remove_func(LinkedList *ll, bool (*predicate)(Node *))
{
    Node *current = ll->head;
    if(!current)
    {
        return;
    }
    
    Node *one_before = NULL;
    
    while(current)
    {
        if(predicate(current))
        {
            if(one_before)
            {
                Node *to_delete = current;
                
                one_before->next = current->next;
                current = current->next;
                
                delete to_delete;
            }
            else
            {
                Node *to_delete = current;
                
                current = ll->head = current->next;
                one_before = NULL;
                
                delete to_delete;
            }
        }
        else
        {
            one_before = current;
            current = current->next;
        }
    }
}

static void
llist_remove_if_above_avg(LinkedList *ll)
{
    if(!llist_is_empty(ll))
    {
        Node *n = ll->head;
        int sum = 0, node_cnt = 0;
        
        while(n)
        {
            sum += n->data;
            node_cnt++;
            
            n = n->next;
        }
        
        float avg = (float)sum / (float)node_cnt;
        
        Node *prev = NULL;
        Node *current = ll->head;
        
        while(current)
        {
            if((float)current->data > avg)
            {
                current = current->next;
                
                llist_remove_next(ll, prev);
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
    }
}

static void
llist_remove_max(LinkedList *ll)
{
    if(!llist_is_empty(ll))
    {
        Node *tr_prev = NULL;
        Node *tr = ll->head;
        
        Node *lprev = tr;
        Node *l = tr->next;
        while(l)
        {
            if(tr->data < l->data)
            {
                tr_prev = lprev;
                tr = l;
            }
            
            lprev = l;
            l = l->next;
        }
        
        llist_remove_next(ll, tr_prev);
    }
}

static void
llist_remove_if_in_fibonacci(LinkedList *ll)
{
    if(!llist_is_empty(ll))
    {
        Node *before = NULL;
        Node *node = ll->head;
        
        int magic_number = 48; // signed 32bit int, can hold up to 48th number of fibonacci
        int *fibo_seq = (int *)malloc(sizeof(int) * magic_number);
        
        for(int i = 0; i < magic_number; i++)
        {
            if(i == 0) { fibo_seq[i] = 0; }
            else if (i == 1) { fibo_seq[i] = 1; }
            else { fibo_seq[i] = fibo_seq[i-1] + fibo_seq[i-2]; }
        }
        
        while(node)
        {
            bool in_sequence = false;
            for(int i = 0; (i < magic_number) && (node->data >= fibo_seq[i]); i++)
            {
                if(node->data == fibo_seq[i])
                {
                    in_sequence = true;
                    break;
                }
            }
            
            if(in_sequence)
            {
                node = node->next;
                llist_remove_next(ll, before);
            }
            else
            {
                before = node;
                node = node->next;
            }
        }
        
        free(fibo_seq);
    }
}

static void
llist_move_end_func(LinkedList *ll, bool (*predicate)(Node *))
{
    if(!llist_is_empty(ll))
    {
        Node *last = ll->head;
        int node_cnt = 1;
        
        while(last->next)
        {
            last = last->next;
            node_cnt += 1;
        }
        
        if(last == ll->head) { return; }
        
        Node *node_prev = NULL;
        Node *node = ll->head;
        
        for(int i = 0; i < node_cnt; i++)
        {
            if(predicate(node))
            {
                if(node_prev)
                {
                    node_prev->next = node->next;
                    
                    last->next = node;
                    last = node;
                    last->next = NULL;
                    
                    node = node_prev->next;
                }
                else
                {
                    ll->head = node->next;
                    
                    last->next = node;
                    last = node;
                    last->next = NULL;
                    
                    node = ll->head;
                }
            }
            else
            {
                node_prev = node;
                node = node->next;
            }
        }
    }
}

static void
llist_move_end_better_func(LinkedList *ll, bool (*predicate)(Node *))
{
    if(!llist_is_empty(ll))
    {
        Node *node_prev = NULL;
        Node *node = ll->head;
        
        LinkedList appended = {};
        Node *append_head = NULL;
        Node *append_back = NULL;
        Node *resulting_end = NULL;
        
        while(node)
        {
            if(predicate(node))
            {
                if(node_prev)
                {
                    node_prev->next = node->next;
                    
                    if(append_back)
                    {
                        append_back->next = node;
                        append_back = append_back->next;
                        node->next = NULL;
                    }
                    else
                    {
                        append_head = append_back = node;
                        node->next = NULL;
                    }
                    
                    node = node_prev->next;
                }
                else
                {
                    ll->head = node->next;
                    
                    if(append_back)
                    {
                        append_back->next = node;
                        append_back = append_back->next;
                        node->next = NULL;
                    }
                    else
                    {
                        append_head = append_back = node;
                        node->next = NULL;
                    }
                    
                    node = ll->head;
                }
            }
            else
            {
                node_prev = node;
                node = node->next;
            }
            
            resulting_end = node_prev;
        }
        
        resulting_end->next = append_head;
    }
}

static void
llist_move_end_between(LinkedList *ll, int x, int y)
{
    if(!llist_is_empty(ll))
    {
        Node *xnode = NULL;
        Node *ynode = NULL;
        
        Node *last = NULL;
        Node *node = ll->head;
        while(node)
        {
            if(node->data == x)
            {
                xnode = node;
            }
            else if(node->data == y)
            {
                ynode = node;
            }
            
            last = node;
            node = node->next;
        }
        
        if(xnode && ynode && xnode->next != ynode)
        {
            Node *moving = xnode->next;
            while(moving != ynode)
            {
                last = last->next = moving;
                moving = moving->next;
                last->next = NULL;
            }
            
            xnode->next = ynode;
        }
    }
}

static void
llist_move_end_reveresed_between(LinkedList *ll, int x, int y)
{
    if(!llist_is_empty(ll))
    {
        Node *xnode = NULL;
        Node *ynode = NULL;
        
        Node *last = NULL;
        Node *node = ll->head;
        while(node)
        {
            if(node->data == x)
            {
                xnode = node;
            }
            else if(node->data == y)
            {
                ynode = node;
            }
            
            last = node;
            node = node->next;
        }
        
        if(xnode && ynode && xnode->next != ynode)
        {
            Node *moving = xnode->next;
            Node *tail = last->next;
            while(moving != ynode)
            {
                last->next = moving;
                moving = moving->next;
                last->next->next = tail;
                
                tail = last->next;
            }
            
            xnode->next = ynode;
        }
    }
}

static void
llist_move_evenodd(LinkedList *ll, int x, int y)
{
    if(!llist_is_empty(ll))
    {
        Node *xnode = NULL;
        Node *ynode = NULL;
        
        Node *last = NULL;
        Node *node = ll->head;
        while(node)
        {
            if(node->data == x)
            {
                xnode = node;
            }
            else if(node->data == y)
            {
                ynode = node;
            }
            
            last = node;
            node = node->next;
        }
        
        if(xnode && ynode && xnode->next != ynode)
        {
            Node *moving = xnode->next;
            while(moving != ynode)
            {
                if(moving->data % 2 == 0)
                {
                    Node *nhead = moving;
                    moving = moving->next;
                    
                    nhead->next = ll->head;
                    ll->head = nhead;
                }
                else
                {
                    last = last->next = moving;
                    moving = moving->next;
                    last->next = NULL;
                }
            }
            
            xnode->next = ynode;
        }
    }
}

static void
llist_reverse(LinkedList *ll)
{
    Node *prev = NULL;
    Node *node = ll->head;
    
    while(node)
    {
        Node *tmp = node->next;
        node->next = prev;
        prev = node;
        node = tmp;
    }
    
    ll->head = prev;
}

static void
llist_reverse_between(LinkedList *ll, int x, int y)
{
    if(!llist_is_empty(ll))
    {
        Node *xnode = NULL;
        Node *ynode = NULL;
        Node *ynode_prev = NULL;
        int cnt = 0;
        
        Node *node_prev = NULL;
        Node *node = ll->head;
        while(node)
        {
            if(xnode && !ynode)
            {
                cnt++;
            }
            
            if(node->data == x)
            {
                xnode = node;
            }
            else if(node->data == y)
            {
                ynode = node;
                ynode_prev = node_prev;
            }
            
            node_prev = node;
            node = node->next;
        }
        
        if(xnode && ynode && cnt >= 2)
        {
            LinkedList to_reverse = {};
            to_reverse.head = xnode->next;
            ynode_prev->next = NULL;
            llist_reverse(&to_reverse);
            
            xnode->next = to_reverse.head;
            
            Node *last = to_reverse.head;
            while(last->next) { last = last->next; }
            
            last->next = ynode;
        }
    }
}

static void
llist_weird_copy(LinkedList *ll)
{
    Node *node = ll->head;
    while(node)
    {
        Node *next = node->next;
        
        Node *tmp = node;
        for(int i = 0; i < node->data - 1; i++)
        {
            tmp->next = new Node;
            
            tmp = tmp->next;
            tmp->data = node->data;
            tmp->next = NULL;
        }
        
        tmp->next = next;
        node = next;
    }
}

static void
llist_weirder_copy(LinkedList *ll)
{
    if(!llist_is_empty(ll))
    {
        int node_cnt = llist_size(ll);
        
        LinkedList left = {};
        LinkedList right = {};
        
        for(Node *n = ll->head; n; n = n->next)
        {
            llist_push_front(&left, n->data);
            llist_push_front(&right, n->data);
        }
        
        Node *middle = ll->head;
        
        ll->head = left.head;
        
        Node *last = ll->head;
        while(last->next)
        {
            last = last->next;
        }
        
        last->next = middle;
        while(last->next)
        {
            last = last->next;
        }
        
        last->next = right.head;
    }
}

static void
llist_pair_even_copy(LinkedList *ll)
{
    int cnt = llist_size(ll);
    
    Node *n0 = ll->head;
    Node *n1 = NULL;
    for(int i = 0; i < cnt / 2; i++)
    {
        n1 = n0->next;
        
        if((n0->data + n1->data) % 2 == 0)
        {
            Node *c0 = new Node;
            Node *c1 = new Node;
            
            c0->data = n0->data;
            c1->data = n1->data;
            
            c1->next = n1->next;
            c0->next = c1;
            n1->next = c0;
            
            n0 = c1->next;
        }
        else
        {
            n0 = n1->next;
        }
        
    }
}

static bool
queue_is_empty(Queue *q)
{
    return q->start == NULL;
}

static void
queue_push(Queue *q, int data)
{
    Node *n = new Node;
    
    n->data = data;
    n->next = NULL;
    
    if(q->start && q->end)
    {
        q->end->next = n;
        q->end = n;
    }
    else
    {
        q->start = q->end = n;
    }
}

static void
queue_pop(Queue *q)
{
    Node *to_delete = NULL;
    if(q->start)
    {
        to_delete = q->start;
        
        q->start = q->start->next;
        if(to_delete == q->end)
        {
            q->end = NULL;
        }
        
        delete to_delete;
    }
}

static void
queue_print(Queue *q)
{
    node_print_until_null(q->start);
}

static bool
bst_is_empty(BSTree *t)
{
    return t->root == NULL;
}

static TreeNode *
bst_find(BSTree *t, int data)
{
    if(!bst_is_empty(t))
    {
        TreeNode *node = t->root;
        
        while(node)
        {
            if(node->data == data) { return node; }
            else if(node->data > data) { node = node->left; }
            else if(node->data < data) { node = node->right; }
        }
    }
    
    return NULL;
}

static TreeNode *
bst_find_prev(BSTree *t, int data)
{
    TreeNode *f = bst_find(t, data);
    return f ? f->prev : NULL;
}


static TreeNode *
bst_find_next(BSTree *t, int data, bool right=false)
{
    TreeNode *f = bst_find(t, data);
    return f ? (right ? f->right : f->left) : NULL;
}

static void
bst_insert(BSTree *t, int data)
{
    TreeNode *new_node = new TreeNode;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    
    TreeNode *prev = NULL;
    TreeNode **write_node = &t->root;
    
    while(*write_node)
    {
        TreeNode *test = *write_node;
        prev = test;
        write_node = (*write_node)->data > data ? &(*write_node)->left : &(*write_node)->right;
    }
    
    new_node->prev = prev;
    *write_node = new_node;
}

static void
bst_remove(BSTree *t, int data)
{
    TreeNode **last_ptr_path_taken = &t->root;
    TreeNode *current_node = t->root;
    
    while(current_node && current_node->data != data)
    {
        last_ptr_path_taken = current_node->data > data ?
            &current_node->left : &current_node->right;
        
        current_node = *last_ptr_path_taken;
    }
    
    if(current_node)
    {
        if(!current_node->left && !current_node->right)
        {
            *last_ptr_path_taken = NULL;
            delete current_node;
        }
        else if(current_node->left && current_node->right)
        {
            // Find the smallest value in the right sub-tree
            TreeNode *smallest = current_node->right;
            while(smallest->left)
            {
                smallest = smallest->left;
            }
            
            *last_ptr_path_taken = smallest;
            smallest->left = current_node->left;
            
            TreeNode *prev = smallest->prev;
            if(prev)
            {
                prev->left = smallest->right;
                smallest->right = current_node->right;
            }
            
            delete current_node;
        }
        else
        {
            *last_ptr_path_taken = current_node->left ? current_node->left : current_node->right;
            
            delete current_node;
        }
    }
}

static void
bst_invert_recursive(TreeNode *node)
{
    if(node)
    {
        bst_invert_recursive(node->left);
        bst_invert_recursive(node->right);
        
        TreeNode *tmp = node->left;
        node->left = node->right;
        node->right = tmp;
    }
}

static void
bst_invert(BSTree *tree)
{
    bst_invert_recursive(tree->root);
}

static void
bst_print_node(TreeNode *n, int depth)
{
    for(int i = 0; i < depth; i++)
    {
        printf("\t");
    }
    printf("%d\n", n->data);
}

static void
bst_for_all_inorder(TreeNode *n, void (*func)(TreeNode *, int), int depth = 0)
{
    if(n)
    {
        bst_for_all_inorder(n->left, func, depth + 1);
        func(n, depth);
        bst_for_all_inorder(n->right, func, depth + 1);
    }
}

static void
bst_for_all_inorder(BSTree *t, void (*func)(TreeNode *, int))
{
    bst_for_all_inorder(t->root, func);
}

static void
bst_rotl_subtree(BSTree *t, TreeNode *sroot)
{
    TreeNode *tmp = sroot->right;
    sroot->right = tmp->left;
    tmp->left = sroot;
    
    TreeNode *prev = sroot->prev;
    if(prev)
    {
        (prev->left == sroot ? prev->left : prev->right) = tmp;
    }
    else
    {
        t->root = tmp;
    }
}

static void
bst_rotr_subtree(BSTree *t, TreeNode *sroot)
{
    TreeNode *tmp = sroot->left;
    sroot->left = tmp->right;
    tmp->right = sroot;
    
    TreeNode *prev = sroot->prev;
    if(prev)
    {
        (prev->left == sroot ? prev->left : prev->right) = tmp;
    }
    else
    {
        t->root = tmp;
    }
}

static void
bst_rotrl_subtree(BSTree *t, TreeNode *sroot)
{
    bst_rotr_subtree(t, sroot->right);
    bst_rotl_subtree(t, sroot);
}

static void
bst_rotlr_subtree(BSTree *t, TreeNode *sroot)
{
    bst_rotl_subtree(t, sroot->left);
    bst_rotr_subtree(t, sroot);
}


