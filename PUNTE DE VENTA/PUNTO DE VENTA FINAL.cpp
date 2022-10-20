#include <iostream>
#include <iomanip>

using namespace std;
//INICIO DE PUNTO DE VENTA

int buscar(string name);

//VOID PARA OPCIONES DE MENU DEL PUNTO DE VENTA
void Administrador();
void Altas();
void Bajas();
void Consultas();
void Modificaciones();
void Inventario();
void Usuarios();

//VOID PARA OPCIONES DEL MENU PARA ADMINISTRAR USUARIOS
void Altas_u();
void Bajas_u();
void Consultas_u();
void Modificaciones_u();
void Mostrar_u();

//VOID PARA EL MENU DE VENTAS Y MANEJO DE PRECIOS/TOTALES DE PRODUCTOS
void Ventas();
string cliente[100] = {};
int total_vendedor[100] = {};
int gran_total;
int check_sell = 0;
int subtotal_2[100] = {};
int cantidad[100] = {};
int egresos_vendedor[100]={};
int egresos_total;
void Verify_admin();
void Verify_seller();

//DECLARACION DE MINI MENU DE OPCIONES ASI COMO SU PRECIO Y STOCK
int id [100] = {1, 2, 3, 4, 5};
string producto [100] = {"COCA-COLA", "LECHE", "CARNE", "PAN", "GALLETAS"};
int pc[100] = {28, 15, 20, 10, 10};
int pv[100] = {30, 20, 25, 16, 15};
int existencia [100] = {20, 20, 20, 20, 20};
int nr[100] = {8, 5, 5, 2, 3};
int st[100] = {1, 1, 1, 1, 1};
int total = 5;

//MINI MENU PARA EL FUNCIONAMIENTO DE BUSQUEDA Y FUNCION DE USUARIOS ADMINISTRADORES
int buscar_a(string admin);
string user_admin[100];
int pass_a[100];
int st_admin[100] = {1, 1};
int check_admin;
int total_admin = 2;

//MINI MENU PARA EL FUNCIONAMIENTO DE BUSQUEDA Y FUNCION DE USUARIOS VENDEDORES
int buscar_v(string seller);
string user_seller[100];
int pass_v[100];
int st_seller[100] = {1, 1};
int check_seller;
int total_seller = 2;

int i_b;
int i_ba;
int i_bv;

//MAIN PARA EL FUNCIONAMIENTO DEL PUNTO DE VENTAS 
int main() {
    int i;
    int j;
    int opc;
    Administrador();
}

