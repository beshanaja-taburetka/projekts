#include "Picerija.h"

Picerija::Picerija()
{
    f.open("Picas.txt", fstream::in | fstream::app);
        while(!f.eof()){
            nosaukums = " ";
            f >> nosaukums;
            f >> cena;
            f >> izmers;
            if (nosaukums != " "){
                p = new Pica(nosaukums, cena, izmers);
                Picas.push_back(p);
            }
        }
    f.close();

    a = new Admin(1, "Sergejs", "Popovs", "0000");
    this->Admins.push_back(a);

    do{
        cout << "1. Admin" <<endl;
        cout << "2. User" <<endl;
        cout << "0. Beigt" << endl;
        izvele = getch();
        switch(izvele){
            case '1': aMenu(); break;
            case '2': uMenu(); break;
        }
    }while(izvele != '0');
}

Picerija::~Picerija()
{
    vector_size = Picas.size();



    f.open("Picas.txt", fstream::out | fstream::trunc);
        for (int i = 0; i < vector_size; i++){

            p = Picas[i];


            f <<" "<< p->nosaukums;
            f <<" "<< p->cena;
            f <<" "<< p->izmers;

        }
    f.close();

}


/// ADMIN MENU /////////////////////////////////////
string Picerija::aMenu()
{
    parb = "0";
    system ("cls");
    cout << "Ievadi paroli" <<endl;
    cin >> parb;

    vector_size = Admins.size();

    for (int i = 0; i < vector_size; i++){
        a = Admins[i];

        if (parb == a->parole){
            parb = "ok";
        }

        if (parb != "ok" ){
            cout << "Nepareiza parole." << endl;
            return parb;
        }
    }

    do{
        system("cls");
        cout << "1.Pievienot picu" <<endl;
        cout << "2.Apskatit picas" <<endl;
        cout << "3.Dzest Picu" << endl;
        cout << "4.Edit picu " << endl;
        cout << "5.Pievienot ingridientus" << endl;
        cout << "6.Apskatit picas ingridientus" << endl;
        cout << "0.Iziet un saglabat" << endl;
        izvele = getch();
        switch(izvele){
            case '1': pievienotPicu(); break;
            case '2': apskatitPicu(); break;
            case '3': dzestPicu(); break;
            case '4': picasEdit(); break;
            case '5': pievienotIngrideentu(); break;
            case '6': apskatitIngr(); break;
        }
    }while(izvele != '0');
    return "0";
}

/// USERMENU /////////////////////////////////////////////////////////////////
void Picerija::uMenu(){

    do{
        system ("cls");
        cout << "1.Pasutijums" <<endl;
        cout << "2.Atpakal" << endl;
        cout << "3.Apskatit ingridientus" << endl;
        cout << "0.Iziet" <<endl;
        izvele = getch();
        switch(izvele){
            case '1': pasutijums(); break;
            case '2': Picerija(); break;
            case '3': apskatitIngr(); break;
        }
    }while (izvele != '0');

}

/// FUNKCIJA PICAS PIEVENOSANAI ///////////////////////////////////
void Picerija::pievienotPicu(){

    cout << "Ievadi nosaukumu" <<endl;
    cin >> nosaukums;
    cout << "Ievadi veleto cenu"<<endl;
    cin >> cena;
    cout << "ievadi izmeru" <<endl;
    cin >> izmers;

    p = new Pica(nosaukums, cena, izmers);
    this->Picas.push_back(p);

    cout << "Pievienots"<<endl;
    system ("pause");


}

/// FUNKCIJA LAI PASKATITIES PICAS ////////////////////////////////////
void Picerija::apskatitPicu(){
    vector_size = Picas.size();

    for (int i = 0; i < vector_size; i++){
        p = Picas[i];

        cout << i + 1 << "." << p->nosaukums << " " << p->izmers << "cm" << " " << p->cena << "euro" << endl;
    }
    system("pause");


}

/// FUNKCIJA PICAS DZESANAI //////////////////////////////////////
void Picerija::dzestPicu(){
    cout << "Izvelies pice, lai nodzest" <<endl;
    apskatitPicu();
    cin >> izv;
    Picas.erase(Picas.begin() + izv - 1);
    cout << "Dzests" <<endl;
    system ("pause");
}

