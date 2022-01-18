#include <vector>
#include <algorithm>
#include <random>
#include <iterator>
#include <iostream>
using std::cout;
using std::endl;

size_t partition(std::vector<int>& v, int low, int high) {
    int pivot = v[high];
    int i = low;
    for(int j = low; j <= high - 1; j++) {
        if(v[j] < pivot) {
            std::swap(v[i++],v[j]);
        }
    }
    std::swap(v[i],v[high]);
    return i;
}

void qs(std::vector<int>& v, int low, int high) {
    if(low < high) {
        int p = partition(v,low,high);
        qs(v,low,p - 1);
        qs(v,p + 1, high);
    }
}

std::vector<int> gen_rand(size_t n) {
    std::random_device rd;
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(1, 1000);
    std::vector<int> ans(n);
    for (size_t i=0; i<n; ++i) { ans[i] = distrib(gen); }
    return ans;
}

int main() {
    bool verbose {false};
    std::vector<int> sample_data{gen_rand(1000)};
    std::vector<int> sample_data_cpy {sample_data};
    if(verbose) cout << "sample data (original):" << endl;
    if(verbose) { std::copy(sample_data.begin(),sample_data.end(),std::ostream_iterator<int>(cout," ")); cout << endl; }

    std::sort(sample_data_cpy.begin(),sample_data_cpy.end());
    qs(sample_data,0,sample_data.size() - 1);
    if(verbose) cout << "sample data (sorted):" << endl;
    if(verbose) { std::copy(sample_data.begin(),sample_data.end(),std::ostream_iterator<int>(cout," ")); cout << endl; }
    if(verbose) cout << "sample data copy: (sorted)" << endl;
    if(verbose) { std::copy(sample_data_cpy.begin(),sample_data_cpy.end(),std::ostream_iterator<int>(cout," ")); cout << endl; }
    if(std::equal(sample_data.begin(),sample_data.end(),sample_data_cpy.begin())) {
        cout << "it worked" << endl;
    }
}