//FUNCIONAMIENTO DEL MENU 
void Ventas() {
    int i;
    int j;
    int k;
    int c = 0;
    int pos;
    int opc;
    int cant;
    int menu;
    menu=1;
    int subtotal[100] = {};
    int suma_subtotal;
    string nombre;
    int total_cliente[100] = {};
    cout << "====================MENU DE VENTAS===================="<<endl;
    while (menu==1) {
        cout << "INGRESE EL NOMBRE DEL CLIENTE: ";
        cin >> cliente[c];
        if (cliente[c] == "*")
            break;
        suma_subtotal = 0;
        while (menu==1) {
            cout << "INGRESE EL PRODUCTO A VENDER: ";
            cin>>nombre;
            if (nombre == "*")
                break;
            pos = buscar(nombre);
            if (pos == -1)
                cout << "EL PRODUCTO NO EXISTE\n";
            else
                if (existencia[pos] < 1)
                cout << "NO HAY EXISTENCIA DISPONIBLE DE ESTE PRODUCTO\n";
            else {
                i = pos;
                cout << "INGRESE CANTIDAD A VENDER: ";
                cin>>cant;
                if (cant > existencia[i]) {
                    do {
                        cout << "NO HAY STOCK DISPONIBLES, DESEA REALIZAR VENTA?\n";
                        cout << "1. SI\n";
                        cout << "2. NO\n";
                        cin>>opc;
                        switch (opc) {
                            case 1:
                            {
                                subtotal[i] = existencia[i] * pv[i];
                                cantidad[i] = existencia[i] + cantidad[i];
                                existencia[i] = 0;
                            }
                                break;
                            case 2:
                                break;
                            default:
                                cout << "OPCION NO VALIDA\n";
                        }
                    } while (opc > 2);
                } else {
                    subtotal[i] = cant * pv[i];
                    existencia[i] = existencia[i] - cant;
                    cantidad[i] = cant + cantidad[i];
                }
                subtotal_2[i] = subtotal[i] + subtotal_2[i];
                suma_subtotal = subtotal[i] + suma_subtotal;
            }
            cout<<"DESEA REALIZAR OTRA COMPRA? "<<endl;
            cout<<"1. SI "<<endl;
            cout<<"2. NO "<<endl;
            cin>>menu;
            
        }
        total_cliente[c] = suma_subtotal;
        c++;
        check_sell = 1;
    }
    for (j = 0; j != c; j++){
        total_vendedor[i_bv] = total_cliente[j] + total_vendedor[i_bv];
        egresos_vendedor[i_bv]=cantidad[i]*pc[i];
    }
    cout << endl;
    cout << "VENDEDOR: " << user_seller[i_bv] << endl;
    cout << "PRODUCTO " << setw(10) << "CANTIDAD" << setw(16) << "PRECIO UNITARIO" << setw(10) << "SUBTOTAL\n";
    for (i = 0; i < total; i++)
        if (st[i] == 1 && cantidad[i] > 0)
            cout << setw(8) << producto[i] << setw(10) << cantidad[i] << setw(16) << pv[i] << setw(10) << subtotal_2[i] << endl;
    cout << setw(41) << "Total: $" << total_vendedor[i_bv] << endl;
}

int buscar_a(string admin) {
    i_ba = 0;
    while (i_ba < total_admin && user_admin[i_ba] != admin)
        i_ba++;
    if (i_ba == total_admin)
        return -1;
    else
        if (st_admin[i_ba] == 0) {
        return -2;
    } else
        return i_ba;
}

int buscar_v(string seller) {
    i_bv = 0;
    while (i_bv < total_seller && user_seller[i_bv] != seller)
        i_bv++;
    if (i_bv == total_seller)
        return -1;
    else
        if (st_seller[i_bv] == 0) {
        return -2;
    } else
        return i_bv;
}


int buscar(string name) {
    i_b = 0;
    while (i_b < total && producto[i_b] != name)
        i_b++;
    if (i_b == total)
        return -1;
    else
        if (st[i_b] == 0) {
        return -2;
    } else
        return i_b;
}

void Administrador() {
    int opc;
    do {
        cout << "====================MENU DEL PUNTO DE VENTA====================\n";
        cout << "1. AGREGAR USUARIOS\n";
        cout << "2. ELIMINAR USUARIOS\n";
        cout << "3. VENDER PRODUCTOS\n";
        cout << "4. CONSULTAS\n";
        cout << "5. MODIFICACIONES\n";
        cout << "6. MOSTRAR INVENTARIO\n";
        cout << "7. ADMINISTRAR USUARIOS\n";
        cout << "8. SALIR\n";
        cout << "OPCION: ";
        cin>>opc;
        switch (opc) {
            case 1: Altas();
                break;
            case 2: Bajas();
                break;
            case 3: Ventas();
                break;
            case 4: Consultas();
                break;
            case 5: Modificaciones();
                break;
            case 6: Inventario();
                break;
            case 7: Usuarios();
                break;
            case 8:
            {
                    for (int j = 0; j < total_seller; j++){
                        gran_total = total_vendedor[j] + gran_total;
                        egresos_total=egresos_vendedor[j]+egresos_total;
                    }
                    cout << setw(30) << "TICKET DE VENTA\n";
                    cout << endl;
                    cout << "PRODUCTO" << setw(10) << "CANTIDAD" << setw(16) << "PRECIO-UNITARIO" << setw(10) << "SUBTOTAL\n";
                    for (int i = 0; i < total; i++)
                        if (st[i] == 1 && cantidad[i] > 0)
                            cout << setw(8) << producto[i] << setw(10) << cantidad[i] << setw(16) << pv[i] << setw(10) << subtotal_2[i] << endl;
                    cout << setw(41) << "TOTAL: $" << gran_total << endl;
                    cout<<endl;
            }
                break;
            default: cout << "OPCION NO VALIDA\n";
        }
    } while (opc != 8);
}

