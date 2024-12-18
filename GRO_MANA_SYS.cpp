#include<iostream>
#include<conio.h>
#include<fstream>
#include<iomanip>
#include<string>
#include<cstring>
using namespace std;
class login
{
    public:
    login()
    {
        char ids[20],pass[20];
	cout << "\t\t\t\t --------- LOGIN -------------" << endl << endl;
    cout<<"\t\t\t--------------------------------------------------"<<endl;
    cout<<"\t\t\t\t\tLogin your System"<<endl;
    cout<<"\t\t\t--------------------------------------------------"<<endl;
    while(pass!="admin"){
    a:
    cout<<"\t\t\t\tUser-Name: ";
    cin>>ids;
    cout<<"\t\t\t\tPassword: ";
    cin>>pass;
    cout<<endl;
     if( (strcmp(ids,"admin")==0) && (strcmp(pass,"admin")==0))
    {
        cout<<"\t\t\t\tWelcome ..........................";
        cout<<endl<<endl;
        system("pause");
        system("cls");
        break;
    }
    else
    {
        cout<<"\t\t\t\tWrong attempt";
        cout<<endl<<endl;
    }
    cout<<endl<<endl;
    system("pause");
    system("cls");
    goto a;
    }
    }
};

//------------------------------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

class admin
{
	protected:
	string name;
	int code;
	float price;
	float discount;
	public:
	void getdata();
    void setdata();
    void addrec();
    void searckrec();
    void editrec();
    void delrec();
    void showrec();
};
void admin::getdata()
{
	cout << "\n\n\t\t\t--------- Add New Product ---------";
	cout << "\n\n Product Code : ";
	cin >> code;
	cout << "\n\n Name : ";
	cin >> name;
	cout << "\n\n Price : ";
	cin >> price;
	cout << "\n\n Discount in % : ";
	cin >> discount;
}
void admin::setdata()
{
	cout << "\n\n Product Code : "<<code<<endl;
	cout << "\n\n Name : "<<name<<endl;
	cout << "\n\n Price : "<<price<<endl;
	cout << "\n\n Discount in % : "<<discount<<endl;
}
void admin::addrec()
{
	system("cls");
	int c, found = 0;
	float p, d;
	string n;
	getdata();
	fstream file;
	file.open("product.txt", ios::in);
	if (!file)
	{
		file.open("product.txt", ios::app | ios::out);
		file << " " << code << " " << name << " " << price << " " << discount << "\n";
		file.close();
	}
	else
	{
		file >> c >> n >> p >> d;
		while (!file.eof())
		{
			if (c == code)
			{
				found++;
			}
			file >> c >> n >> p >> d;
		}
		file.close();
		if (found == 1)
		{
			cout << "\t\t\t******THE RECORD HAS ALREADY INSERT";
		}
		else
		{
			file.open("product.txt", ios::app | ios::out);
			file << " " << code << " " << name << " " << price << " " << discount << "\n";
			file.close();
			cout << "\n\n\t\t Record Inserted Successfully...";
		}
	}
	getch();
	
}
void admin::searckrec()
{
	system("cls");
	fstream file;
	int p_c, found = 0;
	cout << "\n\n\t\t\t----- Search Record -----";
	cout << "\n\n Product Code : ";
	cin >> p_c;
	file.open("product.txt", ios::in);
	if (!file)
	{
		cout << "\n\n File Openning Error...";
	}
	else
	{
		file >> code >> name >> price >> discount;
		while (!file.eof())
		{
			if (p_c == code)
			{
				system("cls");
				cout << "\n\n\t\t\tSearch Record";
				setdata();
				found++;
			}
			file >> code >> name >> price >> discount;
		}
		file.close();
		if (found == 0)
		{
			cout << "\n\n Record Can't Found...";
	    }
	}
	getch();
}
void admin::editrec()
{
	system("cls");
	fstream file, file1;
	int p_c, found = 0, c;
	float p, d;
	string n;
	cout << "\n\n\t\t\t----- Edit Record -----";
	cout << "\n\n Product Code : ";
	cin >> p_c;
	file.open("product.txt", ios::in);
	if (!file)
	{
		cout << "\n\n File Openning Error...";
	}
	else
	{
		file1.open("product1.txt", ios::app | ios::out);
		file >> code >> name >> price >> discount;
		while (!file.eof())
		{
			if (p_c == code)
			{
				cout << "\n\n Product New Code : ";
				cin >> c;
				cout << "\n\n Name : ";
				cin >> n;
				cout << "\n\n Price : ";
				cin >> p;
				cout << "\n\n Discount in % : ";
				cin >> d;
				file1 << " " << c << " " << n << " " << p << " " << d << "\n";
				cout << "\n\n\n\t\tRecord Edit Successfully...";
				found++;
			}
			else
			{
				file1 << " " << code << " " << name << " " << price << " " << discount << "\n";
			}
			file >> code >> name >> price >> discount;
		}
		file.close();
		file1.close();
		remove("product.txt");
		rename("product1.txt", "product.txt");
		if (found == 0)
		{
			cout << "\n\n Record Can't Found...";
		}
	}
	getch();
}
void admin::delrec()
{
	system("cls");
	fstream file, file1;
	int p_c, found = 0;
	cout << "\n\n\t\t\tDelete Product";
	cout << "\n\n Product Code : ";
	cin >> p_c;
	file.open("product.txt", ios::in);
	if (!file)
	{
		cout << "\n\n File openning error...";
	}
	else
	{
		file1.open("product1.txt", ios::app | ios::out);
		file >> code >> name >> price >> discount;
		while (!file.eof())
		{
			if (code == p_c)
			{
				cout << "\n\n Product Deleted Successfully...";
				found++;
			}
			else
			{
				file1 << " " << code << " " << name << " " << price << " " << discount << "\n";
			}
			file >> code >> name >> price >> discount;
		}
		file.close();
		file1.close();
		remove("product.txt");
		rename("product1.txt", "product.txt");
		if (found == 0)
		{
			cout << "\n\n Record Can't Found...";
	    }   
	}
	getch();
}
void admin::showrec()
{
	system("cls");
	fstream file;
	cout << "\n\n\t\t\tShow Products";
	file.open("product.txt", ios::in);
	if (!file)
	{
		cout << "\n\n File openning error...";
	}
	else
	{
		cout << "\n\n Code\tName\t\tPrice\t\tDiscount %";
		file >> code >> name >> price >> discount;
		while (!file.eof())
		{
			cout << "\n " << code << "\t " << name << "\t\t   " << price << "\t\t\t" << discount;
			file >> code >> name >> price >> discount;
		}
		file.close();
	}
	getch();
}

