#include "tree.h"
#include <math.h>
#include <algorithm>
#include <assert.h>
#include "struct.hpp"
#include "algorithm.hpp"
using namespace dynsocc;
using namespace std;

TreeEx::TreeEx()
{
    iData = 0;
    dData = 0.0;
    strData = "";

	 v = NULL;
}

int TreeEx::addNode(TreeEx e)
{
	if (v == NULL)
	{
		v = new std::vector<TreeEx>();
	}
    
	v->push_back(e);
	return 0;
}

void TreeEx::operator=(const TreeEx& t)
{
    iData = t.iData;
    strData = t.strData;
    dData = t.dData;
}

bool TreeEx::hasChild()
{
	return v != NULL && v->size() > 0;
}

const std::vector<TreeEx>* TreeEx::getVChild()
{
	return v;
}

class TreeTechnique
{
	public:
		/* Build: Using data structure to define parent-child relationshop of treenode */
		void parent_child_Establish()
		{
			int parent_id = 0;
			int child_id = 0;

			/*
			* Each node has Unique ID; 
			*/

			int n = 0;
			unsigned char* pMapBuffer;
			int MAX_PAIR = 0;

			pMapBuffer = (unsigned char*)malloc(MAX_PAIR*2);

			int i = 0;
			pMapBuffer[i << 2] = child_id;
			pMapBuffer[i << 2 + 1] = parent_id;	// Map Buffer

			// Add New 
			int nID = 0;			
			int layout[10];	// Ten level


			// Find cycle
			// Valid? 

			// TreeAddress
			free(pMapBuffer);
		}

		void dummy_arrange()
		{
			// Degree (20)
			struct Node
			{
				int data;
				double data1;

				int nchild;
				int loc_start[20];	// Relative position 
				int loc_end[20];	// Relative position
			};

			// 1st Element is the Root
			int const MAX_SIZE=100;
			int n;
			int loc_start[100];
			int loc_end[100];

			Node arr[100];
			// Initialize list
			arr[0].data = 0;
			arr[0].data1 = 0.0;

			arr[0].nchild = 4;
			arr[0].loc_start[0] = 0;
			arr[0].loc_end[0] = 10;

			// Degree 
			loc_start[0] = 0;	// The range of [Start, End)
			loc_end[0] = 100;
			// Lookup address
			int lookup[MAX_SIZE];
		}

		int fully_binary_init_layout(int n)
		{
			return (2 << (n+1) - 1);
		}

		int narrow_init_layout(int n)
		{
			/*
			 * 1 + x + x^2 + .. + x^(n-1) = (x^(n)-1)/(x-1)
			 */
			return 2 * (pow(1.5, (n)) - 1); // = 1 + 1.5 + 1.5^2 + ... + 1.5^(n-1)
											// = (1.5^n - 1)*2
		}

		int relayout(int layer, int curr_layout[])
		{
			// Current layout
			// Position which changes 

			layer = 0;	// layer change
			// int curr_layout[100];
			int nolayout;

			struct RelayoutNeed
			{
				int layer_index;		// layer that need extends
				int layer_size_curr;	// Current layer size 
				int current_layout[];	// Current layout size
			};

			int tree[100];		// Tree with container size = 100.
			int layout[100];	
			int n = 0;
			int m = 0;
			int sz = sizeof(tree)/sizeof(int);
			int nlayout;	// N-layout

			// Initialization layout 
			nlayout = 5;
			for (int i=0; i<nlayout;++i) 
			{
				layout[i] = 1 << i;
			}
			
			// Re-layout 
			int nlayout_needs = 2;
			layout[nlayout_needs] += 10;

			// int Add Node.
			int value;
			tree[0] = 0;
			
			return 0;
		}

		int remove_from_array(std::vector<int>& v, int idx)
		{
			if (idx >=0 && idx < v.size())
			{
				return 0;
			}

			return -1;
		}