void Altas() {
    int pos;
    int opc;
    int menu;
    int i;
    menu=1;
    string nombre;
    cout << "====================MENU PARA DAR DE ALTA PRODUCTOS====================\n";
    while (menu==1) {
        cout << "INGRESE EL NOMBRE DE UN PRODUCTO: ";
        cin>>nombre;
        if (nombre == "*")
            break;
        pos = buscar(nombre);
        if (pos == -1) {
            i = total;
            do {
                cout << "INGRESE EL PRECIO DEL PRODUCTO PARA SU COMPRA: ";
                cin >> pc[i];
                cout << "INGRESE EL PRECIO DEL PRODUCTO PARA SU VENTA: ";
                cin >> pv[i];
                if (pv[i] <= pc[i])
                    cout << "EL PRECIO DE VENTA DEBE SER MAYOR AL PRECIO DE COMPRA\n";
            } while (pv[i] <= pc[i]);
            do {
                cout << "INGRESE CANTIDAD EN EXISTENCIA (STOCK): ";
                cin >> existencia[i];
            } while (existencia[i] <= nr[i]);
            id[i] = i + 1;
            producto[i] = nombre;
            st[i] = 1;
            i++;
            total = i;
            cout << "EL PRODUCTO HA SIDO DADO DE ALTA CORRECTAMENTE!\n";
        } else
            cout << "EL PRODUCTO INGRESADO YA EXISTE\n";
        cout<<"DESEA DAR DE ALTA OTRO PRODUCTO? "<<endl;
        cout<<"1. SI "<<endl;
        cout<<"2. NO "<<endl;
        cin>>menu;
    }
}

void Bajas() {
    int i;
    int pos;
    int opc;
    int menu;
    menu=1;
    string nombre;
    cout << "====================MENU PARA DAR DE BAJA PRODUCTOS====================\n";
    while (menu==1) {
        cout << "INGRESE EL PRODUCTO: ";
        cin>>nombre;
        if (nombre == "*")
            break;
        pos = buscar(nombre);
        if (pos == -1)
            cout << "El PRODUCTO INGRESADO NO EXISTE\n";
        if (pos == -2)
        {
            cout << "El PRODUCTO INGRESADO YA ESTA DADO DE BAJA\n";
        }
        else
        {
            i = pos;
            while (true) {
                cout << "REALMENTE DESEA DAR DE BAJA EL PRODUCTO?\n";
                cout << "1. SI\n";
                cout << "2. NO\n";
                cin >> opc;
                switch (opc) {
                    case 1:
                    {
                        st[i] = 0;
                        cout << "EL PRODUCTO FUE DADO DE BAJA EXITOSAMENTE\n";
                    }
                        break;
                    case 2:
                        break;
                    default: cout << "OPCION INGRESADA NO VALIDA\n";
                }
                if (opc < 3)
                    break;
            }
        }
        cout<<"DESEA DAR DE BAJA OTRO PRODUCTO? "<<endl;
        cout<<"1. SI "<<endl;
        cout<<"2. NO "<<endl;
        cin>>menu;
    }

}