//------------------------------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

class customer:virtual public admin
{
	public:
	void list();
	void invoice();
};
void customer::list()
{
	fstream file;
	file.open("product.txt", ios::in);
	cout << "\n\n====================================================\n";
	cout << "P.NO.\t\tNAME\t\tPRICE\n";
	cout << "====================================================\n";
	file >> code >> name >> price >> discount;
	while (!file.eof())
	{
		cout << code << "\t\t" << name << "\t\t" << price << "\n";
		file >> code >> name >> price >> discount;
	}
	file.close();
}
void customer::invoice()
{
	system("cls");
	fstream file;
	char choice;
	int o_c[50], o_q[50], c = 0;
	float amt = 0, dis = 0, total = 0;
	string n;
	cout << "\n\n\t\t\t ----- Invoice Generate ------";
	file.open("product.txt", ios::in);
	if (!file)
	{
		cout << "\n\n Data Base is Empty...";
	}
	else
	{
		file.close();
		list();
		cout << "\n============================";
		cout << "\n    {PLACE YOUR ORDER}";
		cout << "\n============================\n";
		cout << "\n\n Your Name : ";
		cin >> n;
		do
		{
		p:
			cout << "\n\n Product Code : ";
			cin >> o_c[c];
			cout << "\n Product Quantity : ";
			cin >> o_q[c];
			for (int i = 0; i < c; i++)
			{
				if (o_c[c] == o_c[i])
				{
					cout << "\n\n Duplicate Product Code...";
					goto p;
				}
			}
			c++;
			cout << "\n\n Do You Want Add Another Product (Y,N) : ";
			cin >> choice;
		} while (choice == 'Y' || choice == 'y');
		system("cls");
		cout << "\n\n********************************INVOICE************************\n";
		cout << "\nPr No.\tPr Name\tQuantity \tPrice \tAmount \tAmount after discount\n";
		for (int i = 0; i < c; i++)
		{
			file.open("product.txt", ios::in);
			file >> code >> name >> price >> discount;
			while (!file.eof())
			{
				if (code == o_c[i])
				{
					amt = price * o_q[i];
					dis = amt - (amt / 100 * discount);
					total += dis;
					cout << "\n" << code << "\t" << name << "\t" << o_q[i] << "\t\t" << price << "\t" << amt << "\t\t" << dis;
				}
				file >> code >> name >> price >> discount;
			}
			file.close();
		}
		cout << "\n\n======================================";
		cout << "\n Customer Name : " << n;
		cout << "\n Total Amount : " << total;
	}
	getch();
}

