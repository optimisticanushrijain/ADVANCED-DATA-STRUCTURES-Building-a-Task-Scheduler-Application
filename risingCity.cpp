#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ldb;
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define INDENT_STEP  4
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define V vector
#define pll pair<ll,ll>
#define endl "\n"
#define CLEAR(a) memset(a,0,sizeof(a))
#define all(x) x.begin(),x.end()
#define sz(x) ((ll)x.size())
#define rep0(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define ios_tie() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cerr.tie(nullptr)
#define trace1(a)             cout <<#a<<":"<<a<< endl;
#define trace2(a,b)           cout <<#a<<":"<<a<<" | "<<#b<<":"<<b<< endl;
#define trace3(a,b,c)         cout <<#a<<":"<<a<<" | "<<#b<<":"<<b<<" | "<<#c<<":"<<c<<endl;
#define trace4(a,b,c,d)       cout <<#a<<":"<<a<<" | "<<#b<<":"<<b<<" | "<<#c<<":"<<c<<" | "<<#d<<":"<<d<<endl;
#define trace5(a,b,c,d,e)     cout <<#a<<":"<<a<<" | "<<#b<<":"<<b<<" | "<<#c<<":"<<c<<" | "<<#d<<":"<<d<<" | "<<#e<<":"<<e<<endl;

const ll inf = 1e18;
const ll mod = 987654319 ;
const ll maxn = 2e5+10;
const ldb PI = acos(-1);

void lol(ll s) {cerr<<"check........................................... "<<s<<endl;}
ll power(ll x,ll y) {ll res=1; x%=mod; while(y) {if(y&1) res=(res*x)%mod; y>>=1LL; x=(x*x)%mod; }return res;}
ll inv(ll x) {return power(x,mod-2);}//(1/x)%y = x^(y-2) % y;   // pow(x,y)%m = pow(x,y%(m-1))%m
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



ll now;	// global time
const int capacity = 2005; // maximum possible size of min heap
pll harr[2005]; // array of elements in heap // executed time, building no
int heap_size; // Current number of elements in min heap
int parent(int i) { return (i-1)/2; }
int left(int i) { return (2*i + 1); }
int right(int i) { return (2*i + 2); }
pll getMin() { return harr[0]; }

// Inserts a new key 'k'
void insert(pll k)
{
    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;
    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(harr[i], harr[parent(i)]);
       i = parent(i);
    }
}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}

// Process for removal of minimum element from min heap
void extractMin()
{
    if (heap_size == 1)
    {
        heap_size--;
        return;
    }
    // Store the minimum value, and remove it from heap
    pll root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);
}

enum color { RED, BLACK };
/*
 *** Declaring Node TreeRB
 */
typedef struct treerb_node
{
    enum color color;
    int key;
    int value;
    treerb_node *left, *right, *parent;
}*node;

typedef struct treerb_z
{
    node root;
}*treerb;

/*
 *** Declaration of Class TreeRB
 */
class TreeRB
{
    public:
        typedef int (*compare_func)(int left, int right);
        int treerb_lookup(treerb z, int , compare_func compare);
        void treerb_insertion(treerb z, int , int , compare_func compare);
        void treerb_deletion(treerb z, int , compare_func compare);
        treerb treerb_create();
        void properties_verification(treerb z);
        void properties_verification_1(node root);
        void properties_verification_2(node root);
        color node_color(node m);
        void properties_verification_4(node root);
        void properties_verification_5(node root);
        void properties_verification_5_helper(node m, int , int*);
        node grandparent(node m);
        node sibling(node m);
        node uncle(node m);
        node new_node(int key, int , color , node , node);
        node lookup_node(treerb z, int , compare_func compare);
        node maximum_node(node root);
        void left_rotation(treerb z, node m);
        void right_rotation(treerb z, node m);
        void replace_node(treerb z, node oldm, node newm);
        void case1_deletion(treerb z, node m);
        void case2_deletion(treerb z, node m);
        void case3_deletion(treerb z, node m);
        void case4_deletion(treerb z, node m);
        void case5_deletion(treerb z, node m);
        void case6_deletion(treerb z, node m);
        void case1_insertion(treerb z, node m);
        void case2_insertion(treerb z, node m);
        void case3_insertion(treerb z, node m);
        void case4_insertion(treerb z, node m);
        void case5_insertion(treerb z, node m);
};

