

#include <iostream>

using namespace std;
// 1 km = 67.58
float convertKmToMiles(float km){
    float k_mmiles = 0.62137;
     float miles = k_mmiles * km;
    //  cout << "Miles : " << Miles << "\n";
     return miles;
}


int main()
{
//   convert km to miles
float km;
cin >> km;
float res = convertKmToMiles(km);
cout << "YOur Miles : " << res <<  endl;

    return 0;
}
