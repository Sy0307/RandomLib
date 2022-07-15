#include <bits/stdc++.h>
#include <time.h>

using namespace std;

void time_info_show()
{
    time_t rawtime;
    time(&rawtime);
    auto timeinfo = localtime(&rawtime);
    printf("Log time: %s\n", asctime(timeinfo));
}
int main()
{
    freopen("DATA\\count.txt", "r", stdin);
    int n;
    cin >> n;
    fclose(stdin);
    //    cout<<n<<endl;
    int unable_delete = 0;
    int able_delete = 0;
    while (n--)
    {
        auto path = "DATA\\Data" + to_string(n + 1) + ".txt";
        if (remove(path.c_str()) == 0)
        {
            able_delete++;
        }
        else
        {
            unable_delete++;
        }
    }
    freopen("DATA\\count.txt", "w", stdout);
    cout << 0 << endl;
    fclose(stdout);
    freopen("DATA\\Log.txt", "a", stdout);
    cout<<"==============================="<<endl;
    time_info_show();
    cout << "Able to delete " << able_delete << " files" << endl;
    cout << "Unable to delete " << unable_delete << " files" << endl;
    return 0;
}