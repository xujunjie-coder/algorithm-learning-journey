#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long


//对根号里面进行化简
pair<int,int> simplifySqrt(int n){
    if(n == 0) return{0,1};

    int inside = 1,outside = 1;

    for(int p = 2; p <= n/p; ++p){  //p <= n/p等价与p * p <= n，且不容易导致溢出
        int cot = 0;
        while(n % p == 0){
            n /= p;
            cot++;
        }

        for(int i = 1; i <= cot / 2; ++i){
            outside *= p;
        }

        if(cot % 2 == 1){
            inside *= p;
        }

    }
    if(n > 1){
        inside *= n;
    }
    return {outside,inside};
}

bool is_ration(int n){
    int k = sqrt(n);
    if(k*k == n) return 1;
    else return 0;
}

int gcd(int x,int y){
    int a = x, b = y;
    if(a < 0) a = -x;
    if(b < 0) b = -y;
    while(b){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

pair<int,int> huajian(int zi,int mu){
    if(zi == 0) return{0,1};
    if(zi == mu) return {1,1};
    else{
        int x = gcd(zi,mu);
        zi /= x;
        mu /= x;
        return{zi,mu};
    }
}

int T,M;
int main(){
    cin >> T >> M;
    while(T--){
        int a,b,c;
        cin >> a >> b >> c;
        if(a < 0){
            a = -a;
            b = -b;
            c = -c;
        }
        int derta = b*b-4*a*c;
        if(derta < 0){
            cout << "NO" << "\n";
            continue;
        }else{
            int zi = -b+sqrt(derta);
            int mu = 2*a;
            if(is_ration(derta)){     //有理数
                if(zi % mu == 0){
                    // if(zi < 0) cout << "-";
                    cout << zi / mu << "\n";
                }else{
                    // if(zi < 0) cout << "-";
                    int x = gcd(zi,mu);
                    cout << zi/x << "/" << mu/x << "\n";
                }
            }else{  //无理数
                //先化简根号
                pair<int,int> p = simplifySqrt(derta);
                int q2 = p.first, r = p.second;
                //约分
                auto x2 = huajian(q2,mu);
                int x21 = x2.first, x22 = x2.second;
                auto x1 = huajian(-b,mu);
                int x11 = x1.first, x12 = x1.second;
                
                //有理数部分为0
                if(x11 == 0){
                    if(x21 == 1 && x22 == 1)
                        cout << "sqrt(" << r << ")" << "\n";
                    else if(x21 == 1 && x22 > 1)
                        cout << "sqrt(" << r << ")/" << x22 << "\n";
                    else if(x21 > 1 && x22 > 1)
                        cout << x21 << "*sqrt(" << r << ")/" << x22 << "\n";
                    else if(x21 > 1 && x22 == 1)
                        cout << x21 << "*sqrt(" << r << ")" << "\n";
                }

                else if(x11 == 1 && x12 == 1){
                    cout << 1 << "+";
                    if(x21 == 1 && x22 == 1) cout << "sqrt(" << r << ")" << "\n";
                    else if(x21 == 1 && x22 > 1) cout << "sqrt(" << r << ")/"  << x22 << "\n";
                    else if(x21 > 1 && x22 > 1) cout << x21 << "*" << "sqrt(" << r << ")/"  << x22 << "\n";
                    else if(x21 > 1 && x22 == 1) cout << x21 << "*sqrt(" << r << ")" << "\n";
                }
                else if(x12 > 1){
                    cout << x11 << "/" << x12 << "+";
                    if(x21 == 1 && x22 == 1) cout << "sqrt(" << r << ")" << "\n";
                    else if(x21 == 1 && x22 > 1) cout << "sqrt(" << r << ")/"  << x22 << "\n";
                    else if(x21 > 1 && x22 > 1) cout << x21 << "*" << "sqrt(" << r << ")/"  << x22 << "\n";
                    else if(x21 > 1 && x22 == 1) cout << x21 << "*" << "sqrt(" << r << ")" << "\n";
                }else if(x12 == 1){
                    cout << x11  << "+";
                    if(x21 == 1 && x22 == 1) cout << "sqrt(" << r << ")" << "\n";
                    else if(x21 == 1 && x22 > 1) cout << "sqrt(" << r << ")/"  << x22 << "\n";
                    else if(x21 > 1 && x22 > 1) cout << x21 << "*" << "sqrt(" << r << ")/"  << x22 << "\n";
                    else if(x21 > 1 && x22 == 1) cout << x21 << "*" << "sqrt(" << r << ")" << "\n";
                }
            }
        }
    }
    
    return 0;
}
