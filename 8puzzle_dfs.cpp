#include <iostream>
#include <stack>
#include <queue>
#include <cstdio>
using namespace std;

/*This is program to go from a start state of an 8-Puzzle problem to a goal state through DFS.
Give input with space between each number and give input as 0 for the blank space*/

int blank_xloc=0, blank_yloc=0;

struct state
{
	int matrix[3][3];
};

stack<struct state> open;
queue<struct state> closed;

int check_cycle(struct state cur)
{
	queue<struct state> closed_copy;
	closed_copy = closed;
	struct state temp;
	while (!closed_copy.empty())
	{
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

int move_left(struct state cur, struct state goal)
{
	if (blank_yloc > 0)
	{
		cur.matrix[blank_xloc][blank_yloc] = cur.matrix[blank_xloc][blank_yloc-1];
		cur.matrix[blank_xloc][blank_yloc-1] = 0;
		blank_yloc -= 1;
		return 1;
	}
	return 0;
}

int move_down(struct state cur, struct state goal)
{
	if (blank_xloc < 2)
	{
		cur.matrix[blank_xloc][blank_yloc] = cur.matrix[blank_xloc+1][blank_yloc];
		cur.matrix[blank_xloc+1][blank_yloc] = 0;
		blank_xloc += 1;
		return 1;
	}
	return 0;
}

int move_right(struct state cur, struct state goal)
{
	if (blank_yloc < 2)
	{
		cur.matrix[blank_xloc][blank_yloc] = cur.matrix[blank_xloc][blank_yloc+1];
		cur.matrix[blank_xloc][blank_yloc+1] = 0;
		blank_yloc += 1;
		return 1;
	}
	return 0;
}

int move_up(struct state cur, struct state goal)
{
	if (blank_xloc > 0)
	{
		cur.matrix[blank_xloc][blank_yloc] = cur.matrix[blank_xloc-1][blank_yloc];
		cur.matrix[blank_xloc-1][blank_yloc] = 0;
		blank_xloc -= 1;
		return 1;
	}
	return 0;
	
}


int dfs(struct state cur, struct state goal)
{
	getchar();
	check_cycle(cur);
	closed.push(cur);

	int cmp_val = cmp_cur_goal(cur,goal);
	if (cmp_val == 1)
		return 1;

	int moved;
	moved = move_left(cur, goal);
	if (moved == 1)
	{
		return dfs (cur, goal);
	}
	moved = move_down(cur, goal);
	if (moved == 1)
	{
		return dfs (cur, goal);
	}
	moved = move_right(cur, goal);
	if (moved == 1)
	{
		return dfs (cur, goal);
	}	
	moved = move_up(cur, goal);
	if(moved == 1)
		return dfs (cur, goal);
	else
		return 0;
}

int main()
{
	struct state start, goal;
	int i,j;
	for (i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cin>>start.matrix[i][j];
			if(start.matrix[i][j] == 0)
			{
				blank_xloc = i;
				blank_yloc = j;
			}	
		}
	}
	for (i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			cin>>goal.matrix[i][j];
	}

	open.push(start);
	if( dfs(start, goal) == 1 )
		cout<<"Success\n";
	else
		cout<<"Failure\n";

	return 0;
}