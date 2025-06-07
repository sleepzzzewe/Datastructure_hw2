#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void io(char buf, int id)
{
    cout << "[I/O]  Buffer " << buf << " block " << id << " loaded\n";
    this_thread::sleep_for(chrono::milliseconds(20));
}
void cpu(char buf, int id)
{
    cout << "[CPU]  Sort   Buffer " << buf << " block " << id << '\n';
    this_thread::sleep_for(chrono::milliseconds(10));
}

int main()
{
    constexpr int BLOCK  = 2000;
    constexpr int TOTAL  = 200000;
    constexpr int BLOCKS = TOTAL / BLOCK;   // 100

    for (int i = 0; i < BLOCKS; ++i)
    {
        if (i & 1)
        {
            thread t(io, 'B', i + 1);
            cpu('A', i);
            t.join();
        }
        else
        {
            thread t(io, 'A', i + 1);
            cpu('B', i);
            t.join();
        }
    }

    cout << "\nMax input rate ≈ 100 000 records/s\n";
    return 0;
}