/*
 *** Properties of Redblack Tree Verification
 */
void TreeRB::properties_verification(treerb z)
{
    properties_verification_1 (z->root);
    properties_verification_2 (z->root);
    properties_verification_4 (z->root);
    properties_verification_5 (z->root);
}
/*
 *** Property I Verification
 */
void TreeRB::properties_verification_1(node m)
{
    assert (node_color(m) == RED || node_color(m) == BLACK);
    if (m == NULL)
        return;
    properties_verification_1(m->left);
    properties_verification_1(m->right);
}
/*
 *** Property II Verification
 */
void TreeRB::properties_verification_2(node root)
{
    assert (node_color(root) == BLACK);
}
/*
 *** Returns color of a node
 */
color TreeRB::node_color(node m)
{
    return m == NULL ? BLACK : m->color;
}
/*
 *** Property IV Verification
 */
void TreeRB::properties_verification_4(node m)
{
    if (node_color(m) == RED)
    {
        assert (node_color(m->left) == BLACK);
        assert (node_color(m->right) == BLACK);
        assert (node_color(m->parent) == BLACK);
    }
    if (m == NULL)
        return;
    properties_verification_4(m->left);
    properties_verification_4(m->right);
}
/*
 *** Property V Verification
 */
void TreeRB::properties_verification_5(node root)
{
    int black_count_path = -1;
    properties_verification_5_helper(root, 0, &black_count_path);
}

void TreeRB::properties_verification_5_helper(node m, int black_count, int* path_black_count)
{
    if (node_color(m) == BLACK)
    {
        black_count++;
    }
    if (m == NULL)
    {
        if (*path_black_count == -1)
        {
            *path_black_count = black_count;
        }
        else
        {
            assert (black_count == *path_black_count);
        }
        return;
    }
    properties_verification_5_helper(m->left,  black_count, path_black_count);
    properties_verification_5_helper(m->right, black_count, path_black_count);
}

/*
 *** Grandparent of node will get returned
 */
node TreeRB::grandparent(node m)
{
    assert (m != NULL);
    assert (m->parent != NULL);
    assert (m->parent->parent != NULL);
    return m->parent->parent;
}

/*
 *** Uncle of node will get returned
 */
node TreeRB::uncle(node m)
{
    assert (m != NULL);
    assert (m->parent != NULL);
    assert (m->parent->parent != NULL);
    return sibling(m->parent);
}

/*
 *** Sibling of node will get returned
 */
node TreeRB::sibling(node m)
{
    assert (m != NULL);
    assert (m->parent != NULL);
    if (m == m->parent->left)
        return m->parent->right;
    else
        return m->parent->left;
}


/*
 *** Red Black Tree Creation
 */
treerb TreeRB::treerb_create()
{
    treerb z = new treerb_z;
    z->root = NULL;
    properties_verification(z);
    return z;
}

/*
 *** Reb Black Tree: New Node Creation
 */
node TreeRB::new_node(int k, int v, color m_color, node left, node right)
{
    node result = new treerb_node;
    result->key = k;
    result->value = v;
    result->color = m_color;
    result->left = left;
    result->right = right;
    if (left  != NULL)
        left->parent = result;
    if (right != NULL)
        right->parent = result;
    result->parent = NULL;
    return result;
}
/*
 *** Node Look up
 */
node TreeRB::lookup_node(treerb z, int key, compare_func compare)
{
    node m = z->root;
    while (m != NULL)
    {
        int comp_result = compare(key, m->key);
        if (comp_result == 0)
        {
            return m;
        }
        else if (comp_result < 0)
        {
            m = m->left;
        }
        else
        {
            assert(comp_result > 0);
            m = m->right;
        }
    }
    return m;
}
/*
 *** TreeRB: Lookup
 */
int TreeRB::treerb_lookup(treerb z, int key, compare_func compare)
{
    node m = lookup_node(z, key, compare);
    return m == NULL ? 0 : m->value;
}

/*
 *** Left Rotation
 */
void TreeRB::left_rotation(treerb z, node m)
{
    node r = m->right;
    replace_node(z, m, r);
    m->right = r->left;
    if (r->left != NULL)
    {
        r->left->parent = m;
    }
    r->left = m;
    m->parent = r;
}
/*
 *** Right Rotation
 */
