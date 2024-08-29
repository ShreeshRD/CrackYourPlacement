#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        if (image[sr][sc] != color)
            mytool(image, sr, sc, color, image[sr][sc]);
        return image;
    }
    void mytool(vector<vector<int>> &image, int i, int j, int color, int og)
    {
        image[i][j] = color;
        if (i > 0 && image[i - 1][j] == og)
            mytool(image, i - 1, j, color, og);
        if (i < image.size() - 1 && image[i + 1][j] == og)
            mytool(image, i + 1, j, color, og);
        if (j > 0 && image[i][j - 1] == og)
            mytool(image, i, j - 1, color, og);
        if (j < image[0].size() - 1 && image[i][j + 1] == og)
            mytool(image, i, j + 1, color, og);
    }
};