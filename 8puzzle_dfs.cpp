#include <iostream>
#include <stack>
#include <queue>
#include <cstdio>
<<<<<<< HEAD
using namespace std;

/*This is program to go from a start state of an 8-Puzzle problem to a goal state through DFS.
Give input with space between each number and give input as 0 for the blank space*/

int index=0;
=======
#include <cstdlib>
#include <ctime>
using namespace std;

/*This is a program to go from a start state of an 8-Puzzle problem to a goal state through DFS.
Give input with space between each number and give input as 0 for the cur.blank space*/

>>>>>>> 30e28743c777a4d3efa64eb1c4c8f55505c397c2

struct state
{
	int matrix[3][3];
<<<<<<< HEAD
	int blank_xloc;
	int blank_yloc;
};

struct state visited[10000];
queue<struct state> closed;


=======
	int blank_xloc, blank_yloc;
};

stack<struct state> open;
queue<struct state> closed;

//check_cycle() returns 1 if cycle exists, 0 otherwise
>>>>>>> 30e28743c777a4d3efa64eb1c4c8f55505c397c2
int check_cycle(struct state cur)
{
	queue<struct state> closed_copy;
	closed_copy = closed;
	struct state temp;
	while (!closed_copy.empty())
	{
<<<<<<< HEAD
		temp = closed_copy.front();
		closed_copy.pop();
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout<<temp.matrix[i][j]<<' ';
			}
			cout<<endl;
		}
	}
	cout<<endl;
}

=======
		int i,j;
		temp = closed_copy.front();
		closed_copy.pop();
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (temp.matrix[i][j] != cur.matrix[i][j])
					break;
			}
			if (j<3)
				break;
		}
		if (i == 3)
		{
			return 1;
		}
	}
	return 0;
}

//cmp_cur_goal returns 1 if current state and goal state match, 0 otherwise
>>>>>>> 30e28743c777a4d3efa64eb1c4c8f55505c397c2
int cmp_cur_goal (struct state cur, struct state goal)
{
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			if (cur.matrix[i][j] != goal.matrix[i][j])
				return 0;
		}
	}
	return 1;
}

<<<<<<< HEAD
int move_left(struct state cur, struct state goal)
=======
int move_left(struct state &cur, struct state goal)
>>>>>>> 30e28743c777a4d3efa64eb1c4c8f55505c397c2
{
	if (cur.blank_yloc > 0)
	{
		cur.matrix[cur.blank_xloc][cur.blank_yloc] = cur.matrix[cur.blank_xloc][cur.blank_yloc-1];
		cur.matrix[cur.blank_xloc][cur.blank_yloc-1] = 0;
		cur.blank_yloc -= 1;
<<<<<<< HEAD
		closed.push(cur);
=======
>>>>>>> 30e28743c777a4d3efa64eb1c4c8f55505c397c2
		return 1;
	}
	return 0;
}

<<<<<<< HEAD
int move_down(struct state cur, struct state goal)
=======
int move_down(struct state &cur, struct state goal)
>>>>>>> 30e28743c777a4d3efa64eb1c4c8f55505c397c2
{
	if (cur.blank_xloc < 2)
	{
		cur.matrix[cur.blank_xloc][cur.blank_yloc] = cur.matrix[cur.blank_xloc+1][cur.blank_yloc];
		cur.matrix[cur.blank_xloc+1][cur.blank_yloc] = 0;
		cur.blank_xloc += 1;
<<<<<<< HEAD
		closed.push(cur);
=======
>>>>>>> 30e28743c777a4d3efa64eb1c4c8f55505c397c2
		return 1;
	}
	return 0;
}

<<<<<<< HEAD
int move_right(struct state cur, struct state goal)
=======
int move_right(struct state &cur, struct state goal)
>>>>>>> 30e28743c777a4d3efa64eb1c4c8f55505c397c2
{
	if (cur.blank_yloc < 2)
	{
		cur.matrix[cur.blank_xloc][cur.blank_yloc] = cur.matrix[cur.blank_xloc][cur.blank_yloc+1];
		cur.matrix[cur.blank_xloc][cur.blank_yloc+1] = 0;
		cur.blank_yloc += 1;
<<<<<<< HEAD
		closed.push(cur);
=======
>>>>>>> 30e28743c777a4d3efa64eb1c4c8f55505c397c2
		return 1;
	}
	return 0;
}