		int vector_adjacentlist_tree()
		{
			int raw_data[1000];
			int tree_structure[2000];
			int CountEdge = 0;	// 
			int CountNode = 0;

			int arr[1000];
			int narr = 0;
			int stack[1000];
			int nstack = 0;

			/*********************************************************************************
			 *	Function-001: Is new Parent-Child relationship valid?
			 *		
			 *********************************************************************************/
            {
                bool isValid = true;
                int new_parent = 10;    //Any number
                int new_child = 11;     //Any ID;

                stack[nstack++] = new_parent;
                while (nstack > 0)
                {
                    int element = stack[--nstack];
                    arr[narr++] = element;

                    for (int i=0; i<CountEdge;++i)
                    {
                        // A (Parent,Child) = (tree_structure[2*i], tree_structure[2*i+1])
                        // i << 1 = 2*i
                        if (tree_structure[i << 1 + 1] == new_child)
                        {
                            stack[nstack++] = tree_structure[i << 1];   // Add to stack
                        }
                    }
                }

                // Now arr contains every ancestor of new_parent
                // If new_child is in ancestor list => INVALID
                if (std::find(arr, arr + narr, new_child) != arr + narr)
                {
                    isValid = false;
                }

                printf("IsValid RelationShip %d\r\n", isValid);
            }
            
            /*********************************************************************************
			 *	Function-001: AddNewNode (IfValie)
			 *********************************************************************************/
            {
				
            }

			return 0;
		}
};

TreeAdj::TreeAdj()
{

	_auto_id=0;

	_nRootID = -1;
	_n_edge = 0;	//  Zero Edges
	_nNode = 0;		// Zero Nodes
	_n_id2index = 0;	// Zero Mapping Id-Index
	_n_name2id = 0;		// Zero Mapping Name-ID

}

int TreeAdj::add_node(int parent_id, std::string name, int& nID)   // Parent-ID < 0 => Adding a root node 
{
	/*========================================================
		Node management:
			+ NodeAddress:
				PhysicalAddress:	Index	(Access Physical memory)(Will change?)
				UniqueID:			AutoID	
			+ Manage:
				AutoID to Index mapping (Map: vector of R^2)
	 *========================================================*/

	// Is Parent ID valid?
	//	Performing Binary Searcheing
	int nFound = -1;

	// is adding a Root Node?
	if (parent_id < 0) {
		// Another Root Node is existed?
		if (_nRootID >= 0) {
			// ??
			throw "Root Node is existed";
		}
	}
	else {
		algorithm::binary_search(_m_id2index_l, 0, _n_id2index, parent_id, nFound);

		if (nFound < 0) {
			// 
			throw "ParentID-Invalid";
		}
	}
	
	// Vector of a Node 
	_auto_id++;
	nID = _auto_id;		// Node Address
	int nIndex = _nNode;	// Node Address
	_nNode++;
	
	_vnode[nIndex].name = name;
	_vnode[nIndex].id = _auto_id;
	_vnode[nIndex].parent_id = parent_id;

	// Add a mapping?
	// 1st element sastified:
	//		left[loc] >= new_key
	// Validation?
	//		
	int nInsertLoc = 0;
	while (nInsertLoc < _n_id2index && _m_id2index_l[nInsertLoc] < nID) {
		nInsertLoc++;	
	}

	if (nInsertLoc >= _n_id2index)	// Do not find => Insert at the end 
	{
		_m_id2index_l[_n_id2index] = nID;
		_m_id2index_r[_n_id2index] = nIndex;
		_n_id2index++;
	}
	else if (_m_id2index_l[nInsertLoc] == nID)		// Duplicate? => Replace
	{
		_m_id2index_r[_n_id2index] = nIndex;	// Replace
	}
	else {
		// Insert into right position 

		//1) Move everything 1-position forward
		for (int i = _n_id2index; i > nInsertLoc; i--) {
			_m_id2index_l[i] = _m_id2index_l[i - 1];
			_m_id2index_r[i] = _m_id2index_r[i - 1];
		}
		_n_id2index++;

		//2) Insert
		_m_id2index_l[nInsertLoc] = nID;
		_m_id2index_r[nInsertLoc] = nIndex;
	}

	// New Root Node
	if (parent_id < 0) {
		_nRootID = nID;
		return 0;
	}

	// Register Relationship Graph 
	// Insert one relationship record (new_L,new_R) = (parent_id, new_id).
	// 
	// Find the smallest Location (loc) where: 
	//		(vedgeL[loc] == new_L and vedgeR[loc]>=new_R)
	//		or
	//		(vedgeL[loc] >= new_L)
	nInsertLoc = 0;
	while (nInsertLoc < _n_edge &&
		(_v_edge_l[nInsertLoc] < parent_id
			||
			(_v_edge_l[nInsertLoc] == parent_id && _v_edge_r[nInsertLoc] < nID))) {
		nInsertLoc++;
	}

	if (nInsertLoc >= _n_edge) {
		// Append at the last position
		_v_edge_l[_n_edge] = parent_id;
		_v_edge_r[_n_edge] = nID;
		_n_edge++;
	}
	else {
		// Move everything one-position forward 
		for (int i = _n_edge; i > nInsertLoc; i--) {
			_v_edge_l[i] = _v_edge_l[i - 1];
			_v_edge_r[i] = _v_edge_r[i - 1];
		}
		_n_edge++;

		// Insert
		_v_edge_l[nInsertLoc] = parent_id;
		_v_edge_r[nInsertLoc] = nID;
	}

	// Update the Binary Tree Name Mapping 
	int nIdxName;
	int nIdxNameR;
	int _n_name2id_r = _n_name2id;
	algorithm::insert_into_sorted_asc(_m_name2id_l, 0, _n_name2id, name, nIdxName);
	algorithm::insert(_m_name2id_r, 0, _n_name2id_r, nID, nIdxNameR);
	
	return 0;
}

