#include <iostream>
using namespace std;
class Media
{
protected:
    string title;
    bool isBorrowed;

public:
    Media(const string &title)
        : title(title), isBorrowed(false) {}
    void borrowing()
    {
        isBorrowed = true;
        cout << "Media is borrowed" << endl;
    }
    void returning()
    {
        isBorrowed = false;
        cout << "Media is returned" << endl;
    }
    void display()
    {
        cout << "Title: " << title << endl;
    }
    bool getIsBorrowed() const
    {
        return isBorrowed;
    }
};
class BookAttributes
{
protected:
    string author;

public:
    BookAttributes(const string &author)
        : author(author) {}
    void display()
    {
        cout << "Author: " << author << endl;
    }
};
class MagazineAttributes
{
protected:
    int issueNumber;

public:
    MagazineAttributes(int issueNumber)
        : issueNumber(issueNumber) {}
    void display()
    {
        cout << "Issue Number: " << issueNumber << endl;
    }
};
class DVDAttributes
{
protected:
    string director;

public:
    DVDAttributes(const string &director)
        : director(director) {}
    void display()
    {
        cout << "Director: " << director << endl;
    }
};
class Book : public Media, public BookAttributes
{
public:
    Book(const string &title, const string &author)
        : Media(title), BookAttributes(author) {}
    void display()
    {
        cout << "Type: Book" << endl;
        Media::display();
        BookAttributes::display();
    }
};
class Magazine : public Media, public MagazineAttributes
{
public:
    Magazine(const string &title, int issueNumber)
        : Media(title), MagazineAttributes(issueNumber) {}
    void display()
    {
        cout << "Type: Magazine" << endl;
        Media::display();
        MagazineAttributes::display();
    }
};
class DVD : public Media, public DVDAttributes
{
public:
    DVD(const string &title, const string &director)
        : Media(title), DVDAttributes(director) {}
    void display()
    {
        cout << "Type: DVD" << endl;
        Media::display();
        DVDAttributes::display();
    }
};
int main()
{
    Book book("Robert Kiyosaki", "Rich Dad Poor Dad");
    Magazine magazine("Rolling Stones", 400);
    DVD dvd("Ubisoft", "Prince of Persia");
    book.display();
    book.borrowing();
    book.returning();
    magazine.display();
    magazine.borrowing();
    magazine.returning();
    dvd.display();
    dvd.borrowing();
    dvd.returning();
    return 0;
}
