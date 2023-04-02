#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum class Type {
    Art, Tech
};
class book
{
private:
    const string _author;
    const string _title;
    const Type _type;
public:
    book(const std::string& author, const std::string& title, Type type) : _author(author), _title(title), _type(type) {}
    Type getType() const {
        return _type;
    }

};

class library
{
private:
    vector <book> books;
public:
    void addbook(const std::string& author, const std::string& title, Type type) {
        if (author.empty() || title.empty())
        {
            cout << "enter the title and the name of the author" << endl;
        }
        else
        {
            books.emplace_back(author, title, type);
        }
    }
    void countsSW()
    {
        int countTECH = 0;
        int countART = 0;

        for (book i : books) {
            switch (i.getType()) {
            case Type::Art:
                countART++;
                break;
            default:
                countTECH++;
                break;
            }
        }
        cout << "SWITCH" << '\n' << '\n' << "Art" << countART << '\n' << "Tech" << countTECH << endl << endl << endl;
    }

    void counts()
    {
        int countTECH = 0;
        int countART = 0;

        for (book i : books) {
            if (i.getType() == Type::Art)
            {
                countART++;
            }
            else
            {
                countTECH++;
            }
        }
        cout << "FOR" << '\n' << '\n' << "Art" << countART << '\n' << "Tech" << countTECH << endl;
    }
};

int main()
{
    library lib;
    lib.addbook("pushkin", "golg fish", Type::Art);
    lib.addbook("noname", "math", Type::Tech);
    lib.addbook("newton", "newton's philosophy", Type::Tech);

    lib.countsSW();
    lib.counts();
}