void Consultas() {
    int i;
    int pos;
    int opc;
    int menu;
    menu=1;
    string nombre;
    cout << "====================MENU PARA CONSULTAR PRODUCTOS====================\n";
    while (menu==1) {
        cout << "INGRESE EL PRODUCTO: ";
        cin>>nombre;
        if (nombre == "*")
            break;
        pos = buscar(nombre);
        if (pos == -1) {
            i = total;
                cout << "EL PRODUCTO INGRESADO NO EXISTE\n";
        } else
            {
            i = pos;
            cout << "RESULTADOS DEL PRODUCTO: " << producto[i] << endl;
            cout << setw(6) << "ID" << setw(12) << "PRODUCTO" << setw(6) << "COMPRA" << setw(6) << "VENTA" << setw(14) << "EXISTENCIA" << endl;
            cout << setw(5) << id[i] << setw(12) << producto[i] << setw(7) << pc[i] << setw(6) << pv[i] << setw(9) << existencia[i];
            if (existencia[i] <= nr[i])
                cout << "*\n";
            else
                cout << endl;
        }
        cout<<"DESEA CONSULTAR OTRO PRODUCTO? "<<endl;
        cout<<"1. SI "<<endl;
        cout<<"2. NO "<<endl;
        cin>>menu;
    }
}

void Modificaciones() {
    int i;
    int opc;
    int pos;
    int menu;
    menu=1;
    string nombre;
    cout << "====================MENU PARA MODIFICAR PRODUCTOS====================\n";
    while (menu==1) {
        cout << "INGRESE EL PRODUCTO QUE DESEA MODIFICAR: ";
        cin>>nombre;
        if (nombre == "*")
            break;
        pos = buscar(nombre);
        if (pos == -1)
        {
            cout << "EL PRODUCTO INGRESADO NO EXISTE\n";
        }
        else {
            i = pos;
            while (true) {
                cout << "INGRESE LA OPCION QUE DESEA MODIFICAR\n";
                cout << "1. PRECIO DE COMPRA\n";
                cout << "2. PRECIO DE VENTA\n";
                cout << "3. EXISTENCIA\n";
                cout << "4. TODO\n";
                cout << "5. Regresar\n";
                cin>>opc;
                switch (opc) {
                    case 1:
                    {
                        cout << "INGRESE EL NUEVO PRECIO DE COMPRA: ";
                        cin >> pc[i];
                        cout << "EL PRECIO DE COMPRA HA SIDO MODIFICADO EXITOSAMENTE\n";
                    }
                        break;
                    case 2:
                    {
                        cout << "INGRESE EL NUEVO PRECIO DE VENTA: ";
                        cin >> pv[i];
                        cout << "EL PRECIO DE COMPRA HA SIDO MODIFICADO EXITOSAMENTE\n";
                    }
                        break;
                    case 3:
                    {
                        cout << "INGRESE LA NUEVA EXISTENCIA: ";
                        cin >> existencia[i];
                        cout << "LA EXISTENCIA HA SIDO MODIFICADO EXITOSAMENTE\n";
                    }
                        break;

                    case 4:
                    {
                        cout << "DATOS DEL PRODUCTO:\n";
                        cout << setw(6) << "ID" << setw(12) << "PRODUCTO" << setw(6) << "COMPRA" << setw(6) << "VENTA" << setw(14) << "EXISTENCIA" << endl;
                        cout << setw(5) << id[i] << setw(12) << producto[i] << setw(7) << pc[i] << setw(6) << pv[i] << setw(9) << existencia[i] << endl;
                        cout << "INGRESE LOS NUEVOS DATOS DEL PRODUCTO:\n";
                        cout << "PRECIO DE COMPRA: ";
                        cin >> pc[i];
                        cout << "PRECIO DE VENTA: ";
                        cin >> pv[i];
                        cout << "EXISTENCIA: ";
                        cin >> existencia[i];
                        cout << "LOS DATOS DEL PRODUCTO HAN SIDO MODIFICADOS CORRECTAMENTE\n";
                    }
                        break;
                    case 5:
                        break;
                    default: cout << "OPCION INGRESADA NO VALIDA\n";
                }
                if (opc == 5)
                    break;
            }
        }
        cout<<"DESEA MODIFICAR OTRO PRODUCTO? "<<endl;
        cout<<"1. SI "<<endl;
        cout<<"2. NO "<<endl;
        cin>>menu;
    }
}

