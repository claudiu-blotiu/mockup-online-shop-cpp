#include"ViewUser.h"

int main()
{
    
    //aici

    Customer* f = new Customer(6,"Bogdan","meditatii","BogdanD","acasa","job","RO",98234);

    ViewUser view(f);

    view.play();

  
    
    

    /*ControlProducts* cp = new ControlProducts();

    Products* p = cp->getProduct1(2);

    cout << p->description() << endl;*/

    
}
