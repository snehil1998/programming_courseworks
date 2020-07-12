/*
	First name	SNEHIL
	Last name		KUMAR
	Student ID	01355676
	Username		sk9217
*/

//IMPORTANT: before submitting your source code, please make sure to comment your main function (needed for automated testing)

//Uses C++11 features

#include <iostream>
#include <string>
#include <map>
#include <vector> //or #include <list>
#include <queue>
#include <chrono>


// do not use using namespace std

// do not alter the struct declaration
struct hufftreenode {
	char character;
	int frequency;
	hufftreenode* left;
	hufftreenode* right;
};

// do not alter the typedef
typedef hufftreenode* hufftreeptr;


//utility function
bool valid_hufftree(const hufftreeptr hufftree);

std::string huffencode(const std::string& message, std::map<char, int>& freqtable, hufftreeptr& hufftree, std::map<char, std::string>& hufftable);

std::string huffdecode(const std::string& encodedmessage, const hufftreeptr& hufftree);

void decode(hufftreenode* treenode, int &strsize, std::string str, std::string &strdecode);

void encode(hufftreenode* treenode, std::string str, std::map<char,std::string>& hufftable);

hufftreenode* getTreeNode(char ch, int freq, hufftreenode* left, hufftreenode* right);




// int main() {
//
// 	std::string message, encodedmessage, decodedmessage;
// 	hufftreeptr hufftree;
// 	std::map<char, int> freqtable;
// 	std::map<char, std::string> hufftable;
//
// 	message = "go go gophers";
//
// 	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
// 	encodedmessage = huffencode(message, freqtable, hufftree, hufftable);
// 	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
// 	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count();
// 	std::cout << "Encoding duration: " << duration << "ms" << std::endl;
//
// 	std::chrono::high_resolution_clock::time_point t3 = std::chrono::high_resolution_clock::now();
// 	if(valid_hufftree(hufftree))  {
// 		std::cout << "valid Huffman tree." << std::endl;
// 	}
// 	else {
// 		std::cout << "not valid Huffman tree." << std::endl;
// 	}
// 	std::chrono::high_resolution_clock::time_point t4 = std::chrono::high_resolution_clock::now();
// 	auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(t4-t3).count();
// 	std::cout << "Valid duration: " << duration2 << "ms" << std::endl;
//
// 	std::chrono::high_resolution_clock::time_point t5 = std::chrono::high_resolution_clock::now();
// 	decodedmessage = huffdecode(encodedmessage, hufftree);
// 	std::chrono::high_resolution_clock::time_point t6 = std::chrono::high_resolution_clock::now();
// 	auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(t6-t5).count();
// 	std::cout << "Decoding duration: " << duration3 << "ms" << std::endl;
//
// 	std::cout<<decodedmessage<<std::endl;
// 	std::cout<<std::endl;
// 	if(decodedmessage == message) {
// 		std::cout << "decoding OK." << std::endl;
// 	}
// 	else {
// 		std::cout << "decoding not OK." << std::endl;
// 	}
//
// 	return 0;
// }



std::string huffencode(const std::string& message, std::map<char,int>& freqtable, hufftreeptr& hufftree, std::map<char,std::string>& hufftable){

	for(char ch: message)
	{
		freqtable[ch]++;
	}

	std::priority_queue<hufftreenode*, std::vector<hufftreenode*>, std::greater<hufftreenode*> > pq;
	for (auto freqitem: freqtable)
	{
		pq.push(getTreeNode(freqitem.first, freqitem.second, nullptr, nullptr));						//pushing the node of each item from freqtable into the priority queue in increasing order of frequency
	}

	while (pq.size() != 1)
	{
		hufftreenode*left = pq.top(); 																									// Remove the two nodes of highest priority (lowest frequency) from the queue
		pq.pop();
		hufftreenode*right = pq.top();
		pq.pop();

		int sum = left->frequency + right->frequency;																		//creating a new node with with these nodes as left and right leaves and frequency equal to the sum of the frequency of the two nodes
		pq.push(getTreeNode('\0', sum, left, right));																		//Add the new node to the priority queue.
	}

	hufftree = pq.top();

	std::string strencode;
	encode(hufftree, strencode, hufftable);

	std::string return_encodedstr;
	for (char ch: message)
	{
		return_encodedstr += hufftable[ch];
	}

	return return_encodedstr;
}



void encode(hufftreenode* treenode, std::string str, std::map<char,std::string>& hufftable){

	if (treenode == nullptr){																																				//empty tree
		return;
	}

	if (!treenode->left && !treenode->right) 																												// found a leaf node, stores the binary pattern for the corresponding character in hufftable
	{
		hufftable[treenode->character] = str;
	}

	encode(treenode->left, str + '0', hufftable);
	encode(treenode->right, str + '1', hufftable);
}



std::string huffdecode(const std::string& encodedmessage, const hufftreeptr& hufftree){							//calls decode function and returns the decoded string

	std::string return_decodedstr;
	int strsize = -1;
	while (strsize < (int)(encodedmessage.size()))
	{
		decode(hufftree, strsize, encodedmessage, return_decodedstr);
	}
	return return_decodedstr;
}



void decode(hufftreenode* treenode, int &strsize, std::string str, std::string &strdecode){

	if (treenode == nullptr){																																							//empty tree
		return;
	}

	if (!treenode->left && !treenode->right){																															// found a leaf node, adds the character stored in the node to the string
		strdecode += treenode->character;
		return;
	}

	strsize++;

	if (str[strsize] =='0')
		decode(treenode->left, strsize, str, strdecode);
	else if (str[strsize] =='1')
		decode(treenode->right, strsize, str, strdecode);
}



hufftreenode* getTreeNode(char ch, int freq, hufftreenode* left, hufftreenode* right){									//makes a sub-tree for each character

	hufftreenode* node = new hufftreenode();

	node->character = ch;
	node->frequency = freq;
	node->left = left;
	node->right = right;

	return node;
}



bool valid_hufftree(const hufftreeptr hufftree){																						//checks the validity of huffman tree
	std::string storage;
	storage.clear();
	if((hufftree->left==nullptr)&&(hufftree->right==nullptr)){																//checks whether a character is present in the leaf node
		storage+=hufftree->character;
		if(storage.size()==0){
			return false;
		}
	}
	else{
		if((hufftree->left!=nullptr)&&(hufftree->right!=nullptr)){															//checks whether non-leaf node has left and right child
			if(hufftree->frequency != hufftree->left->frequency + hufftree->right->frequency){		//checks whether the frequency of the non-leaf node is equal to the sum for frequencies of its left and right child
				return false;
			}
		}
		else{
			return false;
		}
	}

	if(hufftree->left!=nullptr)
		valid_hufftree(hufftree->left);
	if(hufftree->right!=nullptr)
		valid_hufftree(hufftree->right);

	return true;
}
