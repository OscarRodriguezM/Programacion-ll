#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int buscar(string name);

void Administrador();
void Altas();
void Bajas();
void Consultas();
void Modificaciones();
void Inventario();
void Usuarios();

void Altas_u();
void Bajas_u();
void Consultas_u();
void Modificaciones_u();
void Mostrar_u();

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

int id [100] = {1, 2, 3, 4, 5};
string producto [100] = {"AGUA", "LECHE", "HUEVOS", "PAN", "REFRESCO"};
int pc[100] = {10, 10, 10, 10, 10};
int pv[100] = {11, 11, 15, 20, 11};
int existencia [100] = {12, 23, 20, 20, 10};
int nr[100] = {8, 5, 5, 2, 3};
int st[100] = {1, 1, 1, 1, 1};
int total = 5;

int buscar_a(string admin);
string user_admin[100];
int pass_a[100];
int st_admin[100] = {1, 1};
int check_admin;
int total_admin = 2;

int buscar_v(string seller);
string user_seller[100];
int pass_v[100];
int st_seller[100] = {1, 1};
int check_seller;
int total_seller = 2;

int i_b;
int i_ba;
int i_bv;

int main() {
    int i;
    int j;
    int opc;
    Administrador();
}
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
    cout << "MENU DE VENTAS"<<endl;
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
            cout<<"DESEA REALIZAR OTRA COMPRA?";
            cout<<"1. SI";
            cout<<"2. NO";
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
    cout << "PRODUCTO " << setw(10) << "CANTIDAD" << setw(16) << "PRECIO UNITARIO" << setw(10) << "Subtotal\n";
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

