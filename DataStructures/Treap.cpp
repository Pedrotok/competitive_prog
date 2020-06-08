// reference: https://cp-algorithms.com/data_structures/treap.html
struct item {
	int prio, cnt, sum, value;
	bool rev;
	item *l, *r;

	item() : cnt(1), rev(false), l(nullptr), r(nullptr){}
	item(int val, int p) : prio(p), cnt(1), sum(val), value(val), rev(false), l(nullptr), r(nullptr){}
};

typedef item* pitem;

class Treap {
	pitem root;

	inline int sum(pitem t) {
		return t ? t->sum : 0;
	}

	inline int cnt (pitem t) {
		return t ? t->cnt : 0;
	}

	void upd_cnt (pitem t) {
		if(t) {
			t->cnt = 1 + cnt(t->l) + cnt(t->r);
			t->sum = t->value + sum(t->l) + sum(t->r);
		}
	}

	void push (pitem it) {
	    if(it && it->rev) {
			it->rev = false;
			swap (it->l, it->r);
			if (it->l)  it->l->rev ^= true;
			if (it->r)  it->r->rev ^= true;
		}
	}

	void split(pitem t, pitem& l, pitem& r, int key, int add = 0) {
		if(!t)
			l = r = nullptr;
		else {
			push(t);
			int curKey = add + cnt(t->l);
			if(key <= curKey) {
				split(t->l, l, t->l, key, add);
				r = t;
			}
			else {
				split(t->r, t->r, r, key, add + cnt(t->l) + 1);
				l = t;
			}
		}
		upd_cnt(t);
	}

	void merge(pitem& t, pitem l, pitem r) {
		push(l);
    	push(r);
		if(l == nullptr || r == nullptr)
			t = l == nullptr ? r : l;
		else if(l->prio > r->prio) {
			merge(l->r, l->r, r);
			t = l;
		}
		else {
			merge(r->l, l, r->l);
			t = r;
		}
		upd_cnt(t);
	}

	void insert(pitem& t, pitem cur, int pos, int add = 0) {
		if(t == nullptr) {
			t = cur;
			return ;
		}
		int curKey = add + cnt(t->l);
		if(t->prio > cur->prio) {
			if(pos <= curKey) insert(t->l, cur, pos, add);
			else insert(t->r, cur, pos, add + cnt(t->l) + 1);
		}
		else {
			split(t, cur->l, cur->r, pos, add);
			t = cur;
		}
		upd_cnt(t);
	}

	void update(pitem& t, int pos, int val, int add = 0) {
		push(t);
		int curKey = add + cnt(t->l);
		if(curKey == pos) t->value = val;
		else if(pos < curKey) update(t->l, pos, val, add);
		else update(t->r, pos, val, add + cnt(t->l) + 1);
		upd_cnt(t);
	}

	void erase(pitem& t, int key, int add = 0) {
		int curKey = add + cnt(t->l);
		if(curKey == key)
			merge(t, t->l, t->r);
		else if(key < curKey)
			erase(t->l, key, add);
		else
			erase(t->r, key, add + cnt(t->l) + 1);
		upd_cnt(t);
	}

	void output (pitem t) {
		if (!t)  return;
		push (t);
		output (t->l);
		printf ("%d ", t->value);
		output (t->r);
	}

	void del(pitem t) {
		if (!t)  return;
		del (t->l);
		del (t->r);
		delete t;
	}

public:
	Treap() : root(nullptr){}

	~Treap() {
		del(root);
	}

	void insert(pitem cur, int pos) {
		insert(root, cur, pos);
	}

	void update(int pos, int val) {
		update(root, pos, val);
	}

	int query(int l, int r) {
		pitem t1, t2, t3;
		split(root, t1, t2, l);
		split(t2, t2, t3, r-l+1);
		int ans = sum(t2);
		merge(root, t1, t2);
		merge(root, root, t3);
		return ans;
	}

	void reverse(int l, int r) {
		pitem t1, t2, t3;
		split(root, t1, t2, l);
		split(t2, t2, t3, r-l+1);
		t2->rev ^= true;
		merge(root, t1, t2);
		merge(root, root, t3);
	}
};