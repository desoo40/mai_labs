#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int tests;
    int max_n;
    
    scanf("%d %d", &tests, &max_n);
    
    int matrix[max_n][max_n];
    
    for (int t = 0; t < tests; ++t) {
        int n = 0;
        int how_many_similar_columns = 0;
        
        scanf("%d", &n);
        
        int similar_columns[n];
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &(matrix[i][j]));
            }
        }
        
        for (int j = 0; j < n; ++j) {
            
            int save_column[n];
            
            for (int i = 0; i < n; ++i) {
                save_column[i] = matrix[i][j];
            }
            
            for (int k = j + 1; k < n; ++k) {
                
                int check_column[n];
                
                for (int i = 0; i < n; ++i) {
                    
                    check_column[i] = matrix[i][k];
                    
                    if (how_many_similar_columns > n - 1) {
                        break;
                    } else if (save_column[i] == check_column[i] && i == n - 1) {
                        
                        similar_columns[how_many_similar_columns] = k;
                        ++how_many_similar_columns;
                        
                    } else if (save_column[i] != check_column[i]) {
                        break;
                    }
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                
                bool is_simmilar = false;
                
                for (int l = 0; l < how_many_similar_columns; ++l) {
                    if (similar_columns[l] == j) {
                        is_simmilar = true;
                        break;
                    }
                }
                if (is_simmilar == true) {
                    break;
                } else {
                    printf("%d ", matrix[i][j]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}