int add_node(std::string parent_node_name, std::string name, int &nodeID) {
	return 0;
}


int TreeAdj::get_root_node(int &nodeid, std::string& name)
{
	if (_nRootID >= 0)
	{
		
		int nFound = -1;
		algorithm::binary_search(_m_id2index_l, 0, _n_id2index, _nRootID, nFound);
	
		if (nFound >= 0)
		{
			nodeid = _nRootID;
			name = _vnode[_m_id2index_r[nFound]].name;
			return 0;
		}
	}
	return 1; // Could not found
}

int TreeAdj::get_node(int ID, std::string& data)
{
	// Binary Search
	int nL = 0;
	int nR = _n_id2index-1;
	int nMid = (nL + nR) / 2;
	int nVal; // 
	int nFound = -1;

	while (nL <= nR && nFound < 0) {
		nMid = (nL + nR) / 2;
		nVal = _m_id2index_l[nMid];

		if (nVal == ID) {
			nFound = nMid;
		}
		else if (nVal < ID)
		{
			nL = nMid + 1;
		}
		else
		{
			nR = nMid - 1;
		}
	}

	if (nFound >= 0)
	{
		int nIndex = _m_id2index_r[nFound];
		data = _vnode[nIndex].name;
		return 0;
	}
	else
	{
		return 1;
	}
}