void TreeRB::right_rotation(treerb z, node m)
{
    node L = m->left;
    replace_node(z, m, L);
    m->left = L->right;
    if (L->right != NULL)
    {
        L->right->parent = m;
    }
    L->right = m;
    m->parent = L;
}
/*
 *** Node Replacement
 */
void TreeRB::replace_node(treerb z, node oldm, node newm)
{
    if (oldm->parent == NULL)
    {
        z->root = newm;
    }
    else
    {
        if (oldm == oldm->parent->left)
            oldm->parent->left = newm;
        else
            oldm->parent->right = newm;
    }
    if (newm != NULL)
    {
        newm->parent = oldm->parent;
    }
}

/*
 *** Maximum Node will get returned
 */
node TreeRB::maximum_node(node m)
{
    assert (m != NULL);
    while (m->right != NULL)
    {
        m = m->right;
    }
    return m;
}

/*
 *** Node deletion from TreeRB
 */
void TreeRB::treerb_deletion(treerb z, int key, compare_func compare)
{
    node child;
    node m = lookup_node(z, key, compare);
    if (m == NULL)
        return;
    if (m->left != NULL && m->right != NULL)
    {
        node pred = maximum_node(m->left);
        m->key   = pred->key;
        m->value = pred->value;
        m = pred;
    }
    assert(m->left == NULL || m->right == NULL);
    child = m->right == NULL ? m->left  : m->right;
    if (node_color(m) == BLACK)
    {
        m->color = node_color(child);
        case1_deletion(z, m);
    }
    replace_node(z, m, child);
    free(m);
    properties_verification(z);
}

/*
 * Case 1: Deletion
 */
void TreeRB::case1_deletion(treerb z, node m)
{
    if (m->parent == NULL)
        return;
    else
        case2_deletion(z, m);
}

/*
 * Case 2: Deletion
 */
void TreeRB::case2_deletion(treerb z, node m)
{
    if (node_color(sibling(m)) == RED)
    {
        m->parent->color = RED;
        sibling(m)->color = BLACK;
        if (m == m->parent->left)
            left_rotation(z, m->parent);
        else
            right_rotation(z, m->parent);
    }
    case3_deletion(z, m);
}

/*
 * Case 3: Deletion
 */
void TreeRB::case3_deletion(treerb z, node m)
{
    if (node_color(m->parent) == BLACK && node_color(sibling(m)) == BLACK &&
        node_color(sibling(m)->left) == BLACK && node_color(sibling(m)->right) == BLACK)
    {
        sibling(m)->color = RED;
        case1_deletion(z, m->parent);
    }
    else
        case4_deletion(z, m);
}

/*
 * Case 4: Deletion
 */
void TreeRB::case4_deletion(treerb z, node m)
{
    if (node_color(m->parent) == RED && node_color(sibling(m)) == BLACK &&
        node_color(sibling(m)->left) == BLACK && node_color(sibling(m)->right) == BLACK)
    {
        sibling(m)->color = RED;
        m->parent->color = BLACK;
    }
    else
        case5_deletion(z, m);
}

/*
 * Case 5: Deletion
 */
void TreeRB::case5_deletion(treerb z, node m)
{
    if (m == m->parent->left && node_color(sibling(m)) == BLACK &&
        node_color(sibling(m)->left) == RED && node_color(sibling(m)->right) == BLACK)
    {
        sibling(m)->color = RED;
        sibling(m)->left->color = BLACK;
        right_rotation(z, sibling(m));
    }
    else if (m == m->parent->right && node_color(sibling(m)) == BLACK &&
             node_color(sibling(m)->right) == RED && node_color(sibling(m)->left) == BLACK)
    {
        sibling(m)->color = RED;
        sibling(m)->right->color = BLACK;
        left_rotation(z, sibling(m));
    }
    case6_deletion(z, m);
}

/*
 * Case 6: Deletion
 */
void TreeRB::case6_deletion(treerb z, node m)
{
    sibling(m)->color = node_color(m->parent);
    m->parent->color = BLACK;
    if (m == m->parent->left)
    {
        assert (node_color(sibling(m)->right) == RED);
        sibling(m)->right->color = BLACK;
        left_rotation(z, m->parent);
    }
    else
    {
        assert (node_color(sibling(m)->left) == RED);
        sibling(m)->left->color = BLACK;
        right_rotation(z, m->parent);
    }
}

/*
 *** Comparison of two nodes
 */