void Inventario() {
    int i, j, k;
    int opc;
    string salir;
    string temp_prod;
    int temp_id, temp_pc, temp_pv, temp_exist, temp_nr, temp_st;
    cout << "====================MENU PARA INVENTARIO DE PRODUCTOS====================\n";
            k = total;
            for (i = 0; i < k - 1; i++)
                for (j = 0; j < (k - 1) - i; j++)
                    if (id[j] > id[j + 1]) {
                        temp_id = id[j + 1];
                        id[j + 1] = id[j];
                        id[j] = temp_id;
                        temp_prod = producto[j + 1];
                        producto[j + 1] = producto[j];
                        producto[j] = temp_prod;
                        temp_pc = pc[j + 1];
                        pc[j + 1] = pc[j];
                        pc[j] = temp_pc;
                        temp_pv = pv[j + 1];
                        pv[j + 1] = pv[j];
                        pv[j] = temp_pv;
                        temp_exist = existencia[j + 1];
                        existencia[j + 1] = existencia[j];
                        existencia[j] = temp_exist;
                        temp_nr = nr[j + 1];
                        nr[j + 1] = nr[j];
                        nr[j] = temp_nr;
                        temp_st = st[j + 1];
                        st[j + 1] = st[j];
                        st[j] = temp_st;
                    }
            cout << setw(6) << "ID" << setw(12) << "NOMBRE" << setw(6) << "COMPRA" << setw(6) << "VENTA" << setw(14) << "STOCK" << endl;
            for (j = 0; j < k; j++) {
                if (st[j] == 1) {
                    cout << setw(5) << id[j] << setw(12) << producto[j] << setw(7) << pc[j] << setw(6) << pv[j] << setw(9) << existencia[j];
                    if (existencia[j] <= nr[j])
                        cout << "*\n";
                    else
                        cout << endl;
                }
            }
            while (true) {
                cout << "PRESIONE 1 PARA SALIR\n";
                cin>>salir;
                if (salir == "1")
                    break;
            }
}

void Usuarios() {
    int opc;
    do {
        cout << "====================MENU PARA ADMINISTRAR USUARIOS====================\n";
        cout << "1. AGREGAR USUARIOS\n";
        cout << "2. ELIMINAR USUARIOS\n";
        cout << "3. MODIFICAR USUARIOS\n";
        cout << "4. MOSTRAR USUARIOS\n";
        cout << "5. REGRESAR\n";
        cout << "INGRESE UNA OPCION: ";
        cin>>opc;
        switch (opc) {
            case 1: Altas_u();
                break;
            case 2: Bajas_u();
                break;
            case 3: Modificaciones_u();
                break;
            case 4: Mostrar_u();
                break;
            case 5:
                break;
            default: cout << "OPCION INGRESADA NO VALIDA\n";
        }
    } while (opc != 5);
}