int TreeAdj::remove_node(int node_id)
{
	/*
		1. Remove node_id
		1.1. Remove Name Mapping of node_id
		2. Remove every descendants 
		2.1. Remove desendants Name Mapping
	 */

	int nID = node_id;
	int nParentID;
	int nL = 0;
	int nR = _n_id2index;
	int nMid = 0;
	int nFindIndex = -1;

	if (algorithm::binary_search(_m_id2index_l, 0, _n_id2index, node_id, nFindIndex) !=0 || nFindIndex<0)
	{
		// Invalid node
		return 1;
	}

	nParentID = _vnode[nFindIndex].parent_id;

	// Find every Edge, where is children of 
	// Starting with n1
	//	Ending with n1
	int nLower, nHigher;
	int nLower2, nHigher2;

	// Starting from node_id
	// Find every children 
	dvqueue<int> q1(ADJTREE_MAX_NODE);	 // Queue structure for findin
	vector<int> v1;  // List of NodeID to be removed
	vector<int> v_node_index; // List of Index-Of-NodeID
	vector<int> v_remove_edge; // list of Edges to be removed
	
	q1.enqueue(node_id);
	int nnode;
	// Do not check a closed-path: there are no closed path in a tree.

	while (!q1.empty())
	{
		assert(q1.dequeue(nnode)==0);
		v1.push_back(nnode);
		algorithm::binary_search(_v_edge_l, 0, _n_edge, nnode, nLower, nHigher);

		if (nLower>=0)
		{
			for (int i=nLower; i<=nHigher;++i)
			{
				q1.enqueue(_v_edge_r[i]);
				v_remove_edge.push_back(i);	// Also remove edge i
			}
		}
	}

	if (algorithm::binary_search(_v_edge_l, 0, _n_edge, nParentID, nLower, nHigher) == 0
			&& nLower >= 0 
			&& algorithm::binary_search(_v_edge_r, nLower, nHigher+1, node_id, nLower2) == 0
			&& nLower2 >= 0)
	{
		// Remove 
		v_remove_edge.push_back(nLower2);
	}

	// Removing all 
	// 	Nodes (node_id & every children)
	// 	Edges 
	//			(x,node_id) every x
	//			(node_id, y) every y
	//	Meta-data node (Mapping )
	//		_m_id2index[]
	for (int i=0;i<v1.size();++i)
	{
		if (algorithm::binary_search(_m_id2index_l, 0, _n_id2index, v1[i], nLower) == 0 && nLower>=0)
		{
			v_node_index.push_back(_m_id2index_r[nLower]);
		}
		else 
		{
			throw "Invalid";
		}
	}

	algorithm::remove_elements(_v_edge_l, 
								_v_edge_r, 
								0, 
								_n_edge, 
								(int*)v_remove_edge.data(), 
								0, 
								v_remove_edge.size()); // Edge removal
	algorithm::remove_elements(_vnode, 0, _nNode, (int*)v_node_index.data(), 0, v_node_index.size()); // 
	
	// Remove Id-2-Index mapping
	// And Remove Name-2-Id Mapping
	for (int i=0;i<v1.size();++i) {

		// Node Mapping: ID-2-Index mappin
		algorithm::binary_search(_m_id2index_l, 0, _n_id2index, v1[i], nLower);

		if (nLower >= 0)
		{
			algorithm::remove_element(
				_m_id2index_l,
				_m_id2index_r,
				0,
				_n_id2index,
				nLower
			);
		}

		// Remove Name-2-ID mapping
		if (algorithm::binary_search((string*)_m_name2id_l, 0, _n_name2id, _vnode[v1[i]].name, nLower, nHigher) == EXOK && nLower >= 0) {
			int nName2ID_r = _n_name2id;
			algorithm::remove_elements(
				(string*)_m_name2id_l,
				0,
				_n_name2id,
				nLower,
				nHigher+1
			);

			algorithm::remove_elements(
				(int*)_m_name2id_r,
				0,
				nName2ID_r,
				nLower,
				nHigher+1
			);
		}
	}


	return 0;
}

int TreeAdj::get_children(int nodeid, std::vector<int>& vchildren, std::vector<std::string>& vname)
{
	int nLower, nHigher;
	std::string name;
	if (algorithm::binary_search(_v_edge_l, 0, _n_edge, nodeid, nLower, nHigher) == 0)
	{
		vchildren.clear();
		vname.clear();
		for (int i=nLower;i<=nHigher;++i)
		{
			get_node(_v_edge_r[i], name);

			vchildren.push_back(_v_edge_r[i]);
			vname.push_back(name);
		}

		return 0;
	}
	return 1;
}

int TreeAdj::get_descentdants(int node_id, std::vector<int>& vid, std::vector<std::string>& vname)
{
	int nid;
	dvqueue<int> d1(ADJTREE_MAX_NODE);
	d1.enqueue(node_id);

	vid.clear();
	vname.clear();

	int nLow, nHigh;
	int nFound;

	int arr_visited[ADJTREE_MAX_NODE];	// Visit flag
	int nVisited=0;

	while (!d1.empty())
	{
		d1.dequeue(nid);
		algorithm::binary_search(_v_edge_l, 0, _n_edge, nid, nLow, nHigh);

		for (int i = nLow; i <= nHigh; ++i)
		{
			int nID = _v_edge_r[i];

			algorithm::binary_search(_m_id2index_l, 0, _n_id2index, nID, nFound);

			vid.push_back(nID);
			vname.push_back(_vnode[nFound].name);

			d1.enqueue(nID);	// Loop 
		}	
	}

	return 0;

}

