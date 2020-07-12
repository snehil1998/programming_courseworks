/*
	First name	SNEHIL
	Last name		KUMAR
	Student ID	01355676
	Username		SK9217
*/

//IMPORTANT: before submitting your source code, please make sure to comment your main function (needed for automated testing)


#include <iostream>
#include <string>
#include <queue>
#include <stack>


struct node {
	char id;
	node* north;
	node* south;
	node* east;
	node* west;
};


typedef node* nodeptr;


void build_basic_maze(nodeptr& start, nodeptr& finish);


nodeptr traverse_maze(const nodeptr& start, const std::string& path);


void solve_interactively(const nodeptr& start, const nodeptr& finish, std::string& path);


nodeptr random_walk(const nodeptr& start, const nodeptr& finish, std::string& path);


void solve_queue(const nodeptr& start, const nodeptr& finish, std::string& path);


void solve_stack(const nodeptr& start, const nodeptr& finish, std::string& path);


void queue_call(const nodeptr& start, const nodeptr& finish, std::string& path, std::string& queue_temp);


void stack_call(const nodeptr& start, const nodeptr& finish, std::string& path, std::string& stack_store);




int main() {

	nodeptr start = NULL ;
	nodeptr finish = NULL ;
	std::string path;

	build_basic_maze(start , finish) ;
	std::cout << "start = " << start->id <<std::endl ;
	std::cout << "finish = " << finish->id <<std::endl ;
	 path = "NWNE" ;
	 nodeptr stop = traverse_maze(start, path) ;
	  std::cout<<stop->id<<std::endl;

	 //solve_interactively(start, finish, path);

	 //nodeptr a = random_walk(start, finish, path);

	//solve_queue(start, finish, path);

	//solve_stack(start, finish, path);

	return 0;
}





void build_basic_maze(nodeptr& start, nodeptr& finish)
{
	nodeptr tmpA = new node ;
	nodeptr tmpB = new node ;
	nodeptr tmpC = new node ;
	nodeptr tmpD = new node ;
	nodeptr tmpE = new node ;
	nodeptr tmpF = new node ;
	nodeptr tmpG = new node ;
	nodeptr tmpH = new node ;
	nodeptr tmpI = new node ;
	nodeptr tmpJ = new node ;
	nodeptr tmpK = new node ;
	nodeptr tmpL = new node ;

 	tmpA->id = 'A' ;
 	tmpA->north = NULL ;
 	tmpA->west = NULL ;
	tmpA->south = tmpE;
	tmpA->east = tmpB;

 	tmpB->id = 'B' ;
 	tmpB->north = NULL ;
 	tmpB->west = tmpA ;
	tmpB->south = tmpF;
	tmpB->east = NULL;

 	tmpC->id = 'C' ;
 	tmpC->north = NULL ;
 	tmpC->west = NULL ;
	tmpC->south = tmpG;
	tmpC->east = tmpD;

 	tmpD->id = 'D' ;
 	tmpD->north = NULL ;
 	tmpD->west = tmpC ;
	tmpD->south = NULL;
	tmpD->east = NULL;

 	tmpE->id = 'E' ;
 	tmpE->north = tmpA ;
 	tmpE->west = NULL ;
	tmpE->south = tmpI;
	tmpE->east = NULL;

 	tmpF->id = 'F' ;
 	tmpF->north = tmpB ;
 	tmpF->west = NULL ;
	tmpF->south = NULL;
	tmpF->east = tmpG;

 	tmpG->id = 'G' ;
 	tmpG->north = tmpC ;
 	tmpG->west = tmpF ;
	tmpG->south = tmpK;
	tmpG->east = tmpH;

 	tmpH->id = 'H' ;
 	tmpH->north = NULL ;
 	tmpH->west = tmpG ;
	tmpH->south = tmpL;
	tmpH->east = NULL;

 	tmpI->id = 'I' ;
 	tmpI->north = tmpE ;
 	tmpI->west = NULL ;
	tmpI->south = NULL;
	tmpI->east = tmpJ;

 	tmpJ->id = 'J' ;
 	tmpJ->north = NULL ;
 	tmpJ->west = tmpI ;
	tmpJ->south = NULL;
	tmpJ->east = NULL;

 	tmpK->id = 'K' ;
 	tmpK->north = tmpG ;
 	tmpK->west = NULL ;
	tmpK->south = NULL;
	tmpK->east = NULL;

 	tmpL->id = 'L' ;
 	tmpL->north = tmpH ;
 	tmpL->west = NULL ;
	tmpL->south = NULL;
	tmpL->east = NULL;

	start = tmpL;
	finish = tmpD;

}




nodeptr traverse_maze(const nodeptr& start, const std::string& path){
	nodeptr current = start;
	for (int i=0; i<path.size(); i++) {
    if(path[i]=='E')
		{current = current->east;}
		else if(path[i]=='W')
		{current = current->west;}
		else if(path[i]=='S')
		{current = current->south;}
		else if(path[i]=='N')
		{current = current->north;}
	}
	return current;
}




