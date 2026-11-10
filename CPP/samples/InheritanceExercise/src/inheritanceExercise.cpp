#include <iostream>
#include <string>

/* Imagine a publishing company that markets both book and audiocassette versions of its works.
 * Create a class publication that stores the title (a string) and price (type float)
 * of a publication. From this class derive two classes: book, which adds a page count (type int),
 * and tape, which adds a playing time in minutes (type float).
 * Each of these three classes should have a getdata() function to get its data
 * from the user at the keyboard, and a putdata() function to display its data.
 *
 * Write a main() program to test the book and tape classes by creating instances of them,
 * asking the user to fill in data with getdata(), and then displaying the data with putdata().
 */

//////////////////////////////////////////////////
class Publication
{
	public:
		Publication()
		{
			_title = "";
			_price = 0.0f;
		}

		Publication(std::string title, float price)
			: _title(title), _price(price) {}

		virtual void GetData() {
			printf("Enter title: ");
			std::cin >> _title;
			
			printf("Enter price: ");
			std::cin >> _price;
		}

		virtual void PutData() {
			printf("Title: %s\n", _title.c_str());
			printf("Price: %0.2f\n", _price);
		}
	private:
		std::string _title;
		float _price;
};

//////////////////////////////////////////////////
class Book : public Publication
{
	public:
		Book() { _pageCount = 0; }
		Book(std::string title, float price, int pageCount)
			: Publication(title, price), _pageCount(pageCount) {}

		void GetData() override {
			Publication::GetData();

			printf("Enter PageCount: ");
			std::cin >> _pageCount;
		}

		void PutData() override {
			Publication::PutData();
			printf("PageCount: %d\n", _pageCount);
		}
	private:
		int _pageCount;
};

//////////////////////////////////////////////////
class Tape : public Publication
{
	public:
		Tape() { _playingTime = 0.0f; }
		Tape(std::string title, float price, float playingTime)
			: Publication(title, price), _playingTime(playingTime) {}

		void GetData() override {
			Publication::GetData();

			printf("Enter PlayingTime: ");
			std::cin >> _playingTime;
		}

		void PutData() override {
			Publication::PutData();

			printf("PlayingTime: %0.2f\n", _playingTime);
		}
	
	private:
		float _playingTime;
};

//////////////////////////////////////////////////
int main(int arc, char* argv[])
{
	Book publicated;

	Publication* publicatedPtr = &publicated;

	publicatedPtr->GetData();
	publicatedPtr->PutData();

	return EXIT_SUCCESS;
}