//------------------------------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

class final: virtual public admin,public customer
{
    admin obj1;
    customer obj2;
    public:
    void fun()
    {
        
        char choose;
        char choice2;
        do
         {
            system("cls");
            cout << "\t\t\t\t-------------------------------------------------------" << endl;
            cout << "\t\t\t\t\t\t---{MAIN PANEL}---" << endl;
            cout << "\t\t\t\t-------------------------------------------------------" << endl;
            cout << "\n\n";
			cout << "\n 1. Admin";
	        cout << "\n 2. Customer";
            cout << "\t\n0. Exit.\n\n";
            cout << "Enter your choice : ";
            fflush(stdin);
            cin >> choose;
            if (choose == '1')
            {
				login obj;
                int choice1;
                fflush(stdin);
                do
                {
                    system("cls");
                    cout << "\t\t\t\t-------------------------------------------------------" << endl;
                    cout << "\t\t\t\t\t\t---{ADMIN PANEL}---" << endl;
                    cout << "\t\t\t\t-------------------------------------------------------" << endl;
                    cout << "\n\n";
                    cout << "\n 1. Add Product";
	                cout << "\n 2. Search Product";
	                cout << "\n 3. Edit Product";
	                cout << "\n 4. Delete Product";
	                cout << "\n 5. Show Products";
                    cout << "\n0. Exit.\n\n";
                    cout << "Enter your choice : ";
                    //fflush(stdin);
                    cin >> choice1;
                            switch (choice1)
                            {
                            case 1:
                                obj1.addrec();
                                break;
                            case 2:
                                obj1.searckrec();
                                break;
                            case 3:
                                obj1.editrec();
                                break;
							case 4:
                                obj1.delrec();
                                break;
							case 5:
                                obj1.showrec();
                                break;
                            }

                        } while (choice1 != 0);
            }    

//------------------------------------------------>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

            if (choose == '2')
            {
                int opt;
                fflush(stdin);
                do
                {
                    system("cls");
                    cout << "\t\t\t\t-------------------------------------------------------" << endl;
                    cout << "\t\t\t\t\t\t---{CUSTOMER PANEL}---" << endl;
                    cout << "\t\t\t\t-------------------------------------------------------" << endl;
                    cout << "\n\n";
					cout << "\n\n 1. Sale Product";
	                cout << "\n 2. Exit..";
                    cout << "\n0. Back To Main Menu" << endl;
                    cout << "\n\t\t\t\t\tEnter your choice : ";
                    cin >> opt;
                    switch (opt)
                    {
                    case 1:
                        obj2.invoice();
                        break;
                    case 2:
                        system("cls");
                        exit(0);
                    }

                } while (opt != 0);
            }

            //----------------------------------------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>.

        } while (choose != '0');
    }

};

//-------------------->>>>>>>>>>>>>> MAIN FUNCTION

int main()
{

	cout << "\n\n\n";
    system("color 0A");
    cout << "\t\t\t\t-----------------------------------------------------" << endl;
    cout << "\t\t\t\t|" << setw(39) << "---- {GROCERY MANAGEMENT SYTEM} ----" << setw(13) << "|" << endl;
    cout << "\t\t\t\t-----------------------------------------------------" << endl;
    system("pause");
    system("cls");
    cout << "\n\n";


//---------------->>>>>>>>>>>>>>>>>>>>>>>. MAKING OBJECTS

	final object;
	object.fun();
}