int TreeAdj::branch_population(int node_id)		// parent included node 
{
	int nCount = 0;
	int nVisitID;
	int nIndex;
	int nLoIndex;
	int nHiIndex;
	dvqueue<int> dq(ADJTREE_MAX_NODE);

	algorithm::binary_search(_m_id2index_l, 0, _n_id2index, node_id, nIndex);
	if (nIndex < 0)
	{
		// Invalid
		return 0;
	}

	dq.enqueue(node_id);
	while (!dq.empty())
	{
		dq.dequeue(nVisitID);
		nCount++;	// Visit

		if (algorithm::binary_search(_v_edge_l, 0, _n_edge, nVisitID, nLoIndex, nHiIndex) == 0)
		{
			for (int i = nLoIndex; i <= nHiIndex; ++i)
			{
				dq.enqueue(_v_edge_r[i]);
			}
		}
	}
	
	return nCount;
}

int TreeAdj::branches_population(std::vector<int> vid)
{
	int arr_visit[ADJTREE_MAX_NODE];
	int nvisit;
	int nIndex, nIndex1;
	int nLoIndex, nHiIndex;
	int nVisitID;
	dvqueue<int> dq(ADJTREE_MAX_NODE);
	int nCount = 0;

	// Push every valid node into 
	for (int i = 0; i < vid.size(); ++i)
	{
		if (algorithm::binary_search(_m_id2index_l, 0, _n_id2index, vid[i], nIndex) == 0
			&& nIndex >= 0
			&& algorithm::binary_search(arr_visit, 0, nvisit, vid[i], nIndex1) == 0	// Not visited yet
			&& nIndex1 < 0)
		{
			dq.enqueue(vid[i]);
			algorithm::insert_into_sorted_asc(arr_visit, 0, nvisit, vid[i], nIndex1);
		}
		else
		{
			// throw "invalid id";
		}
	}

	while (!dq.empty())
	{
		dq.dequeue(nVisitID);

		// dq.dequeue(nVisitID)
		nCount++;

		if (algorithm::binary_search(_v_edge_l, 0, _n_edge, nVisitID, nLoIndex, nHiIndex) == 0)
		{
			for (int i = nLoIndex; i <= nHiIndex; ++i)
			{
				// Has not visited
				if (algorithm::binary_search(arr_visit, 0, nvisit, _v_edge_r[i], nIndex) == 0 && nIndex < 0)
				{
					dq.enqueue(_v_edge_r[i]);
					algorithm::insert_into_sorted_asc(arr_visit, 0, nvisit, _v_edge_r[i], nIndex);
				}
			}
		}

	}
	return 0;
}

int TreeAdj::count_node()
{
	return _nNode;
}

int TreeAdj::count_edge()
{
	return _n_edge;
}

/*================================================== 
 * Be careful: do not modify data after 
 *==================================================*/
int TreeAdj::get_data(int& nEdgesize, int* &pTreeLeft, int* &pTreeRight) {
	nEdgesize = _n_id2index;
	pTreeLeft = _m_id2index_l;
	pTreeRight = _m_id2index_r;

	return 0;
}

#define DISPLAY_ONE_PROCESS printf(".")
#define TEST_CHECK(condition, errormsg, verror, successcount, totalcount) if (condition) { successcount++; } else { verror.push_back(errormsg); } DISPLAY_ONE_PROCESS;totalcount++;
#define CONCAT_STR(strval, str1, str2, str3) strval=str1 + str2 + str3

