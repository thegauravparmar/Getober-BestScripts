#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double weight, height, bmi;
    
    // Get user input for weight (in kilograms) and height (in meters)
    cout << "Enter your weight in kilograms: ";
    cin >> weight;
    cout << "Enter your height in meters: ";
    cin >> height;
    
    // Calculate BMI
    bmi = weight / pow(height, 2);
    
    // Display the BMI value
    cout << "Your BMI is: " << bmi << endl;
    
    // Provide tips based on BMI value
    if (bmi < 18.5) {
        cout << "You are underweight. To improve your BMI, consider gaining some weight in a healthy way. Consult with a nutritionist or doctor if necessary." << endl;
    } else if (bmi >= 18.5 && bmi < 24.9) {
        cout << "Your BMI is within the healthy range. Maintain a balanced diet and regular exercise to stay healthy." << endl;
    } else if (bmi >= 25.0 && bmi < 29.9) {
        cout << "You are overweight. To improve your BMI, consider a balanced diet and regular exercise. Consult with a nutritionist or doctor for a personalized plan." << endl;
    } else {
        cout << "You are obese. It's important to focus on improving your BMI for your health. Consult with a healthcare professional for a personalized plan." << endl;
    }
    
    return 0;
}
