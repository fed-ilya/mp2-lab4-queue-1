#include <iostream>
#include "TQueue.h"

using namespace std;

int main()
{
    TQueue<int> q(3);

    cout << q << '\n';

    q.Push(1);
    cout << q << '\n';

    q.Push(2);
    cout << q << '\n';

    q.Push(3);
    cout << q << '\n';

    q.Pop();
    cout << q << '\n';

    q.Push(4);
    cout << q << '\n';

    q.Pop();
    cout << q << '\n';

    q.Push(5);
    cout << q << '\n';

    q.Pop();
    cout << q << '\n';

    q.Push(6);
    cout << q << '\n';

    q.Pop();
    cout << q << '\n';

    q.Pop();
    cout << q << '\n';

    q.Pop();
    cout << q << '\n';

    q.Push(1000);
    cout << q << '\n';

    q.Push(2000);
    cout << q << '\n';

    q.Push(3000);
    cout << q << "\n\n";

    cout << "Trying to add 4000:\n";
    try
    {
        q.Push(4000);
    }
    catch (Exception e)
    {
        cout << "\n" << e << "\n";
    }

    q.Pop();
    cout << q << '\n';

    q.Pop();
    cout << q << '\n';

    q.Pop();
    cout << q << "\n\n";

    cout << "Trying to pop again:\n";
    try
    {
        q.Pop();
    }
    catch (Exception e)
    {
        cout << "\n" << e << "\n";
    }

    return 0;
}