void solve_interactively(const nodeptr& start, const nodeptr& finish, std::string& path){
	nodeptr curr = start;
	char input = 'Z';
	int i = 0;

	while(curr!=finish){

			std::cout<<"You're in Room "<<curr->id<<" of the maze"<<std::endl;
			std::cout<<"You can go: ";
			if(curr->north!=NULL){
				std::cout<<"(N)orth, ";
			}
			if(curr->south!=NULL){
				std::cout<<"(S)outh, ";
			}
			if(curr->east!=NULL){
				std::cout<<"(E)ast, ";
			}
			if(curr->west!=NULL){
				std::cout<<"(W)est, ";
			}
			std::cout<<"(Q)uit"<<std::endl;

			std::cin>>input;
			path.push_back(input);
			if(input == 'Q'){return;}

			if(input=='E')
			{curr = curr->east;}
			else if(input=='W')
			{curr = curr->west;}
			else if(input=='S')
			{curr = curr->south;}
			else if(input=='N')
			{curr = curr->north;}
	}
	std::cout<<"Congratulations, you have completed the maze"<<std::endl;
	std::cout<<"Path is ";
	for (int i=0 ; i < path.size(); i++)
	{
		std::cout << path[i];
	}
	std::cout << std::endl;
}




nodeptr random_walk(const nodeptr& start, const nodeptr& finish, std::string& path){
	int i = 0, j = 0;
	nodeptr curr = start;
	while(curr!=finish){
		int num = rand()%4;
		if(num == 0){
			i++;
			if(curr->north != NULL){
				curr = curr->north;
				path.push_back('N');
			}
		}
		else if(num == 1){
			i++;
			if(curr->west !=NULL){
				curr = curr->west;
				path.push_back('W');
			}
		}
		else if(num == 2){
			i++;
			if(curr->south !=NULL){
				curr = curr->south;
				path.push_back('S');
			}
		}
		else if(num == 3){
			i++;
			if(curr->east !=NULL){
				curr = curr->east;
				path.push_back('E');
			}


		}
		if(i>100){break;}
	}
	if(i>100){
		std::cout<<"You did not reach the finish"<<std::endl;
		std::cout<<"Path is ";
		for(int k = 0; k<path.size(); k++){
			std::cout<<path[k];
		}
		std::cout<<std::endl;
		std::cout<<curr->id<<std::endl;
	}
	else{
		std::cout<<"Congratulations, you completed the maze"<<std::endl;
		std::cout<<"Path is ";
		for (int i=0 ; i < path.size(); i++)
		{
			std::cout << path[i];
		}
		std::cout << std::endl;
	}
}





void solve_queue(const nodeptr& start, const nodeptr& finish, std::string& path)
{
	nodeptr curr = start;
	std::string visited;
	std::queue <nodeptr> neighbour_node;
	int count = 0;
	bool check = false;
	nodeptr temp;

	while (curr != finish)
	{

		visited[count++]= curr->id;
		if(curr->north != NULL)
		{
			for(int i=0; i < strlen(visited.c_str()); i++)
			{
				if (visited[i] == curr->north->id)
				{
					check = true;
					break;
				}
				else
				{
					check = false;
				}
			}
			if(check == false)
			{
				temp = curr->north;
				neighbour_node.push(temp);
			}
		}
		if(curr->south != NULL)
		{
			for(int i=0; i < strlen(visited.c_str()); i++)
			{
				if (visited[i] == curr->south->id)
				{
					check = true;
					break;
				}
				else
				{
					check = false;
				}
			}
			if(check == false)
			{
				temp = curr->south;
				neighbour_node.push(temp);
			}
		}

		if(curr->east != NULL)
		{
			for(int i=0; i < strlen(visited.c_str()); i++)
			{
				if (visited[i] == curr->east->id)
				{
					check = true;
					break;
				}
				else
				{
					check = false;
				}
			}

			if(check == false)
			{
				temp = curr->east;
				neighbour_node.push(temp);
			}
		}

		if(curr->west != NULL)
		{
			for(int i=0; i < strlen(visited.c_str()); i++)
			{
				if (visited[i] == curr->west->id)
				{
					check = true;
					break;
				}
				else
				{
					check = false;
				}
			}
			if(check == false)
			{
				temp = curr->west;
				neighbour_node.push(temp);
			}
		}

			curr = neighbour_node.front();
			neighbour_node.pop();
	}


	if(curr == finish)
	{
		std::cout << "Congratulations, you reached the finish!" << std::endl;
		std::cout << path << std::endl;
		std::cout<<"Visited nodes- ";
		for(int i = 0; i<strlen(visited.c_str()); i++){
			std::cout<<visited[i];
		}
		std::cout<<std::endl;
	}

	std::string store;
	queue_call(start, finish, store, path);
}




