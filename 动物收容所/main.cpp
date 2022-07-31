class AnimalShelf {
    queue<pair<int,int>> queCat; //猫队列
    queue<pair<int,int>> queDog; //狗队列
    int cout = 0; //设置自增数
public:
    AnimalShelf() {
    }

    void enqueue(vector<int> animal) {
        if(animal[1]) queDog.push({cout,animal[0]});
        else queCat.push({cout,animal[0]});
        cout ++;
    }

    vector<int> dequeueAny() {
        if(queDog.empty() && queCat.empty()) return {-1, -1};
        else if(queCat.empty() && queDog.size()) return dequeueDog();
        else if(queDog.empty() && queCat.size()) return dequeueCat();
        else if(queDog.front() < queCat.front()) return dequeueDog();
        else return dequeueCat();
    }

    vector<int> dequeueDog() {
        if(queDog.empty()) return {-1, -1};
        int temp = queDog.front().first;
        queDog.pop();
        return {temp, 1};
    }

    vector<int> dequeueCat() {
        if(queCat.empty()) return {-1, -1};
        int temp = queCat.front().first;
        queCat.pop();
        return {temp, 0};
    }
};
