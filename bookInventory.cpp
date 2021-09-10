#include <iostream>
#include <map> 
#include <algorithm>
#include <string>

using namespace std;



class BookSystem
{

	//need either a vector, dynamic array or // dictionary
		
	
	class Book	
	{
	
		public:
        		string  bookName;
       			float  price;
			int quantity;
	
			Book(const string bookName, float price, int quantity):
				bookName{bookName}, price{price}, quantity{quantity} 
			{
		
	
			}	
	


        
        
        
	};
	map<string,Book> Books;	
	public:
	BookSystem()
		{ 
			Book MD{"Molby Dick", 20.00,5};
			Book WP{"Winnie The Pooh", 13.00,20};
			Book OMAndM{"Of Mice And Men", 15.00,10};


			Books= {
				{"Of Mice And Men", OMAndM},

				{"Molby Dick",MD}
				,

				{"Winnie The Pooh", WP} 
				
			};

		}	

		void Add(string name,float price, int quantity)
		{				//create a new book
						
			Books.insert({name,Book{name, price, quantity}});
			cout << name <<" Your book has been added"<< endl;
		}

		int Search(string keyword)
		{//search by name
			//will have to access the book object and check each name 
			
			if(Books.count(keyword)>0)
			{
				cout<< keyword << " is in stock. " << endl;
			}
			else
			{
				cout<< keyword << " is not is not available. " << endl;

			}
			return Books.count(keyword);

		
		}

		void Buy(string bookName){

			//use the find or iterate through and exit on condition
			
			
				if((Books.at(bookName)).quantity > 0){
			
					Books.at(bookName).quantity-=1; 
					cout << bookName <<  " purchased."<< endl; 
				}
				else{
					cout << "This book is not available"<< endl;
				}
		
			//point to info: decrease the quantity by 1
			//print the previous and current quantity

							
					
		}

		void showBooks()
		{
			//basic for loop through the dictionary
			////show ID 
			//show book name
			cout << "Books available: " << endl;

			for(auto book : Books){ 
			
				cout << book.first << "   "
				<< "stock: " << book.second.quantity << endl;
			}
		}		
		


	
	
};




int main()
{
       //put whole thing in while loop, if input does not equal exit, keep looping 

	//show all books
	BookSystem Smiths; 
	
	
	cout <<"Welcome to Smiths\n"<< endl;
	string input;
	

	Smiths.showBooks();


	while(true){
		string addUserInput;	
	
		cout<< "\nPlease enter one of the 5 options: \nBuy - This is to Buy a book\nAdd -to add a book \nSearch - to search for a book\nShow - to show all books available\nExit - to exit the booksystem" << endl;

		getline(cin,input);

		transform(input.begin(),input.end(),input.begin(),::tolower);	
		
		if(input =="exit"){
			cout<< "	***Exiting Application*** "<<endl;
			break;}
		else if(input =="show"){
			cout << "List of books \n"<<endl;
			Smiths.showBooks();
			
		}
		else if(input == "search"){
				
			cout << "Please enter a book to search for: "<< endl;	
			getline(cin, addUserInput);
			Smiths.Search(addUserInput);
		
		}
		else if(input == "buy")		
		{
			cout << 
			"Plese enter the the name of the product you would like to buy"
			<<endl;
			getline(cin, addUserInput);
			if(Smiths.Search(addUserInput))
			{
				Smiths.Buy(addUserInput);
			}

		}
		else if (input == "add")
		{	string name;
			float price;
			int quantity;
			string temp_str;
		       	

			cout<<"Please enter: "<<endl;
			cout<<"Name(string): ";
			getline(cin,name);
			
			cout<< "Price(double): ";
			getline(cin, temp_str);
			price = stod(temp_str);	
			
			cout << "Quantity(int): ";
			getline(cin,temp_str);
			quantity =stoi(temp_str);
			
			cout << "Object Name(string): ";
		
					
			
			Smiths.Add(name, price, quantity);
		}

	
	}
	
 	
			
        return 0;
        
}

