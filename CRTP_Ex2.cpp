#include<iostream>
using namespace std;
//Library Vendor
class Flute {public: void play(){cout <<"playing Flute" << endl;} };
class Drums {public: void play(){cout <<"playing Drum" << endl;} };
class Piano {public: void play(){cout <<"playing Piano" << endl;} };

//Library consumer cum Application developer

template<typename INSTRUMENT> class InstrumentBase
{
private:
    INSTRUMENT& GetType() { return static_cast<INSTRUMENT&>(*this);}
public:
    void play() { GetType().play();}
};

class ComposeFlute:public InstrumentBase<ComposeFlute>
{
private:
    Flute ob1;
public:
    void play(){ob1.play();}
};

class ComposeDrums:public InstrumentBase<ComposeDrums>
{
private:
    Drums ob1;
public:
    void play(){ob1.play();}
};

class ComposePiano:public InstrumentBase<ComposePiano>
{
private:
    Piano ob1;
public:
    void play(){ob1.play();}
};
//consuming function
template<typename T> void Process(InstrumentBase<T>& x)
{
    x.play();
}

//Application consumer

int main()
{
    ComposeDrums ob1;
    ComposeFlute ob2;
    ComposePiano ob3;
    //ob1.play();
    //ob2.play();
    //ob3.play();
    Process(ob1);
    Process(ob2);
    Process(ob3);

    return 0;
}