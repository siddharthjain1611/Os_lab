#include </Users/stdc++.h>
using namespace std;

int pageFaults(int pages[], int n, int capacity)
{
    set <int> s;
    queue<int> indexes;
    int page_faults = 0;
    for (int i=0; i<n; i++)
    {
        if (s.size() < capacity)
        {
            if (s.find(pages[i])==s.end())
            {
                s.insert(pages[i]);
                page_faults++;
                indexes.push(pages[i]);
            }
        }
        else
        {
            if (s.find(pages[i]) == s.end())
            {
                int val = indexes.front();

                indexes.pop();
                s.erase(val);
                s.insert(pages[i]);
                indexes.push(pages[i]);
                page_faults++;
            }
        }
    }

    return page_faults;
}
int main()
{
	int n;
	scanf("%d",&n);
    int pages[n];
    for(int i=0;i<n;i++)
    {
		scanf("%d",&pages[i]);
	}
    //int n = sizeof(pages)/sizeof(pages[0]);
    int capacity = 3;
    cout << pageFaults(pages, n, capacity);
    return 0;
}
