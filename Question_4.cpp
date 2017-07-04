#include <bits/stdc++.h>

using namespace std;
#define MAX 60
int products_count[MAX][MAX][MAX];
map<string, int> brand_index;
map<int, string> brand_index_back;
map<string, int> color_index;
map<int, string> color_index_back;
int indexed_brand = 0, indexed_color = 0;

void split_and_save(string product) {
    string brand = "", color = "";
    stringstream number;
    int size = 0, brand_i, color_i;
    int count_ = 0;
    for (int i = 0; i < product.size(); ++i) {
        if (product[i] == '_')
            count_++, i++;
        if (!count_)
            brand += product[i];
        else if (count_ == 1)
            color += product[i];
        else
            number << product[i];
    }
    number >> size;
    brand[0] = toupper(brand[0]);
    color[0] = toupper(color[0]);
    if (brand_index.count(brand))
        brand_i = brand_index[brand];
    else
        brand_index[brand] = indexed_brand, brand_index_back[indexed_brand] = brand, brand_i = indexed_brand++;
    if (color_index.count(color))
        color_i = color_index[color];
    else
        color_index[color] = indexed_color, color_index_back[indexed_color] = color, color_i = indexed_color++;
    products_count[brand_i][color_i][size]++;
}

void classify(string A[], unsigned len_A) {
    for (int i = 0; i < len_A; ++i) {
        split_and_save(A[i]);
    }
}

int main(void) {
    string A[] = {"nike_red_42", "nike_yellow_40", "adidas_red_37", "nike_red_42", "adidas_black_40", "nike_red_42",
                  "adidas_black_40"};
    classify(A, 7);
    for (auto brand : brand_index) {
        cout << brand.first << ":  ";
        bool flag = false;
        for (auto color : color_index) {
            for (int size = 1; size <= 50; ++size) {
                if (products_count[brand.second][color.second][size]) {
                    if(flag) cout << "         ";
                    flag = true;
                    cout << color.first << "  " << size << ": " << products_count[brand.second][color.second][size]
                         << "\n";
                }
            }
        }
    }
}