<<<<<<< HEAD
int move_up(struct state cur, struct state goal)
=======
int move_up(struct state &cur, struct state goal)
>>>>>>> 30e28743c777a4d3efa64eb1c4c8f55505c397c2
{
	if (cur.blank_xloc > 0)
	{
		cur.matrix[cur.blank_xloc][cur.blank_yloc] = cur.matrix[cur.blank_xloc-1][cur.blank_yloc];
		cur.matrix[cur.blank_xloc-1][cur.blank_yloc] = 0;
		cur.blank_xloc -= 1;
<<<<<<< HEAD
		closed.push(cur);
=======
>>>>>>> 30e28743c777a4d3efa64eb1c4c8f55505c397c2
		return 1;
	}
	return 0;
	
}

<<<<<<< HEAD
void print(struct state temp){

	for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout<<temp.matrix[i][j]<<' ';
			}
			cout<<endl;
		}
}
int check_visited (struct state cur, int index)
{
	for (int i=0; i<index; i++)
	{
		int val = cmp_cur_goal(visited[i], cur);
		if(val==1)
			return i;
	}
	return -1;
}

int bfs(struct state goal)
{
	int flag=0;
	getchar();
	//check_cycle(cur);
	//queue<struct state> Q;
	struct state cur = closed.front();
	print(cur);
	closed.pop();

	if(check_visited(cur, index)!=-1)
		return bfs(goal);
=======

int dfs(struct state cur, struct state goal)
{
	if(check_cycle(cur) == 1)
	{
		cout<<"Cycle exists. Failure\n";
		exit(0);
	}
	closed.push(cur);
>>>>>>> 30e28743c777a4d3efa64eb1c4c8f55505c397c2

	int cmp_val = cmp_cur_goal(cur,goal);
	if (cmp_val == 1)
		return 1;

	int moved;
	moved = move_left(cur, goal);
	if (moved == 1)
	{
<<<<<<< HEAD
		flag=1;
=======
		return dfs (cur, goal);
>>>>>>> 30e28743c777a4d3efa64eb1c4c8f55505c397c2
	}
	moved = move_down(cur, goal);
	if (moved == 1)
	{
<<<<<<< HEAD
		flag=1;
		//cout << "1" << endl;
=======
		return dfs (cur, goal);
>>>>>>> 30e28743c777a4d3efa64eb1c4c8f55505c397c2
	}
	moved = move_right(cur, goal);
	if (moved == 1)
	{
<<<<<<< HEAD
		flag=1;
	}	
	moved = move_up(cur, goal);
	if(moved == 1)
	{	
		flag=1;
		//return bfs (cur, goal);
	}

	if(flag == 1){
		//cout << "3" << endl;
		visited[index++]=cur;
		return bfs(goal);
	}
=======
		return dfs (cur, goal);
	}	
	moved = move_up(cur, goal);
	if(moved == 1)
		return dfs (cur, goal);
>>>>>>> 30e28743c777a4d3efa64eb1c4c8f55505c397c2
	else
		return 0;
}

int main()
{
	struct state start, goal;
	int i,j;
<<<<<<< HEAD

	cin>> "Enter the start/inital state";
=======
>>>>>>> 30e28743c777a4d3efa64eb1c4c8f55505c397c2
	for (i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cin>>start.matrix[i][j];
			if(start.matrix[i][j] == 0)
			{
				start.blank_xloc = i;
				start.blank_yloc = j;
			}	
		}
	}
<<<<<<< HEAD
	cin>> "Enter the goal/final state";
=======
>>>>>>> 30e28743c777a4d3efa64eb1c4c8f55505c397c2
	for (i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			cin>>goal.matrix[i][j];
	}

<<<<<<< HEAD
	closed.push(start);
	if( bfs(goal) == 1 )
		cout<<"Success\n";
=======
	const clock_t begin_time = clock();
	open.push(start);
	if( dfs(start, goal) == 1 )
	{
		cout<<"Success\nPath\n";
		queue<struct state> closed_copy;
		closed_copy = closed;
		struct state temp;
		while (!closed_copy.empty())
		{
			int i,j;
			temp = closed_copy.front();
			closed_copy.pop();
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
					cout<<temp.matrix[i][j]<<' ';
				cout<<endl;
			}
			cout<<"\n";
		}
		float time_taken = float( clock () - begin_time ) /  CLOCKS_PER_SEC;
		cout<<"Time taken: "<<time_taken<<endl;
		cout<<"Size of closed list: "<<closed.size()<<endl;
	}	
>>>>>>> 30e28743c777a4d3efa64eb1c4c8f55505c397c2
	else
		cout<<"Failure\n";

	return 0;
}