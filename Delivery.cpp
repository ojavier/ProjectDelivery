#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


//Las Clases Fecha y Hora no poseen relevancia para el prop�sito del programa,
//mas bien son clases auxiliares para poder tener un formato
class Fecha {
private:
    int dia;
    int mes;
    int a�o;

public:
    // Constructor
    Fecha(int d, int m, int a) : dia(d), mes(m), a�o(a) {}

    // Sobrecarga del operador de inserci�n <<
    friend std::ostream& operator<<(std::ostream& os, const Fecha& fecha) {
        os << fecha.dia << "/" << fecha.mes << "/" << fecha.a�o;
        return os;
    }
};

class Hora {
private:
    int horas;
    int minutos;

public:
    // Constructor
    Hora(int h, int m) : horas(h), minutos(m) {}

    // Sobrecarga del operador de inserci�n <<
    friend std::ostream& operator<<(std::ostream& os, const Hora& hora) {
        os << hora.horas << ":" << hora.minutos;
        return os;
    }
};


class Pago {
private:
    int idPago;
    int idUsuario;
    int idBoleto;
    Fecha fechaPago;
    float monto;

public:
    // Constructor
    Pago(int id, int idUsuarioPago, int idBoletoPago, const Fecha& fecha, float montoPago)
        : idPago(id), idUsuario(idUsuarioPago), idBoleto(idBoletoPago), fechaPago(fecha), monto(montoPago) {}

    // Getters
    int getIdPago() const {
        return idPago;
    }

    int getIdUsuario() const {
        return idUsuario;
    }

    int getIdBoleto() const {
        return idBoleto;
    }

    Fecha getFechaPago() const {
        return fechaPago;
    }

    float getMonto() const {
        return monto;
    }

    // Setters
    void setIdPago(int id) {
        idPago = id;
    }

    void setIdUsuario(int idUsuarioPago) {
        idUsuario = idUsuarioPago;
    }

    void setIdBoleto(int idBoletoPago) {
        idBoleto = idBoletoPago;
    }

    void setFechaPago(const Fecha& nuevaFecha) {
        fechaPago = nuevaFecha;
    }

    void setMonto(float nuevoMonto) {
        monto = nuevoMonto;
    }

    // Otros m�todos
    void realizarPago() {
        cout << "Realizando pago con ID: " << idPago << endl;
        // L�gica para realizar el pago
    }

    void cancelarPago() {
        cout << "Cancelando pago con ID: " << idPago << endl;
        // L�gica para cancelar el pago
    }
};

class Usuario; // Declaraci�n anticipada de la clase Usuario

class Boleto {
private:
    int idBoleto;
    string origen;
    string destino;
    Fecha fecha;
    Hora hora;
    Usuario* usuario;
    vector<Pago*> pagos;
    float costo;      // Atributo para el costo del boleto
    int asiento;      // Atributo para el n�mero de asiento asignado

public:
    // Constructor
    Boleto(int id, const string& origenBoleto, const string& destinoBoleto, const Fecha& fechaViaje, const Hora& horaViaje, float costoBoleto)
        : idBoleto(id), origen(origenBoleto), destino(destinoBoleto), fecha(fechaViaje), hora(horaViaje), usuario(nullptr), costo(costoBoleto), asiento(0) {}

    // Getters
    int getIdBoleto() const {
        return idBoleto;
    }

    string getOrigen() const {
        return origen;
    }

    string getDestino() const {
        return destino;
    }

    Fecha getFecha() const {
        return fecha;
    }

    Hora getHora() const {
        return hora;
    }

    Usuario* getUsuario() const {
        return usuario;
    }

    float getCosto() const {
        return costo;
    }

    int getAsiento() const {
        return asiento;
    }

    // Setter
    void setUsuario(Usuario* usuario) {
        this->usuario = usuario;
    }

    // Otros m�todos
    void realizarPago() {
        cout << "Realizando pago del boleto ID: " << idBoleto << endl;
        // L�gica de pago
    }