void Verify_seller() {
    string usuario;
    int pos;
    int pass;
    int i;
    i = 0;
    while (i < 3) {
        cout << "INGRESE NOMBRE DE USUARIO DEL VENDEDOR: ";
        cin>>usuario;
        cout << "INGRESE LA CONTRASEï¿½A: ";
        cin>> pass;
        pos = buscar_v(usuario);
        if (pos == -1)
            cout << "USUARIO O CONTRASEï¿½A INCORRECTOS. QUEDAN: " << 2 - i << " INTENTOS\n";
        else
            if (pos == -2)
            cout << "EL USUARIO ESTA DADO DE BAJA\n";
        else
            if (pass == pass_v[pos]) {
            check_seller = 1;
            break;
        } else
            cout << "USUARIO O CONTRASEï¿½A INCORRECTOS. QUEDAN: " << 2 - i << " INTENTOS\n";
        i++;
    }
    if (i > 2)
        check_seller = 0;
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
        cout << "1. ALTAS\n";
        cout << "2. BAJAS\n";
        cout << "3. VENTAS\n";
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
                    cout<<"UTILIDADES: $"<<gran_total-egresos_total<<endl;
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
                    cout << "EL PRECIO DE VENTA DEBEB SER MAYOR AL PRECIO DE COMPRA\n";
            } while (pv[i] <= pc[i]);
            do {
                cout << "INGRESE CANTIDAD EN EXISTENCIA (STOCK): ";
                cin >> existencia[i];
                cout << "INGRESE EL NIVEL DE REORDEN: ";
                cin >> nr[i];
                if (existencia[i] <= nr[i])
                    cout << "LA EXISTENCIA DEBE SER MAYOR AL NIVEL DE REORDEN\n";
            } while (existencia[i] <= nr[i]);
            id[i] = i + 1;
            producto[i] = nombre;
            st[i] = 1;
            i++;
            total = i;
            cout << "EL PRODUCTO HA SIDO DADO DE ALTA CORRECTAMENTE!\n";
        } else
            cout << "EL PRODUCTO INGRESADO YA EXISTE\n";
        cout<<"DESEA DAR DE ALTA OTRO PRODUCTO?"<<endl;
        cout<<"1. SI"<<endl;
        cout<<"2. NO"<<endl;
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
        cout<<"DESEA DAR DE BAJA OTRO PRODUCTO?"<<endl;
        cout<<"1. SI"<<endl;
        cout<<"2. NO"<<endl;
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
            cout << setw(6) << "ID" << setw(12) << "Producto" << setw(6) << "PC" << setw(6) << "PV" << setw(14) << "Existencia" << setw(6) << "NR" << endl;
            cout << setw(5) << id[i] << setw(12) << producto[i] << setw(7) << pc[i] << setw(6) << pv[i] << setw(9) << existencia[i] << setw(11) << nr[i];
            if (existencia[i] <= nr[i])
                cout << "*\n";
            else
                cout << endl;
        }
        cout<<"DESEA CONSULTAR OTRO PRODUCTO?"<<endl;
        cout<<"1. SI"<<endl;
        cout<<"2. NO"<<endl;
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
    cout << "Modificaciones\n";
    while (menu==1) {
        cout << "Ingrese producto a Modificar: ";
        cin>>nombre;
        if (nombre == "*")
            break;
        pos = buscar(nombre);
        if (pos == -1)
            cout << "El producto: " << nombre << ", no existe\n";
        else
            if (pos == -2)
            cout << "El producto: " << nombre << ", estï¿½ dado de baja\n";
        else {
            i = pos;
            while (true) {
                cout << "QUE desea Modificar?\n";
                cout << "1. Precio de Compra\n";
                cout << "2. Precio de Venta\n";
                cout << "3. Existencia\n";
                cout << "4. Nivel de Reorden\n";
                cout << "5. TODO\n";
                cout << "6. Regresar\n";
                cin>>opc;
                switch (opc) {
                    case 1:
                    {
                        cout << "El Precio de Compra actual es de: " << pc[i] << endl << "Ingrese el nuevo Precio de Compra: ";
                        cin >> pc[i];
                        cout << "El Precio de Compra ha sido Modificado\n";
                    }
                        break;
                    case 2:
                    {
                        cout << "El Precio de Venta actual es de: " << pv[i] << endl << "Ingrese el nuevo Precio de Venta: ";
                        cin >> pv[i];
                        cout << "El Precio de Venta ha sido Modificado\n";
                    }
                        break;
                    case 3:
                    {
                        cout << "La Existencia actual es de: " << existencia[i] << endl << "Ingrese la nueva Existencia: ";
                        cin >> existencia[i];
                        cout << "La Existencia ha sido Modificada\n";
                    }
                        break;
                    case 4:
                    {
                        cout << "El Nivel de Reorden actual es de: " << nr[i] << endl << "Ingrese el nuevo Nivel de Reorden: ";
                        cin >> nr[i];
                        cout << "El Nivel de Reorden ha sido Modificado\n";
                    }
                        break;
                    case 5:
                    {
                        cout << "Datos actuales:\n";
                        cout << setw(6) << "ID" << setw(12) << "Producto" << setw(6) << "PC" << setw(6) << "PV" << setw(14) << "Existencia" << setw(6) << "NR" << endl;
                        cout << setw(5) << id[i] << setw(12) << producto[i] << setw(7) << pc[i] << setw(6) << pv[i] << setw(9) << existencia[i] << setw(11) << nr[i] << endl;
                        cout << "Ingrese los nuevos datos:\n";
                        cout << "Precio de compra: ";
                        cin >> pc[i];
                        cout << "Precio de Venta: ";
                        cin >> pv[i];
                        cout << "Existencia: ";
                        cin >> existencia[i];
                        cout << "Nivel de Reorden: ";
                        cin >> nr[i];
                        cout << "Los datos han sido Modificados\n";
                    }
                        break;
                    case 6:
                        break;
                    default: cout << "Opciï¿½n Invï¿½lida\n";
                }
                if (opc == 6)
                    break;
            }
        }
        cout<<"DESEA MODIFICAR OTRO PRODUCTO?"<<endl;
        cout<<"1. SI"<<endl;
        cout<<"2. NO"<<endl;
        cin>>menu;
    }
}