int compare_int(int leftp, int rightp)
{
    int left = (int)leftp;
    int right = (int)rightp;
    if (left < right)
        return -1;
    else if (left > right)
        return 1;
    else
    {
        assert (left == right);
        return 0;
    }
}
/*
 *** Node Insertion into TreeRB
 */
void TreeRB::treerb_insertion(treerb z, int key, int value, compare_func compare)
{
    node inserted_node = new_node(key, value, RED, NULL, NULL);
    if (z->root == NULL)
    {
        z->root = inserted_node;
    }
    else
    {
        node m = z->root;
        while (1)
        {
            int comp_result = compare(key, m->key);
            if (comp_result == 0)
            {
                m->value = value;
                return;
            }
            else if (comp_result < 0)
            {
                if (m->left == NULL)
                {
                    m->left = inserted_node;
                    break;
                }
                else
                {
                    m = m->left;
                }
            }
            else
            {
                assert (comp_result > 0);
                if (m->right == NULL)
                {
                    m->right = inserted_node;
                    break;
                }
                else
                {
                    m = m->right;
                }
            }
        }
        inserted_node->parent = m;
    }
    case1_insertion(z, inserted_node);
    properties_verification(z);
}

/*
 * Case 1: Insertion
 */
void TreeRB::case1_insertion(treerb z, node m)
{
    if (m->parent == NULL)
        m->color = BLACK;
    else
        case2_insertion(z, m);
}

/*
 * Case 2: Insertion
 */
void TreeRB::case2_insertion(treerb z, node m)
{
    if (node_color(m->parent) == BLACK)
        return;
    else
        case3_insertion(z, m);
}

/*
 * Case 3: Insertion
 */
void TreeRB::case3_insertion(treerb z, node m)
{
    if (node_color(uncle(m)) == RED)
    {
        m->parent->color = BLACK;
        uncle(m)->color = BLACK;
        grandparent(m)->color = RED;
        case1_insertion(z, grandparent(m));
    }
    else
    {
        case4_insertion(z, m);
    }
}

/*
 * Case 4: Insertion
 */
void TreeRB::case4_insertion(treerb z, node m)
{
    if (m == m->parent->right && m->parent == grandparent(m)->left)
    {
        left_rotation(z, m->parent);
        m = m->left;
    }
    else if (m == m->parent->left && m->parent == grandparent(m)->right)
    {
        right_rotation(z, m->parent);
        m = m->right;
    }
    case5_insertion(z, m);
}

/*
 * Case 5: Insertion
 */
void TreeRB::case5_insertion(treerb z, node m)
{
    m->parent->color = BLACK;
    grandparent(m)->color = RED;
    if (m == m->parent->left && m->parent == grandparent(m)->left)
    {
        right_rotation(z, grandparent(m));
    }
    else
    {
        assert (m == m->parent->right && m->parent == grandparent(m)->right);
        left_rotation(z, grandparent(m));
    }
}




/*
 *** Printing of TreeRB
 */
void ttree_printt_helper(node m, int indent)
{
    int i;
    if (m == NULL)
    {
        fputs("<empty tree>", stdout);
        return;
    }
    if (m->right != NULL)
    {
        ttree_printt_helper(m->right, indent + INDENT_STEP);
    }
    for(i = 0; i < indent; i++)
        fputs(" ", stdout);
    if (m->color == BLACK)
        cout<<(int)m->key<<endl;
    else
        cout<<"<"<<(int)m->key<<">"<<endl;
    if (m->left != NULL)
    {
        ttree_printt_helper(m->left, indent + INDENT_STEP);
    }
}

void ttree_printt(treerb z)
{
    ttree_printt_helper(z->root, 0);
    puts("");
}