    void cancelarReserva() {
        cout << "Cancelando reserva del boleto ID: " << idBoleto << endl;
        // L�gica de cancelaci�n de reserva
    }

    void agregarPago(Pago* pago) {
        cout << "Agregando pago al boleto ID: " << idBoleto << endl;
        pagos.push_back(pago);
    }

    // Setters
    void setIdBoleto(int id) {
        idBoleto = id;
    }

    void setOrigen(const string& nuevoOrigen) {
        origen = nuevoOrigen;
    }

    void setDestino(const string& nuevoDestino) {
        destino = nuevoDestino;
    }

    void setFecha(const Fecha& nuevaFecha) {
        fecha = nuevaFecha;
    }

    void setHora(const Hora& nuevaHora) {
        hora = nuevaHora;
    }

    void setCosto(float nuevoCosto) {
        costo = nuevoCosto;
    }

    void setAsiento(int nuevoAsiento) {
        asiento = nuevoAsiento;
    }
};

class Persona {
protected:
    string nombre;
    int edad;
    int id;

public:
    Persona(const string& nombre, int edad, int id)
        : nombre(nombre), edad(edad), id(id) {}

    void mostrarInformacion() const {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "ID: " << id << endl;
    }

    string getNombre() const {
        return nombre;
    }

    void setNombre(const string& nuevoNombre) {
        nombre = nuevoNombre;
    }

    int getEdad() const {
        return edad;
    }

    void setEdad(int nuevaEdad) {
        edad = nuevaEdad;
    }

    int getID() const {
        return id;
    }

    void setID(int nuevoID) {
        id = nuevoID;
    }
};


class Usuario : public Persona {
private:
    string idUsuario;
    string correoElectronico;
    string contrase�a;
    vector<Boleto*> boletos;
    vector<Pago*> pagos;

public:
    Usuario(int id, const string& nombre, int edad, const string& correo, const string& contrasena)
        : Persona(nombre, edad, id), correoElectronico(correo), contrase�a(contrasena) {}

    void mostrarInformacion() const {
        Persona::mostrarInformacion();
        cout << "Correo: " << correoElectronico << endl;
        cout << "Contrase�a: " << contrase�a << endl;
    }

    void iniciarSesion() {
        cout << "Iniciando sesi�n como " << nombre << endl;
        // L�gica de inicio de sesi�n
    }

    void realizarReserva(Boleto* boleto) {
        cout << "Realizando reserva del boleto ID: " << boleto->getIdBoleto() << " para el usuario " << nombre << endl;
        // L�gica para realizar la reserva
    }

    void cancelarReserva(Boleto* boleto) {
        cout << "Cancelando reserva del boleto ID: " << boleto->getIdBoleto() << " para el usuario " << nombre << endl;
        // L�gica para cancelar la reserva
    }

    void agregarBoleto(Boleto* boleto) {
        cout << "Agregando boleto ID: " << boleto->getIdBoleto() << " al usuario " << nombre << endl;
        boletos.push_back(boleto);
    }

    void agregarPago(Pago* pago) {
        cout << "Agregando pago al usuario " << nombre << endl;
        pagos.push_back(pago);
    }

    string getCorreoElectronico() const {
        return correoElectronico;
    }

    void setCorreoElectronico(const string& nuevoCorreo) {
        correoElectronico = nuevoCorreo;
    }

    string getContrase�a() const {
        return contrase�a;
    }

    void setContrase�a(const string& nuevaContrase�a) {
        contrase�a = nuevaContrase�a;
    }
};

class Conductor : public Persona {
private:
    int idConductor;

public:
    Conductor(const std::string& nombre, int edad, int id, int idConductor)
        : Persona(nombre, edad, id), idConductor(idConductor) {}

    void mostrarInformacion() const {
        cout << "--- Informaci�n del Conductor ---" << endl;
        Persona::mostrarInformacion();
        cout << "ID Conductor: " << idConductor << endl;
    }

    int getIDConductor() const {
        return idConductor;
    }

