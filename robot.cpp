#include <unordered_set>
using namespace std;
#include <iostream>

// hash function for unordered set
template <>
struct hash<pair<int, int> >
{
    inline size_t operator()(const pair<int, int> &v) const
    {
        hash<int> int_hasher;
        return int_hasher(v.first) ^ int_hasher(v.second);
    }
};

//Processes a single clean instruction by taking the current co-ordinates, direction and steps.
//Every point that is cleaned is added to a set (to avoid duplicate insertions of point)

void clean(unordered_set<pair<int, int> > &set, int *x, int *y, int steps, int a, int b)
{
    pair<int, int> m;
    if (a == 0) //cleans in the 'y' axis direction
        for (int i = 0; i < steps; i++)
        {
            *y = *y + b;
            m = make_pair(*x, *y);
            set.insert(m);
        }

    else //cleans in the 'x' axis direction
        for (int i = 0; i < steps; i++)
        {
            *x = *x + a;
            m = make_pair(*x, *y);
            set.insert(m);
        }
}

int main()
{
    unordered_set<pair<int, int> > set;
    int n, x, y, a, b, steps;
    char direction;
    cin >> n; //Number of instructions
    cin >> x; // Given starting 'x' co-ordinate
    cin >> y; // starting 'y' co-ordinate
    pair<int, int> m = make_pair(x, y); 
    set.insert(m); // inserting the pair of initial co-ordinates into the set
    for (int i = 0; i < n; i++)
    {
        cin >> direction;
        cin >> steps;
        switch (direction)
        {
        case 'E':
            clean(set, &x, &y, steps, 1, 0);
            break;
        case 'W':
            clean(set, &x, &y, steps, -1, 0);
            break;
        case 'N':
            clean(set, &x, &y, steps, 0, 1);
            break;
        case 'S':
            clean(set, &x, &y, steps, 0, -1);
            break;
        }
    }
    cout << "=> Cleaned: " << set.size() << endl;
    return 0;
}
