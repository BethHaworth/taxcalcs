#include <iostream>

using namespace std;

int main()
{
    // user inputs income
    float gross;
    cout << "Calculate your income tax liability for 2017-2018 /" << endl;
    cout << "Please enter your annual gross income (GBP):" << endl;
    cin >> gross;

    // define taxable gross salary, after personal allowance
    float taxablegross = gross - 11500;
    
    // define income tax variable
    float incometax;

    // calculate income tax liability
    if ( taxablegross < 33501 ){
        incometax =  0.2 * taxablegross;
        } else if ( taxablegross >= 33501 && taxablegross <= 150000 ){
        incometax = ( 0.4 * ( taxablegross - 33500 )) + ( 0.2 * 33500 );
        } else if ( taxablegross >= 150001 ){
        incometax = ( 0.45 * (taxablegross - 150000)) + ( 0.4 * ( 150000 - 33500 ) + ( 0.2 * 33500 ) );
    };

    // print income tax liability
    cout << "Your total tax liability is: " << endl;
    cout << incometax << endl;

    // calculate yearly post income tax income
    float yearlypostit = gross - incometax;

    // print yearly post income tax income
    cout << "Your yearly income after income tax is: " << endl;
    cout << yearlypostit << endl;

    // calculate monthly post income tax income
    float monthlypostit = yearlypostit / 12;

    // print monthly post income tax income
    cout << "This equates to " ;
    cout << monthlypostit ;
    cout << " per month, before other deductions." << endl;

    // define national insurance thresholds as variables
    float LEL = 490 * 12;
    float PT = 680 * 12;
    float UEL = 3750 * 12;

    // define national insurance as variable
    float nationalins;

    // calculate national insurance level
    if ( gross < LEL ) {
        cout << "Your earnings are too low for NI to apply. You don't receive NI benefits." << endl;
        } else if ( gross > LEL && gross < PT ) {
        cout << "Your earnings are too low to pay NI, but you still receive all the benefits, courtesy of Employers' NICs." << endl;
        } else if ( gross > PT && gross < UEL ) {
        nationalins = ( gross - PT ) * 0.12;
        cout << "Your annual national insurance obligation is " << endl;
        cout << nationalins << endl;
        } else if ( gross > UEL ){
        nationalins = ( ( UEL - PT ) * 0.12 ) + (( gross - UEL ) * 0.02 );
        cout << "Your annual national insurance obligation is " << endl;
        cout << nationalins << endl; }

    // calculate monthly national insurance
    float monthlynatins = nationalins / 12;
    
    // calculate net monthly pay
    float netmonthlypay = monthlypostit - monthlynatins;

    // print net monthly pay with formatting
    cout << " ------------------------------------- " << endl;
    cout << "Your total net monthly pay (after deductions) is: " << endl;
    cout << netmonthlypay << endl;
    cout << " ------------------------------------- " << endl;

    return 0;
};
