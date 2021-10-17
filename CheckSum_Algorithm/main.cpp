#include <iostream>
#include <string>

using namespace std;

int senderChecksum (int* arr, int m)
{
    int checksum, sum=0;
    for(int i=0; i<m; i++)
        sum = sum + arr[i];
    checksum = ~sum;
    return checksum;
}

int senderSum (int* arr, int m)
{
    int checksum, sum=0;
    for(int i=0; i<m; i++)
        sum = sum + arr[i];
    return sum;
}

int receiverChecksum (int* arr, int m, int senderchecksum)
{
    int checksum, sum=0;
    for(int i=0; i<m; i++)
        sum = sum + arr[i];
    sum = sum + senderchecksum;
    checksum = ~sum;
    return checksum;
}

int receiverSum (int* arr, int m)
{

    int checksum, sum=0;
    for(int i=0; i<m; i++)
        sum = sum + arr[i];
    return sum;
}

int main()
{
    string mssg;
    int senderValue, receiverValue;
    cout << "Enter the message to be transmitted: ";
    cin >> mssg;
    int arr[mssg.length()];
    for(int i=0;i<mssg.length();i++) {
        int k = int(mssg[i]);
        string str = "";
        for(int j=7;j>=0;j--) {
          str = to_string(k%2).append(str);
          k=k/2;
        }
        arr[i] = stoi(str);
    }

    cout << "The binary form of given message is: " << endl;
    for(int i=0; i<mssg.length(); i++)
        cout << arr[i] << endl;
    senderValue = senderChecksum(arr, mssg.length());
    //Introduction of error
    arr[0] = 11001100;
    receiverValue = receiverChecksum(arr, mssg.length(), senderValue);
    cout << "\n\n/***Sender's End***/" << endl;
    cout << "Sender side Sum : " << senderSum(arr, mssg.length()) << endl;
    cout << "Sender side Checksum Value: " << senderValue << endl;
    cout << "\n\n/***Receiver's End***/" << endl;
    cout << "Receiver side Sum: " << receiverSum(arr, mssg.length()) << endl;
    cout << "Receiver side Checksum Value: "<< receiverValue << endl;
    cout << "\nFinal Result: ";
    if(receiverValue == 0)
        cout << "No Error Detected \n" ;
    else
        cout << "Error detected!!!, Please repeat the process\n" ;
}
