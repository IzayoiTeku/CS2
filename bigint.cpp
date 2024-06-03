#include "bigint.hpp"

bigint::bigint() {  // default constructor
    for (int i = 0; i < capacity; ++i){
        hugeNum[i] = 0;
    }
}

bigint::bigint(int convert){
    for (int i = 0; i < capacity; ++i){
        hugeNum[i] = 0;
    }
    for (int j = 0; j < capacity; ++j){
        int digit = convert % 10;
        convert = convert /10;
        hugeNum[j] = digit;
    }
}

bigint::bigint(const char holdNum[]){

    int length = 0;
    int j = 0;
    do {
        ++length;
    }
    while (holdNum[length] != '\0');
    for (int k = length -1; k >= 0; --k, ++j){
        hugeNum[j] = int(holdNum[j]) - int ('0');
    }
     
}

bigint bigint::operator+(bigint rhs) const{
    int temp = 0;
    int temp2 = 0;
    for(int i = 0; i < capacity; ++i){
        temp2 = hugeNum[i] + rhs.hugeNum[i] + temp2;
        temp = temp2 % 10;
        temp2 = temp2 / 10;
        rhs.hugeNum[i] = temp;
    }
    return rhs;
}


int bigint::operator[](int index) const {
    if((index <0) || (index > = capacity)) return 0;
    return hugeNum[index];
}

bool bigint::operator== (std::ostream& out, const bigint& overl) const {
    for(int i =0; i < capacity; ++i) {
        if(hugeNum[i] == over1.hugeNum[i]){
            return true;
        }
    }
    return false;
}

void bigint::debugPrint(std::ostream& out, const char largeNum[]) const {
    for (int i = capacity - 1; i >= 0; i--){
        out << largeNum[i] << "|";
    }
}
friend std::ostream& operator<<(std::ostream& out, bigint& rhs) {

    int newCapacity = capacity;
    int newOut = 0;
    do {
        --newCapacity;
    } while (newCapacity >0 && hugeNum[newCapacity] == 0);

    do {
        if (newCapacity % 80){
            out << hugeNum[newCapacity];
        }
        else
            out << hugeNum[newCapacity] << std::endl;
            --newCapacity;
            ++newOut;
    } while (newCapacity >= 0);
    return out;


}

friend std::ostream& operator>>(std::istream& in, const bigint& rhs) {
    char ch;
    char tempArr[capacity];
    for (int i = 0; i < capacity; ++i){
        tempArr[i] = 0;
    }
    in >> ch;
    for(int j = 0; j < capacity && ch != ';'; ++i){
        tempArr[i] =ch;
        in = ch;
    }

    rhs = bigint(tempArr);
    return in;
}
bigint::bigint timesDigit(int digit){
    bigint temp;
    int num = 0;
    int result = 0;
    for (int i = 0; i < capacity; ++i) {
        num = hugeNum[i] * digit + num;
        result = num % 10;
        num/= 10;
        temp.hugeNum[i] = result;

    }
    return temp;

}
bigint::bigint times10(int mult){
    bigint temp;
    for (int i = capacity - 1 - mult; i >= 0; --i){
        temp.hugeNum[i + mult] = hugeNum[i];
    }
    for (int j = 0;  j < mult; ++j ) {
        temp.hugeNum[j] = 0;
    }
    return temp;

}
bigint::bigint operator*(bigint rhs){
    bigint product = 0;
    for (int i = 0; i < capacity-1; ++i) {
        bigint temp = timesDigit(rhs.hugeNum[i]);
        product = product + temp.times10(i);
    }
    return product;
}



