#if __linux
#include <sys/syscall.h>
#elif defined(_WIN64) || defined(_WIN64)
#include <windows.h>
#endif
#include <iostream>
#include<fcntl.h>
#include <string>

using namespace std;

void Create();
void Read();
void Write();

int main()
{
    Create();
    Write();
    Read();
    return 0;
}

void Create()
{
    cout << "Creating a file...." << endl;
    int file = open("C:/Users/Joshua Cute/Documents/sample/samplemyFile.txt", O_CREAT, O_TRUNC , 0644);
}
void Write()
{
    char buff[10];
    cout << "Type your text: ";
    cin.getline(buff,10);
    cout << "Writing in a file...." << endl;
    int file = open("C:/Users/Joshua Cute/Documents/sample/samplemyFile.txt", O_WRONLY);
    write(file, strcat(buff,","), strlen(strcat(buff,",")));
    close(file);
}
void Read()
{
    int sz;
    char *c = (char *) calloc(100, sizeof(char));
    cout << "Read text inside a file..." << endl;
    int file = open("C:/Users/Joshua Cute/Documents/sample/samplemyFile.txt", O_RDONLY);;
    sz = read(file, c, 100);
    printf("Text in a file:\n % s", c);
}