/// FUNKCIJA PICAS LABOSANAI //////////////////////////////////////
void Picerija::picasEdit(){
    cout << "1. Edit nosaukums" <<endl;
    cout << "2. Edit cena" << endl;

    cin >> izvele;

    if (izvele == '1'){
        cout << "Izvelies picu" <<endl;
        apskatitPicu();
        cin >> izv;
        p = Picas[izv - 1];
        cout << "Ievadi jaunu nosaukumu" <<endl;
        cin >> nosaukums;
        p->nosaukums = nosaukums;
    }

    if (izvele == '2'){
        cout << "Izvelies picu" <<endl;
        apskatitPicu();
        cin >> izv;
        p = Picas[izv - 1];
        cout << "Ievadi jaunu cenu" <<endl;
        cin >> p->cena;
    }
}

/// FUNKCIJA LAI PIEVIENOTU INGRIDIENTUS IZVELETAI PICAI ////////////////
void Picerija::pievienotIngrideentu(){

    apskatitPicu();
    cout << "Izvelies picu" <<endl;
    cin >> izv;
    p = Picas[izv - 1];
    fails = "Picas/" + p->nosaukums;
    do{
        cout << "Pievieno ingridientu (0 - beigt)" <<endl;
        cin >> ingridient;
        if(ingridient != "0"){
            f.open(fails.c_str(), fstream::in | fstream::out | fstream::app);
            f <<" "<< ingridient;
            f.close();
        }
    }while(ingridient != "0");
    f.close();
}

/// FUNKCIJA LAI PASKATITIES INGRIDIENTUS IZVELETAI PICAI //////////////////////
void Picerija::apskatitIngr(){

        cout << "Izvelies picu" <<endl;
        apskatitPicu();
        cin >> izv;
        p = Picas[izv - 1];
        fails = "Picas/" + p->nosaukums;
        f.open(fails.c_str(), fstream::in | fstream::out | fstream::app);
        do{
            f >> ingridient;
            cout << ingridient << endl;
        }while(!f.eof());
        f.close();
        system ("pause");
}


/// FUNKCIJA PASUTIJUMS ///////////////////////////////////////////////////////////////
void Picerija::pasutijums(){

    cout << "Izvelies picu" <<endl;
    apskatitPicu();
    cin >> izv;

    p = Picas[izv - 1];

    cout << "Ievadi savu vardu" <<endl;
    cin >> vards;

    cout << "Ievadi adresi(izmantojot _ nevis atstarpes)" << endl;
    cin >> adrese;


    nosaukums = p->nosaukums;
    cena = p->cena;
    izmers = p->izmers;

    u = new User(vards, nosaukums);
    Users.push_back(u);

    /// PASUTIJUMA HTML DRUKASANA  /////////////////////////////////////////////////////////////////////////

    f.open("Pasutijums.html", fstream::in | fstream::out | fstream::trunc);
        f << "<!DOCTYPE html>";
        f << "<html>";
        f << "<head>";
        f << "<title>PASUTIJUMS</title>";
        f << "</head>";
        f << "<body>";
        f << "<table border=""1"">";
        f << "<tr>";
        f << "<style>" ;
        f << "td { font-size: 150% }";
        f << "</style>";
        f << " <td>" << "Vards:" <<"</td>";
        f << " <td>" << vards <<"</td>";
        f << "</tr>";
        f << "<tr>";
        f << " <td>" << "Adrese:" <<"</td>";
        f << " <td>" << adrese <<"</td>";
        f << "</tr>";
        f << "<tr>";
        f << "<td>" << "Pica:" << "</td>";
        f << "<td>" << nosaukums << "</td>";
        f << "</tr>";
        f << "<tr>";
        f << "<td>" << "Izmers(cm):" << "</td>";
        f << "<td>" << izmers << "</td>";
        f << "</tr>";
        f << "<tr>";
        f << "<td>" << "Cena(euro):" << "</td>";
        f << "<td>" << cena << "</td>" ;
        f << "</tr>";
        f << "</table>";
        f << "Paldies par pasutijumu.";
        f << "Jusu pica bus apmeram pec 30 minutem :)";
        f << "</body>";
        f << "</html>";
    f.close();

    ShellExecute(NULL, "open", "Pasutijums.html",NULL, NULL, SW_SHOWNORMAL); /// HTML dokuments atveras pashs
    system ("pause");
}