void Inventario() {
    int i, j, k;
    int opc;
    string salir;
    string temp_prod;
    int temp_id, temp_pc, temp_pv, temp_exist, temp_nr, temp_st;
    cout << "Inventario\n";
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
            cout << setw(6) << "ID" << setw(12) << "Producto" << setw(6) << "PC" << setw(6) << "PV" << setw(14) << "Existencia" << setw(6) << "NR" << endl;
            for (j = 0; j < k; j++) {
                if (st[j] == 1) {
                    cout << setw(5) << id[j] << setw(12) << producto[j] << setw(7) << pc[j] << setw(6) << pv[j] << setw(9) << existencia[j] << setw(11) << nr[j];
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
        cout << "Administrador de Usuarios\n";
        cout << "1. Alta de Usuarios\n";
        cout << "2. Baja de Usuarios\n";
        cout << "3. Consulta de Usuarios\n";
        cout << "4. Modificaciï¿½n de Usuarios\n";
        cout << "5. Mostrar Usuarios\n";
        cout << "6. Regresar\n";
        cout << "Opciï¿½n: ";
        cin>>opc;
        switch (opc) {
            case 1: Altas_u();
                break;
            case 2: Bajas_u();
                break;
            case 3: Consultas_u();
                break;
            case 4: Modificaciones_u();
                break;
            case 5: Mostrar_u();
                break;
            case 6:
                break;
            default: cout << "Opciï¿½n Invï¿½lida\n";
        }
    } while (opc != 6);
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
                            cout << "INGRESE LA CONTRASEÃ‘A DEL USUARIO " << usuario << ": ";
                            cin>>pass1;
                            cout << "CONFIRME LA CONTRASEÃ‘A: ";
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
                            cout << "CONFIRME LA CONTRASEÃ‘A: ";
                            cin>>pass2;
                            if (pass1 == pass2) {
                                pass_v[i] = pass2;
                                break;
                            } else
                                cout << "LAS CONTRASEÃ‘AS NO COINCIDEN, INGRESE DE NUEVO\n";
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
        cout << "ï¿½El usuario a dar de Baja es Administador o Vendedor?\n";
        cout << "1. Administrador\n";
        cout << "2. Vendedor\n";
        cout << "3. Regresar\n";
        cin>>opc;
        switch (opc) {
            case 1:
            {
                while (true) {
                    cout << "Ingrese usuario: ";
                    cin>>usuario;
                    if (usuario == "*")
                        break;
                    pos = buscar_a(usuario);
                    if (pos == -1) {
                        i = total_admin;
                        while (true) {
                            cout << "El usuario " << usuario << " no existe. ï¿½Desea darlo de Alta?\n";
                            cout << "1. Sï¿½\n" << "2. No\n";
                            cin >> opc;
                            switch (opc) {
                                case 1:
                                {
                                    do {
                                        cout << "Ingrese contraseï¿½a del usuario " << usuario << ": ";
                                        cin>>pass1;
                                        cout << "Confirme la contraseï¿½a: ";
                                        cin>>pass2;
                                        if (pass1 == pass2) {
                                            pass_a[i] = pass2;
                                            break;
                                        } else
                                            cout << "Las contraseï¿½as no coinciden, intente de nuevo\n";
                                    } while (pass1 != pass2);
                                    user_admin[i] = usuario;
                                    st_admin[i] = 1;
                                    cout << pass_a[i];
                                    i++;
                                    total_admin = i;
                                    cout << "El usuario ha sido dado de alta exitosamente\n";
                                }
                                    break;
                                case 2:
                                    break;
                                default: cout << "Opciï¿½n Invï¿½lida\n";
                            }
                            if (opc < 3)
                                break;
                        }
                    } else
                        if (pos == -2) {
                        i = i_ba;
                        while (true) {
                            cout << "El usuario " << usuario << " estï¿½ dado de baja, ï¿½Desea Reactivarlo?\n";
                            cout << "1. Sï¿½\n";
                            cout << "2. No\n";
                            cin >> opc;
                            switch (opc) {
                                case 1:
                                {
                                    do {
                                        cout << "Ingrese contraseï¿½a del usuario " << usuario << ": ";
                                        cin>>pass1;
                                        cout << "Confirme la contraseï¿½a: ";
                                        cin>>pass2;
                                        if (pass1 == pass2) {
                                            pass_a[i] = pass2;
                                            break;
                                        } else
                                            cout << "Las contraseï¿½as no coinciden, intente de nuevo\n";
                                    } while (pass1 != pass2);
                                    st_admin[i] = 1;
                                    cout << pass_a[i];
                                    cout << "El usuario ha sido reactivado exitosamente\n";
                                }
                                    break;
                                case 2:
                                    break;
                                default: cout << "Opciï¿½n Invï¿½lida\n";
                            }
                            if (opc < 3)
                                break;
                        }
                    } else {
                        i = pos;
                        cout << "Informaciï¿½n del Usuario: " << user_admin[i] << endl;
                        cout << setw(6) << "Nombre" << setw(14) << "Contraseï¿½a" << setw(8) << "Tipo" << endl;
                        cout << setw(5) << user_admin[i] << setw(10) << pass_a[i] << setw(20) << "Administrador" << endl;
                    }
                }
            }
                break;
            case 2:
            {
                while (true) {
                    cout << "Ingrese usuario: ";
                    cin>>usuario;
                    if (usuario == "*")
                        break;
                    pos = buscar_v(usuario);
                    if (pos == -1) {
                        i = total_seller;
                        while (true) {
                            cout << "El usuario " << usuario << " no existe. ï¿½Desea darlo de Alta?\n";
                            cout << "1. Sï¿½\n" << "2. No\n";
                            cin >> opc;
                            switch (opc) {
                                case 1:
                                {
                                    do {
                                        cout << "Ingrese contraseï¿½a del usuario " << usuario << ": ";
                                        cin>>pass1;
                                        cout << "Confirme la contraseï¿½a: ";
                                        cin>>pass2;
                                        if (pass1 == pass2) {
                                            pass_v[i] = pass2;
                                            break;
                                        } else
                                            cout << "Las contraseï¿½as no coinciden, intente de nuevo\n";
                                    } while (pass1 != pass2);
                                    user_seller[i] = usuario;
                                    st_seller[i] = 1;
                                    cout << pass_v[i];
                                    i++;
                                    total_seller = i;
                                    cout << "El usuario ha sido dado de alta exitosamente\n";
                                }
                                    break;
                                case 2:
                                    break;
                                default: cout << "Opciï¿½n Invï¿½lida\n";
                            }
                            if (opc < 3)
                                break;
                        }
                    } else
                        if (pos == -2) {
                        i = i_ba;
                        while (true) {
                            cout << "El usuario " << usuario << " estï¿½ dado de baja, ï¿½Desea Reactivarlo?\n";
                            cout << "1. Sï¿½\n";
                            cout << "2. No\n";
                            cin >> opc;
                            switch (opc) {
                                case 1:
                                {
                                    do {
                                        cout << "Ingrese contraseï¿½a del usuario " << usuario << ": ";
                                        cin>>pass1;
                                        cout << "Confirme la contraseï¿½a: ";
                                        cin>>pass2;
                                        if (pass1 == pass2) {
                                            pass_v[i] = pass2;
                                            break;
                                        } else
                                            cout << "Las contraseï¿½as no coinciden, intente de nuevo\n";
                                    } while (pass1 != pass2);
                                    st_seller[i] = 1;
                                    cout << pass_a[i];
                                    cout << "El usuario ha sido reactivado exitosamente\n";
                                }
                                    break;
                                case 2:
                                    break;
                                default: cout << "Opciï¿½n Invï¿½lida\n";
                            }
                            if (opc < 3)
                                break;
                        }
                    } else {
                        i = pos;
                        cout << "INFORMACION DEL USUARIO: " << user_seller[i] << endl;
                        cout << setw(6) << "Nombre" << setw(14) << "Contraseï¿½a" << setw(8) << "Tipo" << endl;
                        cout << setw(5) << user_seller[i] << setw(10) << pass_v[i] << setw(20) << "Vendedor" << endl;
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