void queue_call(const nodeptr& start, const nodeptr& finish, std::string& path, std::string& queue_store)
{
	nodeptr next;
	std::string path_queue;
	nodeptr curr = start;

	if(curr->east != NULL)
	{
		path.push_back('E');
		next = curr->east;
		next->west = NULL;
		curr->east = NULL;
		queue_call(next, finish, path, queue_store);
	}

	if(curr->west != NULL)
	{
		path.push_back('W');
		next = curr->west;
		next->east = NULL;
		curr->west = NULL;
		queue_call(next, finish, path, queue_store);
	}

	if(curr->south != NULL)
	{
		path.push_back('S');
		next = curr->south;
		next->north = NULL;
		curr->south = NULL;
		queue_call(next, finish, path, queue_store);
	}

	if(curr->north != NULL)
	{
		path.push_back('N');
		next = curr->north;
		next->south = NULL;
		curr->north = NULL;
		queue_call(next, finish, path, queue_store);
	}

	std::cout << std::endl;

	if (curr != finish)
	{
		for(int i=0; i < path.size()-1; i++)
		{
			path_queue.push_back(path[i]);
		}
		path.clear();
		path = path_queue;
	}

	if(curr == finish)
	{
		std::cout <<"Path- "<< path << std::endl;
		queue_store = path;
	}
}





void solve_stack(const nodeptr& start, const nodeptr& finish, std::string& path){
	nodeptr curr = start;
	std::string visited;
	std::stack <nodeptr> neighbour_node;
	int count = 0;
	bool check = 0;
	nodeptr store;

	while (curr != finish)
	{

		visited[count++]= curr->id;
		if(curr->north != NULL)
		{
			for(int i=0; i < strlen(visited.c_str()); i++)
			{
				if (visited[i] == curr->north->id)
				{
					check = true;
					break;
				}
				else
				{
					check = false;
				}
			}
			if(check == false)
			{
				store = curr->north;
				neighbour_node.push(store);
			}
		}
		if(curr->south != NULL)
		{
			for(int i=0; i < strlen(visited.c_str()); i++)
			{
				if (visited[i] == curr->south->id)
				{
					check = true;
					break;
				}
				else
				{
					check = false;
				}
			}
			if(check == false)
			{
				store = curr->south;
				neighbour_node.push(store);
			}
		}

		if(curr->east != NULL)
		{
			for(int i=0; i < strlen(visited.c_str()); i++)
			{
				if (visited[i] == curr->east->id)
				{
					check = true;
					break;
				}
				else
				{
					check = false;
				}
			}

			if(check == false)
			{
				store = curr->east;
				neighbour_node.push(store);
			}
		}

		if(curr->west != NULL)
		{
			for(int i=0; i < strlen(visited.c_str()); i++)
			{
				if (visited[i] == curr->west->id)
				{
					check = true;
					break;
				}
				else
				{
					check = false;
				}
			}
			if(check == false)
			{
				store = curr->west;
				neighbour_node.push(store);
			}
		}
			curr = neighbour_node.top();
			neighbour_node.pop();
	}


	if(curr == finish)
	{
		std::cout << "Congratulations, you reached the finish!" << std::endl;
		std::cout << "Visited Nodes- ";
		for(int i = 0; i<strlen(visited.c_str()); i++)
		{
			std::cout<< visited[i];
		}
		std::cout<<std::endl;
	}

		std::string temporary;
		stack_call(start, finish, temporary, path);
}




void stack_call(const nodeptr& start, const nodeptr& finish, std::string& path, std::string& stack_store)
{
	nodeptr curr = start;
	nodeptr next;
	std::stack <char> path_stack;

	if(curr->east != NULL)
	{
		path.push_back('E');
		next = curr->east;
		next->west = NULL;
		curr->east = NULL;
		stack_call(next, finish, path, stack_store);
	}

	if(curr->west != NULL)
	{
		path.push_back('W');
		next = curr->west;
		next->east = NULL;
		curr->west = NULL;
		stack_call(next, finish, path, stack_store);
	}

	if(curr->south != NULL)
	{
		path.push_back('S');
		next = curr->south;
		next->north = NULL;
		curr->south = NULL;
		stack_call(next, finish, path, stack_store);
	}

	if(curr->north != NULL)
	{
		path.push_back('N');
		next = curr->north;
		next->south = NULL;
		curr->north = NULL;
		stack_call(next, finish, path, stack_store);
	}

	if (curr != finish)
	{
		for(int i=path.size()-2; i >= 0; i--)
		{
			path_stack.push(path[i]);
		}
		path.clear();

		while(!path_stack.empty())
		{
			path.push_back(path_stack.top());
			path_stack.pop();
		}
	}

	if(curr == finish)
	{
		std::cout << "Path- " << path << std::endl;
		stack_store = path;
	}
}