    void setIDConductor(int nuevoIDConductor) {
        idConductor = nuevoIDConductor;
    }
};

// Declaraci�n anticipada de la clase Autobus
class Autobus;

class Ruta {
private:
    int idRuta;
    string origen;
    string destino;
    Autobus* autobus;  // Relaci�n de agregaci�n con la clase Autobus

public:
    // Constructor
    Ruta(int id, const string& origenRuta, const string& destinoRuta)
        : idRuta(id), origen(origenRuta), destino(destinoRuta), autobus(nullptr) {}

    // Getters
    int getIdRuta() const {
        return idRuta;
    }

    string getOrigen() const {
        return origen;
    }

    string getDestino() const {
        return destino;
    }

    Autobus* getAutobus() const {
        return autobus;
    }

    // Otros m�todos
    void agregarRuta() {
        std::cout << "Ruta agregada con ID: " << idRuta << std::endl;
        // L�gica para agregar la ruta
    }

    void eliminarRuta() {
        std::cout << "Ruta eliminada con ID: " << idRuta << std::endl;
        // L�gica para eliminar la ruta
    }

    // Setters
    void setIdRuta(int id) {
        idRuta = id;
    }

    void setOrigen(const string& nuevoOrigen) {
        origen = nuevoOrigen;
    }

    void setDestino(const string& nuevoDestino) {
        destino = nuevoDestino;
    }

    void setAutobus(Autobus* nuevoAutobus) {
        autobus = nuevoAutobus;
    }
};


class Autobus : public Conductor {
private:
    int idAutobus;
    string modelo;
    int capacidadMaxima;
    Ruta* ruta;  // Relaci�n de agregaci�n con la clase Ruta
    vector<Boleto*> boletos;  // Relaci�n de agregaci�n con la clase Boleto

public:
    // Constructor
    Autobus(int id, const string& modeloAutobus, int capacidad, const string& conductorAutobus, int idConductor)
        : Conductor(conductorAutobus, 0, id, idConductor), idAutobus(id), modelo(modeloAutobus), capacidadMaxima(capacidad), ruta(nullptr) {}

    // Getters
    int getIdAutobus() const {
        return idAutobus;
    }

    string getModelo() const {
        return modelo;
    }

    int getCapacidadMaxima() const {
        return capacidadMaxima;
    }

    Ruta* getRuta() const {
        return ruta;
    }

    const vector<Boleto*>& getBoletos() const {
        return boletos;
    }

    // Otros m�todos
    bool verificarDisponibilidad() {
        // L�gica para verificar la disponibilidad del autob�s
    }

    void reservarAsiento() {
        // L�gica para reservar un asiento en el autob�s
    }

    // M�todo para agregar un boleto al autob�s
    void agregarBoleto(Boleto* boleto) {
        boletos.push_back(boleto);
    }

    // Setters
    void setIdAutobus(int id) {
        idAutobus = id;
    }

    void setModelo(const string& nuevoModelo) {
        modelo = nuevoModelo;
    }

    void setCapacidadMaxima(int capacidad) {
        capacidadMaxima = capacidad;
    }

    void setRuta(Ruta* nuevaRuta) {
        ruta = nuevaRuta;
    }
};


void verHistorialBoletos() {
    vector<Boleto*> boletos;

    ifstream archivo("boletos.txt");
    if (archivo.is_open()) {
        int idBoleto, costo, asiento;
        string origen, destino;
        int dia, mes, a�o;
        int horas, minutos;

        while (archivo >> idBoleto >> origen >> destino >> dia >> mes >> a�o >> horas >> minutos >> costo >> asiento) {
            Fecha fecha(dia, mes, a�o);
            Hora hora(horas, minutos);

            Boleto* boleto = new Boleto(idBoleto, origen, destino, fecha, hora, costo);
            boleto->setAsiento(asiento);

            boletos.push_back(boleto);
        }

        archivo.close();
    }

    if (boletos.empty()) {
        cout << "No hay boletos registrados." << endl;
    }
    else {
        cout << "Historial de Boletos:" << endl;
        for (const auto& boleto : boletos) {
            cout << "ID del Boleto: " << boleto->getIdBoleto() << endl;
            cout << "Origen: " << boleto->getOrigen() << endl;
            cout << "Destino: " << boleto->getDestino() << endl;
            cout << "Fecha: " << boleto->getFecha() << endl;
            cout << "Hora: " << boleto->getHora() << endl;
            cout << "Costo: " << boleto->getCosto() << endl;
            cout << "Asiento: " << boleto->getAsiento() << endl;
            cout << "------------------------" << endl;
        }
    }
}


