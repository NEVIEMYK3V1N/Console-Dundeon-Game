class C {
     int x;
 public:
     C(int x) : x{x} {}
     void o() {
         cout << x << endl;
     }
};

int main()
{
    std::vector<unique_ptr<C>> v {};
    C *c = new C(1);
    v.emplace_back(make_unique<C> (*c));
    C *c2 = new C(23);
    v.emplace_back(make_unique<C> (*c2));
    for (int i = 0; i < v.size(); i++) {
        v[i]->o();
    }
}