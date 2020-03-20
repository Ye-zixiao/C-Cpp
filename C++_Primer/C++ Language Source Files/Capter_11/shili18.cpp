#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<map>
#include<set>
#include<string>
#include<unordered_map>
using namespace::std;

int main(void)
{
	unordered_map<string, size_t> word_count;
	string word;
	while (cin >> word)
		++word_count[word];

	cout << "--------------bucket information-----------------" << endl;
	cout << "bucket count: " << word_count.bucket_count() << endl;
	cout << "bucket max count: " << word_count.max_bucket_count() << endl;
	cout << "bucket avg size: " << word_count.load_factor() << endl;
	cout << "bucket max size: " << word_count.max_load_factor() << endl;
	cout << static_cast<float>(word_count.size()) / word_count.bucket_count() << endl;

	for (const auto& word_size : word_count)
		cout << word_size.first << ' ' << word_size.second << endl;
/*在code::blocks中好像不能使用local_iterator

	for (unordered_map<string, size_t>::const_local_iterator iter = word_count.cbegin(); iter != word_count.cend(); ++iter)
		cout << iter->first << ' ' << iter->second << endl;
*/
	return 0;
}
