#include <iostream>
#include <iomanip>

using namespace std;

int ReduceBanknotes(int *banknotes) {

    int money = 0;

    cout << "If you don't want to use all part of the sum enter money that you are gone to convert: " << endl;
    cin >> money;

    int reduce = *banknotes - money;
    cout << "Now you have " << reduce << " leva." << endl;

    return reduce;
}

bool AllSumOrPart() {

    bool command;

    cout << "If you want to use full amount enter 1 else enter 0!" << endl;
    cin >> command;
    return command;

}

void GetTheCurrency(string currency, int banknotes) {
    
    double convertCurrency = 0;

    bool cmd = AllSumOrPart();

    if (cmd == 0)
    {
        banknotes = ReduceBanknotes(&banknotes);
    }
    else
    {
        cout << "You are going to use all of your amount! " << endl;
    }

    if (currency == "EUR")
    {
        convertCurrency = banknotes / 1.95;
        cout << "Now you have " << fixed << setprecision(2) << convertCurrency << " EUR." << endl;
    }
    else if (currency == "CHF")
    {
        convertCurrency = banknotes / 1.99;
        cout << "Now you have " << fixed << setprecision(2) << convertCurrency << " CHF." << endl;
    }
    else if (currency == "GBP")
    {
        convertCurrency = banknotes / 2.20;
        cout << "Now you have " << fixed << setprecision(2) << convertCurrency << " GBP." << endl;
    }
    else if (currency == "USD")
    {
        convertCurrency = banknotes / 1.78;
        cout << "Now you have " << fixed << setprecision(2) << convertCurrency << " USD." << endl;
    }
    else
    {
        cout << "Wrong currency!" << endl;
    }

    /*ReduceBanknotes(*banknotes);*/
    /*cout << convertCurrency;*/
}


int main()
{
    int banknotes;
    cout << "Enter banknotes. " << endl;
    cin >> banknotes;

    string currency;
    cout << "Enter currency that you want. " << endl;
    cin >> currency;

    GetTheCurrency(currency, banknotes);

    return 0;
}
