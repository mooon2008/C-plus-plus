#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <map>
using namespace std;


class RCB;
class PCB;

PCB* self;                          //running process
queue<PCB*> Priority_List[100];     //queue array to save PCBs in each priority
list<PCB*> RL;                      //ready list
vector<RCB*> getRCB;                //resource list
int m;                              //number of priority

struct process_Status               //PCB member Status
{
	string Type;
	list<RCB*> List;
	process_Status()
	{
		Type = "free";
	}
};
struct creation_ptree               //PCB member Creation_tree
{
	PCB* Parent;
	list<PCB*> Child;
	creation_ptree(PCB* parent)
	{
		Parent = parent;
	}
};

class PCB
{
public:
	string ID;
	list<int> Memory;
	list<RCB*> other_resources;
	process_Status Status;
	creation_ptree Creation_tree;
	int priority;
	PCB(string id, int p) : ID(id), Creation_tree(self), priority(p)
	{
		Priority_List[p].push(this), RL.push_back(this);
	}
};

class RCB
{
public:
	int RID;
	string Status;
	queue<PCB*> Waiting_list;
	RCB(int id) : RID(id), Status("free"){}
};

PCB *find_highest()
{
	int i = m;
	while (i--)
	if (!Priority_List[i].empty())
		return Priority_List[i].front();
	return NULL;
}
void preempt(PCB *p)
{
	p->Status.Type = "running";
	if (self)
	{
		if (self->Status.Type != "blocked")
			self->Status.Type = "ready";
		Priority_List[self->priority].push(self);
	}
	Priority_List[p->priority].pop();
	self = p;
}
//scheduler function
void Scheduler()
{
	PCB * p = find_highest();      //Find highest priority process p;
	if (!self || self->priority < p->priority || self->Status.Type != "running" || RL.empty())
		preempt(p);
	cout << "Process " << self->ID << " is running.....\n";
}

void Create(string name, int pri)
{
	new PCB(name, pri);
	Scheduler();
}

void Request(int RID)
{
	RCB *r = getRCB[RID];
	if (r->Status == "free")
	{
		r->Status = "allocated";
		self->other_resources.push_back(r);  //insert(self->Other_Resource,r);
	}
	else
	{
		cout << "Process " << self->ID << " is blocked. ";
		self->Status.Type = "blocked ";
		self->Status.List = { r };
		RL.remove(self);                    //remove(RL,self);
		r->Waiting_list.push(self);         //insert(r->Waiting_list,self);
	}
	Scheduler();
}

void Release(int RID)
{
	RCB *r = getRCB[RID];
	self->other_resources.remove(r);
	if (r->Waiting_list.empty())
		r->Status = "free";
	else
	{
		PCB *q = r->Waiting_list.front();
		r->Waiting_list.pop();
		q->Status.Type = "ready";
		RL.push_back(q), Priority_List[q->priority].push(q);
	}
	Scheduler();
}

void removeFromQueue(queue<PCB*>& qu, PCB* val)
{
	queue<PCB*> q;
	while (!qu.empty())
	{
		PCB* top = qu.front();
		qu.pop();
		if (top->ID == val->ID)
			continue;
		q.push(top);
	}
	while (!q.empty())
	{
		PCB* top = q.front();
		q.pop(), qu.push(top);
	}
}

void DestroyTree(PCB* root)
{
	removeFromQueue(Priority_List[root->priority], root);
	for (PCB* child : root->Creation_tree.Child)
		DestroyTree(child);
	for (RCB* resource : root->other_resources)
		Release(resource->RID);
	delete root;
}

void Destroy()
{
	RL.remove(self);
	PCB* parent = self->Creation_tree.Parent;
	parent->Creation_tree.Child.remove(self);
	DestroyTree(self);
	self = NULL;
	Scheduler();
}

void timeout()
{
	self->Status.Type = "ready", Priority_List[self->priority].push(self);
	Scheduler();
}

int main()
{
	int n;   //number of resource
	cout << "******* Process and Resource Management System *******\n"
		<< "Instruction      Function\n"
		<< "   cr            Create\n"
		<< "   de            Destroy\n"
		<< "   su            Suspend\n"
		<< "   rq            Request\n"
		<< "   rl            Release\n";

	cout << "Input the number of priority levels:(<= 100)\n";
	cin >> m;

	cout << "Input the number of resource(<= 100): \n";
	cin >> n;

	getRCB.resize(n);
	for (int i = 0; i < n; ++i)
		getRCB[i] = new RCB(i);

	cout << "Now we have resource R1~R" << n - 1 << endl;

	PCB* init = new PCB("init", 0);   //dummy process
	self = init;

	cout << "Now process starts to run...\n"
		<< "*Process init is running...\n";

	string cmd, pname;
	int prio, rn;
	char c;
	cout << ">  ";
	while (cin >> cmd)
	{
		if (cmd == "cr")
		{
			cout << "enter the name and priority" << endl;
			cin >> pname >> prio;
			Create(pname, prio);
		}
		else if (cmd == "de")
		{
			Destroy();
		}
		else if (cmd == "rq")
		{
			cout << "enter 'r' to request and amount of resources (less then the regeter resources)" << endl;
			cin >> c >> rn;
			if (c != 'r')
				cout << "Invalid instruction" << endl;
			else if (rn < 0 || rn >= n)
				cout << "The resource does not exist" << endl;
			else
				Request(rn);
		}
		else if (cmd == "rl")
		{
			cout << "enter 'r' to release and amount of resources (less then the regeter resources)" << endl;
			cin >> c >> rn;
			if (c != 'r')
				cout << "Invalid instruction" << endl;
			else if (rn < 0 || rn >= n)
				cout << "The resource does not exist" << endl;
			else
				Release(rn);
		}
		else if (cmd == "su")
		{
			timeout();
		}
		cout << ">  ";
	}

	for (int i = 0; i < n; ++i)
		delete getRCB[i];
	DestroyTree(init);

	return 0;
}