// Funci�n para liberar memoria de los objetos creados
template<typename T>
void liberarMemoria(const vector<T*>& objetos) {
    for (const auto& objeto : objetos) {
        delete objeto;
    }
}

int main() {
    // Variables necesarias
    vector<Usuario*> usuarios;
    vector<Autobus*> autobuses;
    vector<Ruta*> rutas;

    int opcion;

    do {
        // Mostrar opciones del men�
        cout << "" << endl;
        cout << "===== MEN� =====" << endl;
        cout << "1. Crear usuario" << endl;
        cout << "2. Mostrar informaci�n de usuario" << endl;
        cout << "3. Crear autob�s" << endl;
        cout << "4. Mostrar informaci�n de autob�s" << endl;
        cout << "5. Crear ruta" << endl;
        cout << "6. Mostrar informaci�n de ruta" << endl;
        cout << "7. Ver historial de boletos" << endl;
        cout << "8. Salir" << endl;
        cout << "Ingrese una opci�n: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            // L�gica para crear un nuevo usuario
            int idUsuario;
            string nombreUsuario, correo, contrasena;

            cout << "Ingrese el ID del usuario: ";
            cin >> idUsuario;

            cout << "Ingrese el nombre del usuario: ";
            cin >> nombreUsuario;

            cout << "Ingrese el correo electr�nico del usuario: ";
            cin >> correo;

            cout << "Ingrese la contrase�a del usuario: ";
            cin >> contrasena;

            Usuario* nuevoUsuario = new Usuario(idUsuario, nombreUsuario, idUsuario, correo, contrasena);

            cout << "Usuario creado exitosamente." << endl;
            break;
        }

        case 2: {
            // L�gica para mostrar informaci�n de un usuario
            int idUsuario;

            cout << "Ingrese el ID del usuario: ";
            cin >> idUsuario;

            bool encontrado = false;
            for (const auto& usuario : usuarios) {
                if (usuario->getID() == idUsuario) {
                    usuario->mostrarInformacion();
                    encontrado = true;
                    break;
                }
            }

            if (!encontrado) {
                cout << "Usuario no encontrado." << endl;
            }
            break;
        }

        case 3: {
            // L�gica para crear un nuevo autob�s
            int idAutobus, capacidad, idConductor;
            string modeloAutobus, conductorAutobus;

            cout << "Ingrese el ID del autob�s: ";
            cin >> idAutobus;

            cout << "Ingrese el modelo del autob�s: ";
            cin >> modeloAutobus;

            cout << "Ingrese el conductor del autob�s: ";
            cin >> conductorAutobus;

            cout << "Ingrese la capacidad m�xima del autob�s: ";
            cin >> capacidad;

            cout << "Ingrese el ID del conductor: ";
            cin >> idConductor;

            Autobus* nuevoAutobus = new Autobus(idAutobus, modeloAutobus, capacidad, conductorAutobus, idConductor);

            cout << "Autob�s creado exitosamente." << endl;
            break;
        }

              // ... Resto del c�digo ...

        default:
            cout << "Opci�n inv�lida. Intente nuevamente." << endl;
            break;
        }
    } while (opcion != 8);

    // Liberar memoria de los objetos creados
    liberarMemoria(usuarios);
    liberarMemoria(autobuses);
    liberarMemoria(rutas);

    return 0;
}