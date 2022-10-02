#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
    //DECLARACION DE VARIABLES
    int opc;
    float saldoInicial1=2000;
    float saldoInicial2=2000;
    int usuario;
    int clave;
    int claveCorrecta1=1802;
    int claveCorrecta2=2002;
    float deposito, retiro, transferencia, transferir;
    int usuario1=0001;
    int usuario2=0002;
    
    //EL USUARIO 1 ES 0001
    //LA CLAVE DEL USUARIO 1 ES 1802
    //BUCLE WHILE PARA VERIFICAR QUE EL USUARIO Y CONTRASEÑA SEAN CORRECTOS
    while(usuario!=000 && clave!=claveCorrecta1)
    {
        cout<<"INGRESE EL NUMERO DE USUARIO: ";
        cin>>usuario;
        cout<<"INGRESE SU CLAVE DE USUARIO: ";
        cin>>clave;
        //CONDICIONAL IF PARA COMPROBAR SI SE TRATA DEL INICIO DE SESION DEL USUARIO 1 O USUARIO 2
        if(usuario==usuario1 && clave==claveCorrecta1)
        {
            cout<<"BIENVENIDO USUARIO 1";
    while(1==1)
    {
        
        //INICIO DEL MENU DE CAJERO
        cout<<endl<<"CAJERO AUTOMATICO"<<endl;
        cout<<"1. RETIRO"<<endl;
        cout<<"2. DEPOSITO"<<endl;
        cout<<"3. CONSULTA DE SALDO"<<endl;
        cout<<"4. CAMBIO DE NIP"<<endl;
        cout<<"5. TRANSFERENCIA"<<endl;
        cout<<"6. SALIR"<<endl;
        cout<<"SELECCION: ";
        cin>>opc;
        //INICIO DEL FUNCIONAMIENTO DEL MENU SEGUN LA OPCION ELEGIDA
        switch(opc)
        {
            case 1:
            cout<<endl<<"INGRESE LA CANTIDAD DE DINERO A RETIRAR: ";
            cin>>retiro;
            //CONDICIONAL PARA IMPEDIR UN RETIRO MAYOR AL SALDO QUE SE TIENE
            if(retiro > saldoInicial1)
            {
                cout<<endl<<"NO CUENTA CON LA CANTIDAD SELECCIONADA PARA RETIRAR";
            }
            else
            {
                saldoInicial1=saldoInicial1-retiro;
                cout<<endl<<"RETIRO EXITOSO! SALDO ACTUAL: "<<saldoInicial1;
            }
            break;
            case 2:
            cout<<endl<<"INGRESE LA CANTIDAD A DEPOSITAR: ";
            cin>>deposito;
            if(deposito > saldoInicial1)
                {
                    cout<<endl<<"NO CUENTA CON LA CANTIDAD SELECCIONADA PARA DEPOSITAR";
                }
                else
                {
                    saldoInicial1=saldoInicial1+deposito;
                    cout<<endl<<"DEPOSITO EXITOSO! SALDO ACTUAL: "<<saldoInicial1;
                }
            break;
            case 3:
            cout<<endl<<"SALDO ACTUAL DISPONIBLE: ";
            cout<<saldoInicial1<<endl;
            break;
            case 4:
            while(clave==1802)
            {
            cout<<endl<<"INGRESE SU NIP PARA CONFIRMAR CAMBIO: ";
            cin>>clave;
            if(clave!=claveCorrecta1)
            {
                cout<<"NIP INCORRECTO!!!"<<endl;
            }
            else
            {
                cout<<"INGRESE EL NUEVO NIP: ";
                cin>>clave;
                cout<<"NIP CAMBIADO EXITOSAMENTE!!!"<<endl;
                claveCorrecta1=clave;
            }
            }
            break;
            case 5:
            while(transferencia!=usuario2)
            {
                cout<<endl<<"INGRESE EL NUMERO DE CUENTA PARA TRANSFERIR: ";
                cin>>transferencia;
                if(transferencia!=usuario2)
                {
                    cout<<"NUMERO DE CUENTA INCORRECTO!!!";
                }
                else
                {
                    cout<<"INGRESE LA CANTIDAD A TRANSFERIR: ";
                    cin>>transferir;
                    if(transferir > saldoInicial1)
                    {
                        cout<<"NO CUENTA CON ESA CANTIDAD EN SU CUENTA!!!";
                    }
                    else
                    {
                        saldoInicial1=saldoInicial1-transferir;
                        saldoInicial2=saldoInicial2+transferir;
                        cout<<endl<<"TRANSFERENCIA EXITOSA!!!"<<endl;
                    }
                }
            }
            break;
            case 6:
            exit(0);
            break;
            default:
            cout<<endl<<"OPCION INVALIDA";
            break;
        }
    }
        }
        if(clave!=claveCorrecta1)
        {
            cout<<endl<<"USUARIO O CLAVE INCORRECTA!!!"<<endl;
        }
        
        //INICIAL DEL CAJERO AUTOMATICO PARA EL USUARIO 2
        if(usuario==usuario2 && clave==claveCorrecta2)
        {
            cout<<"BIENVENIDO USUARIO 2";
    while(1==1)
    {
        
        //INICIO DEL MENU DE CAJERO
        cout<<endl<<"CAJERO AUTOMATICO"<<endl;
        cout<<"1. RETIRO"<<endl;
        cout<<"2. DEPOSITO"<<endl;
        cout<<"3. CONSULTA DE SALDO"<<endl;
        cout<<"4. CAMBIO DE NIP"<<endl;
        cout<<"5. TRANSFERENCIA"<<endl;
        cout<<"6. SALIR"<<endl;
        cout<<"SELECCION: ";
        cin>>opc;
        //INICIO DEL FUNCIONAMIENTO DEL MENU SEGUN LA OPCION ELEGIDA
        switch(opc)
        {
            case 1:
            cout<<endl<<"INGRESE LA CANTIDAD DE DINERO A RETIRAR: ";
            cin>>retiro;
            //CONDICIONAL PARA IMPEDIR UN RETIRO MAYOR AL SALDO QUE SE TIENE
            if(retiro > saldoInicial2)
            {
                cout<<endl<<"NO CUENTA CON LA CANTIDAD SELECCIONADA PARA RETIRAR";
            }
            else
            {
                saldoInicial2=saldoInicial2-retiro;
                cout<<endl<<"RETIRO EXITOSO! SALDO ACTUAL: "<<saldoInicial2;
            }
            break;
            case 2:
            cout<<endl<<"INGRESE LA CANTIDAD A DEPOSITAR: ";
            cin>>deposito;
            if(deposito > saldoInicial2)
                {
                    cout<<endl<<"NO CUENTA CON LA CANTIDAD SELECCIONADA PARA DEPOSITAR";
                }
                else
                {
                    saldoInicial2=saldoInicial2+deposito;
                    cout<<endl<<"DEPOSITO EXITOSO! SALDO ACTUAL: "<<saldoInicial2;
                }
            break;
            case 3:
            cout<<endl<<"SALDO ACTUAL DISPONIBLE: ";
            cout<<saldoInicial2<<endl;
            break;
            case 4:
            while(clave==1802)
            {
            cout<<endl<<"INGRESE SU NIP PARA CONFIRMAR CAMBIO: ";
            cin>>clave;
            if(clave!=claveCorrecta2)
            {
                cout<<"NIP INCORRECTO!!!"<<endl;
            }
            else
            {
                cout<<"INGRESE EL NUEVO NIP: ";
                cin>>clave;
                cout<<"NIP CAMBIADO EXITOSAMENTE!!!"<<endl;
                claveCorrecta2=clave;
            }
            }
            break;
            case 5:
            while(transferencia!=usuario1)
            {
                cout<<endl<<"INGRESE EL NUMERO DE CUENTA PARA TRANSFERIR: ";
                cin>>transferencia;
                if(transferencia!=usuario1)
                {
                    cout<<"NUMERO DE CUENTA INCORRECTO!!!";
                }
                else
                {
                    cout<<"INGRESE LA CANTIDAD A TRANSFERIR: ";
                    cin>>transferir;
                    if(transferir > saldoInicial2)
                    {
                        cout<<"NO CUENTA CON ESA CANTIDAD EN SU CUENTA!!!";
                    }
                    else
                    {
                        saldoInicial2=saldoInicial2-transferir;
                        saldoInicial1=saldoInicial1+transferir;
                        cout<<endl<<"TRANSFERENCIA EXITOSA!!!"<<endl;
                    }
                }
            }
            break;
            case 7:
            exit(0);
            break;
            default:
            cout<<endl<<"OPCION INVALIDA";
            break;
        }
    }
        }
        if(clave!=claveCorrecta2)
        {
            cout<<endl<<"USUARIO O CLAVE INCORRECTA!!!"<<endl;
        }
    }

    return 0;
}