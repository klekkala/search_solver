#include <iostream>
#include <queue>

using namespace std;


int scan(int (*closed)[3][3], int matrix[][3], int index){

    int flag=0;
    for(int i=0;i<index;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(closed[i][j][k]!=matrix[j][k]){

                    flag = 1;
                    break;
                }
            }
            if(flag==1)
                break;
        }
    }

    if(flag==0)
        return 0;
    else{
        return 1;
    }

}
int compare(int current_matrix[][3], int goal_matrix[][3]){

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(current_matrix[i][j]!=goal_matrix[i][j])
                return 1;
        }
    }

    return 0;
}




int BFS(int start_matrix[][3], int goal_matrix[][3])
{
    int closed[1000][3][3]={0};
    int index=0;
    int** matrix;
    queue<int**> Q;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            closed[index++][i][j]=start_matrix[i][j];
        }
    }
    Q.push(start_matrix);
    int current_matrix[][3] = start_matrix;
    while(compare(current_matrix, goal_matrix))
    {
        //int x=Q.front();
        current_matrix = Q.pop(); // pop here. we have x now

        matrix = current_matrix;
        for(int i=0;i<3;i++){
            for(int j=1;j<3;j++){
                if(matrix[i][j]>0){
                    matrix[i][j] = matrix[i-1][j];
                    matrix[i-1][j] = 0;
                }

            }
        }
        if(scan(closed, matrix, index)==0)
        {
             for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            closed[index++][i][j]=start_matrix[i][j];
        }
    }
            Q.push(matrix);
        }

        matrix = current_matrix;
        for(int i=0;i<3;i++){
            for(int j=0;j<2;j++){
                if(matrix[i][j]>0){
                    matrix[i][j] = matrix[i+1][j];
                    matrix[i+1][j] = 0;
                }

            }
        }
        if(scan(closed, matrix, index)==0)
        {
             for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            closed[index++][i][j]=start_matrix[i][j];
        }
    }
            Q.push(matrix);
        }

        matrix = current_matrix;
        for(int i=1;i<3;i++){
            for(int j=0;j<3;j++){
                if(matrix[i][j]>0){
                    matrix[i][j] = matrix[i][j-1];
                    matrix[i][j-1] = 0;
                }

            }
        }

        if(scan(closed, matrix, index)==0)
        {
             for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            closed[index++][i][j]=start_matrix[i][j];
        }
    }
            Q.push(matrix);
        }

        matrix = current_matrix;
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                if(matrix[i][j]>0){
                    matrix[i][j] = matrix[i][j+1];
                    matrix[i][j+1] = 0;
                }

            }
        }

        if(scan(closed, matrix, index)==0)
        {
             for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            closed[index++][i][j]=start_matrix[i][j];
        }
    }
            Q.push(matrix);
        }

    }

    //closed[x]=2; // set closed here.
    return 0;
}


int main(){


    int start_matrix[3][3];
    int goal_matrix[3][3];

    //int start_matrix_int[3][3];
    //int goal_matrix_int[3][3];
    //int x,y;

    cout << "Enter the start state";
    for(int x=0;x<3;x++)  // loop 3 times for three lines
    {
        for(int y=0;y<3;y++)  // loop for the three elements on the line
        {
            cin >> start_matrix[x][y];  // display the current element out of the array
        }
    }


    cout << "Enter the goal state";
    for(int x=0;x<3;x++)  // loop 3 times for three lines
    {
        for(int y=0;y<3;y++)  // loop for the three elements on the line
        {
            cin >> goal_matrix[x][y];  // display the current element out of the array
        }
    }


    int result = BFS(start_matrix, goal_matrix);
    //print result;
    return 0;
}
