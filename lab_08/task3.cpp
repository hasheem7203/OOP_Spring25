# include <iostream>
using namespace std ;


class vector2d{
    private :
        int x,y;

    public:
        vector2d(int x,int y):x(x),y(y){};

        vector2d operator+(vector2d& v){
            return vector2d(x+v.x,y+v.y);
        }
        vector2d operator-(vector2d& v){
            return vector2d(x-v.x,y-v.y);
        }

        vector2d operator*(int scalar){
            return vector2d(x*scalar,y*scalar);
        }

        friend ostream& operator<<(ostream& COUT,vector2d& v);
        friend float dotProduct(const vector2d& v1, const vector2d& v2);

};
        float dotProduct(const vector2d& v1, const vector2d& v2){
            return v1.x * v2.x + v1.y * v2.y;
        }

    ostream& operator<<(ostream& COUT,vector2d& v){
        COUT<<"("<<v.x<<","<<v.y<<")"<<endl;
        return COUT;
    }


int main (){
    vector2d v1(3, 4);
    vector2d v2(1, 2);

    vector2d sum = v1 + v2;
    vector2d diff = v1 - v2;
    vector2d scaled = v1 *5;

    cout << "v1 = "<<v1 << endl;
    cout << "v2 = " << v2 << endl;
    cout << "v1 + v2 = " << sum << endl;
    cout << "v1 - v2 = " << diff << endl;
    cout << "v1 * 2.5 = " << scaled << endl;

    float dp = dotProduct(v1, v2);
    cout << "Dot Product of v1 and v2 = " << dp << endl;

    return 0;
}
