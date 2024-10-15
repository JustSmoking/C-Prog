#include <iostream>


double ExtractImagePartnumber(std::string &ImageComplexe){
    std::string t;
    for (int i = 0; i <= ImageComplexe.size() ; i++) {
        if (ImageComplexe[i] != 'i')
            t += ImageComplexe[i];
    }
    return std::stod(t);
}
std::tuple<double,double,double> pow(double reel, std::string Image){
    double f = ExtractImagePartnumber(Image);
    double z = f;
    double ab;
    double ab1;
   // std::cout<< f << std::endl;
    if (f < 0){
        f = (f * f);
        ab = reel * reel + f;
        ab1 = 2 * reel * z;
      //  std::cout<<"(" << reel << " + " << Image << ")^2 =" << ab << " + " << ab1 << "i" << std::endl;
    }else if(f > 0){
        f = - (f * f);
        ab = reel * reel + f;
        ab1 = 2 * reel * z;
      //  std::cout<<"(" << reel << " + " << Image << ")^2 =" << ab << " + " << ab1 << "i" << std::endl;
    }
    return std::make_tuple(reel,ab,ab1);
}

void MandelBrotComplexeCalcul(int n, double reel, std::string Complexe) {
    std::tuple<double, double, double> Stock = pow(reel, Complexe);
    double a,b,c;
    a = std::get<0>(Stock);
    b = std::get<1>(Stock);//ab
    c = std::get<2>(Stock);//abi
    for (int i = 1; i <= n; i++)
    {
        if (i == 1 || n == 1)
        {
            std::cout<<"Z("<< 0 << ")" << " = " << 0 << std::endl;
            std::cout<<"Z("<< i << ")" << " = " << reel <<" + " << ExtractImagePartnumber(Complexe)<< "i" << std::endl;
        }
        else if (i == 2)
        {
            b += reel;
            c += ExtractImagePartnumber(Complexe);
            std::cout<<"Z("<< i << ")" << " = " << b << " + " << c << "i" << std::endl;
        }
        else
        {
            std::string Chaine = std::to_string(c) + "i";
            std::tuple<double, double, double> Stock1 = pow(b, Chaine);
            //std::cout<<std::get<1>(Stock1)<<" " <<std::get<2>(Stock1)<<std::endl;
            b = std::get<1>(Stock1) + reel;
            c = std::get<2>(Stock1) + ExtractImagePartnumber(Complexe);
            std::cout<<"Z("<< i << ")" << " = " << b << " + " << c << "i" << std::endl;
        }
    }
}
int main(){
    double reel{0};
    std::string Complexe{};
    int n{0};
    std::cout<<"===============================EXECUTION==============================="<< std::endl;
    std::cout<<"Le programme permet de calculer les termes de la fractale de MandelBrot"<< std::endl;
    std::cout<<"Dans un premier temps vous devriez rentrer votre nombre complexe de la forme a + bi"<< std::endl;
    std::cout<<"la partie reel du nombre complexe :"<< std::endl;
    std::cin >> reel;
    std::cout<<"la partie imaginaire du nombre complexe(exemple:(3i), 3):"<< std::endl;
    std::cin >> Complexe;
    std::cout<<"Automatisation et calcul de la fractale de mandelbrot " << std::endl;
    std::cout<<"Entrez le nombre d'iteration" << std::endl;
    std::cin >> n;
    std::cout<<"La toute puissance fractale de mandelbrot est la suivante: "<< std::endl;
    MandelBrotComplexeCalcul(n, reel, Complexe);
    std::cout<<"===============================END_EXEC==============================="<< std::endl;
    return 0;
}