void test_adjtree::test()
{
	printf("Starting Test\r\n");
	TreeAdj tree;
	int nRoot;
	int nChildID;
	int nChildID_L2;
	int nSuccess = 0;
	int nTotal = 0;
	const std::string nameRoot = "Root";
	vector<string> vname_in = { "A", "B", "C"};
	vector<string> vname_in_l2 = { "C1", "C2", "C3", "C4" };
	vector<string> vname_in_l3_1 = { "C11", "C12", "C13" };
	vector<string> vname_in_l3_2 = { "C21", "C22" };
	vector<int> vid_l2;
	vector<int> vid_l3_1;
	vector<int> vid_l3_2;

	std::sort(vname_in.begin(), vname_in.end());
	std::sort(vname_in_l2.begin(), vname_in_l2.end());

	tree.add_node(-1, nameRoot, nRoot);

	for (int i=0;i<vname_in.size();++i)
	{
		tree.add_node(nRoot, vname_in[i], nChildID);
	}

	int nRoot1;
	std::string name;
	tree.get_root_node(nRoot1, name);

	std::vector<std::string> verror;
	std::string strError;

	std::string str_Err_Root;
	CONCAT_STR(str_Err_Root, "Test Root name error. Expected Name=", nameRoot, "; Actual Name=");
	TEST_CHECK(name == nameRoot, str_Err_Root, verror, nSuccess,nTotal);

	/*
	if (!(name == nameRoot))
	{
		strError = "Test Root name error. Expected Name=" + nameRoot + "; Actual Name=" + name;
		verror.push_back(strError);
	}
	else
	{
		nSuccess++;
	}
	*/

	std::vector<int> vchild;
	std::vector<string> vchild_name;
	std::vector<int> vint;
	std::vector<string> vstr;

	tree.get_children(nRoot1, vchild, vchild_name);
	std::sort(vchild_name.begin(), vchild_name.end());

	char szBuff[1000];
	sprintf(szBuff, "Number of children. Expected=%d, Actual=%d", 3, vchild.size());
	TEST_CHECK(vchild.size()==3, szBuff, verror, nSuccess,nTotal);


	sprintf(szBuff, "Children name are not OK");
	TEST_CHECK(vname_in == vchild_name, szBuff, verror, nSuccess,nTotal);

	// 
	for (int i = 0; i < vname_in_l2.size(); ++i)
	{
		tree.add_node(nChildID, vname_in_l2[i], nChildID_L2);
		vid_l2.push_back(nChildID_L2);
	}

	for (int i=0;i<vname_in_l3_1.size();++i)
	{
		int nRetID;
		tree.add_node(vid_l2[0], vname_in_l3_1[i], nRetID);
		vid_l3_1.push_back(nRetID);
	}

	for (int i=0;i<vname_in_l3_2.size();++i)
	{
		int nRetID;
		tree.add_node(vid_l2[1], vname_in_l3_2[i], nRetID);
		vid_l3_2.push_back(nRetID);
	}

	vint.clear();
	vstr.clear();
	tree.get_children(nChildID, vint, vstr);

	std::sort(vstr.begin(), vstr.end());

	sprintf(szBuff, "Number of children (L2) not OK. Expected=%d, Actual=%d", vname_in_l2.size(), vint.size());
	TEST_CHECK(vint.size() == vname_in_l2.size(), szBuff, verror, nSuccess, nTotal);
	TEST_CHECK(vstr == vname_in_l2, "Name of children (L2) are not OK", verror, nSuccess, nTotal);


	tree.remove_node(nChildID);

	int nInt1, nInt2;

	nInt1 = tree.branch_population(nRoot);
	nInt2 = tree.count_node();
	sprintf(szBuff, "Test Node Count and Branch Popuplation is not OK, expected: they are equal. RootBranch Population=%d, TotalNode=%d", nInt1, nInt2);
	TEST_CHECK(nInt1 == nInt2, szBuff, verror, nSuccess, nTotal);

	tree.get_children(nRoot1, vchild, vchild_name);
	std::sort(vchild_name.begin(), vchild_name.end());
	sprintf(szBuff, "Number of children after removing a node - is not ok. Expected=%d, Actual=%d", vname_in.size() - 1, vchild.size());
	TEST_CHECK(vchild.size() == vname_in.size()-1, szBuff, verror, nSuccess, nTotal);


	int countNode = tree.count_node();
	int countEdge = tree.count_edge();

	sprintf(szBuff, "Reletionship Node/Edge is not OK. Expected num_node=num_edge+1. Actual, num_node=%d, num_edge=%d", countNode, countEdge);
	TEST_CHECK(countNode == countEdge + 1, szBuff, verror, nSuccess, nTotal);

	sprintf(szBuff, "Expected Node number after removal - Expected=%d, Actual=%d", (1+vname_in.size()-1), countNode);
	TEST_CHECK((1 + vname_in.size() - 1) == countNode, szBuff, verror, nSuccess, nTotal);

	printf("\r\nTest Finished. Success Operations: %02d/%02d.\r\n. \tError operations: %02d\r\n", nSuccess, nTotal, verror.size());
	for (int i = 0; i < verror.size(); ++i)
	{
		printf("\t Error (%d): %s\r\n", (i + 1), verror[i].c_str());
	}
}