void Altas_u() {
    int i;
    int pos;
    int opc;
    int menu;
    menu=1;
    int pass1;
    int pass2;
    string usuario;
    cout << "====================MENU PARA DAR DE ALTA A USUARIOS====================\n";
    do {
        cout << "INGRESE EL TIPO DE USUARIO QUE DESEA DAR DE ALTA\n";
        cout << "1. ADMINISTRADOR\n";
        cout << "2. VENDEDOR\n";
        cout << "3. REGRESAR\n";
        cin>>opc;
        switch (opc) {
            case 1:
            {
                while (menu==1) {
                    cout << "INGRESE EL USUARIO QUE DESEA DAR DE ALTA: ";
                    cin>>usuario;
                    if (usuario == "*")
                        break;
                    pos = buscar_a(usuario);
                    if (pos == -1) {
                        i = total_admin;
                        do {
                            cout << "INGRESE LA CONTRASENA DEL USUARIO " << usuario << ": ";
                            cin>>pass1;
                            cout << "CONFIRME LA CONTRASENA: ";
                            cin>>pass2;
                            if (pass1 == pass2) {
                                pass_a[i] = pass2;
                                break;
                            } else
                                cout << "LAS CONTRASEÑAS NO COINCIDEN, INGRESELA DE NUEVO\n";
                        } while (pass1 != pass2);
                        user_admin[i] = usuario;
                        st_admin[i] = 1;
                        cout << pass_a[i];
                        i++;
                        total_admin = i;
                        cout << "EL USUARIO HA SIDO DADO DE ALTA EXITOSAMENTE\n";
                    } else
                        cout << "EL USUARIO " << user_admin[pos] << " YA EXISTE\n";
                        cout<<"DESEA DAR DE ALTA OTRO USUARIO?"<<endl;
                        cout<<"1. SI"<<endl;
                        cout<<"2. NO"<<endl;
                        cin>>menu;
                }
            }
                break;
            case 2:
            {
                while (menu==1) {
                    cout << "INGRESE EL USUARIO QUE DESEA DAR DE ALTA: ";
                    cin>>usuario;
                    if (usuario == "*")
                        break;
                    pos = buscar_v(usuario);
                    if (pos == -1) {
                        i = total_seller;
                        do {
                            cout << "INGRESE LA CONTRASEÑA DEL USUARIO " << usuario << ": ";
                            cin>>pass1;
                            cout << "CONFIRME LA CONTRASENA: ";
                            cin>>pass2;
                            if (pass1 == pass2) {
                                pass_v[i] = pass2;
                                break;
                            } else
                                cout << "LAS CONTRASENAS NO COINCIDEN, INGRESE DE NUEVO\n";
                        } while (pass1 != pass2);
                        user_seller[i] = usuario;
                        st_seller[i] = 1;
                        cout << pass_v[i];
                        i++;
                        total_seller = i;
                        cout << "EL USUARIO HA SIDO DADO DE ALTA EXITOSAMENTE\n";
                    } else
                        cout << "EL USUARIO " << user_seller[pos] << " YA EXISTE\n";
                        cout<<"DESEA DAR DE ALTA OTRO USUARIO?"<<endl;
                        cout<<"1. SI"<<endl;
                        cout<<"2. NO"<<endl;
                        cin>>menu;
                }
            }
                break;
            case 3:
                break;
            default: cout << "OPCION INGRESADA NO VALIDA\n";
        }
        break;
    } while (opc != 3);

}

