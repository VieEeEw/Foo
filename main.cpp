#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::map;
using std::unordered_map;
using std::vector;
using ll = unsigned long long;

struct Library {
	ll id;
	ll signup;
	vector<ll> books;
	ll books_per_day;
	std::ostream& operator<<(std::ostream& s) {
		s << "Library i " << id << ", signup takes " << signup << " days, has " << books.size()
		  << " books:\n";
		for (auto book : books) s << book << ' ';
		s << "\nCan scan " << books_per_day << " books per day.\n";
		return s;
	}
	friend std::ostream& operator<<(std::ostream& s, const Library& lib);
};

int main(int argc, char** argv) {
	ll B, L, D;
	scanf("%lld %lld %lld", &B, &L, &D);
	vector<uint> book_score(B);
	for (auto& i : book_score) scanf("%ud", &i);
	vector<Library> libs(L);
	ll id = 0;
	for (auto& lib : libs) {
		lib.id = id++;
		ll size;
		scanf("%lld", &size);
		lib.books.resize(size);
		scanf("%lld %lld", &lib.books_per_day, &lib.signup);
		for (auto i = 0; i < lib.books.size(); i++) scanf("%lld", &lib.books[i]);
	}
	cout << "Book scores: \n";
	for (auto i : book_score) cout << i << ' ';
	cout << '\n';
	for (auto lib : libs) cout << lib;
}
