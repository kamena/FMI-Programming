#include <iostream>

using namespace std;

const int MAX_WIDTH = 100;
const int MAX_HEIGHT = 100;

void copy_2d(char* this_arr, char* other_arr, int cols, int rows) {
  for (int x=0 ; x < rows; x++) {
      for (int y=0 ; y < cols; y++) {
        *((this_arr+x*cols) + y) = *((other_arr+x*cols) + y);
      }
    }  
}

void forest100(char* tree, int cols, int rows) {
    char comparetree[rows][cols];
    copy_2d((char*)comparetree, tree, cols, rows);

    for (int time_passed = 0; time_passed < 99; time_passed++) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                switch(comparetree[i][j]) {
                    case '1':
                        *((tree+i*cols) + j) = '2';
                        break;
                    case '2':
                        *((tree+i*cols) + j) = '3';
                        break;
                    case '3':
                        *((tree+i*cols) + j) = '4';
                        break;
                    case '4': {
                        int count_trees = 0;
                        for (int k = i-1; k <= i+1; ++k) {
                            for (int l = j-1; l <= j+1; ++l) {
                                if (k < 0 || k >= rows || l < 0 || l >= cols || (k == i && l == j)) {
                                    continue;
                                }
                                if (comparetree[k][l] == '4') count_trees++;
                                if (count_trees >= 3) break;
                            }
                            if (count_trees >= 3) break;
                        }
                        // if (comparetree[i+1][j] == '4') count_trees++;
                        // if (comparetree[i+1][j+1] == '4') count_trees++;
                        // if (comparetree[i-1][j] == '4') count_trees++;
                        // if (comparetree[i-1][j-1] == '4') count_trees++;
                        // if (comparetree[i+1][j-1] == '4') count_trees++;
                        // if (comparetree[i-1][j+1] == '4') count_trees++;
                        // if (comparetree[i][j-1] == '4') count_trees++;
                        // if (comparetree[i][j+1] == '4') count_trees++;
                        
                        
                        *((tree+i*cols) + j) = count_trees >= 3 ? '3' : '4';
                        break;
                    }
                }
            }
        }
        copy_2d((char*)comparetree, tree, cols, rows);
    }
};

int main() {
    char forest[4][6] = {
        {'R', 'R', '1', '1', '2', '2'},
        {'1', 'R', 'R', 'R', '1', '2'},
        {'S', '1', 'R', 'R', '2', '3'},
        {'4', '4', 'S', 'S', 'R', 'R'}
    };
    
    forest100((char *)forest, 6, 4);
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            cout << forest[i][j] << " "; 
        }
        cout << endl;
    }

    return 0;
}
