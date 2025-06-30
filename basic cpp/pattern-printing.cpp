#include<bits/stdc++.h>
using namespace std;


void pattern1(int n) {
    for(int i=1; i<=n; i++) {
        // space
        for(int j=1; j<=n-i; j++) {
            cout << " ";
        }
        // star
        for(int k=1; k<=i+i-1; k++) {
            cout << "*";
        }
        // space
        for(int j=1; j<=n-i; j++) {
            cout << " ";
        }
        cout << endl;
    }
}

void pattern4(int n) {
    for(int i=1; i<=2*n-1; i++) {
        // star
        if (i<=n) {
            for(int j=1; j<=i; j++) {
                cout << "*";
            }
        }
        else if (i >n) {
            for (int k=1; k<=2*n-i; k++) {
                cout << "*";
            }
        }
        cout << endl;
    }
}

void pattern5(int n) {
    int start=1;
    for (int i=1; i<=n; i++) {
        if (i%2 == 0) start=0;
        for (int j=1; j<=i; j++) {
            cout << start;
            start=1-start;
        }
        start=1-start;
        cout << endl;
    }
}

void pattern6(int n) {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            cout << j;
        }
        for(int k=1; k<=2*n-2*i; k++) {
            cout << " ";
        }
        for(int l=1; l<=i; l++) {
            cout << i-l+1;
        }
        cout << endl;
    }
}

void pattern7(int n) {
    int x = 1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            cout << x << " ";
            x = x+1;
        }
        cout << endl;
    }
}

void pattern8(int n) {
    for(int i=1; i <=n; i++){
        for(char j='A';  j<='A'+n-i; j++){
            cout << j << " ";
        }
        cout << endl;
    }
}

void pattern9(int n) {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++){
            char ch ='A'+i-1;
            cout << ch << " ";
        }
        cout << endl;
    }
}

// tough one
void pattern10(int n) {
    for(int i =1; i<=n; i++){
        // space
        for(int j=1; j<=n-i; j++) {
            cout << " ";
        }
        // characters
        char ch = 'A';
        for(int l=1; l<=2*i-1; l++){
            cout << ch;
            if(l<=i-1) ch++;
            else ch--;
        }
        // space
        for(int k=1; k<=n-i; k++) {
            cout << " ";
        }
        cout << endl;
    }
}

void pattern11(int n) {
    for(int i=1; i<=n; i++) {
        for(char ch='A'+ n-i; ch<='A' +n -1; ch++) {
            cout << ch << " ";
        }
        cout << endl;
    }
}

void pattern12(int n) {
    for(int i=1; i<=2*n; i++) {
        if(i<=n){
            //star
            for(int j=1; j<=n-i+1; j++) {
                cout << "*";
            }
            //space
            for(int k=1; k<=2*i-2; k++) {
                cout << " ";
            }
            //star
            for(int j=1; j<=n-i+1; j++) {
                cout << "*";
            }
            cout << endl;
        }
        else{
            //star
            for(int j=1; j<=i-n; j++) {
                cout << "*";
            }
            //space
            for(int k=1; k<=4*n-2*i; k++) {
                cout << " ";
            }
            //star
            for(int j=1; j<=i-n; j++) {
                cout << "*";
            }
            cout << endl;
        }
    }
}

void pattern13(int n) {
    for(int i=1; i<=2*n-1; i++) {
        if(i<=n) {
            // star
            for(int j=1; j<=i; j++) {
                cout << "*";
            }
            // space
            for(int k=1; k<=2*n-2*i; k++){
                cout << " ";
            }
            // star
            for(int j=1; j<=i; j++) {
                cout << "*";
            }
            cout << endl;
        }
        else{
            // star
            for(int j=1; j<=2*n-i; j++) {
                cout << "*";
            }
            // space
            for(int k=1; k<=2*i-2*n; k++){
                cout << " ";
            }
            // star
            for(int j=1; j<=2*n-i; j++) {
                cout << "*";
            }
            cout << endl;
        }
    }
}

void pattern14(int n) {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i==1|| i==n|| j==1|| j==n) cout << "*";
            else cout << " ";
        }
        cout << endl;
    }
}

// good one
void pattern15(int n){
    for(int i=0; i<=2*n-2; i++){
        for(int j=0; j<=2*n-2; j++){
            cout << min(min(i, j), min(2*n-2-i, 2*n-2-j));
        }
        cout << endl;
    }
}