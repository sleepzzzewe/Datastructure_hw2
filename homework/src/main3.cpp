#include <iostream>
#include <thread>
#include <chrono>

void io(char buf,int id){
    std::cout << "[I/O]  Buffer " << buf << " block " << id << " loaded\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
}
void cpu(char buf,int id){
    std::cout << "[CPU]  Sort   Buffer " << buf << " block " << id << '\n';
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

int main(){
    constexpr int BLOCKS = 100;   // 200k records / 2k records per block

    for(int i = 0; i < BLOCKS; ++i){
        if(i & 1){
            std::thread t(io,'B',i+1);
            cpu('A',i);
            t.join();
        }else{
            std::thread t(io,'A',i+1);
            cpu('B',i);
            t.join();
        }
    }
    std::cout << "\nMax input rate ~100 000 records/s\n";
    return 0;
}