void Bajas_u() {
    int i;
    int pos;
    int opc;
    int menu;
    menu=1;
    string usuario;
    cout << "====================MENU PARA DAR DE BAJA A USUARIOS====================\n";
    do {
        cout << "SELECCIONE QUE TIPO DE USUARIO QUIERE DAR DE BAJA\n";
        cout << "1. ADMINISTRADOR\n";
        cout << "2. VENDEDOR\n";
        cout << "3. REGRESAR\n";
        cin>>opc;
        switch (opc) {
            case 1:
            {
                while (menu==1) {
                    cout << "INGRESE EL USUARIO QUE QUIERE DAR DE BAJA: ";
                    cin>>usuario;
                    if (usuario == "*")
                        break;
                    pos = buscar_a(usuario);
                    if (pos == -1)
                        cout << "EL USUARIO: " << usuario << ", NO EXISTE\n";
                    else
                        if (pos == -2)
                        cout << "EL USUARIO: " << usuario << ", YA ESTA DADO DE BAJA\n";
                    else {
                        i = pos;
                        st_admin[i] = 0;
                        cout << "EL USUARIO HA SIDO DADO DE BAJA EXITOSAMENTE\n";
                    }
                        cout<<"DESEA DAR DE BAJA OTRO USUARIO?"<<endl;
                        cout<<"1. SI"<<endl;
                        cout<<"2. NO"<<endl;
                        cin>>menu;
                }
            }
                break;
            case 2:
            {
                while (true) {
                    cout << "INGRESE EL USUARIO QUE DESEA DAR DE BAJA: ";
                    cin>>usuario;
                    if (usuario == "*")
                        break;
                    pos = buscar_v(usuario);
                    if (pos == -1)
                        cout << "EL USUARIO: " << usuario << ", NO EXISTE\n";
                    else
                        if (pos == -2)
                        cout << "EL USUARIO: " << usuario << ", YA ESTA DADO DE BAJA\n";
                    else {
                        i = pos;
                        st_seller[i] = 0;
                        cout << "EL USUARIO HA SIDO DADO DE BAJA EXITOSAMENTE\n";
                        }
                        
                    }
        }
        break;
    } 
    }while (opc != 3);
}
void Consultas_u() {
    int i;
    int pos;
    int opc;
    int pass1;
    int pass2;
    string usuario;
    cout << "====================MENU PARA LA CONSULTA DE USUARIOS===================\n";
    do {
        cout << "SELECCIONE EL TIPO DE USUARIO QUE DESEA ELIMINAR\n";
        cout << "1. ADMINISTRADOR\n";
        cout << "2. VENDEDOR\n";
        cout << "3. REGRESAR\n";
        cin>>opc;
        switch (opc) {
            case 1:
            {
                while (true) {
                    cout << "INGRESE EL USUARIO A ELIMINAR: ";
                    cin>>usuario;
                    if (usuario == "*")
                        break;
                    pos = buscar_a(usuario);
                    if (pos == -1) {
                        i = total_admin;
                        while (true) {
                            cout << "EL USUARIO INGRESADO NO EXISTE\n";
                            break;
                        }
                    }else {
                        i = pos;
                        cout << "DATOS DEL USUARIO: " << user_admin[i] << endl;
                        cout << setw(6) << "NOMBRE" << setw(14) << "CONTRASENA" << setw(8) << "TIPO" << endl;
                        cout << setw(5) << user_admin[i] << setw(10) << pass_a[i] << setw(20) << "ADMINISTRADOR" << endl;
                    }
                }
            }
                break;
            case 2:
            {
                while (true) {
                    cout << "INGRESE EL USUARIO A ELIMINAR: ";
                    cin>>usuario;
                    if (usuario == "*")
                        break;
                    pos = buscar_v(usuario);
                    if (pos == -1) {
                        i = total_seller;
                        while (true) {
                            cout << "EL USUARIO INGRESADO NO EXISTE\n";
                        }
                    } else {
                        i = pos;
                        cout << "DATOS DEL USUARIO: " << user_seller[i] << endl;
                        cout << setw(6) << "NOMBRE" << setw(14) << "CONTRASENA" << setw(8) << "TIPO" << endl;
                        cout << setw(5) << user_seller[i] << setw(10) << pass_v[i] << setw(20) << "VENDEDOR" << endl;
                    }
                }
            }
                break;
            case 3:
                break;
            default: cout << "OPCION INGRESADA NO VALIDA\n";
        }
        break;
    } while (opc != 3);
}

