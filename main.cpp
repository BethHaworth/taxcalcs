#include <iostream>

using namespace std;

int main()
{
    /* set income */
    float gross;
    cout << "Calculate your income tax liability for 2017-2018 /" << endl;
    cout << "Please enter your annual gross income (GBP):" << endl;
    cin >> gross;

    /* calculate income tax */
    float taxablegross = gross - 11500;
    float incometax;

    if ( taxablegross < 33501 ){
        incometax =  0.2 * taxablegross;
        } else if ( taxablegross >= 33501 && taxablegross <= 150000 ){
        incometax = ( 0.4 * ( taxablegross - 33500 )) + ( 0.2 * 33500 );
        } else if ( taxablegross >= 150001 ){
        incometax = ( 0.45 * (taxablegross - 150000)) + ( 0.4 * ( 150000 - 33500 ) + ( 0.2 * 33500 ) );
    }

    cout << "Your total tax liability is: " << endl;
    cout << incometax << endl;

    float yearlypostit = gross - incometax;

    cout << "Your yearly income after income tax is: " << endl;
    cout << yearlypostit << endl;

    float monthlypostit = yearlypostit / 12;

    cout << "This equates to " ;
    cout << monthlypostit ;
    cout << " per month, before other deductions." << endl;

    /* calculate national insurance */

    float LEL = 490 * 12;
    float PT = 680 * 12;
    float UEL = 3750 * 12;

    float nationalins;

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

        float monthlynatins = nationalins / 12;
        float netmonthlypay = monthlypostit - monthlynatins;

        /* Summary */

        cout << " ------------------------------------- " << endl;

        cout << "Your total net monthly pay (after deductions) is: " << endl;
        cout << netmonthlypay << endl;
        cout << " ------------------------------------- " << endl;


    return 0;
}
