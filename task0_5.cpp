#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
using namespace std;

string file_work(const char* name, int key)
{
   string cypr, words, str;
   ifstream file;
   file.open(name);
   file.seekg (0, std::ios::end);
   int len = file.tellg();

   if(!file.is_open() || key >= len/2)
   {
       return "false";
   }
   else
   {

        file.seekg (0, std::ios::beg);

        while (file >> words)
            str += words;

        len = str.length();
        // //////////////////////////////////////////////////////////////////////////////////

        for (int i = 0; i < key; i++)
        {

            int st1 = (key-1)*2-i*2, st2 = i*2, step = i;
            bool halfstep = false;

            cypr += str[step];

            while (step < len)
            {
                if(!halfstep)
                {
                    step+= st1;
                    if(step >= len)
                        break;
                    if(st1!=0){
                        cypr+= str[step];
                    }
                    halfstep = true;
                }
                else
                {
                    step+=st2;
                    if(step >= len)
                        break;
                    if(st2!=0){
                        cypr+= str[step];
                    }
                    halfstep = false;
                }
            }
        }


        // //////////////////////////////////////////////////////////////////////////////////
        ofstream out("ciphered.txt");
        out << cypr << endl;
        out.close();
        return "true";
   }

}

int main()
{
    int key;
    string name;

    cout << "Enter key: ";
    cin >> key;
    cout << "Enter filename (without txt): ";
    cin >> name;

    name += ".txt";

    cout << file_work(name.c_str(), key) << endl;

    return 0;
}


