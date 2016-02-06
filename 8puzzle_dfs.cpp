#include <iostream>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

/*This is a program to go from a start state of an 8-Puzzle problem to a goal state through DFS.
Give input with space between each number and give input as 0 for the cur.blank space*/


struct state
{
	int matrix[3][3];
	int blank_xloc, blank_yloc;
};

stack<struct state> open;
queue<struct state> closed;

//check_cycle() returns 1 if cycle exists, 0 otherwise
int check_cycle(struct state cur)
{
	queue<struct state> closed_copy;
	closed_copy = closed;
	struct state temp;
	while (!closed_copy.empty())
	{
		int flag=0;
		int i,j;
		temp = closed_copy.front();
		closed_copy.pop();
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (temp.matrix[i][j] != cur.matrix[i][j])
				{
					flag=1;
					break;
				}
			}
			if (flag == 1)
				break;
		}

		if (flag == 0)
		{
			return 1;
		}
	}
	return 0;
}

//cmp_cur_goal returns 1 if current state and goal state match, 0 otherwise
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

int move_left(struct state &cur, struct state goal)
{
	if (cur.blank_yloc > 0)
	{
		cur.matrix[cur.blank_xloc][cur.blank_yloc] = cur.matrix[cur.blank_xloc][cur.blank_yloc-1];
		cur.matrix[cur.blank_xloc][cur.blank_yloc-1] = 0;
		cur.blank_yloc -= 1;
		return 1;
	}
	return 0;
}

int move_down(struct state &cur, struct state goal)
{
	if (cur.blank_xloc < 2)
	{
		cur.matrix[cur.blank_xloc][cur.blank_yloc] = cur.matrix[cur.blank_xloc+1][cur.blank_yloc];
		cur.matrix[cur.blank_xloc+1][cur.blank_yloc] = 0;
		cur.blank_xloc += 1;
		return 1;
	}
	return 0;
}

int move_right(struct state &cur, struct state goal)
{
	if (cur.blank_yloc < 2)
	{
		cur.matrix[cur.blank_xloc][cur.blank_yloc] = cur.matrix[cur.blank_xloc][cur.blank_yloc+1];
		cur.matrix[cur.blank_xloc][cur.blank_yloc+1] = 0;
		cur.blank_yloc += 1;
		return 1;
	}
	return 0;
}

int move_up(struct state &cur, struct state goal)
{
	if (cur.blank_xloc > 0)
	{
		cur.matrix[cur.blank_xloc][cur.blank_yloc] = cur.matrix[cur.blank_xloc-1][cur.blank_yloc];
		cur.matrix[cur.blank_xloc-1][cur.blank_yloc] = 0;
		cur.blank_xloc -= 1;
		return 1;
	}
	return 0;

}


int dfs(struct state cur, struct state goal)
{
	if(check_cycle(cur) == 1)
	{
		cout<<"Cycle exists. Failure\n";
		exit(0);
	}
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
				start.blank_xloc = i;
				start.blank_yloc = j;
			}
		}
	}
	for (i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			cin>>goal.matrix[i][j];
	}

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
		cout<<"Size of closed list: "<<closed.size()<<endl;
	}
	else
		cout<<"Failure\n";

		cout<<closed.size()<<endl;
    return 0;
}
