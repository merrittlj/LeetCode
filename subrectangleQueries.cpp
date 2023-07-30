// Problem: https://leetcode.com/problems/subrectangle-queries/

#include <iostream>
#include <vector>


// Recursive solution.
class SubrectangleQueries
{
public:
    std::vector<std::vector<int>> actionRectangle;  // The rectangle in which actions are taken on(updateSubrectangle and getValue).
    
    
    SubrectangleQueries(std::vector<std::vector<int>>& rectangle)
    {
        std::swap(this->actionRectangle, rectangle);  // Save memory: swap values.
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)
    {
        // Recursive solution.
        if (col1 > col2) {
            return;
        }
        
        for (int i = row1; i < (row2 + 1); ++i) {
            this->actionRectangle.at(i).at(col2) = newValue;
        }
        
        this->updateSubrectangle(row1, col1, row2, --col2, newValue);

        // Loop solution.
        /*
        for (int i = row1; i < (row2 + 1); ++i) {
            for (int j = col1; j < (col2 + 1); ++j) {
                this->actionRectangle.at(i).at(j) = newValue;
            }
        }
        */
    }
    
    int getValue(int row, int col)
    {
        return (this->actionRectangle.at(row).at(col));
    }
};

// Not my personal solution, but notice this "black-box" solution, simply looking at what getValue should output, and when.
/*
class SubrectangleQueries {
public:

    vector<vector<int>> rectangle;
    vector<pair<int, int>> rows;
    vector<pair<int, int>> columns;
    vector<int> values;
    
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        this->rectangle = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        rows.push_back({row1, row2});
        columns.push_back({col1, col2});
        values.push_back(newValue);
    }
    
    int getValue(int row, int col) {
        int cnt = -1;
        for(int i = rows.size() - 1; i >= 0; -- i) {
            if(
                (row >= rows[i].first && row <= rows[i].second)
                && 
                (col >= columns[i].first && col <= columns[i].second)
            ) {
                cnt = values[i];
                break;
            }
        }
        
        return (cnt == -1) ? rectangle[row][col] : cnt;
    }
};
*/


int main()
{
    std::vector<std::vector<int>> matrix {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    SubrectangleQueries *subrectangleQueries = new SubrectangleQueries(matrix);
    std::cout << subrectangleQueries->getValue(0, 0) << std::endl;  // Should return 1.
    std::cout << "update" << std::endl;
    subrectangleQueries->updateSubrectangle(0, 0, 2, 2, 100);
    std::cout << subrectangleQueries->getValue(0, 0) << std::endl;  // Should return 100.
    std::cout << subrectangleQueries->getValue(2, 2) << std::endl;  // Should return 100.
    std::cout << "update" << std::endl;
    subrectangleQueries->updateSubrectangle(1, 1, 2, 2, 20);
    std::cout << subrectangleQueries->getValue(2, 2) << std::endl;  // Should return 20.
}