void Modificaciones_u() {
    int i;
    int opc;
    int pos;
    string usuario;
    cout << "====================MENU PARA MODIFICACION DE USUARIOS===================\n";
    do {
        cout << "SELECCIONE QUE TIPO DE USUARIO QUIERE MODIFICAR\n";
        cout << "1. ADMINISTRADOR\n";
        cout << "2. VENDEDOR\n";
        cout << "3. REGRESAR\n";
        cin>>opc;
        switch (opc) {
            case 1:
            {
                while (true) {
                    cout << "INGRESE EL USUARIO QUE DESEA MODIFICAR: ";
                    cin>>usuario;
                    if (usuario == "*")
                        break;
                    pos = buscar_a(usuario);
                    if (pos == -1)
                    {
                        cout << "EL USUARIO INGRESADO NO EXISTE\n";
                	}
                    else {
                        i = pos;
                        while (true) {
                            cout << "INDIQUE LO QUE DESEA MODIFICAR DEL USUARIO\n";
                            cout << "1. NOMBRE DEL USUARIO\n";
                            cout << "2. CONTRASEÑA DEL USUARIO\n";
                            cout << "3. REGRESAR\n";
                            cin>>opc;
                            switch (opc) {
                                case 1:
                                {
                                    cout << "INGRESE EL NUEVO NOMBRE DE USUARIO: ";
                                    cin >> user_admin[i];
                                    cout << "EL USUARIO FUE MODIFICADO CORRECTAMENTE\n";
                                }
                                    break;
                                case 2:
                                {
                                    cout << "INGRESE LA NUEVA CONTRASEÑA\n";
                                    cin >> pass_a[i];
                                    cout << "LA CONTRASEÑA FUE MODIFICADA CORRECTAMENTE\n";
                                }
                                    break;
                                case 3:
                                    break;
                                default: cout << "OPCION INGRESADA NO VALIDA\n";
                            }
                            if (opc == 3)
                                break;
                        }
                    }
                }
            }
                break;
            case 2:
            {
                while (true) {
                    cout << "SELECCIONE QUE TIPO DE USUARIO QUIERE MODIFICAR: ";
                    cin>>usuario;
                    if (usuario == "*")
                        break;
                    pos = buscar_v(usuario);
                    if (pos == -1)
                    {
                        cout << "EL USUARIO NO EXISTE\n";
                	}
                    else {
                        i = pos;
                        while (true) {
                            cout << "INDIQUE LO QUE DESEA MODIFICAR DEL USUARIO\n";
                            cout << "1. NOMBRE DEL USUARIO\n";
                            cout << "2. CONTRASEÑA DEL USUARIO\n";
                            cout << "3. Regresar\n";
                            cin>>opc;
                            switch (opc) {
                                case 1:
                                {
                                    cout << "INGRESE EL NUEVO NOMBRE DE USUARIO: ";
                                    cin >> user_seller[i];
                                    cout << "EL NOMBRE DEL USUARIO FUE MODIFICADO CORRECTAMENTE\n";
                                }
                                    break;
                                case 2:
                                {
                                    cout << "INGRESE LA NUEVA CONTRASEÑA ";
                                    cin >> pass_v[i];
                                    cout << "LA CONTRASEÑA DEL USUARIO FUE MODIFICADA CORRECTAMENTE\n";
                                }
                                    break;
                                case 3:
                                    break;
                                default: cout << "OPCION INGRESADA NO VALIDA\n";
                            }
                            if (opc == 3)
                                break;
                        }
                    }
                }
            }
                break;
            case 3:
                break;
            default: cout << "OPCION INGRESADA NO VALIDA\n";
        }
        break;
    } while (opc != 3);
}

void Mostrar_u() {
    int i;
    int opc;
    string salir;
    while (true) {
        cout << "====================MENU PARA VER INFORMACION DE USUARIOS===================\n";
        cout << "1. MOSTRAR USUARIOS ADMINISTRADORES\n";
        cout << "2. MOSTRAR USUARIOS VENDEDORES\n";
        cout << "3. SALIR\n";
        cin>>opc;
        switch (opc) {
            case 1:
            {
                cout << "====================MENU PARA VER INFORMACION DE USUARIOS ADMINISTRADORES===================\n";
                cout << setw(6) << "NOMBRE" << setw(14) << "CONTRASEÑA" << setw(8) << "TIPO" << endl;
                for (i = 0; i < total_admin; i++) {
                    if (st_seller[i] == 1)
                        cout << setw(5) << user_admin[i] << setw(10) << pass_a[i] << setw(20) << "ADMINISTRADOR" << endl;
                }
                while (true) {
                    cout << "PRESIONE 1 PARA SALIR\n";
                    cin>>salir;
                    if (salir == "1")
                        break;
                }
            }
                break;
            case 2:
            {
                cout << "====================MENU PARA VER INFORMACION DE USUARIOS VENDEDORES===================\n";
                cout << setw(6) << "NOMBRE" << setw(14) << "CONTRASEÑA" << setw(8) << "TIPO" << endl;
                for (i = 0; i < total_seller; i++) {
                    if (st_seller[i] == 1)
                        cout << setw(5) << user_seller[i] << setw(10) << pass_v[i] << setw(15) << "VENDEDOR" << endl;
                }
                while (true) {
                    cout << "PRESIONE 1 PARA SALIR\n";
                    cin>>salir;
                    if (salir == "1")
                        break;
                }
            }
                break;
            case 3:
                break;
            default: cout << "OPCION INGRESADA NO VALIDA\n";
        }
        break;
    }
}