int main()
{
	ios_tie();
	ifstream file("Sample_input2.txt");
    freopen("output2.txt", "w", stdout);
    cout<<"This code is brought to you by gts_47\n";
    TreeRB rbt;
    treerb z = rbt.treerb_create();
	map<ll,pll> mm;	// building no -> (executed time, total time)
	ll cnt = 0;	// number of days the minimum executed time building is worked
	V<pll> to;	// buildings that should be inserted
	string s;
	while(getline(file,s))
	{
		string tmp = "";
		rep0(i,sz(s))
		{
			if(s[i]==':')
				break;
			tmp += s[i];
		}
		ll curr = stoll(tmp);	// input global time
		while(now<=curr && heap_size)
		{
			ll bn = getMin().ss;
			cnt++;
			mm[bn].ff++;
			if(mm[bn].ff==mm[bn].ss)
			{
				cout<<"building "<<bn<<" is completed in "<<now<<" days\n";
				cnt = 0;
				extractMin();
				mm.erase(bn);
			}
			if(cnt==5)	// maximum 5 days
			{
				// update min heap
				cnt = 0;
				extractMin();
				insert({mm[bn].ff,bn});
			}
			if(cnt==0)
			{
				//	currently no work on buildings so we can insert new buildings
				for(auto it:to)
				{
					insert(mp(0ll,it.ff));
					mm[it.ff] = mp(0ll,it.ss);
				}
				to.clear();
			}
			now++;
		}
		if(heap_size==0 && now)
		{
			cout<<"city completion day is : "<<now-1<<".\n";
			return 0;
		}
		now = curr+1;
		//	find the type of query
		ll comma = 0;
		rep0(i,sz(s))
			if(s[i]==',')
				comma++;
		ll type;
		rep0(i,sz(s))
		{
			if(s[i]!='I' && s[i]!='P')
				continue;
			if(s[i]=='I')
				type = 3;
			else if(comma)
				type = 2;
			else
				type = 1;
			break;
		}
		//-----------------------------------
		if(type==1)
		{
			// triple of building no, executed time, total time
			string tmp = "";
			bool ok = 0;
			rep0(i,sz(s))
			{
				if(ok && '0'<=s[i] && s[i]<='9')
					tmp += s[i];
				if(s[i]==':')
					ok = 1;
			}
			ll bn = stoll(tmp);
			if(mm.find(bn)==mm.end())	// if bn not exist
				cout<<"0 0 0\n";
			else
			{
				pll p = mm[bn];
				cout<<bn<<" "<<p.ff<<" "<<p.ss<<endl;
			}
		}
		else if(type==2)
		{
			//	all triplets such that bn1<=bn<=bn2
			string tmp1 = "", tmp2 = "";
			bool ok = 0;
			rep0(i,sz(s))
			{
				if(ok && '0'<=s[i] && s[i]<='9')
					if(comma==1)
						tmp1 += s[i];
					else
						tmp2 += s[i];
				if(s[i]==':')
					ok = 1;
				if(s[i]==',')
					comma--;
			}
			ll bn1 = stoll(tmp1);
			ll bn2 = stoll(tmp2);
			auto it = mm.lower_bound(bn1);	// binary search for buidling 1
			ll sum = 0;
			while(it!=mm.end())
			{
				ll bn = it->ff;
				pll p = it->ss;
				if(bn>bn2)
					break;
				cout<<bn<<" "<<p.ff<<" "<<p.ss<<endl;
				sum++;
				it++;
			}
			if(sum==0)	// if no building exist between bn1 & bn2
				cout<<"0 0 0\n";
		}
		else
		{
			//	insert a new building
			string tmp1 = "", tmp2 = "";
			bool ok = 0;
			rep0(i,sz(s))
			{
				if(ok && '0'<=s[i] && s[i]<='9')
					if(comma==1)
						tmp1 += s[i];
					else
						tmp2 += s[i];
				if(s[i]==':')
					ok = 1;
				if(s[i]==',')
					comma--;
			}
			ll bn = stoll(tmp1);
			ll tt = stoll(tmp2);
			if(mm.find(bn)!=mm.end())
			{
				// already present
				cout<<"error\n";
				return 0;
			}
			if(cnt==0)
			{
				// no building is getting worked upon so insert in data structure
				insert(mp(0ll,bn));
				mm[bn] = mp(0ll,tt);
			}
			else
				to.pb({bn,tt});	// will be inserted when cnt = 0
		}
	}
	while(heap_size)	// final loop to complete all buildings (same as previous while loop)
	{
		ll bn = getMin().ss;
		cnt++;
		mm[bn].ff++;
		if(mm[bn].ff==mm[bn].ss)
		{
			cout<<"building "<<bn<<" is completed in "<<now<<" days\n";
			cnt = 0;
			extractMin();
			mm.erase(bn);
		}
		if(cnt==5)
		{
			cnt = 0;
			extractMin();
			insert({mm[bn].ff,bn});
		}
		now++;
	}
	cout<<"city completion day is : "<<now-1<<".\n";
return 0;
}
